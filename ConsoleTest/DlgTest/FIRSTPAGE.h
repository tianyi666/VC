#pragma once


// CFIRSTPAGE �Ի���

class CFIRSTPAGE : public CPropertyPage
{
	DECLARE_DYNAMIC(CFIRSTPAGE)

public:
	CFIRSTPAGE();
	virtual ~CFIRSTPAGE();

// �Ի�������
	enum { IDD = IDD_FIRSTPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
