// Pic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "Pic.h"
#include "afxdialogex.h"


// CPic �Ի���

IMPLEMENT_DYNAMIC(CPic, CDialogEx)

CPic::CPic(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPic::IDD, pParent)
{

}

CPic::~CPic()
{
}

void CPic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_colorlist);
}


BEGIN_MESSAGE_MAP(CPic, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CPic::OnClickList1)
END_MESSAGE_MAP()


// CPic ��Ϣ�������
CImage img1;

BOOL CPic::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//img1.Load(_T("E:/pic/6.jpg"));
	//HBITMAP bitmap = img1.Detach();
	//((CStatic*)(GetDlgItem(IDC_PIC)))->SetBitmap(bitmap);
	//delete img1;
	m_colorlist.SetExtendedStyle(m_colorlist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_colorlist.InsertColumn(0, _T("��ɫ"), LVCFMT_LEFT,50);
	m_colorlist.InsertColumn(1, _T("RGB"), LVCFMT_LEFT,100);

	m_colorlist.InsertItem(0,_T("��ɫ"));
	m_colorlist.SetItemText(0, 1, _T("Red"));

	m_colorlist.InsertItem(1, _T("��ɫ"));
	m_colorlist.SetItemText(1, 1, _T("Green"));
	return TRUE;  
}


void CPic::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	//if (((NMLISTVIEW*)pNMHDR)->iItem != -1)
	//{
	//	SetDlgItemText(IDC_STATIC_SEL, m_colorlist.GetItemText(((NMLISTVIEW*)pNMHDR)->iItem,1 ) );
	//}

	POSITION pos = m_colorlist.GetFirstSelectedItemPosition();
	SetDlgItemText(IDC_STATIC_SEL, m_colorlist.GetItemText(m_colorlist.GetNextSelectedItem(pos), 1));
}
