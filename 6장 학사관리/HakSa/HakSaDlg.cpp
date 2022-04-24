
// HakSaDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "HakSa.h"
#include "HakSaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CHakSaDlg 대화 상자




CHakSaDlg::CHakSaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHakSaDlg::IDD, pParent)
	, m_HakBun(_T(""))
	, m_Name(_T(""))
	, m_ListData(_T(""))
	, m_ChkBox1(FALSE)
	, m_Radio1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CHakSaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_HAKBUN, m_HakBun); // 학번(Edit Box)
	DDX_Text(pDX, IDC_NAME, m_Name);   // 이름(Edit Box)
	DDX_Text(pDX, IDC_COLLEGE, m_ListData); // 지역대학이름(Edit Box)
	DDX_Check(pDX, IDC_CHKBOX1, m_ChkBox1); // 졸업논문 제출여부 (체크박스)
	DDX_Control(pDX, IDC_LIST, m_List);   // 지역대학추가 리스크 박스
	DDX_Control(pDX, IDC_COMBO, m_Combo); // 지역대학 추가 콤보 박스
	DDX_Control(pDX, IDC_CHKBOX2, m_ChkBox2); // 수강신청여부 (체크박스)
	DDX_Radio(pDX, IDC_RADIO1, m_Radio1); // 출석수업(라디오 버튼)
}

BEGIN_MESSAGE_MAP(CHakSaDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_HAKBUN, &CHakSaDlg::OnBnClickedBtnHakbun)
	ON_BN_CLICKED(IDC_BTN_HAKBUN_CHK, &CHakSaDlg::OnBnClickedBtnHakbunChk)
	ON_BN_CLICKED(IDC_BTN_NAME, &CHakSaDlg::OnBnClickedBtnName)
	ON_BN_CLICKED(IDC_BTN_NAME_CHK, &CHakSaDlg::OnBnClickedBtnNameChk)
	ON_BN_CLICKED(IDC_BTN_LIST, &CHakSaDlg::OnBnClickedBtnList)
	ON_BN_CLICKED(IDC_BTN_COMBO, &CHakSaDlg::OnBnClickedBtnCombo)
	ON_BN_CLICKED(IDC_BTN_DEL_LIST, &CHakSaDlg::OnBnClickedBtnDelList)
	ON_BN_CLICKED(IDC_BTN_DEL_COMBO, &CHakSaDlg::OnBnClickedBtnDelCombo)
	ON_LBN_DBLCLK(IDC_LIST, &CHakSaDlg::OnLbnDblclkList)
	ON_CBN_SELCHANGE(IDC_COMBO, &CHakSaDlg::OnCbnSelchangeCombo)
	ON_BN_CLICKED(IDC_CHKBOX1, &CHakSaDlg::OnBnClickedChkbox1)
	ON_BN_CLICKED(IDC_CHKBOX2, &CHakSaDlg::OnBnClickedChkbox2)
	ON_BN_CLICKED(IDC_RADIO1, &CHakSaDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CHakSaDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CHakSaDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CHakSaDlg 메시지 처리기

BOOL CHakSaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// 초기 라디오 버튼 선택은 출석수업이다. 
	SetDlgItemText(IDC_RADIO_STAT, L"출석수업 선택");
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CHakSaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CHakSaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHakSaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHakSaDlg::OnBnClickedBtnHakbun()
{
	// 학번 버튼을 클릭했을 경우 메시지 박스에 입력된 학번을 보여준다. 
	UpdateData(TRUE);
	AfxMessageBox(m_HakBun);
}

void CHakSaDlg::OnBnClickedBtnHakbunChk()
{
	// 학번 체크을 클릭했을 경우 에디터 박스에 "학번입력완료~!!!" 을 보여준다. 
	UpdateData(TRUE);
	if (m_HakBun != "") 
		SetDlgItemText(IDC_HAKBUN,  L"학번입력완료~!!!");
	else AfxMessageBox(L"학번입력하세요");
	
}

void CHakSaDlg::OnBnClickedBtnName()
{
	// 이름 버튼을 클릭했을 경우 메시지 박스에 입력된 이름을 보여준다. 
	CString msg;

	GetDlgItemText(IDC_NAME, msg);
	AfxMessageBox(msg);
}

void CHakSaDlg::OnBnClickedBtnNameChk()
{
	// 이름 체크을 클릭했을 경우 에디터 박스에 "성명입력완료~!!!" 을 보여준다. 
	UpdateData(TRUE);
	if (m_Name != "")
		SetDlgItemText(IDC_NAME,  L"성명입력완료~!!!");
	else
		AfxMessageBox(L"성명입력하세요");
}

void CHakSaDlg::OnBnClickedBtnList()
{
	// [지역대학리스트 추가] 버튼을 클릭했을 경우  
	UpdateData(TRUE);

	if(!m_ListData.IsEmpty())
	{
		m_List.AddString(m_ListData); // 리스트 박스에 이름을 추가한다.

		// [List건수] 에디터박스에 증가된 숫자를 보여준다. 
		SetDlgItemInt(IDC_LIST_COUNT, m_List.GetCount()); 
	}

}

void CHakSaDlg::OnBnClickedBtnCombo()
{
// [지역대학 콤보 추가] 버튼을 클릭했을 경우  
	UpdateData(TRUE);

	if(!m_ListData.IsEmpty())
	{
		m_Combo.AddString(m_ListData);// 콤보 박스에 이름을 추가한다.
 // 콤보박스에서 추가된 이름을 선택한다. 
 //  인덱스는 0부터 시작하므로 전체 문자열 개수에서  -1을 해주어야 한다.    
		m_Combo.SetCurSel(m_Combo.GetCount()-1);

		// [ComBo건수] 에디터박스에 증가된 숫자를 보여준다. 
		SetDlgItemInt(IDC_COMBO_COUNT, m_Combo.GetCount());
	}
}

void CHakSaDlg::OnBnClickedBtnDelList()
{
	// [지역대학리스트 삭제] 버튼을 클릭했을 경우 
	int loc;

	loc = m_List.GetCurSel(); // 현재 선택된 문자열의 인덱스(0부터 시작하는)를 구해온다. 

	/* if (loc= CB_ERR)
     AfxMessageBox("비어 있음");  */

	m_List.DeleteString(loc);// 리스트 박스에서 선택된 이름을 삭제한다.
    // 문자열이 하나 줄었으므로 m_List.GetCount() 수도 1 감소했다. 
	
	if(loc == m_List.GetCount()) // 마지막 문자열을 삭제했을 경우이다. 
		loc = loc - 1;

	m_List.SetCurSel(loc); // 리스트 박스에서 제일 마지막 문자열을 선택한다. 

	// [List건수] 에디터박스에 감소된 숫자를 보여준다. 
	SetDlgItemInt(IDC_LIST_COUNT, m_List.GetCount());
}

void CHakSaDlg::OnBnClickedBtnDelCombo()
{
	// [지역대학 콤보 삭제] 버튼을 클릭했을 경우 
	int loc;
    // 현재 선택된 문자열의 인덱스(0부터 시작하는)를 구해온다.
	loc = m_Combo.GetCurSel();
	// 콤보 박스 리스트에서 선택된 이름을 삭제한다.
	m_Combo.DeleteString(loc);

	if(loc == m_Combo.GetCount())
		loc = loc - 1;

	m_Combo.SetCurSel(loc);
	// [콤보 건수] 에디터박스에 감소된 숫자를 보여준다. 
	SetDlgItemInt(IDC_COMBO_COUNT, m_Combo.GetCount());

}

void CHakSaDlg::OnLbnDblclkList()
{
	// 지역대학 리스트 박스에서 문자열을 더블클릭한 경우
	// 현재 더블클릭한 문자열의 인덱스를 구해온다. 
	int curSel = m_List.GetCurSel();
	CString msg;
    // 선택한 문자열을 msg 에 넣는다.  
	m_List.GetText(curSel, msg);
	AfxMessageBox(msg);
}

void CHakSaDlg::OnCbnSelchangeCombo()
{
	// 콤보박스 리스트에서 문자열 선택을 변경하였을 경우
// 현재 선택된 문자열의 인덱스를 구해온다. 
	int curSel = m_Combo.GetCurSel(); 
	CString msg;
// 선택한 문자열을 msg 에 넣는다.  
	m_Combo.GetLBText(curSel, msg);
	AfxMessageBox(msg);
}

void CHakSaDlg::OnBnClickedChkbox1()
{
	// 졸업논문제출여부 체크박스를 클릭한 경우
	UpdateData(TRUE);

	if(m_ChkBox1)
	{
		SetDlgItemText(IDC_CHKSTAT1, L"체크");
	}
	else
	{
		SetDlgItemText(IDC_CHKSTAT1, L"해제");
	}
}

void CHakSaDlg::OnBnClickedChkbox2()
{
	// 수강신청여부 체크박스를 클릭한 경우
	UpdateData(TRUE);

	int stat;
// 라디오 버튼이 눌려진 상태를 얻어온다. 
	stat = m_ChkBox2.GetCheck();

	switch (stat)
	{
	case BST_UNCHECKED:
		SetDlgItemText(IDC_CHKSTAT2, L"해제");
		break;
	case BST_CHECKED:
		SetDlgItemText(IDC_CHKSTAT2, L"체크");
		break;
	case BST_INDETERMINATE:
		SetDlgItemText(IDC_CHKSTAT2, L"보류");
		break;
	}	
}

void CHakSaDlg::OnBnClickedRadio1()
{
	// 라디오 버튼1: 출석수업 클릭
	UpdateData(TRUE);

	SetRadioStatus();
}

void CHakSaDlg::OnBnClickedRadio2()
{
	// 라디오 버튼2: 대체시험 클릭
	UpdateData(TRUE);

	SetRadioStatus();
}

void CHakSaDlg::OnBnClickedRadio3()
{
	// 라디오 버튼3: 과제물 클릭
	UpdateData(TRUE);

	SetRadioStatus();
}

// 라디오 버튼의 상태 셋팅
void CHakSaDlg::SetRadioStatus(void)
{
//  m_Radio1 은 라디오 버튼의 상태값을 갖고 있는 value 형 컨트롤 변수
// Group 속성을 갖고 있으므로 모든 라디오 버튼1,2,3 들의 값을 표현한다. 
	switch (m_Radio1)
	{
	case 0:
		SetDlgItemText(IDC_RADIO_STAT, L"출석수업 선택");
		break;
	case 1:
		SetDlgItemText(IDC_RADIO_STAT, L"대체시험 선택");
		break;
	case 2:
		SetDlgItemText(IDC_RADIO_STAT, L"과제물 선택");
		break;
	
	}
}
