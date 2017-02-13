// TestTree.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "TestTree.h"
#include "afxdialogex.h"


// CTestTree �Ի���

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


// CTestTree ��Ϣ�������


BOOL CTestTree::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣:  OCX ����ҳӦ���� FALSE
}
