
// MainFrm.cpp : CMainFrame Ŭ������ ����
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

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	cs.style &= ~FWS_ADDTOTITLE;  // ������� - ������Ʈ�� ���� ���� 
	 this->SetTitle("Stakato");

	 /////////////////////////////////////
	 /////////////////////////////////////
	
 // cs.lpszName = _T("�̹������"); // �̷��� �ص� �����

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

// CMainFrame ����

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


// CMainFrame �޽��� ó����



int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	// TODO: Add your specialized creation code here
	HICON hLargeIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME); // 32*32 ������ ����
	HICON hSmallIcon=(HICON) ::LoadImage(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16,16, LR_DEFAULTCOLOR);
	SetIcon(hSmallIcon,TRUE);
return 0;
}


BOOL CMainFrame::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	

	return CFrameWnd::OnEraseBkgnd(pDC);
}


BOOL CMainFrame::OnNcActivate(BOOL bActive)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CFrameWnd::OnNcActivate(bActive);
}
