// ConfirmDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "ConfirmDlg.h"
#include "afxdialogex.h"



// CConfirmDlg �Ի���

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


// CConfirmDlg ��Ϣ�������


void CConfirmDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CConfirmDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
