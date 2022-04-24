
// ShoppingDoc.cpp : CShoppingDoc 클래스의 구현
//

#include "stdafx.h"
#include "Shopping.h"

#include "ShoppingDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CShoppingDoc

IMPLEMENT_DYNCREATE(CShoppingDoc, CDocument)

BEGIN_MESSAGE_MAP(CShoppingDoc, CDocument)
END_MESSAGE_MAP()


// CShoppingDoc 생성/소멸

CShoppingDoc::CShoppingDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CShoppingDoc::~CShoppingDoc()
{
}

BOOL CShoppingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CShoppingDoc serialization

void CShoppingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CShoppingDoc 진단

#ifdef _DEBUG
void CShoppingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShoppingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CShoppingDoc 명령
