// TestTree.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "TestTree.h"
#include "afxdialogex.h"


// CTestTree 对话框

IMPLEMENT_DYNAMIC(CTestTree, CDialogEx)

CTestTree::CTestTree(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestTree::IDD, pParent)
{

}

CTestTree::~CTestTree()
{
}

void CTestTree::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}


BEGIN_MESSAGE_MAP(CTestTree, CDialogEx)
END_MESSAGE_MAP()


// CTestTree 消息处理程序


BOOL CTestTree::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HICON hicon[2];
	hicon[0] = theApp.LoadIcon(IDI_ICON1);
	hicon[1] = theApp.LoadIcon(IDI_ICON2);

	HTREEITEM fitem;
	HTREEITEM sItem;
	m_imageList.Create(32, 32, ILC_COLOR32, 2, 1);
	m_imageList.Add(hicon[0]);
	m_imageList.Add(hicon[1]);

	m_tree.SetImageList(&m_imageList, TVSIL_NORMAL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
