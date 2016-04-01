
// openSurfView.h : CopenSurfView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "surflib.h"
#include "kmeans.h"


class CopenSurfView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CopenSurfView();
	DECLARE_DYNCREATE(CopenSurfView)

public:
	enum{ IDD = IDD_OPENSURF_FORM };

// Ư���Դϴ�.
public:
	CopenSurfDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CopenSurfView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // openSurfView.cpp�� ����� ����
inline CopenSurfDoc* CopenSurfView::GetDocument() const
   { return reinterpret_cast<CopenSurfDoc*>(m_pDocument); }
#endif

