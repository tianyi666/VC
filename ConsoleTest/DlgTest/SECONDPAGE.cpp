// SECONDPAGE.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "SECONDPAGE.h"
#include "afxdialogex.h"


// CSECONDPAGE 对话框

IMPLEMENT_DYNAMIC(CSECONDPAGE, CPropertyPage)

CSECONDPAGE::CSECONDPAGE()
	: CPropertyPage(CSECONDPAGE::IDD)
{

}

CSECONDPAGE::~CSECONDPAGE()
{
}

void CSECONDPAGE::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSECONDPAGE, CPropertyPage)
END_MESSAGE_MAP()


// CSECONDPAGE 消息处理程序




BOOL CSECONDPAGE::OnSetActive()
{
	// TODO:  在此添加专用代码和/或调用基类
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}
