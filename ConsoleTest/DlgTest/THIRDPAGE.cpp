// THIRDPAGE.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "THIRDPAGE.h"
#include "afxdialogex.h"


// CTHIRDPAGE 对话框

IMPLEMENT_DYNAMIC(CTHIRDPAGE, CPropertyPage)

CTHIRDPAGE::CTHIRDPAGE()
	: CPropertyPage(CTHIRDPAGE::IDD)
{

}

CTHIRDPAGE::~CTHIRDPAGE()
{
}

void CTHIRDPAGE::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTHIRDPAGE, CPropertyPage)
END_MESSAGE_MAP()


// CTHIRDPAGE 消息处理程序


BOOL CTHIRDPAGE::OnSetActive()
{
	// TODO:  在此添加专用代码和/或调用基类
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	//pSheet->SetFinishText(_T("完成"));

	return CPropertyPage::OnSetActive();
}


BOOL CTHIRDPAGE::OnWizardFinish()
{
	// TODO:  在此添加专用代码和/或调用基类
	MessageBox(_T("使用说明向导已阅读完！"));
	return CPropertyPage::OnWizardFinish();
}
