#include "stdafx.h"
#include "VFXINIT.h"

#include "Global.h"

CVFX_Init::CVFX_Init(HWND hWnd)
{
	//capSetVideoFormat() ���� ����� ������ų�� ����ϱ� ���ؼ� �ʱ�ȭ�� �� �Ӵϴ�.
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
	 4�� ����� �Ǵ� DIB�� ���� ��Ʈ�� �������� ũ�⸦ ���մϴ�.
	 �� 4�� ����İ�? DIB�߿� ���� ��Ʈ ������ �κ��� 4�� ����� �ǵ��� ����Ǿ� �ֽ��ϴ�.
 	 �����ϱ�... Ʈ���÷��� ��� ���ȼ��� ǥ���ϴµ� ���Ǵ� �޸𸮴� r, g, b�ؼ� 3byte�Դϴ�.
 	 ���� �� ��ĵ����(����)�� 49pixel�̶�� 49*3 = 147byte �ڳ���... ������
	 DIB�� �ѽ�ĵ������ 4�� ����� �ǵ��� �����ؾ� �ϹǷ� 147 Byte�� �ƴ� 148 Byte�� ���ǰ� �˴ϴ�.
 	 �̷��� ���� �޸𸮸� ����ؼ� ��Ȯ�� ��Ʈ �������� ũ�⸦ ���ؾ� �մϴ�.
	----------------------------------------------------------------------------------------------*/

	int size = ((g_BitInfo.bmiHeader.biWidth * 3 + 3)/4)*4*g_BitInfo.bmiHeader.biHeight;


	//ĸ�ĵ� ���� ��Ʈ �����͸� �����޸� �� ������ �����մϴ�.
	m_hMapFile = ::CreateFileMapping( (HANDLE)0xFFFFFFFF, 
									  NULL, 
									  PAGE_READWRITE, 
									  0, 
									  size, 
									  "JINI4X8DU");
	if( !m_hMapFile )
		return FALSE;


	//����ϱ� ���ؼ� �޸� �� ������ �����͸� ����ϴ�.
	g_pMapMemory = (BYTE *)::MapViewOfFile( m_hMapFile, FILE_MAP_WRITE, 0, 0, 0 );

	
	return TRUE;
}
BOOL CVFX_Init::InitVideoWnd()
{
	HWND hwndCap;

	CRect rect;

	rect.left = 20;                //ó���ߴ� ȭ�� ������ ����
	rect.right =0;//V_WIDTH;     
	rect.top = 20;
	rect.bottom = 0;//V_HEIGHT;        //ó���ߴ� ȭ�� ������ ����
 
	//����ĸ�� �����츦 ������ ������ �����մϴ�.
    hwndCap = capCreateCaptureWindow(
                NULL,
                WS_CHILD | WS_VISIBLE,
                rect.left, rect.top, rect.Width(), rect.Height(),
                m_hWnd,
                1);

	//������ ����� �Ǿ����� Ȯ�� �մϴ�.
    if( hwndCap == NULL )
		return FALSE;
	

	//������ ����� �Ǿ��ٸ� ���� ĸ�������� �ڵ��� ��������� ������ �����ϴ�.
	m_hwndCap = hwndCap;


	//ĸ�� ������� ����̹��� �����Ѵ�.
	//capDriverConnect()�Լ����� �� ��° �Ķ������ 0�� ĸ�ĵ���̹��� �ε��� ��ȣ�ε� �ϳ� �̻���
	//ĸ�ĵ���̽��� ��ġ�Ǿ��� ��� �� �ε��� ������ ����̽��� �����մϴ�.
    if( capDriverConnect(hwndCap, 0) == FALSE ) 
		return FALSE;
	

	//ĸ�������쿡 ������ ���� ���÷��̸� �����մϴ�.
	/*
	capPreview( hwndCap, true );
	capPreviewRate( hwndCap, 33 );
	capPreviewScale( hwndCap, false );
*/
	//capDlgVideoFormat( m_hwndCap );
		
	//�ݹ� �Լ����� ����ε� DIB������ ������� ���� ������ RGB 24bit�� �����մϴ�.
	if( !capSetVideoFormat( hwndCap, &m_bmpInfo, sizeof(BITMAPINFO) ) )
	{
		AfxMessageBox(("�ػ� ��Ȯ�� �������ּ���"));
		capDlgVideoFormat( m_hwndCap );
		if( !capSetVideoFormat( hwndCap, &m_bmpInfo, sizeof(BITMAPINFO) ) )
		{
			AfxMessageBox(("���� ���� ������ �����߽��ϴ�. ����̹��� ������ �� �ֽ��ϴ�. ����ó�� ������ �ֽʽÿ�."));
			return FALSE;
		}
	}

	//ĸ�ĵǴ� �̹����� ������ �Ǵ� BITMAPINFO�� �����ϴ�.
	capGetVideoFormat( hwndCap, &g_BitInfo, sizeof(BITMAPINFO) );


	//�ݹ� �Լ��� �����մϴ�. �ھ����߿��
	capSetCallbackOnVideoStream( hwndCap, VideoStreamCallbackProc );
	

	//ĸ�Ŀ� �ʿ��� ��� �������� �����մϴ�.
	CAPTUREPARMS captureParms;
	captureParms.fCaptureAudio = false;               //������� ĸ����������
	captureParms.fMCIControl = false;				   //MCI��ġ ĸ�� �÷���(TRUE�ϸ� ĸ�� �ȵ�)
	captureParms.fLimitEnabled = false;				 //�ð����� ���� ĸ�ĸ��� 
	captureParms.dwRequestMicroSecPerFrame = 1000000/30;   
	captureParms.wTimeLimit = 20000;				  //wTimeLimit�ð���ŭ ����� �Ŀ� ���� ĸ�İ� �����.  
	captureParms.fUsingDOSMemory = true;			  
	captureParms.fMakeUserHitOKToCapture = true;	  //����ڰ� ĸ�ĸ� ���������� ��ȭ���ڸ������ִ� �÷���
	captureParms.wPercentDropForError = 100;			//������ �������� �ִ� 10%�� ����(�⺻��:10)
	captureParms.wNumVideoRequested = 1;//32;			   //���� ���� ������ �ִ� ����
	captureParms.fAbortLeftMouse = false;			  //���� ���콺�� ������ ĸ������ �ȵǰ�...
	captureParms.fAbortRightMouse = false;			  //������ ���콺�� ������ ĸ������ �ȵǰ�...
	captureParms.wChunkGranularity = 0;				   //AVI������ ���� ���(0:���缽��ũ�Ⱑ �˰���ó�����ǰ������� ����Ų��.)
	captureParms.fYield = true;						  //�����带 �������� ĸ�ĸ���.
	captureParms.dwIndexSize = 27000;				   //ĸ�� �� �� �ִ� ������ Ȥ�� ����� ������ ������ ���� ������ ����.
	captureParms.wNumAudioRequested = 4;		       //����ϴ� ����� ������ �ִ� ����(�ִ��10�̴�)
	captureParms.vKeyAbort = 0;//VK_ESCAPE;				//����ĸ�ĸ����ῡ ����ϴ� ���� Ű�ڵ�(�⺻����Esc=VK_ESCAPE) RegisterHotKey�Լ��� ����Ͽ� ���� �����ϴ�. //Esc Ű�� ������ ĸ������.  
	captureParms.fStepMCIDevice = 0;                   //MCI��ġ ���� ĸ�� �÷���: FALSE�� MCI��ġ�̿��� ����ĸ�İ���������. fMCIControl�� FALSE�̸� �� ����� ���õȴ�.
	captureParms.dwMCIStartTime = 10000;			 //ĸ�Ľ�����������MCI��ġ�� ms���� ���� ����(fMCIControl��FALSE�� ���õ�)

	captureParms.dwMCIStopTime = 20000;				  //ĸ�Ľ�����������MCI��ġ�� ms���� �ߴ� ����(fMCIControl��FALSE�� ���õ�)
	captureParms.fStepCaptureAt2x = 0;				  //�����ػ� ����ĸ�� �÷���:TRUE�� ��õ� �ػ��� �ι�� ĸ�� �Ѵ�.RGB������ ĸ�� ���̶�� ��� �����ϴ�.
	captureParms.wStepCaptureAverageFrames = 5;//5;    //���������� ���� �� �������� ĸ�� �Ǵ� Ƚ��, ���ġ�� 5.  
	captureParms.dwAudioBufferSize = 0;               //����� ���۽�����...(�⺻����0:������ũ��¿�����ִ�ũ����0.5��Ȥ��10k bytes�� �ɰ�)
	captureParms.fDisableWriteCache = 0;              //win32���α׷��� ������� ����
	captureParms.AVStreamMaster = 0;                   //AVI������ ����Ҷ� ����� ��Ʈ���� �ð踦 �����ϴ����� ���� ����

	//ĸ�Ŀ� �ʿ��� ������ �����մϴ�.
	capCaptureSetSetup( hwndCap, &captureParms, sizeof(CAPTUREPARMS) );

	
	
	//ĸ�ĸ��� �ǽ��մϴ�.
	capCaptureSequenceNoFile( hwndCap );
	
	
	

	return TRUE;


}
void CVFX_Init::init()
{
	if( !InitVideoWnd() )
		AfxMessageBox( "CCD ī�޶� �ʱ�ȭ �� �� �����ϴ�." );

	//�ڵ����μ����� ���� ���μ������� ������ ��ȯ�� �����ϵ��� �����޸𸮸� �����մϴ�.
	if( !InitSharedMemory() )
		AfxMessageBox( "�����޸𸮸� ������ �� �����ϴ�." );


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