#pragma once


// CSECONDPAGE 对话框

class CSECONDPAGE : public CPropertyPage
{
	DECLARE_DYNAMIC(CSECONDPAGE)

public:
	CSECONDPAGE();
	virtual ~CSECONDPAGE();

// 对话框数据
	enum { IDD = IDD_SECONDPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
