
// MFCApplication1View.h : CMFCApplication1View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "CPYH_Comm.h"
#include "afxwin.h"

#include "surflib.h"
#include "kmeans.h"
#include "afxext.h"
#include "midi.h"

class CMFCApplication1View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

public:
	enum{ IDD = IDD_MFCAPPLICATION1_FORM };

// 특성입니다.
public:
	CMFCApplication1Doc* GetDocument() const;

// 작업입니다.
public:
	CBitmap m_bitmap;
	CBrush m_brush;
	midi getmidi;

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	/*int m_sldRMIN;
	int m_sldRMAX;
	int m_sldGMIN;
	int m_sldGMAX;
	int m_sldBMIN;
	int m_sldBMAX;*/
	CPYH_Comm* m_Comm;
	//afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//BOOL Binary;
	//
	//int m_sldBinary;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	LRESULT	OnThreadClosed(WPARAM length, LPARAM lpara);
	LRESULT	OnReceive(WPARAM length, LPARAM lpara);
	//CEdit m_RcvData;
	CString Filename;


	/*static*/ BOOL       bRecording, bPlaying, bPaused ;
//	static TCHAR      szFileName[] = TEXT ("record2.wav") ;
	//static TCHAR      FileName[] = TEXT ("E:\\WaveFile's\\sa1.wav") ;
	/*static*/ WORD       wDeviceID ;
	DWORD             dwError ;
	MCI_GENERIC_PARMS mciGeneric ;
	MCI_OPEN_PARMS    mciOpen ;
	MCI_PLAY_PARMS    mciPlay ;
	MCI_RECORD_PARMS  mciRecord ;
	MCI_SAVE_PARMS    mciSave ;
	//static BOOL bPlaying;
	/*int m_sldYHMIN;
	int m_sldYHMAX;
	int m_sldYSMIN;
	int m_sldYSMAX;
	int m_sldYIMIN;
	int m_sldYIMAX;
	BOOL test;*/
	//afx_msg void OnBnClickedCheck1();
	//BOOL red;
	//BOOL green;
	//BOOL yellow;
	//BOOL blue;
	/*afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();*/
	/*int YHMIN_edit;
	int YHMAX_edit;
	int YSMIN_edit;
	int YSMAX_edit;
	int YIMIN_edit;
	int YIMAX_edit;*/
	/*afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit9();*/
	//int m_sldRHMIN;
	//int m_sldRHMAX;
	//int m_sldRSMIN;
	//int m_sldRSMAX;
	//int m_sldRIMIN;
	//int m_sldRIMAX;
	//int m_sldBHMIN;
	//int m_sldBHMAX;
	//int m_sldBSMIN;
	//int m_sldBIMIN;
	//int m_sldBSMAX;
	//int m_sldBIMAX;
	//int RHMIN_edit;
	//int RHMAX_edit;
	//int RSMIN_edit;
	//int RSMAX_edit;
	//int RIMIN_edit;
	//int RIMAX_edit;
	//int BHMIN_edit;
	//int BHMAX_edit;
	//int BSMIN_edit;
	//int BSMAX_edit;
	//int BIMIN_edit;
	//int BIMAX_edit;
	/*afx_msg void OnEnChangeEdit10();
	afx_msg void OnEnChangeEdit11();
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnEnChangeEdit13();
	afx_msg void OnEnChangeEdit14();
	afx_msg void OnEnChangeEdit15();
	afx_msg void OnEnChangeEdit16();
	afx_msg void OnEnChangeEdit17();
	afx_msg void OnEnChangeEdit18();
	afx_msg void OnEnChangeEdit19();
	afx_msg void OnEnChangeEdit20();
	afx_msg void OnEnChangeEdit21();*/
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton8();
	//CString charx;
	//CString chary;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	
	//CBitmapButton m_setting;
	
	//CBitmapButton m_open;
	int m_musicslider;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCApplication1View.cpp의 디버그 버전
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

