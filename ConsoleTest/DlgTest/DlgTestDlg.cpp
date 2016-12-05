
// DlgTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "DlgTestDlg.h"
#include "afxdialogex.h"
//#include "ConfirmDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CDlgTestDlg 对话框



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


// CDlgTestDlg 消息处理程序
CEdit *pEdit;
BOOL CDlgTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	pEdit = (CEdit *)GetDlgItem(IDC_EDIT_MULTI);
	//pEdit->ModifyStyleEx(0, ES_NOHIDESEL); //无效 必须要在Create的时候设置风格
	pEdit->SetWindowTextW(_T("你妹！"));

	pEdit->UpdateWindow();


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDlgTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDlgTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDlgTestDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDlgTestDlg::OnClickedBtnCal()
{
	// TODO:  在此添加控件通知处理程序代码
	//CConfirmDlg dlg;
	//if (dlg.DoModal()==IDCANCEL)
	//{
	//	return;
	//}

	// 如果指针变量m_pTipDlg的值为NULL，则对话框还未创建，需要动态创建   
	if (!m_pDlg)
	{
		 //创建非模态对话框实例   
		m_pDlg = new CConfirmDlg();
		m_pDlg->Create(IDD_CONFIRMDLG, this);
	}
	// 显示非模态对话框   
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
	// TODO:  在此添加控件通知处理程序代码
	CPageSheet pSheet(_T("帮助"));
	////pSheet.SetWizardMode(); //向导模式才调用  OnSetActive() finish 等函数 也是
	pSheet.DoModal();
}


void CDlgTestDlg::OnBnClickedBtnOpen()
{
	// TODO:  在此添加控件通知处理程序代码

	CFileDialog fileDlg(true, _T(".txt"), NULL, 0, _T("文本文件|*.txt|所有文件|*.*"), this);
	if (IDOK == fileDlg.DoModal())
	{
		SetDlgItemText(IDC_RESULT, fileDlg.GetFolderPath() + fileDlg.GetFileTitle());// 
	}
}

  

CImage img;

CStatic cs;
void CDlgTestDlg::OnBnClickedBtnSave()
{
	//CFileDialog fileDlg(false, _T(".txt"), _T("ReadMe"), 0, _T("文本文件|*.txt|所有文件|*.*"), this);

	//if (IDOK == fileDlg.DoModal())
	//{
	//	SetDlgItemText(IDC_RESULT, fileDlg.GetPathName() );// 
	//}

	//cs = new CStatic();
	//cs->Create(_T("111"), WS_CHILD | WS_VISIBLE , CRect(20, 20, 50, 50), this);
	//cs.Create(_T("图片"), WS_CHILD | WS_VISIBLE | SS_BITMAP, CRect(90, 90, 50, 50), this);
	//HRESULT ret = img.Load(_T("D:/111.png"));
	//HBITMAP bitmap = img.Detach();
	//cs.SetBitmap(bitmap);
	//cs.ShowWindow(SW_SHOW);
	pEdit->SetSel(1, -1);
	pEdit->ReplaceSel(_T("是一个小花猫！"));
	pEdit->GetFocus();
}
