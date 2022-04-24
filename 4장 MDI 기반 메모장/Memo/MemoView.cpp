
// MemoView.cpp : CMemoView Ŭ������ ����
//

#include "stdafx.h"
#include "Memo.h"

#include "MemoDoc.h"
#include "MemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMemoView

IMPLEMENT_DYNCREATE(CMemoView, CView)

BEGIN_MESSAGE_MAP(CMemoView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMemoView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_UNDO, &CMemoView::OnEditUndo)
	ON_COMMAND(ID_EDIT_CUT, &CMemoView::OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, &CMemoView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CMemoView::OnEditPaste)
END_MESSAGE_MAP()

// CMemoView ����/�Ҹ�

CMemoView::CMemoView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMemoView::~CMemoView()
{
}

BOOL CMemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMemoView �׸���

void CMemoView::OnDraw(CDC* /*pDC*/)
{
	CMemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMemoView �μ�


void CMemoView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CMemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMemoView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMemoView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CMemoView ����

#ifdef _DEBUG
void CMemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMemoDoc* CMemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMemoDoc)));
	return (CMemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMemoView �޽��� ó����

void CMemoView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CMemoDoc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(rect);
	pDoc->m_Edit.SetWindowPos(&wndTop,0,0,rect.right-rect.left,
				rect.bottom-rect.top,SWP_SHOWWINDOW);
}

int CMemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
    CMemoDoc* pDoc = GetDocument();
	
	CRect rect(0,0,0,0);
	pDoc->m_Edit.Create(ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN | WS_VISIBLE
						|WS_CHILD|WS_VSCROLL,rect,this,1);
	return 0;
}

BOOL CMemoView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
  CMemoDoc* pDoc = GetDocument();
	switch(LOWORD(wParam))
	{
	case 1:
			switch(HIWORD(wParam))
			{
			case EN_CHANGE:
						pDoc->SetModifiedFlag(TRUE);
			}
			break;
	}
	return CView::OnCommand(wParam, lParam);
}

void CMemoView::OnEditCopy()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMemoDoc* pDoc = GetDocument();
	pDoc->m_Edit.Copy();
}

void CMemoView::OnEditPaste()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMemoDoc* pDoc = GetDocument();
	pDoc->m_Edit.Paste();
}


void CMemoView::OnEditCut()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMemoDoc* pDoc = GetDocument();
	pDoc->m_Edit.Cut();
}

void CMemoView::OnEditUndo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMemoDoc* pDoc = GetDocument();
	pDoc->m_Edit.Undo();
}
