// SECONDPAGE.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "SECONDPAGE.h"
#include "afxdialogex.h"


// CSECONDPAGE �Ի���

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


// CSECONDPAGE ��Ϣ�������




BOOL CSECONDPAGE::OnSetActive()
{
	// TODO:  �ڴ����ר�ô����/����û���
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}
