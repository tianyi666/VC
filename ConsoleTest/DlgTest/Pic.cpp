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
	ON_NOTIFY(NM_SETFOCUS, IDC_LIST1, &CPic::OnSetfocusList1)
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

	////////////////////////////////////////////////////////////////////////

	m_colorlist.SetExtendedStyle(m_colorlist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EDITLABELS);//
	m_colorlist.InsertColumn(0, _T("��ɫ"), LVCFMT_LEFT,50);
	m_colorlist.InsertColumn(1, _T("RGB"), LVCFMT_LEFT,100);

	m_colorlist.InsertItem(0,_T("��ɫ"));
	m_colorlist.SetItemText(0, 1, _T("Red"));

	m_colorlist.InsertItem(1, _T("��ɫ"));
	m_colorlist.SetItemText(1, 1, _T("Green"));
	return TRUE;  
}

CEdit m_Edit;
int m_Item;  //��
int m_SubItem; //��
int rowCount=2;  //������
bool  needSave; //���ڱ����־,����й���д��ΪTURE,���´α༭ʱ����ԭ����λ������ԭ�����������
void CPic::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//��ȡ ѡ�����ֵ ����һ
	if (((NMLISTVIEW*)pNMHDR)->iItem != -1)
	{
		SetDlgItemText(IDC_STATIC_SEL, m_colorlist.GetItemText(((NMLISTVIEW*)pNMHDR)->iItem,1 ) );
	}

	//��ȡ ѡ�����ֵ ������
	//POSITION pos = m_colorlist.GetFirstSelectedItemPosition();
	//SetDlgItemText(IDC_STATIC_SEL, m_colorlist.GetItemText(m_colorlist.GetNextSelectedItem(pos), 0));
	

	/*return;*/

	/////////////////////////////////////////////////////////////////////////////

	//�༭list
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	CRect  EditRect;
	if (needSave)
	{
		//needSave == TURE  
		CString  EditStr;
		m_Edit.GetWindowText(EditStr); //��ȡ���������  
		m_colorlist.SetItemText(m_Item, m_SubItem, EditStr); //m_Item,m_SubItem������������ֵ��ԭ���ĵ�Ԫ���ֵ 
		m_Edit.ShowWindow(SW_HIDE);
		
	}


	m_Item = pEditCtrl->iItem;
	m_SubItem = pEditCtrl->iSubItem;
	//m_Item = m_list.SubItemHitTest(&info);  

	if (m_Item == -1)
	{
		needSave = false;
		m_Edit.ShowWindow(SW_HIDE);
		return;
	}
	//m_SubItem = info.iSubItem;  

	if (m_Item < rowCount)
	{

		m_colorlist.GetSubItemRect(m_Item, m_SubItem, LVIR_LABEL, EditRect);
		needSave = true;
		if (m_Edit.m_hWnd == NULL)

		{    //m_Edit.m_hWnd == NULL˵����û����  
			//RECT rect;  
			//rect.left = rect.top = 0;  
			//rect.bottom = 20;  
			//rect.right = 100;  

			m_Edit.Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN | WS_BORDER,
				CRect(0, 0, 0, 0), this, IDC_EDIT);

			//IDC_EDIT�ѽ���ͷ�ļ��ж���,�������Ҫ,�ܶ�ʱ������,  
			//�����ҵ���ʵ�ֱ༭�취�������û˵��  
			//�Ҷ���Ϊ#define  IDC_EDIT 0xffff  

			m_Edit.ShowWindow(SW_HIDE); //Edit�����������  
			m_Edit.SetFont(this->GetFont(), FALSE);//��������  
			/*
			CFont tpFont;
			tpFont.CreateStockObject(DEFAULT_GUI_FONT);
			m_Edit.SetFont(&tpFont);
			tpFont.DeleteObject();
			*/
		}
		m_Edit.SetParent(&m_colorlist); //��list control����Ϊ������,���ɵ�Edit������ȷ��λ,���Ҳ����Ҫ,  

		EditRect.SetRect(EditRect.left, EditRect.top, EditRect.left + m_colorlist.GetColumnWidth(m_SubItem), EditRect.bottom);
		//m_list.GetColumnWidth(m_SubItem)��ȡ�еĿ��  

		CString strItem = m_colorlist.GetItemText(m_Item, m_SubItem);
		m_Edit.MoveWindow(&EditRect);
		m_Edit.ShowWindow(SW_SHOW);
		m_Edit.SetWindowText(strItem);
		m_Edit.SetFocus();//����Ϊ����  
		m_Edit.SetSel(0, -1);  //0,-1��ʾ��Ԫ������ȫѡ��  

	}
	else
	{
		m_Edit.ShowWindow(SW_HIDE);
	}
		
	*pResult = 0;
	
}


void CPic::OnSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	if (m_Edit)
	{ 
	//������� ��ѡ������
	m_Edit.SetSel(0, -1);
	m_Edit.Clear();
	m_Edit.ShowWindow(SW_HIDE);
	needSave = false;
	}
}
