
// BallView.h : CBallView 클래스의 인터페이스
//


#pragma once


class CBallView : public CView
{
protected: // serialization에서만 만들어집니다.
	CBallView();
	DECLARE_DYNCREATE(CBallView)

// 특성입니다.
public:
	CBallDoc* GetDocument() const;

// 작업입니다.
public:
    
	int nX, nY;    //원의 중심 x,y좌표
	int nMx, nMy;  //x축, y축 이동폭과 방향

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CBallView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	
};

#ifndef _DEBUG  // BallView.cpp의 디버그 버전
inline CBallDoc* CBallView::GetDocument() const
   { return reinterpret_cast<CBallDoc*>(m_pDocument); }
#endif

