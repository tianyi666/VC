// BtnDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "BtnDlg.h"
#include "afxdialogex.h"


// CBtnDlg 对话框

IMPLEMENT_DYNAMIC(CBtnDlg, CDialogEx)

CBtnDlg::CBtnDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBtnDlg::IDD, pParent)
{

}

CBtnDlg::~CBtnDlg()
{
}

void CBtnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CBtnDlg::InitChks()
{
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(0);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(0);
	((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(0);
	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(0);
	((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(0);
	((CButton*)GetDlgItem(IDC_CHECK6))->SetCheck(0);

	((CButton*)GetDlgItem(IDC_CHECK1))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_CHECK2))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_CHECK3))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_CHECK4))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_CHECK5))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_CHECK6))->EnableWindow(false);
}


BEGIN_MESSAGE_MAP(CBtnDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_PORTAL, &CBtnDlg::OnBnClickedRadioPortal)
	ON_BN_CLICKED(IDC_RADIO_FORUM, &CBtnDlg::OnBnClickedRadioForum)
	ON_BN_CLICKED(IDC_RADIO_BLOG, &CBtnDlg::OnBnClickedRadioBlog)
	ON_BN_CLICKED(IDOK, &CBtnDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CBtnDlg 消息处理程序


void CBtnDlg::OnBnClickedRadioPortal()
{
	InitChks();
	((CButton*)GetDlgItem(IDC_CHECK1))->EnableWindow(true);
}


void CBtnDlg::OnBnClickedRadioForum()
{
	InitChks();
	((CButton*)GetDlgItem(IDC_CHECK2))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_CHECK3))->EnableWindow(true);
}


void CBtnDlg::OnBnClickedRadioBlog()
{
	InitChks();
	((CButton*)GetDlgItem(IDC_CHECK4))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_CHECK5))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_CHECK6))->EnableWindow(true);
}


void CBtnDlg::OnBnClickedOk()
{
	CString res;
	CString tmp;
	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		GetDlgItemText(IDC_CHECK1, tmp);
			res += tmp;
	}
	if (((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
	{
		GetDlgItemText(IDC_CHECK2, tmp);
		res += tmp;
	}
	if (((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	{
		GetDlgItemText(IDC_CHECK3, tmp);
		res += tmp;
	}
	if (((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
	{
		GetDlgItemText(IDC_CHECK4, tmp);
		res += tmp;
	}
	if (((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
	{
		GetDlgItemText(IDC_CHECK5, tmp);
		res += tmp;

	}
	if (((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
	{
		GetDlgItemText(IDC_CHECK6, tmp);
		res += tmp;
	}

	SetDlgItemText(IDC_EDIT_RESULT, res);
	//CDialogEx::OnOK();
}
