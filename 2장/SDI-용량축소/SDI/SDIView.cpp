﻿
// SDIView.cpp: CSDIView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SDI.h"
#endif

#include "SDIDoc.h"
#include "SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  ID_DECREASE_BUTTON	3000
#define  ID_INCREASE_BUTTON	3100
#define  ID_LISTBOX	            3200
#define    ID_PROGBAR           3300
// CSDIView

IMPLEMENT_DYNCREATE(CSDIView, CView)

BEGIN_MESSAGE_MAP(CSDIView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(ID_DECREASE_BUTTON, OnDecreaseButton)
	ON_COMMAND(ID_INCREASE_BUTTON, OnIncreaseButton)
END_MESSAGE_MAP()

// CSDIView 생성/소멸

CSDIView::CSDIView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSDIView::~CSDIView()
{
}

BOOL CSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSDIView 그리기

void CSDIView::OnDraw(CDC* /*pDC*/)
{
	CSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSDIView 인쇄

BOOL CSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSDIView 진단

#ifdef _DEBUG
void CSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIDoc* CSDIView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIDoc)));
	return (CSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIView 메시지 처리기


int CSDIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
    m_ProgressBar.Create(WS_DLGFRAME | WS_VISIBLE, CRect(50, 230, 300, 270), this, ID_PROGBAR);
	m_ProgressBar.SetRange(0, 9);
	m_ProgressBar.SetPos(1);

	m_Wnd01.Create(AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW),
		_T("첫번째 차일드윈도우"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CHILD,
		CRect(50,50,300,200),
		this,
		1010);
	ASSERT(m_Wnd01.m_hWnd != NULL);

	m_Wnd02.Create(AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW),
		_T("두번째 차일드윈도우"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CHILD,
		CRect(350, 50, 600, 250),
		this,
		1020);
	m_Increase_Btn.Create(_T("증가"), WS_VISIBLE, CRect(400, 300, 600, 330),
	                        this, ID_INCREASE_BUTTON);
 	m_Decrease_Btn.Create(_T("감소"), WS_VISIBLE, CRect(400, 350, 600, 380),
	                         this, ID_DECREASE_BUTTON);

	m_ListBox.Create(WS_DLGFRAME | WS_VISIBLE, CRect(50, 350, 300, 600),
							this, ID_LISTBOX);
	m_ListBox.AddString(_T("윈도우 프로그래밍!"));


	return 0;
}
void CSDIView::OnDecreaseButton()
{
	int count = m_ListBox.GetCount();
	if (count > 0)
	{
		m_ListBox.DeleteString(count - 1);
		m_ProgressBar.SetPos(count - 1);
	}
	else
	{
		AfxMessageBox(_T("지울 아이템이 없습니다"));
	}
}
void CSDIView::OnIncreaseButton()
{
	int count = m_ListBox.GetCount();
	if (count < 10)
	{
		m_ListBox.AddString(_T("윈도우 프로그래밍!"));
		m_ProgressBar.SetPos(count + 1);
	}
	else
	{
		AfxMessageBox(_T("더 이상 추가할 수 없습니다"));
	}
}
