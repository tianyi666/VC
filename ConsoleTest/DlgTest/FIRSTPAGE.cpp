// FIRSTPAGE.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgTest.h"
#include "FIRSTPAGE.h"
#include "afxdialogex.h"


// CFIRSTPAGE �Ի���

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


// CFIRSTPAGE ��Ϣ�������


BOOL CFIRSTPAGE::OnSetActive()
{
	// TODO:  �ڴ����ר�ô����/����û���
	CPropertySheet* pSheet = (CPropertySheet*)GetParent();
	pSheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}
