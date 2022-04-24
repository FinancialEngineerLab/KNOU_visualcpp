
// MemoDoc.cpp : CMemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "Memo.h"

#include "MemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMemoDoc

IMPLEMENT_DYNCREATE(CMemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMemoDoc, CDocument)
END_MESSAGE_MAP()


// CMemoDoc 생성/소멸

CMemoDoc::CMemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMemoDoc::~CMemoDoc()
{
}

BOOL CMemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMemoDoc serialization

void CMemoDoc::Serialize(CArchive& ar)
{
	CString data;
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		m_Edit.GetWindowText(data);
		ar << data;
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		ar >> data;
		m_Edit.SetWindowText(data);
	}
}


// CMemoDoc 진단

#ifdef _DEBUG
void CMemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMemoDoc 명령
