#pragma once
#include "FIRSTPAGE.h"
#include "SECONDPAGE.h"
#include "THIRDPAGE.h"

// CPageSheet

class CPageSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPageSheet)

public:
	CPageSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPageSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPageSheet();

protected:
	DECLARE_MESSAGE_MAP()
private:
	CFIRSTPAGE m_first;
	CSECONDPAGE m_second;
	CTHIRDPAGE m_third;
};


