
// openSurfView.cpp : CopenSurfView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CopenSurfView

IMPLEMENT_DYNCREATE(CopenSurfView, CFormView)

BEGIN_MESSAGE_MAP(CopenSurfView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CopenSurfView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CopenSurfView 생성/소멸

CopenSurfView::CopenSurfView()
	: CFormView(CopenSurfView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CopenSurfView::~CopenSurfView()
{
}

void CopenSurfView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CopenSurfView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CopenSurfView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CopenSurfView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CopenSurfView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CopenSurfView 진단

#ifdef _DEBUG
void CopenSurfView::AssertValid() const
{
	CFormView::AssertValid();
}

void CopenSurfView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CopenSurfDoc* CopenSurfView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CopenSurfDoc)));
	return (CopenSurfDoc*)m_pDocument;
}
#endif //_DEBUG


// CopenSurfView 메시지 처리기




void CopenSurfView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	 IplImage *img1, *img2;
  img1 = cvLoadImage("44m.jpg");
  img2 = cvLoadImage("mast.jpg");

  IpVec ipts1, ipts2;
  surfDetDes(img1,ipts1,false,4,4,2,0.0001f);
  surfDetDes(img2,ipts2,false,4,4,2,0.0001f);

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
