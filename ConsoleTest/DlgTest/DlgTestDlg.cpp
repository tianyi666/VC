
// DlgTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "DlgTestDlg.h"
#include "afxdialogex.h"
//#include "ConfirmDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDlgTestDlg �Ի���



CDlgTestDlg::CDlgTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTestDlg::IDD, pParent)
	, m_edit1(0)
	, m_edit2(0)
	, m_result(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pDlg = NULL;
}

void CDlgTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_RESULT, m_result);
}

BEGIN_MESSAGE_MAP(CDlgTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CDlgTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTN_CAL, &CDlgTestDlg::OnClickedBtnCal)
	ON_BN_CLICKED(IDC_BTN_HELP, &CDlgTestDlg::OnBnClickedBtnHelp)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CDlgTestDlg::OnBnClickedBtnOpen)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CDlgTestDlg::OnBnClickedBtnSave)
END_MESSAGE_MAP()


// CDlgTestDlg ��Ϣ�������
CEdit *pEdit;
BOOL CDlgTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	pEdit = (CEdit *)GetDlgItem(IDC_EDIT_MULTI);
	//pEdit->ModifyStyleEx(0, ES_NOHIDESEL); //��Ч ����Ҫ��Create��ʱ�����÷��
	pEdit->SetWindowTextW(_T("���ã�"));

	pEdit->UpdateWindow();


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDlgTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDlgTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDlgTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDlgTestDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CDlgTestDlg::OnClickedBtnCal()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CConfirmDlg dlg;
	//if (dlg.DoModal()==IDCANCEL)
	//{
	//	return;
	//}

	// ���ָ�����m_pTipDlg��ֵΪNULL����Ի���δ��������Ҫ��̬����   
	if (!m_pDlg)
	{
		 //������ģ̬�Ի���ʵ��   
		m_pDlg = new CConfirmDlg();
		m_pDlg->Create(IDD_CONFIRMDLG, this);
	}
	// ��ʾ��ģ̬�Ի���   
	m_pDlg->ShowWindow(SW_SHOW);
	
	UpdateData();
	m_result = m_edit1 + m_edit2;
	UpdateData(false);
}

CDlgTestDlg::~CDlgTestDlg()
{
	if (m_pDlg != NULL)
	{
		delete m_pDlg;
		m_pDlg = NULL;
	}
}




void CDlgTestDlg::OnBnClickedBtnHelp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CPageSheet pSheet(_T("����"));
	////pSheet.SetWizardMode(); //��ģʽ�ŵ���  OnSetActive() finish �Ⱥ��� Ҳ��
	pSheet.DoModal();
}


void CDlgTestDlg::OnBnClickedBtnOpen()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CFileDialog fileDlg(true, _T(".txt"), NULL, 0, _T("�ı��ļ�|*.txt|�����ļ�|*.*"), this);
	if (IDOK == fileDlg.DoModal())
	{
		SetDlgItemText(IDC_RESULT, fileDlg.GetFolderPath() + fileDlg.GetFileTitle());// 
	}
}

  

CImage img;

CStatic cs;
void CDlgTestDlg::OnBnClickedBtnSave()
{
	//CFileDialog fileDlg(false, _T(".txt"), _T("ReadMe"), 0, _T("�ı��ļ�|*.txt|�����ļ�|*.*"), this);

	//if (IDOK == fileDlg.DoModal())
	//{
	//	SetDlgItemText(IDC_RESULT, fileDlg.GetPathName() );// 
	//}

	//cs = new CStatic();
	//cs->Create(_T("111"), WS_CHILD | WS_VISIBLE , CRect(20, 20, 50, 50), this);
	//cs.Create(_T("ͼƬ"), WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(90, 90, 50, 50), this);
	//HRESULT ret = img.Load(_T("D:/111.png"));
	//HBITMAP bitmap = img.Detach();
	//cs.SetBitmap(bitmap);
	//cs.ShowWindow(SW_SHOW);
	pEdit->SetSel(1, -1);
	pEdit->ReplaceSel(_T("��һ��С��è��"));
	pEdit->GetFocus();
}
