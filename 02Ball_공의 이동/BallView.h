
// BallView.h : CBallView Ŭ������ �������̽�
//


#pragma once


class CBallView : public CView
{
protected: // serialization������ ��������ϴ�.
	CBallView();
	DECLARE_DYNCREATE(CBallView)

// Ư���Դϴ�.
public:
	CBallDoc* GetDocument() const;

// �۾��Դϴ�.
public:
    
	int nX, nY;    //���� �߽� x,y��ǥ
	int nMx, nMy;  //x��, y�� �̵����� ����

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CBallView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	
};

#ifndef _DEBUG  // BallView.cpp�� ����� ����
inline CBallDoc* CBallView::GetDocument() const
   { return reinterpret_cast<CBallDoc*>(m_pDocument); }
#endif

