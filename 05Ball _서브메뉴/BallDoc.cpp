
// BallDoc.cpp : CBallDoc 클래스의 구현
//

#include "stdafx.h"
#include "Ball.h"

#include "BallDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBallDoc

IMPLEMENT_DYNCREATE(CBallDoc, CDocument)

BEGIN_MESSAGE_MAP(CBallDoc, CDocument)
END_MESSAGE_MAP()


// CBallDoc 생성/소멸

CBallDoc::CBallDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CBallDoc::~CBallDoc()
{
}

BOOL CBallDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CBallDoc serialization

void CBallDoc::Serialize(CArchive& ar)
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


// CBallDoc 진단

#ifdef _DEBUG
void CBallDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBallDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CBallDoc 명령
