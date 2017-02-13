// Pic.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "Pic.h"
#include "afxdialogex.h"


// CPic 对话框

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


// CPic 消息处理程序
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
	m_colorlist.InsertColumn(0, _T("颜色"), LVCFMT_LEFT,50);
	m_colorlist.InsertColumn(1, _T("RGB"), LVCFMT_LEFT,100);

	m_colorlist.InsertItem(0,_T("红色"));
	m_colorlist.SetItemText(0, 1, _T("Red"));

	m_colorlist.InsertItem(1, _T("绿色"));
	m_colorlist.SetItemText(1, 1, _T("Green"));
	return TRUE;  
}

CEdit m_Edit;
int m_Item;  //行
int m_SubItem; //列
int rowCount=2;  //总行数
bool  needSave; //用于保存标志,如果有过编写则为TURE,当下次编辑时会在原来的位置输入原来输入的内容
void CPic::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;

	//获取 选中项的值 方法一
	if (((NMLISTVIEW*)pNMHDR)->iItem != -1)
	{
		SetDlgItemText(IDC_STATIC_SEL, m_colorlist.GetItemText(((NMLISTVIEW*)pNMHDR)->iItem,1 ) );
	}

	//获取 选中项的值 方法二
	//POSITION pos = m_colorlist.GetFirstSelectedItemPosition();
	//SetDlgItemText(IDC_STATIC_SEL, m_colorlist.GetItemText(m_colorlist.GetNextSelectedItem(pos), 0));
	

	/*return;*/

	/////////////////////////////////////////////////////////////////////////////

	//编辑list
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	CRect  EditRect;
	if (needSave)
	{
		//needSave == TURE  
		CString  EditStr;
		m_Edit.GetWindowText(EditStr); //获取输入的内容  
		m_colorlist.SetItemText(m_Item, m_SubItem, EditStr); //m_Item,m_SubItem这两个变量的值是原来的单元格的值 
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

		{    //m_Edit.m_hWnd == NULL说明还没创建  
			//RECT rect;  
			//rect.left = rect.top = 0;  
			//rect.bottom = 20;  
			//rect.right = 100;  

			m_Edit.Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN | WS_BORDER,
				CRect(0, 0, 0, 0), this, IDC_EDIT);

			//IDC_EDIT已近在头文件中定义,这个很重要,很多时候会忽略,  
			//网上找到的实现编辑办法中这个都没说明  
			//我定义为#define  IDC_EDIT 0xffff  

			m_Edit.ShowWindow(SW_HIDE); //Edit创建完后隐藏  
			m_Edit.SetFont(this->GetFont(), FALSE);//设置字体  
			/*
			CFont tpFont;
			tpFont.CreateStockObject(DEFAULT_GUI_FONT);
			m_Edit.SetFont(&tpFont);
			tpFont.DeleteObject();
			*/
		}
		m_Edit.SetParent(&m_colorlist); //将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要,  

		EditRect.SetRect(EditRect.left, EditRect.top, EditRect.left + m_colorlist.GetColumnWidth(m_SubItem), EditRect.bottom);
		//m_list.GetColumnWidth(m_SubItem)获取列的宽度  

		CString strItem = m_colorlist.GetItemText(m_Item, m_SubItem);
		m_Edit.MoveWindow(&EditRect);
		m_Edit.ShowWindow(SW_SHOW);
		m_Edit.SetWindowText(strItem);
		m_Edit.SetFocus();//设置为焦点  
		m_Edit.SetSel(0, -1);  //0,-1表示单元格内容全选中  

	}
	else
	{
		m_Edit.ShowWindow(SW_HIDE);
	}
		
	*pResult = 0;
	
}


void CPic::OnSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	if (m_Edit)
	{ 
	//清空内容 先选中内容
	m_Edit.SetSel(0, -1);
	m_Edit.Clear();
	m_Edit.ShowWindow(SW_HIDE);
	needSave = false;
	}
}
