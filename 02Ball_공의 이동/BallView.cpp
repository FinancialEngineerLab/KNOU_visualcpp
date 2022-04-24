
// BallView.cpp : CBallView 클래스의 구현
//

#include "stdafx.h"
#include "Ball.h"

#include "BallDoc.h"
#include "BallView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//간격과 반지름을 정의
#define  STEP     5
#define  RAD      20

// CBallView

IMPLEMENT_DYNCREATE(CBallView, CView)

BEGIN_MESSAGE_MAP(CBallView, CView)
	// 표준 인쇄 명령입니다.
ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBallView::OnFilePrintPreview)
ON_WM_CREATE()
ON_WM_DESTROY()
ON_WM_TIMER()
END_MESSAGE_MAP()

// CBallView 생성/소멸

CBallView::CBallView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	nX = nY = RAD;
	nMx = nMy = STEP;
}

CBallView::~CBallView()
{
}

BOOL CBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBallView 그리기

void CBallView::OnDraw(CDC* /*pDC*/)
{
	CBallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// CBallView 인쇄


void CBallView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CBallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


void CBallView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CBallView 진단

#ifdef _DEBUG
void CBallView::AssertValid() const
{
	CView::AssertValid();
}

void CBallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBallDoc* CBallView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBallDoc)));
	return (CBallDoc*)m_pDocument;
}
#endif //_DEBUG

int CBallView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer(1,20,NULL);	
	return 0;
}

void CBallView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
}

void CBallView::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);
	CRect r;			// 클라이언트 영역의 크기
	GetClientRect(&r);  // 클라이언트 영역의 크기를 얻음

	CBrush brush, *pOldB;
	brush.CreateSolidBrush(RGB(255, 255, 255));  //브러시가 흰색을 갖게 한다.
	pOldB = dc.SelectObject(&brush);			//이전의 브러시를 저장한다.
	dc.Ellipse(nX - RAD, nY - RAD, nX + RAD, nY + RAD);
    nX += nMx ;  
    nY += nMy;

	CView::OnTimer(nIDEvent);
}



