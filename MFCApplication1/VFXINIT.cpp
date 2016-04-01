#include "stdafx.h"
#include "VFXINIT.h"

#include "Global.h"

CVFX_Init::CVFX_Init(HWND hWnd)
{
	//capSetVideoFormat() 에서 사이즈를 고정시킬때 사용하기 위해서 초기화를 해 둡니다.
	m_bmpInfo.bmiHeader.biBitCount		= 24;
	m_bmpInfo.bmiHeader.biClrImportant	= 0;
	m_bmpInfo.bmiHeader.biClrUsed		= 0;
	m_bmpInfo.bmiHeader.biCompression	= BI_RGB;
	m_bmpInfo.bmiHeader.biHeight		= V_HEIGHT;
	m_bmpInfo.bmiHeader.biPlanes		= 1;
	m_bmpInfo.bmiHeader.biSize			= 40;
	m_bmpInfo.bmiHeader.biSizeImage		= 3*V_WIDTH*V_HEIGHT;
	//160*120=57600 176*144=76032, 320*240=230400, 352*288=304128, 640*480=921600
	m_bmpInfo.bmiHeader.biWidth			= V_WIDTH;
	m_bmpInfo.bmiHeader.biXPelsPerMeter	= 0;
	m_bmpInfo.bmiHeader.biYPelsPerMeter	= 0;
	m_bmpInfo.bmiColors[0].rgbBlue		= 0;
	m_bmpInfo.bmiColors[0].rgbGreen		= 0;
	m_bmpInfo.bmiColors[0].rgbRed		= 0;
	m_bmpInfo.bmiColors[0].rgbReserved	= 0;
	Graphing = 0;
	m_hWnd = hWnd;
}
CVFX_Init::~CVFX_Init()
{
	
}



BOOL CVFX_Init::InitSharedMemory()
{
	/*----------------------------------------------------------------------------------------------
	 4의 배수가 되는 DIB의 실제 비트맵 데이터의 크기를 구합니다.
	 왜 4의 배수냐고여? DIB중에 실제 비트 데이터 부분은 4의 배수가 되도록 설계되어 있습니다.
 	 구러니까... 트루컬러일 경우 한픽셀을 표현하는데 사용되는 메모리는 r, g, b해서 3byte입니다.
 	 만약 한 스캔라인(한줄)이 49pixel이라면 49*3 = 147byte 자나여... 하지만
	 DIB은 한스캔라인이 4의 배수가 되도록 구성해야 하므로 147 Byte가 아닌 148 Byte가 사용되게 됩니다.
 	 이러한 더미 메모리를 고려해서 정확한 비트 데이터의 크기를 구해야 합니다.
	----------------------------------------------------------------------------------------------*/

	int size = ((g_BitInfo.bmiHeader.biWidth * 3 + 3)/4)*4*g_BitInfo.bmiHeader.biHeight;


	//캡쳐된 실제 비트 데이터를 담을메모리 맵 파일을 생성합니다.
	m_hMapFile = ::CreateFileMapping( (HANDLE)0xFFFFFFFF, 
									  NULL, 
									  PAGE_READWRITE, 
									  0, 
									  size, 
									  "JINI4X8DU");
	if( !m_hMapFile )
		return FALSE;


	//사용하기 위해서 메모리 맵 파일의 포인터를 얻습니다.
	g_pMapMemory = (BYTE *)::MapViewOfFile( m_hMapFile, FILE_MAP_WRITE, 0, 0, 0 );

	
	return TRUE;
}
BOOL CVFX_Init::InitVideoWnd()
{
	HWND hwndCap;

	CRect rect;

	rect.left = 20;                //처음뜨는 화면 사이즈 조절
	rect.right =0;//V_WIDTH;     
	rect.top = 20;
	rect.bottom = 0;//V_HEIGHT;        //처음뜨는 화면 사이즈 조절
 
	//비디오캡쳐 윈도우를 지정된 영역에 생성합니다.
    hwndCap = capCreateCaptureWindow(
                NULL,
                WS_CHILD | WS_VISIBLE,
                rect.left, rect.top, rect.Width(), rect.Height(),
                m_hWnd,
                1);

	//생성이 제대로 되었는지 확인 합니다.
    if( hwndCap == NULL )
		return FALSE;
	

	//생성이 제대로 되었다면 얻은 캡쳐윈도우 핸들을 멤버변수에 설정해 놓습니다.
	m_hwndCap = hwndCap;


	//캡쳐 윈도우와 드라이버를 연결한다.
	//capDriverConnect()함수에서 두 번째 파라메터인 0은 캡쳐드라이버의 인덱스 번호인데 하나 이상의
	//캡쳐디바이스가 설치되었을 경우 이 인덱스 값으로 디바이스를 구분합니다.
    if( capDriverConnect(hwndCap, 0) == FALSE ) 
		return FALSE;
	

	//캡쳐윈도우에 프리뷰 모드로 디스플레이를 시작합니다.
	/*
	capPreview( hwndCap, true );
	capPreviewRate( hwndCap, 33 );
	capPreviewScale( hwndCap, false );
*/
	//capDlgVideoFormat( m_hwndCap );
		
	//콜백 함수에서 제대로된 DIB정보를 얻기위해 비디오 포맷을 RGB 24bit로 설정합니다.
	if( !capSetVideoFormat( hwndCap, &m_bmpInfo, sizeof(BITMAPINFO) ) )
	{
		AfxMessageBox(("해상도 정확히 설정해주세요"));
		capDlgVideoFormat( m_hwndCap );
		if( !capSetVideoFormat( hwndCap, &m_bmpInfo, sizeof(BITMAPINFO) ) )
		{
			AfxMessageBox(("비디오 포맷 설정에 실패했습니다. 드라이버의 문제일 수 있습니다. 구입처에 문의해 주십시요."));
			return FALSE;
		}
	}

	//캡쳐되는 이미지의 정보가 되는 BITMAPINFO를 얻어냅니다.
	capGetVideoFormat( hwndCap, &g_BitInfo, sizeof(BITMAPINFO) );


	//콜백 함수를 지정합니다. ★앗쭈중요★
	capSetCallbackOnVideoStream( hwndCap, VideoStreamCallbackProc );
	

	//캡쳐에 필요한 모든 정보들을 셋팅합니다.
	CAPTUREPARMS captureParms;
	captureParms.fCaptureAudio = false;               //오디오는 캡쳐하지않음
	captureParms.fMCIControl = false;				   //MCI장치 캡쳐 플래그(TRUE하면 캡쳐 안됨)
	captureParms.fLimitEnabled = false;				 //시간제한 없이 캡쳐링함 
	captureParms.dwRequestMicroSecPerFrame = 1000000/30;   
	captureParms.wTimeLimit = 20000;				  //wTimeLimit시간만큼 경과한 후에 연속 캡쳐가 멈춘다.  
	captureParms.fUsingDOSMemory = true;			  
	captureParms.fMakeUserHitOKToCapture = true;	  //사용자가 캡쳐를 시작했음을 대화상자를띄어보여주는 플래그
	captureParms.wPercentDropForError = 100;			//놓지는 프레임은 최대 10%로 제한(기본값:10)
	captureParms.wNumVideoRequested = 1;//32;			   //허용된 비디오 버퍼의 최대 갯수
	captureParms.fAbortLeftMouse = false;			  //왼쪽 마우스를 눌러도 캡쳐종료 안되게...
	captureParms.fAbortRightMouse = false;			  //오른쪽 마우스를 눌러도 캡쳐종료 안되게...
	captureParms.wChunkGranularity = 0;				   //AVI파일의 논리적 블록(0:현재섹터크기가 알갱이처럼사용되고있음을 가리킨다.)
	captureParms.fYield = true;						  //쓰레드를 생성시켜 캡쳐링함.
	captureParms.dwIndexSize = 27000;				   //캡쳐 할 수 있는 프레임 혹은 오디오 버퍼의 갯수에 대한 제한을 정함.
	captureParms.wNumAudioRequested = 4;		       //허용하는 오디오 버퍼의 최대 갯수(최대는10이다)
	captureParms.vKeyAbort = 0;//VK_ESCAPE;				//연속캡쳐를종료에 사용하는 가상 키코드(기본값은Esc=VK_ESCAPE) RegisterHotKey함수를 사용하여 변경 가능하다. //Esc 키를 누르면 캡쳐종료.  
	captureParms.fStepMCIDevice = 0;                   //MCI장치 스텝 캡쳐 플래그: FALSE면 MCI장치이용한 스텝캡쳐가가능해짐. fMCIControl이 FALSE이면 이 멤버는 무시된다.
	captureParms.dwMCIStartTime = 10000;			 //캡쳐시퀀스를위한MCI장치의 ms단위 시작 지점(fMCIControl이FALSE면 무시됨)

	captureParms.dwMCIStopTime = 20000;				  //캡쳐시퀀스를위한MCI장치의 ms단위 중단 지점(fMCIControl이FALSE면 무시됨)
	captureParms.fStepCaptureAt2x = 0;				  //이중해상도 스텝캡쳐 플래그:TRUE면 명시된 해상도의 두배로 캡쳐 한다.RGB형식의 캡쳐 중이라면 사용 가능하다.
	captureParms.wStepCaptureAverageFrames = 5;//5;    //한프레임을 만들 때 프레임이 캡쳐 되는 횟수, 평균치는 5.  
	captureParms.dwAudioBufferSize = 0;               //오디오 버퍼싸이즈...(기본값은0:각버퍼크기는오디오최대크기인0.5초혹은10k bytes가 될것)
	captureParms.fDisableWriteCache = 0;              //win32프로그램을 사용하지 않음
	captureParms.AVStreamMaster = 0;                   //AVI파일을 기록할때 오디오 스트림이 시계를 제어하는지에 대한 여부

	//캡쳐에 필요한 정보를 저장합니다.
	capCaptureSetSetup( hwndCap, &captureParms, sizeof(CAPTUREPARMS) );

	
	
	//캡쳐링을 실시합니다.
	capCaptureSequenceNoFile( hwndCap );
	
	
	

	return TRUE;


}
void CVFX_Init::init()
{
	if( !InitVideoWnd() )
		AfxMessageBox( "CCD 카메라를 초기화 할 수 없습니다." );

	//코덱프로세스와 메인 프로세스간에 데이터 교환이 가능하도록 공유메모리를 셋팅합니다.
	if( !InitSharedMemory() )
		AfxMessageBox( "공유메모리를 설정할 수 없습니다." );


}

void CVFX_Init::DLG_ON()
{
	//int WM_CAP_START = 1024; // WM_USER
	//int WM_CAP_DLG_VIDEODISPLAY = WM_CAP_START + 42;
	
	Graphing = 1;
	capCaptureStop(m_hwndCap);
	capPreview( m_hwndCap, true );
	
	Sleep(3000);
	capDlgVideoSource(m_hwndCap);
	capPreview( m_hwndCap, false );
	Graphing = 0;
	
	

	//capGrabFrameNoStop(m_hwndCap);
	capCaptureSequenceNoFile( m_hwndCap );
	
}


void CVFX_Init::Graph()
{ 
	capGrabFrameNoStop(m_hwndCap);
}