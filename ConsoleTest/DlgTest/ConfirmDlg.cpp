// ConfirmDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "ConfirmDlg.h"
#include "afxdialogex.h"



// CConfirmDlg 对话框

IMPLEMENT_DYNAMIC(CConfirmDlg, CDialogEx)



CConfirmDlg::CConfirmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CConfirmDlg::IDD, pParent)
{
	
}

CConfirmDlg::~CConfirmDlg()
{
	
}

void CConfirmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfirmDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CConfirmDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CConfirmDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CConfirmDlg 消息处理程序


void CConfirmDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CConfirmDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
