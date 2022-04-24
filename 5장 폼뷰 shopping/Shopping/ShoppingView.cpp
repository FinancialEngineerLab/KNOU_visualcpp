
// ShoppingView.cpp : CShoppingView 클래스의 구현
//

#include "stdafx.h"
#include "Shopping.h"

#include "ShoppingDoc.h"
#include "ShoppingView.h"
//setlocale함수를 쓰고자 아래 헤더 파일사용
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

// CShoppingView 생성/소멸

CShoppingView::CShoppingView()
	: CFormView(CShoppingView::IDD)
	, m_Product(_T(""))
	, m_ProductCD(_T(""))
	, m_Price(0)
	, m_Cnt(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CShoppingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Result.SetWindowText(L"데이타 없음");
	m_Spin1.SetRange(1, 100);

}


// CShoppingView 진단

#ifdef _DEBUG
void CShoppingView::AssertValid() const
{
	CFormView::AssertValid();
}

void CShoppingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CShoppingDoc* CShoppingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShoppingDoc)));
	return (CShoppingDoc*)m_pDocument;
}
#endif //_DEBUG


// CShoppingView 메시지 처리기

void CShoppingView::OnBnClickedButtonDone()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	
	if (m_Product =="") 
	{
		MessageBox(_T("상품명을 입력하세요"), _T("상품명 에러"),  MB_ICONERROR | MB_OK);		
		return;
	}else{
	str += L" 상품명 : ";
	str += m_Product;
	}

	str += L" 상품코드 : ";
	str += m_ProductCD;


	CString temp = _T("");
	temp.Format(_T(" 단가 %d "), m_Price);
	str += temp;

	temp.Format(_T("개수 %d 합계 %d \r\n"), m_Cnt, m_Price * m_Cnt);
	str += temp;	



    m_Result.SetWindowText(str);
	
	UpdateData(FALSE);
}
/*******************************************************************************
Locale 이란?
사용자의 언어, 지역, 특별한 특징(사용자들의 UI에서 선호하고 싶은 사항)을 정의해주는 매개변수의 집합이다. 
주로 Locale은 적어도 하나의 언어 식별자와 국가 식별자로 구성되어있다.
이를 잘 지정해 주지 못하면 글자가 깨지거나 출력되지 않는 경우가 발생한다.
이런 경우에는 다음과 같은 코드를 넣어줍니다.
setlocale(LC_ALL, "");

첫번째 인자 : 표시형식의 설정입니다. 인자로 주어진 부분에 영향을 미친다.
LC_ALL  //모든 Locale
LC_COLLATE // 유니코드 문자열을 비교, 변형하는 함수
LC_CTYPE // 문자를 처리하는 함수, 멀티바이트/유니코드 함수
LC_MONETARY // 통화
LC_NUMERIC // 숫자 형식
LC_TIME // 시간형식

두번째 인자 : Locale 지정자입니다. 어떤 국가의 규칙을 따를지 지정한다.
Ex) "Korean", null
null값을 지정해 주면 현재 시스템의 기본값을 따라간다.
setlocale 함수를 쓰고자 #include <locale.h> 한다

CFileDialog::GetPathName
대화 상자에 입력 한 파일의 전체 경로 검색 하려면 이 함수를 호출 한다.
파일 경로가 제목 파일의 전체 디렉터리 경로 포함 된다. 
예를 들어, "C:\FILES\TEXT.DAT"이면 파일은 C:\FILES\TEXT.DAT 이다.
GetPathName 를 반환 한다

****************************************************************************/
void CShoppingView::OnFileSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
    CStdioFile file; 
    CString lineStr;
	//유니코드해결에 필요한 코딩
	char* pLocale = setlocale(LC_ALL, "Korean");

    lineStr = str;
    CFileDialog fDlg(FALSE, _T("txt"),0, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
				     _T("텍스트 화일(*.txt)|*.txt"));
 
   if (fDlg.DoModal() ==IDOK)
   {
	 //CString nfilename =fDlg.GetFileName();
	 CString nfilename = fDlg.GetPathName(); //파일경로    
	 file.Open(nfilename , CFile::modeCreate|CFile::modeWrite|CFile::typeText);

	 file.WriteString(lineStr);
	 file.Close();
   }
    
}

void CShoppingView::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CShoppingDoc* pDoc= GetDocument();
	CStdioFile file; 
    CFileDialog fDlg(TRUE, _T("txt"),0, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
					 _T("텍스트 화일(*.txt)|*.txt|모든 화일(*.*)|*.*||"));
	
	//유니코드해결에 필요한 코딩
	char* pLocale = setlocale(LC_ALL, "Korean");

    if (fDlg.DoModal() ==IDOK)
   {
	 str = _T("");
	 CString strFileData;

	 //file.Open(fDlg.GetFileName(), CFile::modeCreate|CFile::modeNoTruncate|
	//								CFile::modeRead|CFile::typeText);
	
	 file.Open(fDlg.GetPathName(), CFile::modeCreate|CFile::modeNoTruncate|
 								CFile::modeRead|CFile::typeText);
	 //불러온 화일명을 윈도우 타이틀로 보여줌
     pDoc->SetTitle(fDlg.GetFileTitle());

	 while(file.ReadString(strFileData))
	 {
		str = str +strFileData + _T("\n");
		m_Result.SetWindowText(str);

	

	 }
     file.Close();
   }

 
}
