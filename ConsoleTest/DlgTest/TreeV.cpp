// TreeV.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "TreeV.h"
#include "afxdialogex.h"


// CTreeV �Ի���

IMPLEMENT_DYNAMIC(CTreeV, CDialog)

CTreeV::CTreeV(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeV::IDD, pParent)
{

}

CTreeV::~CTreeV()
{
}

void CTreeV::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, tree);
}


BEGIN_MESSAGE_MAP(CTreeV, CDialog)
END_MESSAGE_MAP()


// CTreeV ��Ϣ�������


BOOL CTreeV::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_imageList.Create(32, 32, ILC_COLOR32, 2,2);
	m_imageList.Add(theApp.LoadIcon(IDI_ICON1));
	m_imageList.Add(theApp.LoadIcon(IDI_ICON2));
	tree.SetImageList(&m_imageList, TVSIL_NORMAL);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HTREEITEM hRoot =tree.InsertItem(_T("a"),0,1);
	//HTREEITEM hFirst = tree.InsertItem(_T("b"), 1, 0, hRoot);
	//HTREEITEM hSec = tree.InsertItem(_T("c"), 1, 0, hRoot, hFirst);
	//tree.InsertItem(_T("d"), 1, 0, hRoot, hFirst);
	tree.InsertItem(_T("e"), 0, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
