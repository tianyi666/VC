#pragma once


// CConfirmDlg �Ի���

class CConfirmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConfirmDlg)

public:
	CConfirmDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfirmDlg();

// �Ի�������
	enum { IDD = IDD_CONFIRMDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
