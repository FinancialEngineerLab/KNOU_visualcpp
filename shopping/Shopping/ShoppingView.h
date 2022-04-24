
// ShoppingView.h : CShoppingView 클래스의 인터페이스
//


#pragma once
#include "afxwin.h"
#include "afxcmn.h"


class CShoppingView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CShoppingView();
	DECLARE_DYNCREATE(CShoppingView)

public:
	enum{ IDD = IDD_SHOPPING_FORM };

// 특성입니다.
public:
	CShoppingDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CShoppingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString str;
	// 주문완료버튼 클릭시 결과값을 보여줄 컨트롤 변수
	CEdit m_Result;
	// 상품명
	CString m_Product;
	CString m_ProductCD;
	// 단가
	int m_Price;
	int m_Cnt;
	CSpinButtonCtrl m_Spin1;
	afx_msg void OnBnClickedButtonDone();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // ShoppingView.cpp의 디버그 버전
inline CShoppingDoc* CShoppingView::GetDocument() const
   { return reinterpret_cast<CShoppingDoc*>(m_pDocument); }
#endif

