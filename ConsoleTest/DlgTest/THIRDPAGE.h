#pragma once


// CTHIRDPAGE 对话框

class CTHIRDPAGE : public CPropertyPage
{
	DECLARE_DYNAMIC(CTHIRDPAGE)

public:
	CTHIRDPAGE();
	virtual ~CTHIRDPAGE();

// 对话框数据
	enum { IDD = IDD_THIRDPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual BOOL OnWizardFinish();
};
