// THIRDPAGE.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "THIRDPAGE.h"
#include "afxdialogex.h"


// CTHIRDPAGE �Ի���

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


// CTHIRDPAGE ��Ϣ�������


BOOL CTHIRDPAGE::OnSetActive()
{
	// TODO:  �ڴ����ר�ô����/����û���
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	//pSheet->SetFinishText(_T("���"));

	return CPropertyPage::OnSetActive();
}


BOOL CTHIRDPAGE::OnWizardFinish()
{
	// TODO:  �ڴ����ר�ô����/����û���
	MessageBox(_T("ʹ��˵�������Ķ��꣡"));
	return CPropertyPage::OnWizardFinish();
}
