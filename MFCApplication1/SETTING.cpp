// SETTING.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Global.h"
#include "SETTING.h"
#include "afxdialogex.h"


// SETTING 대화 상자입니다.

IMPLEMENT_DYNAMIC(SETTING, CDialog)

	SETTING::SETTING(CWnd* pParent /*=NULL*/)
	: CDialog(SETTING::IDD, pParent)
	, m_sldRHMIN(0)
	, m_sldRHMAX(0)
	, m_sldRSMIN(0)
	, m_sldRSMAX(0)
	, m_sldRIMIN(0)
	, m_sldRIMAX(0)
	, m_sldYHMIN(0)
	, m_sldYHMAX(0)
	, m_sldYSMIN(0)
	, m_sldYSMAX(0)
	, m_sldYIMIN(0)
	, m_sldYIMAX(0)
	, m_sldBHMIN(0)
	, m_sldBHMAX(0)
	, m_sldBSMIN(0)
	, m_sldBSMAX(0)
	, m_sldBIMIN(0)
	, m_sldBIMAX(0)
	, RHMIN_edit(0)
	, RHMAX_edit(0)
	, RSMIN_edit(0)
	, RSMAX_edit(0)
	, RIMIN_edit(0)
	, RIMAX_edit(0)
	, YHMIN_edit(0)
	, YHMAX_edit(0)
	, YSMIN_edit(0)
	, YSMAX_edit(0)
	, YIMIN_edit(0)
	, YIMAX_edit(0)
	, BHMIN_edit(0)
	, BHMAX_edit(0)
	, BSMIN_edit(0)
	, BSMAX_edit(0)
	, BIMIN_edit(0)
	, BIMAX_edit(0)
	, red(FALSE)
	, yellow(FALSE)
	, blue(FALSE)
{

}

SETTING::~SETTING()
{
}

void SETTING::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, m_sldRHMIN);
	DDV_MinMaxInt(pDX, m_sldRHMIN, 0, 360);
	DDX_Slider(pDX, IDC_SLIDER2, m_sldRHMAX);
	DDV_MinMaxInt(pDX, m_sldRHMAX, 0, 360);
	DDX_Slider(pDX, IDC_SLIDER3, m_sldRSMIN);
	DDV_MinMaxInt(pDX, m_sldRSMIN, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER4, m_sldRSMAX);
	DDV_MinMaxInt(pDX, m_sldRSMAX, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER5, m_sldRIMIN);
	DDV_MinMaxInt(pDX, m_sldRIMIN, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER6, m_sldRIMAX);
	DDV_MinMaxInt(pDX, m_sldRIMAX, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER7, m_sldYHMIN);
	DDV_MinMaxInt(pDX, m_sldYHMIN, 0, 360);
	DDX_Slider(pDX, IDC_SLIDER8, m_sldYHMAX);
	DDV_MinMaxInt(pDX, m_sldYHMAX, 0, 360);
	DDX_Slider(pDX, IDC_SLIDER26, m_sldYSMIN);
	DDV_MinMaxInt(pDX, m_sldYSMIN, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER27, m_sldYSMAX);
	DDV_MinMaxInt(pDX, m_sldYSMAX, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER28, m_sldYIMIN);
	DDV_MinMaxInt(pDX, m_sldYIMIN, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER29, m_sldYIMAX);
	DDV_MinMaxInt(pDX, m_sldYIMAX, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER30, m_sldBHMIN);
	DDV_MinMaxInt(pDX, m_sldBHMIN, 0, 360);
	DDX_Slider(pDX, IDC_SLIDER31, m_sldBHMAX);
	DDV_MinMaxInt(pDX, m_sldBHMAX, 0, 360);
	DDX_Slider(pDX, IDC_SLIDER32, m_sldBSMIN);
	DDV_MinMaxInt(pDX, m_sldBSMIN, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER33, m_sldBSMAX);
	DDV_MinMaxInt(pDX, m_sldBSMAX, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER34, m_sldBIMIN);
	DDV_MinMaxInt(pDX, m_sldBIMIN, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER35, m_sldBIMAX);
	DDV_MinMaxInt(pDX, m_sldBIMAX, 0, 100);
	DDX_Text(pDX, IDC_EDIT4, RHMIN_edit);
	DDV_MinMaxInt(pDX, RHMIN_edit, 0, 360);
	DDX_Text(pDX, IDC_EDIT5, RHMAX_edit);
	DDV_MinMaxInt(pDX, RHMAX_edit, 0, 360);
	DDX_Text(pDX, IDC_EDIT6, RSMIN_edit);
	DDV_MinMaxInt(pDX, RSMIN_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT7, RSMAX_edit);
	DDV_MinMaxInt(pDX, RSMAX_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT8, RIMIN_edit);
	DDV_MinMaxInt(pDX, RIMIN_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT9, RIMAX_edit);
	DDV_MinMaxInt(pDX, RIMAX_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT22, YHMIN_edit);
	DDV_MinMaxInt(pDX, YHMIN_edit, 0, 360);
	DDX_Text(pDX, IDC_EDIT23, YHMAX_edit);
	DDV_MinMaxInt(pDX, YHMAX_edit, 0, 360);
	DDX_Text(pDX, IDC_EDIT24, YSMIN_edit);
	DDV_MinMaxInt(pDX, YSMIN_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT25, YSMAX_edit);
	DDV_MinMaxInt(pDX, YSMAX_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT26, YIMIN_edit);
	DDV_MinMaxInt(pDX, YIMIN_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT10, YIMAX_edit);
	DDV_MinMaxInt(pDX, YIMAX_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT27, BHMIN_edit);
	DDV_MinMaxInt(pDX, BHMIN_edit, 0, 360);
	DDX_Text(pDX, IDC_EDIT28, BHMAX_edit);
	DDV_MinMaxInt(pDX, BHMAX_edit, 0, 360);
	DDX_Text(pDX, IDC_EDIT29, BSMIN_edit);
	DDV_MinMaxInt(pDX, BSMIN_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT30, BSMAX_edit);
	DDV_MinMaxInt(pDX, BSMAX_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT31, BIMIN_edit);
	DDV_MinMaxInt(pDX, BIMIN_edit, 0, 100);
	DDX_Text(pDX, IDC_EDIT32, BIMAX_edit);
	DDV_MinMaxInt(pDX, BIMAX_edit, 0, 100);
	DDX_Check(pDX, IDC_CHECK2, red);
	DDX_Check(pDX, IDC_CHECK3, yellow);
	DDX_Check(pDX, IDC_CHECK4, blue);

	((CSliderCtrl *)GetDlgItem(IDC_SLIDER1))->SetRange(0,360,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER2))->SetRange(0,360,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER3))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER4))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER5))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER6))->SetRange(0,100,TRUE);

	((CSliderCtrl *)GetDlgItem(IDC_SLIDER7))->SetRange(0,360,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER8))->SetRange(0,360,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER26))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER27))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER28))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER29))->SetRange(0,100,TRUE);

	((CSliderCtrl *)GetDlgItem(IDC_SLIDER30))->SetRange(0,360,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER31))->SetRange(0,360,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER32))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER33))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER34))->SetRange(0,100,TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER35))->SetRange(0,100,TRUE);
}


BEGIN_MESSAGE_MAP(SETTING, CDialog)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT4, &SETTING::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &SETTING::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &SETTING::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, &SETTING::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &SETTING::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, &SETTING::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT22, &SETTING::OnEnChangeEdit22)
	ON_EN_CHANGE(IDC_EDIT23, &SETTING::OnEnChangeEdit23)
	ON_EN_CHANGE(IDC_EDIT24, &SETTING::OnEnChangeEdit24)
	ON_EN_CHANGE(IDC_EDIT25, &SETTING::OnEnChangeEdit25)
	ON_EN_CHANGE(IDC_EDIT26, &SETTING::OnEnChangeEdit26)
	ON_EN_CHANGE(IDC_EDIT10, &SETTING::OnEnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT27, &SETTING::OnEnChangeEdit27)
	ON_EN_CHANGE(IDC_EDIT28, &SETTING::OnEnChangeEdit28)
	ON_EN_CHANGE(IDC_EDIT29, &SETTING::OnEnChangeEdit29)
	ON_EN_CHANGE(IDC_EDIT30, &SETTING::OnEnChangeEdit30)
	ON_EN_CHANGE(IDC_EDIT31, &SETTING::OnEnChangeEdit31)
	ON_EN_CHANGE(IDC_EDIT32, &SETTING::OnEnChangeEdit32)
	ON_BN_CLICKED(IDC_CHECK2, &SETTING::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &SETTING::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &SETTING::OnBnClickedCheck4)
	ON_BN_CLICKED(IDOK, &SETTING::OnBnClickedOk)
	//	ON_WM_INITMENU()
	//	ON_WM_CREATE()
	//	ON_WM_ENABLE()
END_MESSAGE_MAP()


// SETTING 메시지 처리기입니다.


void SETTING::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	UpdateData(TRUE);

	YHMIN = m_sldYHMIN;
	YHMAX = m_sldYHMAX;
	YSMIN = m_sldYSMIN;
	YSMAX = m_sldYSMAX;
	YVMIN = m_sldYIMIN;
	YVMAX = m_sldYIMAX;



	YHMIN_edit = m_sldYHMIN;
	YHMAX_edit = m_sldYHMAX;
	YSMIN_edit = m_sldYSMIN;
	YSMAX_edit = m_sldYSMAX;
	YIMIN_edit = m_sldYIMIN;
	YIMAX_edit = m_sldYIMAX;

	RHMIN = m_sldRHMIN;
	RHMAX = m_sldRHMAX;
	RSMIN = m_sldRSMIN;
	RSMAX = m_sldRSMAX;
	RVMIN = m_sldRIMIN;
	RVMAX = m_sldRIMAX;


	RHMIN_edit = m_sldRHMIN;
	RHMAX_edit = m_sldRHMAX;
	RSMIN_edit = m_sldRSMIN;
	RSMAX_edit = m_sldRSMAX;
	RIMIN_edit = m_sldRIMIN;
	RIMAX_edit = m_sldRIMAX;

	BHMIN = m_sldBHMIN;
	BHMAX = m_sldBHMAX;
	BSMIN = m_sldBSMIN;
	BSMAX = m_sldBSMAX;
	BVMIN = m_sldBIMIN;
	BVMAX = m_sldBIMAX;


	BHMIN_edit = m_sldBHMIN;
	BHMAX_edit = m_sldBHMAX;
	BSMIN_edit = m_sldBSMIN;
	BSMAX_edit = m_sldBSMAX;
	BIMIN_edit = m_sldBIMIN;
	BIMAX_edit = m_sldBIMAX;


	UpdateData(FALSE);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void SETTING::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	RHMIN=RHMIN_edit;
	m_sldRHMIN=RHMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit5()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	RHMAX=RHMAX_edit;
	m_sldRHMAX=RHMAX_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit6()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	RSMIN=RSMIN_edit;
	m_sldRSMIN=RSMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit7()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	RSMAX=RSMAX_edit;
	m_sldRSMAX=RSMAX_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit8()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	RVMIN=RIMIN_edit;
	m_sldRIMIN=RIMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit9()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	RVMAX=RIMAX_edit;
	m_sldRIMAX=RIMAX_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit22()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	YHMIN=YHMIN_edit;
	m_sldYHMIN=YHMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit23()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	YHMAX=YHMAX_edit;
	m_sldYHMAX=YHMAX_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit24()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	YSMIN=YSMIN_edit;
	m_sldYSMIN=YSMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit25()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	YSMAX=YSMAX_edit;
	m_sldYSMAX=YSMAX_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit26()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	YVMIN=YIMIN_edit;
	m_sldYIMIN=YIMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit10()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	YVMAX=YIMAX_edit;
	m_sldYIMAX=YIMAX_edit;

	UpdateData(FALSE);
}

void SETTING::OnEnChangeEdit27()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	BHMIN=BHMIN_edit;
	m_sldBHMIN=BHMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit28()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	BHMAX=BHMAX_edit;
	m_sldBHMAX=BHMAX_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit29()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	BSMIN=BSMIN_edit;
	m_sldBSMIN=BSMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit30()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	BSMAX=BSMAX_edit;
	m_sldBSMAX=BSMAX_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit31()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRIchEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	BVMIN=BIMIN_edit;
	m_sldBIMIN=BIMIN_edit;

	UpdateData(FALSE);
}


void SETTING::OnEnChangeEdit32()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRIchEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	BVMAX=BIMAX_edit;
	m_sldBIMAX=BIMAX_edit;

	UpdateData(FALSE);
}



void SETTING::OnBnClickedCheck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	RED=red;
}


void SETTING::OnBnClickedCheck3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	YELLOW=yellow;
}


void SETTING::OnBnClickedCheck4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	BLUE=blue;
}


void SETTING::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();
	TEST=FALSE;
	//delete this;
}

//
//void SETTING::OnInitMenu(CMenu* pMenu)
//{
//	CDialog::OnInitMenu(pMenu);
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//
//
//}



//	void SETTING::OnEnable(BOOL bEnable)
//	{
//		CDialog::OnEnable(bEnable);
//
//		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER1))->SetRange(0,360,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER2))->SetRange(0,360,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER3))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER4))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER5))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER6))->SetRange(0,100,TRUE);
//
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER7))->SetRange(0,360,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER8))->SetRange(0,360,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER26))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER27))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER28))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER29))->SetRange(0,100,TRUE);
//
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER30))->SetRange(0,360,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER31))->SetRange(0,360,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER32))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER33))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER34))->SetRange(0,100,TRUE);
//		((CSliderCtrl *)GetDlgItem(IDC_SLIDER35))->SetRange(0,100,TRUE);
//
//	}
