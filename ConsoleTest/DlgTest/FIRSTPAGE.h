#pragma once


// CFIRSTPAGE 对话框

class CFIRSTPAGE : public CPropertyPage
{
	DECLARE_DYNAMIC(CFIRSTPAGE)

public:
	CFIRSTPAGE();
	virtual ~CFIRSTPAGE();

// 对话框数据
	enum { IDD = IDD_FIRSTPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
