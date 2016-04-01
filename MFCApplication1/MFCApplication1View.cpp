
// MFCApplication1View.cpp : CMFCApplication1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#include "VFXINIT.h"
#include "Global.h"
#include "SETTING.h"
#include <mmsystem.h>





#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CVFX_Init *pCVfx;

CStdioFile Csf;
// CMFCApplication1View


void ShowError (HWND hwnd, DWORD dwError)
{
	TCHAR szErrorStr [1024] ;

	mciGetErrorString (dwError, szErrorStr, 
		sizeof (szErrorStr) / sizeof (TCHAR)) ;
	MessageBeep (MB_ICONEXCLAMATION) ;

}


IMPLEMENT_DYNCREATE(CMFCApplication1View, CFormView)

	BEGIN_MESSAGE_MAP(CMFCApplication1View, CFormView)
		//ON_WM_HSCROLL()
		ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1View::OnBnClickedButton1)
		ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1View::OnBnClickedButton2)
		ON_MESSAGE(WM_MYRECEIVE,OnReceive)
		ON_MESSAGE(WM_MYCLOSE,OnThreadClosed)

		ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1View::OnBnClickedButton3)

		ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1View::OnBnClickedButton8)
		ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1View::OnBnClickedButton9)
		ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1View::OnBnClickedButton5)
		ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1View::OnBnClickedButton6)
		ON_WM_CREATE()
		ON_WM_ERASEBKGND()
		//ON_WM_CTLCOLOR()
		ON_WM_TIMER()
	END_MESSAGE_MAP()

	// CMFCApplication1View 생성/소멸

	CMFCApplication1View::CMFCApplication1View()
		: CFormView(CMFCApplication1View::IDD)

		/*, charx(_T(""))
		, chary(_T(""))*/
		, m_musicslider(0)
	{
		// TODO: 여기에 생성 코드를 추가합니다.

	}

	CMFCApplication1View::~CMFCApplication1View()
	{
	}

	void CMFCApplication1View::DoDataExchange(CDataExchange* pDX)
	{
		CFormView::DoDataExchange(pDX);

		//DDX_Control(pDX, IDC_EDIT1, m_RcvData);

		/*	DDX_Text(pDX, IDC_x, charx);
		DDX_Text(pDX, IDC_y, chary);*/

		//DDX_Control(pDX, IDC_BUTTON3, m_setting);

		//DDX_Control(pDX, IDC_BUTTON8, m_open);
		DDX_Slider(pDX, IDC_SLIDER1, m_musicslider);
		DDV_MinMaxInt(pDX, m_musicslider, 0, 100);
}

	BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
	{
		cs.hMenu=NULL;
		// TODO: CREATESTRUCT cs를 수정하여 여기에서
		//  Window 클래스 또는 스타일을 수정합니다.

		return CFormView::PreCreateWindow(cs);
	}

	void CMFCApplication1View::OnInitialUpdate()
	{
		CFormView::OnInitialUpdate();
		GetParentFrame()->RecalcLayout();
		ResizeParentToFit();


		CStatic *size=(CStatic *)GetDlgItem(IDC_PICTURE);
		CWnd * pWnd;
		pWnd = GetDlgItem(IDC_PICTURE);
		CRect rect;
		pWnd->GetWindowRect(&rect);
		size->GetClientRect(rect);

		pCVfx = new CVFX_Init(pWnd->GetSafeHwnd());
		pCVfx->init();

		//rect.SetRect(100,100,300,300);
		pCView = new CDX_VIEW(&rect,pWnd);
		pCView->Init(m_hWnd);
		pCView->main_hWnd = this->m_hWnd;



		/*m_ctlMessage.SetWindowTextW(m_msg);*/
		m_bitmap.LoadBitmapA(IDB_BITMAP7);
		//m_brush.CreateSolidBrush(RGB(30,30,30));

/*
		m_setting.LoadBitmaps();
		m_setting.SizeToContent();*/
		//m_open.LoadBitmaps(OpenD,OpenD,OpenU,OpenU);
		//m_open.SizeToContent();
		

	}


	// CMFCApplication1View 진단

#ifdef _DEBUG
	void CMFCApplication1View::AssertValid() const
	{
		CFormView::AssertValid();
	}

	void CMFCApplication1View::Dump(CDumpContext& dc) const
	{
		CFormView::Dump(dc);
	}

	CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
		return (CMFCApplication1Doc*)m_pDocument;
	}
#endif //_DEBUG




	void CMFCApplication1View::OnBnClickedButton1()
	{
		// TODO: Add your control notification handler code here
		CString str = "COM9";
		m_Comm= new CPYH_Comm("\\\\.\\"+str,"9600","None","8 Bit","1 Bit");	// initial Comm port
		if(	m_Comm->Create(GetSafeHwnd()) != 0)	//통신포트를 열고 윈도우의 핸들을 넘긴다.
		{
			AfxMessageBox("됨");

			GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(true);
		}
		else
		{
			AfxMessageBox("안됨");
			GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
		}
	}


	void CMFCApplication1View::OnBnClickedButton2()
	{
		// TODO: Add your control notification handler code here
		if(m_Comm)	//컴포트가 존재하면
		{
			m_Comm->Close();
			m_Comm = NULL;
			GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
		}
	}


	LRESULT CMFCApplication1View::OnThreadClosed(WPARAM length, LPARAM lpara)
	{
		//overlapped i/o 핸들을 닫는다.
		((CPYH_Comm*)lpara)->HandleClose();
		delete ((CPYH_Comm*)lpara);

		return 0;
	}


	LRESULT CMFCApplication1View::OnReceive(WPARAM length, LPARAM lpara)
	{
		CString str;
		char data[20000];/*="Speed X : -25.916, Y : -100.674, Z: -55.819 Range X : 20.135, Y : 21.484, Z: 22.437 Angle X : -44.701, Y : 38.554, Z: 37.378 Angle_center 45.753 flex 326.979 END\0";*/
		if(m_Comm)
		{
			UpdateData(TRUE);
			m_Comm->Receive(data,length);	//length 길이만큼 데이터를 받는다.   data 를 땡겨쓰면 되겠네
			data[length]='\0';

			pCView->parsing(data,length);   //파싱시작

			for(int i = 0;i<length;i++)
			{
				str += data[i];
			}
		//	m_RcvData.ReplaceSel(str); //에디트 박스에 표시하기 위함
			str = "";


			UpdateData(FALSE);

		}


		return 0;
	}



	void CMFCApplication1View::OnBnClickedButton3()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

		TEST=TRUE;
		SETTING *sett=new SETTING;
		sett->Create(IDD_DIALOG1);
		sett->ShowWindow(SW_SHOW);

	}



	void CMFCApplication1View::OnBnClickedButton8()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		CFileDialog dlg( true, "*.*", NULL, OFN_HIDEREADONLY ,/* "All Files(*.*)|*.*|" */ "MID 파일(*.MID)|*.MID|", NULL );
		if( dlg.DoModal() == IDOK )
		{
			if(Csf.Open(dlg.GetPathName(),CFile::modeRead | CFile::typeText))
			{
				//////////////////////////////////////////////////////////임시용
				
				Filename=Csf.GetFilePath();
				bPlaying=FALSE;
				bPaused=FALSE;
			/*	midi getmidi;*/

				int iCStringLength = Filename.GetLength();
				char *str = new char[iCStringLength+1];
				strcpy(str, Filename.GetBuffer(0));
			
				int cnt = 0;
				for (int i = 0 ; str[i] != '\0' ; i++)
				{
					printf("%c", str[i]);
					cnt += 1;
				}
				printf("\n%d", cnt);
			
				Filename.ReleaseBuffer();

				//char *str;
				//str = =LPSTR(LPCTSTR(Filename));
				getmidi.load_midi(str);
				mciSendCommand (wDeviceID, MCI_CLOSE, MCI_WAIT,(DWORD) (LPMCI_GENERIC_PARMS) &mciGeneric) ;
				Csf.Close();
			}
		}
		else
		{
		}


	}


	void CMFCApplication1View::OnBnClickedButton9()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

		IplImage *img1, *img2;
		img1 = cvLoadImage("44m.jpg");
		img2 = cvLoadImage("test.bmp");

		IpVec ipts1, ipts2;
		surfDetDes(img1,ipts1,false,5,4,2,0.0001f);
		surfDetDes(img2,ipts2,false,5,4,2,0.0001f);

		IpPairVec matches;
		getMatches(ipts1,ipts2,matches);

		for (unsigned int i = 0; i < matches.size(); ++i)
		{
			drawPoint(img1,matches[i].first);
			drawPoint(img2,matches[i].second);

			const int & w = img1->width;
			cvLine(img1,cvPoint(matches[i].first.x,matches[i].first.y),cvPoint(matches[i].second.x+w,matches[i].second.y), cvScalar(255,255,255),1);
			cvLine(img2,cvPoint(matches[i].first.x-w,matches[i].first.y),cvPoint(matches[i].second.x,matches[i].second.y), cvScalar(255,255,255),1);
		}
		

		std::cout<< "Matches: " << matches.size();
		SetDlgItemInt(IDC_SPOT,matches.size());


		cvNamedWindow("1", CV_WINDOW_AUTOSIZE );
		cvNamedWindow("2", CV_WINDOW_AUTOSIZE );
		cvShowImage("1", img1);
		cvShowImage("2",img2);
		cvWaitKey(0);


	}


	void CMFCApplication1View::OnBnClickedButton5()
	{

		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

		if(!getmidi.ms.playing)
		{


			////-- 다시 PLAY 버튼을 누르면 디바이스를 닫는다!! -OK! --//
			//mciSendCommand (wDeviceID, MCI_CLOSE, MCI_WAIT,(DWORD) (LPMCI_GENERIC_PARMS) &mciGeneric) ;

			//// Open waveform audio 
			//mciOpen.dwCallback       = 0 ;
			//mciOpen.wDeviceID        = 0 ;
			//mciOpen.lpstrDeviceType  = NULL ;
			//mciOpen.lpstrElementName = Filename; // 전역 변수 
			////mciOpen.lpstrElementName = szFileName ;
			//mciOpen.lpstrAlias       = NULL ;  
			//dwError = mciSendCommand (0, MCI_OPEN,
			//	MCI_WAIT | MCI_OPEN_ELEMENT,
			//	(DWORD) (LPMCI_OPEN_PARMS) &mciOpen) ;  

			//if (dwError != 0)
			//{
			//	ShowError (this->m_hWnd, dwError) ;
			//	//return 0 ;
			//}
			//// Save the device ID     

			//wDeviceID = mciOpen.wDeviceID ;   
			//// Begin playing

			//mciPlay.dwCallback = (DWORD) this->m_hWnd ;
			//mciPlay.dwFrom     = 0 ;
			//mciPlay.dwTo       = 0 ;

			//mciSendCommand (wDeviceID, MCI_PLAY, MCI_NOTIFY,
			//	(DWORD) (LPMCI_PLAY_PARMS) &mciPlay) ;
			//// Enable and disable buttons

			///*	EnableWindow (GetDlgItem (hwnd, IDC_RECORD_BEG), FALSE);
			//EnableWindow (GetDlgItem (hwnd, IDC_RECORD_END), FALSE);
			//EnableWindow (GetDlgItem (hwnd, IDC_PLAY_BEG),   FALSE);
			//EnableWindow (GetDlgItem (hwnd, IDC_PLAY_PAUSE), TRUE) ;
			//EnableWindow (GetDlgItem (hwnd, IDC_PLAY_END),   TRUE) ;
			//SetFocus (GetDlgItem (hwnd, IDC_PLAY_END)) ;*/

			////////////////////////////////////////////////////
			
			////////////////////////////////////////////////////
			//bPlaying = TRUE; 
			//return TRUE ;

			
			getmidi.run();
		}

		else
		{
			//if (!bPaused)
			//	// Pause the play
			//{
			//	mciGeneric.dwCallback = 0 ;                   

			//	mciSendCommand (wDeviceID, MCI_PAUSE, MCI_WAIT,
			//		(DWORD) (LPMCI_GENERIC_PARMS) & mciGeneric);

			//	//SetDlgItemText (this->m_hWnd, IDC_PLAY_PAUSE, TEXT ("Resume")) ;
			//	bPaused = TRUE ;
			//}

			//else
			//	// Begin playing again
			//{
			//	mciPlay.dwCallback = (DWORD) this->m_hWnd ;
			//	mciPlay.dwFrom     = 0 ;
			//	mciPlay.dwTo       = 0 ;

			//	mciSendCommand (wDeviceID, MCI_PLAY, MCI_NOTIFY,
			//		(DWORD) (LPMCI_PLAY_PARMS) &mciPlay) ;

			//	//SetDlgItemText (this->m_hWnd, IDC_PLAY_PAUSE, TEXT ("Pause")) ;
				//bPaused = FALSE ;
			//}


			
			getmidi.ms.paused = !(getmidi.ms.paused);
			//return TRUE ;
		}
	}


	void CMFCApplication1View::OnBnClickedButton6()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


		/*mciGeneric.dwCallback = 0 ;

		mciSendCommand (wDeviceID, MCI_STOP, MCI_WAIT,
			(DWORD) (LPMCI_GENERIC_PARMS) &mciGeneric) ;

		mciSendCommand (wDeviceID, MCI_CLOSE, MCI_WAIT,
			(DWORD) (LPMCI_GENERIC_PARMS) &mciGeneric) ;*/
		// Enable and disable buttons

		/*EnableWindow (GetDlgItem (hwnd, IDC_RECORD_BEG), TRUE) ;
		EnableWindow (GetDlgItem (hwnd, IDC_RECORD_END), FALSE);
		EnableWindow (GetDlgItem (hwnd, IDC_PLAY_BEG),   TRUE) ;
		EnableWindow (GetDlgItem (hwnd, IDC_PLAY_PAUSE), FALSE);
		EnableWindow (GetDlgItem (hwnd, IDC_PLAY_END),   FALSE);*/
		//SetFocus (GetDlgItem (hwnd, IDC_PLAY_BEG)) ;

		/*bPlaying = FALSE ;
		bPaused  = FALSE ;*/
		
		getmidi.ms.stop_requested = 1;

	}


	int CMFCApplication1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CFormView::OnCreate(lpCreateStruct) == -1)
			return -1;


		SetMenu(NULL); 

		// TODO:  여기에 특수화된 작성 코드를 추가합니다.
		HICON hLargeIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME); // 32*32 아이콘 선택
		HICON hSmallIcon=(HICON) ::LoadImage(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16,16, LR_DEFAULTCOLOR);
		SetIcon(hSmallIcon,TRUE);
		return 0;



		return 0;
	}


	BOOL CMFCApplication1View::OnEraseBkgnd(CDC* pDC)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

		if(!m_bitmap.m_hObject)
		{
			return true;
		}

		CRect rect;
		GetClientRect(&rect);

		CDC dc;
		dc.CreateCompatibleDC(pDC);
		CBitmap *pOldBitmap=dc.SelectObject(&m_bitmap);

		BITMAP bmap;
		m_bitmap.GetBitmap(&bmap);
		pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,bmap.bmWidth,bmap.bmHeight,SRCCOPY);

		dc.SelectObject(pOldBitmap);
		return true;

		return CFormView::OnEraseBkgnd(pDC);
	}


	//HBRUSH CMFCApplication1View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
	//{
	//	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	//	// TODO:  여기서 DC의 특성을 변경합니다.

	//	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	//	if(nCtlColor==CTLCOLOR_BTN)
	//	{
	//		pDC->SetTextColor(RGB(255,255,255));
	//		pDC->SetBkColor(RGB(0,0,0));
	//		return m_brush;
	//	}
	//	//return hbr;

	//	return CFormView::OnCtlColor(pDC,pWnd,nCtlColor); 
	//}


	void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

		m_musicslider;
		Sleep(1000);

		CFormView::OnTimer(nIDEvent);
	}
