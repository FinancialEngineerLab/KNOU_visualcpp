
// BallDoc.cpp : CBallDoc Ŭ������ ����
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


// CBallDoc ����/�Ҹ�

CBallDoc::CBallDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CBallDoc::~CBallDoc()
{
}

BOOL CBallDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CBallDoc serialization

void CBallDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CBallDoc ����

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


// CBallDoc ���
