
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication1.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_NCACTIVATE()
END_MESSAGE_MAP()

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	cs.style &= ~FWS_ADDTOTITLE;  // 제목없음 - 프로젝트명 형식 제거 
	 this->SetTitle("Stakato");

	 /////////////////////////////////////
	 /////////////////////////////////////
	
 // cs.lpszName = _T("이미지뷰어"); // 이렇게 해도 변경됨

	 if(cs.hMenu!=NULL)
	 {
		 ::DestroyMenu(cs.hMenu);
		 cs.hMenu=NULL;
	 }
	 if(!CFrameWnd::PreCreateWindow(cs))
	 {
		 return FALSE;
	 }

 return TRUE;


	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기



int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	// TODO: Add your specialized creation code here
	HICON hLargeIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME); // 32*32 아이콘 선택
	HICON hSmallIcon=(HICON) ::LoadImage(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16,16, LR_DEFAULTCOLOR);
	SetIcon(hSmallIcon,TRUE);
return 0;
}


BOOL CMainFrame::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	

	return CFrameWnd::OnEraseBkgnd(pDC);
}


BOOL CMainFrame::OnNcActivate(BOOL bActive)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CFrameWnd::OnNcActivate(bActive);
}
