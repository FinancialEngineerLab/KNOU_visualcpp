
// HakSaDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "HakSa.h"
#include "HakSaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CHakSaDlg ��ȭ ����




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

	DDX_Text(pDX, IDC_HAKBUN, m_HakBun); // �й�(Edit Box)
	DDX_Text(pDX, IDC_NAME, m_Name);   // �̸�(Edit Box)
	DDX_Text(pDX, IDC_COLLEGE, m_ListData); // ���������̸�(Edit Box)
	DDX_Check(pDX, IDC_CHKBOX1, m_ChkBox1); // ������ ���⿩�� (üũ�ڽ�)
	DDX_Control(pDX, IDC_LIST, m_List);   // ���������߰� ����ũ �ڽ�
	DDX_Control(pDX, IDC_COMBO, m_Combo); // �������� �߰� �޺� �ڽ�
	DDX_Control(pDX, IDC_CHKBOX2, m_ChkBox2); // ������û���� (üũ�ڽ�)
	DDX_Radio(pDX, IDC_RADIO1, m_Radio1); // �⼮����(���� ��ư)
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


// CHakSaDlg �޽��� ó����

BOOL CHakSaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// �ʱ� ���� ��ư ������ �⼮�����̴�. 
	SetDlgItemText(IDC_RADIO_STAT, L"�⼮���� ����");
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CHakSaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CHakSaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHakSaDlg::OnBnClickedBtnHakbun()
{
	// �й� ��ư�� Ŭ������ ��� �޽��� �ڽ��� �Էµ� �й��� �����ش�. 
	UpdateData(TRUE);
	AfxMessageBox(m_HakBun);
}

void CHakSaDlg::OnBnClickedBtnHakbunChk()
{
	// �й� üũ�� Ŭ������ ��� ������ �ڽ��� "�й��Է¿Ϸ�~!!!" �� �����ش�. 
	UpdateData(TRUE);
	if (m_HakBun != "") 
		SetDlgItemText(IDC_HAKBUN,  L"�й��Է¿Ϸ�~!!!");
	else AfxMessageBox(L"�й��Է��ϼ���");
	
}

void CHakSaDlg::OnBnClickedBtnName()
{
	// �̸� ��ư�� Ŭ������ ��� �޽��� �ڽ��� �Էµ� �̸��� �����ش�. 
	CString msg;

	GetDlgItemText(IDC_NAME, msg);
	AfxMessageBox(msg);
}

void CHakSaDlg::OnBnClickedBtnNameChk()
{
	// �̸� üũ�� Ŭ������ ��� ������ �ڽ��� "�����Է¿Ϸ�~!!!" �� �����ش�. 
	UpdateData(TRUE);
	if (m_Name != "")
		SetDlgItemText(IDC_NAME,  L"�����Է¿Ϸ�~!!!");
	else
		AfxMessageBox(L"�����Է��ϼ���");
}

void CHakSaDlg::OnBnClickedBtnList()
{
	// [�������и���Ʈ �߰�] ��ư�� Ŭ������ ���  
	UpdateData(TRUE);

	if(!m_ListData.IsEmpty())
	{
		m_List.AddString(m_ListData); // ����Ʈ �ڽ��� �̸��� �߰��Ѵ�.

		// [List�Ǽ�] �����͹ڽ��� ������ ���ڸ� �����ش�. 
		SetDlgItemInt(IDC_LIST_COUNT, m_List.GetCount()); 
	}

}

void CHakSaDlg::OnBnClickedBtnCombo()
{
// [�������� �޺� �߰�] ��ư�� Ŭ������ ���  
	UpdateData(TRUE);

	if(!m_ListData.IsEmpty())
	{
		m_Combo.AddString(m_ListData);// �޺� �ڽ��� �̸��� �߰��Ѵ�.
 // �޺��ڽ����� �߰��� �̸��� �����Ѵ�. 
 //  �ε����� 0���� �����ϹǷ� ��ü ���ڿ� ��������  -1�� ���־�� �Ѵ�.    
		m_Combo.SetCurSel(m_Combo.GetCount()-1);

		// [ComBo�Ǽ�] �����͹ڽ��� ������ ���ڸ� �����ش�. 
		SetDlgItemInt(IDC_COMBO_COUNT, m_Combo.GetCount());
	}
}

void CHakSaDlg::OnBnClickedBtnDelList()
{
	// [�������и���Ʈ ����] ��ư�� Ŭ������ ��� 
	int loc;

	loc = m_List.GetCurSel(); // ���� ���õ� ���ڿ��� �ε���(0���� �����ϴ�)�� ���ؿ´�. 

	/* if (loc= CB_ERR)
     AfxMessageBox("��� ����");  */

	m_List.DeleteString(loc);// ����Ʈ �ڽ����� ���õ� �̸��� �����Ѵ�.
    // ���ڿ��� �ϳ� �پ����Ƿ� m_List.GetCount() ���� 1 �����ߴ�. 
	
	if(loc == m_List.GetCount()) // ������ ���ڿ��� �������� ����̴�. 
		loc = loc - 1;

	m_List.SetCurSel(loc); // ����Ʈ �ڽ����� ���� ������ ���ڿ��� �����Ѵ�. 

	// [List�Ǽ�] �����͹ڽ��� ���ҵ� ���ڸ� �����ش�. 
	SetDlgItemInt(IDC_LIST_COUNT, m_List.GetCount());
}

void CHakSaDlg::OnBnClickedBtnDelCombo()
{
	// [�������� �޺� ����] ��ư�� Ŭ������ ��� 
	int loc;
    // ���� ���õ� ���ڿ��� �ε���(0���� �����ϴ�)�� ���ؿ´�.
	loc = m_Combo.GetCurSel();
	// �޺� �ڽ� ����Ʈ���� ���õ� �̸��� �����Ѵ�.
	m_Combo.DeleteString(loc);

	if(loc == m_Combo.GetCount())
		loc = loc - 1;

	m_Combo.SetCurSel(loc);
	// [�޺� �Ǽ�] �����͹ڽ��� ���ҵ� ���ڸ� �����ش�. 
	SetDlgItemInt(IDC_COMBO_COUNT, m_Combo.GetCount());

}

void CHakSaDlg::OnLbnDblclkList()
{
	// �������� ����Ʈ �ڽ����� ���ڿ��� ����Ŭ���� ���
	// ���� ����Ŭ���� ���ڿ��� �ε����� ���ؿ´�. 
	int curSel = m_List.GetCurSel();
	CString msg;
    // ������ ���ڿ��� msg �� �ִ´�.  
	m_List.GetText(curSel, msg);
	AfxMessageBox(msg);
}

void CHakSaDlg::OnCbnSelchangeCombo()
{
	// �޺��ڽ� ����Ʈ���� ���ڿ� ������ �����Ͽ��� ���
// ���� ���õ� ���ڿ��� �ε����� ���ؿ´�. 
	int curSel = m_Combo.GetCurSel(); 
	CString msg;
// ������ ���ڿ��� msg �� �ִ´�.  
	m_Combo.GetLBText(curSel, msg);
	AfxMessageBox(msg);
}

void CHakSaDlg::OnBnClickedChkbox1()
{
	// ���������⿩�� üũ�ڽ��� Ŭ���� ���
	UpdateData(TRUE);

	if(m_ChkBox1)
	{
		SetDlgItemText(IDC_CHKSTAT1, L"üũ");
	}
	else
	{
		SetDlgItemText(IDC_CHKSTAT1, L"����");
	}
}

void CHakSaDlg::OnBnClickedChkbox2()
{
	// ������û���� üũ�ڽ��� Ŭ���� ���
	UpdateData(TRUE);

	int stat;
// ���� ��ư�� ������ ���¸� ���´�. 
	stat = m_ChkBox2.GetCheck();

	switch (stat)
	{
	case BST_UNCHECKED:
		SetDlgItemText(IDC_CHKSTAT2, L"����");
		break;
	case BST_CHECKED:
		SetDlgItemText(IDC_CHKSTAT2, L"üũ");
		break;
	case BST_INDETERMINATE:
		SetDlgItemText(IDC_CHKSTAT2, L"����");
		break;
	}	
}

void CHakSaDlg::OnBnClickedRadio1()
{
	// ���� ��ư1: �⼮���� Ŭ��
	UpdateData(TRUE);

	SetRadioStatus();
}

void CHakSaDlg::OnBnClickedRadio2()
{
	// ���� ��ư2: ��ü���� Ŭ��
	UpdateData(TRUE);

	SetRadioStatus();
}

void CHakSaDlg::OnBnClickedRadio3()
{
	// ���� ��ư3: ������ Ŭ��
	UpdateData(TRUE);

	SetRadioStatus();
}

// ���� ��ư�� ���� ����
void CHakSaDlg::SetRadioStatus(void)
{
//  m_Radio1 �� ���� ��ư�� ���°��� ���� �ִ� value �� ��Ʈ�� ����
// Group �Ӽ��� ���� �����Ƿ� ��� ���� ��ư1,2,3 ���� ���� ǥ���Ѵ�. 
	switch (m_Radio1)
	{
	case 0:
		SetDlgItemText(IDC_RADIO_STAT, L"�⼮���� ����");
		break;
	case 1:
		SetDlgItemText(IDC_RADIO_STAT, L"��ü���� ����");
		break;
	case 2:
		SetDlgItemText(IDC_RADIO_STAT, L"������ ����");
		break;
	
	}
}
