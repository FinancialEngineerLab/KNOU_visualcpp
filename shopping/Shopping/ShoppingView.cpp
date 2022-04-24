
// ShoppingView.cpp : CShoppingView Ŭ������ ����
//

#include "stdafx.h"
#include "Shopping.h"

#include "ShoppingDoc.h"
#include "ShoppingView.h"
//setlocale�Լ��� ������ �Ʒ� ��� ���ϻ��
#include <locale.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CShoppingView

IMPLEMENT_DYNCREATE(CShoppingView, CFormView)

BEGIN_MESSAGE_MAP(CShoppingView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_DONE, &CShoppingView::OnBnClickedButtonDone)
	ON_COMMAND(ID_FILE_SAVE, &CShoppingView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CShoppingView::OnFileOpen)
END_MESSAGE_MAP()

// CShoppingView ����/�Ҹ�

CShoppingView::CShoppingView()
	: CFormView(CShoppingView::IDD)
	, m_Product(_T(""))
	, m_ProductCD(_T(""))
	, m_Price(0)
	, m_Cnt(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CShoppingView::~CShoppingView()
{
}

void CShoppingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESULT, m_Result);
	DDX_Text(pDX, IDC_PRODUCT, m_Product);
	DDX_Text(pDX, IDC_PRODUCT_CD, m_ProductCD);
	DDX_Text(pDX, IDC_PRICE, m_Price);
	DDX_Text(pDX, IDC_CNT, m_Cnt);
	DDX_Control(pDX, IDC_SPIN1, m_Spin1);
}

BOOL CShoppingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CShoppingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Result.SetWindowText(L"����Ÿ ����");
	m_Spin1.SetRange(1, 100);

}


// CShoppingView ����

#ifdef _DEBUG
void CShoppingView::AssertValid() const
{
	CFormView::AssertValid();
}

void CShoppingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CShoppingDoc* CShoppingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShoppingDoc)));
	return (CShoppingDoc*)m_pDocument;
}
#endif //_DEBUG


// CShoppingView �޽��� ó����

void CShoppingView::OnBnClickedButtonDone()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	
	if (m_Product =="") 
	{
		MessageBox(_T("��ǰ���� �Է��ϼ���"), _T("��ǰ�� ����"),  MB_ICONERROR | MB_OK);		
		return;
	}else{
	str += L" ��ǰ�� : ";
	str += m_Product;
	}

	str += L" ��ǰ�ڵ� : ";
	str += m_ProductCD;


	CString temp = _T("");
	temp.Format(_T(" �ܰ� %d "), m_Price);
	str += temp;

	temp.Format(_T("���� %d �հ� %d \r\n"), m_Cnt, m_Price * m_Cnt);
	str += temp;	



    m_Result.SetWindowText(str);
	
	UpdateData(FALSE);
}
/*******************************************************************************
Locale �̶�?
������� ���, ����, Ư���� Ư¡(����ڵ��� UI���� ��ȣ�ϰ� ���� ����)�� �������ִ� �Ű������� �����̴�. 
�ַ� Locale�� ��� �ϳ��� ��� �ĺ��ڿ� ���� �ĺ��ڷ� �����Ǿ��ִ�.
�̸� �� ������ ���� ���ϸ� ���ڰ� �����ų� ��µ��� �ʴ� ��찡 �߻��Ѵ�.
�̷� ��쿡�� ������ ���� �ڵ带 �־��ݴϴ�.
setlocale(LC_ALL, "");

ù��° ���� : ǥ�������� �����Դϴ�. ���ڷ� �־��� �κп� ������ ��ģ��.
LC_ALL  //��� Locale
LC_COLLATE // �����ڵ� ���ڿ��� ��, �����ϴ� �Լ�
LC_CTYPE // ���ڸ� ó���ϴ� �Լ�, ��Ƽ����Ʈ/�����ڵ� �Լ�
LC_MONETARY // ��ȭ
LC_NUMERIC // ���� ����
LC_TIME // �ð�����

�ι�° ���� : Locale �������Դϴ�. � ������ ��Ģ�� ������ �����Ѵ�.
Ex) "Korean", null
null���� ������ �ָ� ���� �ý����� �⺻���� ���󰣴�.
setlocale �Լ��� ������ #include <locale.h> �Ѵ�

CFileDialog::GetPathName
��ȭ ���ڿ� �Է� �� ������ ��ü ��� �˻� �Ϸ��� �� �Լ��� ȣ�� �Ѵ�.
���� ��ΰ� ���� ������ ��ü ���͸� ��� ���� �ȴ�. 
���� ���, "C:\FILES\TEXT.DAT"�̸� ������ C:\FILES\TEXT.DAT �̴�.
GetPathName �� ��ȯ �Ѵ�

****************************************************************************/
void CShoppingView::OnFileSave()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
    CStdioFile file; 
    CString lineStr;
	//�����ڵ��ذῡ �ʿ��� �ڵ�
	char* pLocale = setlocale(LC_ALL, "Korean");

    lineStr = str;
    CFileDialog fDlg(FALSE, _T("txt"),0, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
				     _T("�ؽ�Ʈ ȭ��(*.txt)|*.txt"));
 
   if (fDlg.DoModal() ==IDOK)
   {
	 //CString nfilename =fDlg.GetFileName();
	 CString nfilename = fDlg.GetPathName(); //���ϰ��    
	 file.Open(nfilename , CFile::modeCreate|CFile::modeWrite|CFile::typeText);

	 file.WriteString(lineStr);
	 file.Close();
   }
    
}

void CShoppingView::OnFileOpen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CShoppingDoc* pDoc= GetDocument();
	CStdioFile file; 
    CFileDialog fDlg(TRUE, _T("txt"),0, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
					 _T("�ؽ�Ʈ ȭ��(*.txt)|*.txt|��� ȭ��(*.*)|*.*||"));
	
	//�����ڵ��ذῡ �ʿ��� �ڵ�
	char* pLocale = setlocale(LC_ALL, "Korean");

    if (fDlg.DoModal() ==IDOK)
   {
	 str = _T("");
	 CString strFileData;

	 //file.Open(fDlg.GetFileName(), CFile::modeCreate|CFile::modeNoTruncate|
	//								CFile::modeRead|CFile::typeText);
	
	 file.Open(fDlg.GetPathName(), CFile::modeCreate|CFile::modeNoTruncate|
 								CFile::modeRead|CFile::typeText);
	 //�ҷ��� ȭ�ϸ��� ������ Ÿ��Ʋ�� ������
     pDoc->SetTitle(fDlg.GetFileTitle());

	 while(file.ReadString(strFileData))
	 {
		str = str +strFileData + _T("\n");
		m_Result.SetWindowText(str);

	

	 }
     file.Close();
   }

 
}
