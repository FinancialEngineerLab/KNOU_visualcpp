
// ShoppingDoc.cpp : CShoppingDoc Ŭ������ ����
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


// CShoppingDoc ����/�Ҹ�

CShoppingDoc::CShoppingDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CShoppingDoc::~CShoppingDoc()
{
}

BOOL CShoppingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CShoppingDoc serialization

void CShoppingDoc::Serialize(CArchive& ar)
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


// CShoppingDoc ����

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


// CShoppingDoc ���
