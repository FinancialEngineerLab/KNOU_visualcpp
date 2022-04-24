
// ShoppingView.h : CShoppingView Ŭ������ �������̽�
//


#pragma once
#include "afxwin.h"
#include "afxcmn.h"


class CShoppingView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CShoppingView();
	DECLARE_DYNCREATE(CShoppingView)

public:
	enum{ IDD = IDD_SHOPPING_FORM };

// Ư���Դϴ�.
public:
	CShoppingDoc* GetDocument() const;

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
	virtual ~CShoppingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString str;
	// �ֹ��Ϸ��ư Ŭ���� ������� ������ ��Ʈ�� ����
	CEdit m_Result;
	// ��ǰ��
	CString m_Product;
	CString m_ProductCD;
	// �ܰ�
	int m_Price;
	int m_Cnt;
	CSpinButtonCtrl m_Spin1;
	afx_msg void OnBnClickedButtonDone();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // ShoppingView.cpp�� ����� ����
inline CShoppingDoc* CShoppingView::GetDocument() const
   { return reinterpret_cast<CShoppingDoc*>(m_pDocument); }
#endif

