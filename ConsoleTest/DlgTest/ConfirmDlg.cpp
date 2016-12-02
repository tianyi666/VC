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
END_MESSAGE_MAP()


// CConfirmDlg 消息处理程序
