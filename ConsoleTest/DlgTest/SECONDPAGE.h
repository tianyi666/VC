#pragma once


// CSECONDPAGE �Ի���

class CSECONDPAGE : public CPropertyPage
{
	DECLARE_DYNAMIC(CSECONDPAGE)

public:
	CSECONDPAGE();
	virtual ~CSECONDPAGE();

// �Ի�������
	enum { IDD = IDD_SECONDPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
