#pragma once


// SETTING 대화 상자입니다.

class SETTING : public CDialog
{
	DECLARE_DYNAMIC(SETTING)

public:
	SETTING(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SETTING();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_sldRHMIN;
	int m_sldRHMAX;
	int m_sldRSMIN;
	int m_sldRSMAX;
	int m_sldRIMIN;
	int m_sldRIMAX;
	int m_sldYHMIN;
	int m_sldYHMAX;
	int m_sldYSMIN;
	int m_sldYSMAX;
	int m_sldYIMIN;
	int m_sldYIMAX;
	int m_sldBHMIN;
	int m_sldBHMAX;
	int m_sldBSMIN;
	int m_sldBSMAX;
	int m_sldBIMIN;
	int m_sldBIMAX;
	int RHMIN_edit;
	int RHMAX_edit;
	INT RSMIN_edit;
	INT RSMAX_edit;
	INT RIMIN_edit;
	INT RIMAX_edit;
	INT YHMIN_edit;
	INT YHMAX_edit;
	INT YSMIN_edit;
	INT YSMAX_edit;
	INT YIMIN_edit;
	INT YIMAX_edit;
	INT BHMIN_edit;
	INT BHMAX_edit;
	INT BSMIN_edit;
	INT BSMAX_edit;
	INT BIMIN_edit;
	INT BIMAX_edit;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnEnChangeEdit22();
	afx_msg void OnEnChangeEdit23();
	afx_msg void OnEnChangeEdit24();
	afx_msg void OnEnChangeEdit25();
	afx_msg void OnEnChangeEdit26();
	afx_msg void OnEnChangeEdit10();
	afx_msg void OnEnChangeEdit27();
	afx_msg void OnEnChangeEdit28();
	afx_msg void OnEnChangeEdit29();
	afx_msg void OnEnChangeEdit30();
	afx_msg void OnEnChangeEdit31();
	afx_msg void OnEnChangeEdit32();
	BOOL red;
	BOOL yellow;
	BOOL blue;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedOk();
//	afx_msg void OnInitMenu(CMenu* pMenu);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnEnable(BOOL bEnable);
};
