// PageSheet.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgTest.h"
#include "PageSheet.h"


// CPageSheet

IMPLEMENT_DYNAMIC(CPageSheet, CPropertySheet)

CPageSheet::CPageSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_first);
	AddPage(&m_second);
	AddPage(&m_third);

}

CPageSheet::CPageSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_first);
	AddPage(&m_second);
	AddPage(&m_third);
}

CPageSheet::~CPageSheet()
{
}


BEGIN_MESSAGE_MAP(CPageSheet, CPropertySheet)
END_MESSAGE_MAP()


// CPageSheet 消息处理程序
