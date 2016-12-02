// FIRSTPAGE.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "FIRSTPAGE.h"
#include "afxdialogex.h"


// CFIRSTPAGE 对话框

IMPLEMENT_DYNAMIC(CFIRSTPAGE, CPropertyPage)

CFIRSTPAGE::CFIRSTPAGE()
	: CPropertyPage(CFIRSTPAGE::IDD)
{

}

CFIRSTPAGE::~CFIRSTPAGE()
{
}

void CFIRSTPAGE::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFIRSTPAGE, CPropertyPage)
END_MESSAGE_MAP()


// CFIRSTPAGE 消息处理程序


BOOL CFIRSTPAGE::OnSetActive()
{
	// TODO:  在此添加专用代码和/或调用基类
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}
