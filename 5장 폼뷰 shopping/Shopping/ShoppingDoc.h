
// ShoppingDoc.h : CShoppingDoc Ŭ������ �������̽�
//


#pragma once


class CShoppingDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CShoppingDoc();
	DECLARE_DYNCREATE(CShoppingDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CShoppingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


