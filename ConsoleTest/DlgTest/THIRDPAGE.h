#pragma once


// CTHIRDPAGE �Ի���

class CTHIRDPAGE : public CPropertyPage
{
	DECLARE_DYNAMIC(CTHIRDPAGE)

public:
	CTHIRDPAGE();
	virtual ~CTHIRDPAGE();

// �Ի�������
	enum { IDD = IDD_THIRDPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual BOOL OnWizardFinish();
};
