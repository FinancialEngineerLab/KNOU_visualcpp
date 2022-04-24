
// BallView.cpp : CBallView Ŭ������ ����
//

#include "stdafx.h"
#include "Ball.h"

#include "BallDoc.h"
#include "BallView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//���ݰ� �������� ��ũ�η� ����
#define  STEP     5
#define  RAD      20

// CBallView

IMPLEMENT_DYNCREATE(CBallView, CView)

BEGIN_MESSAGE_MAP(CBallView, CView)
	// ǥ�� �μ� ����Դϴ�.
ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBallView::OnFilePrintPreview)
ON_WM_CREATE()
ON_WM_DESTROY()
ON_WM_TIMER()
ON_COMMAND(ID_START, &CBallView::OnStart)
ON_COMMAND(ID_STOP, &CBallView::OnStop)
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CBallView ����/�Ҹ�

CBallView::CBallView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	nX = nY = RAD;
	nMx = nMy = STEP;
}

CBallView::~CBallView()
{
}

BOOL CBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CBallView �׸���

void CBallView::OnDraw(CDC* pDC)
{
	CBallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;



// GDI �Լ� ����
  
      pDC->MoveTo(100, 50);
	  pDC->LineTo(200, 50);
	  pDC->LineTo(100, 100);
   
  // GDI ��ü CPen
      CPen pen, *oldpen;
	  pen.CreatePen(PS_DASH,1,RGB(255,0,0));
      oldpen = pDC->SelectObject(&pen);	  
	  pDC->LineTo(200, 100);

// GDI �Լ� �簢��
	  pDC->Rectangle(100,200,250,350);
      pDC->SelectObject(oldpen);

// GDI �Լ� Ÿ�� Stock ��ü
     pDC->SelectStockObject(GRAY_BRUSH);
     pDC->Ellipse(350,200,500,300);



}


// CBallView �μ�


void CBallView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CBallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CBallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CBallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CBallView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBallView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CBallView ����

#ifdef _DEBUG
void CBallView::AssertValid() const
{
	CView::AssertValid();
}

void CBallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBallDoc* CBallView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBallDoc)));
	return (CBallDoc*)m_pDocument;
}
#endif //_DEBUG

int CBallView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	// SetTimer(1,20,NULL);	
	return 0;
}

void CBallView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(1);
}

void CBallView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CRect r;			// Ŭ���̾�Ʈ ������ ũ��
	GetClientRect(&r);  // Ŭ���̾�Ʈ ������ ũ�⸦ ����

	CBrush brush, *pOldB;
	brush.CreateSolidBrush(RGB(255, 255, 255));  //�귯�ð� ����� ���� �Ѵ�.
	pOldB = dc.SelectObject(&brush);			//������ �귯�ø� �����Ѵ�.
	dc.Ellipse(nX - RAD, nY - RAD, nX + RAD, nY + RAD);
    nX += nMx ;  
    nY += nMy;

	

	CView::OnTimer(nIDEvent);
}

void CBallView::OnStart()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//�� ������ �����Ѵ�.
	 
}

void CBallView::OnStop()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//Ÿ�̸Ӹ� ���ش�
	 
}

void CBallView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.


	CView::OnRButtonDown(nFlags, point);
}
