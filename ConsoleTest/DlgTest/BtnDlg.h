#pragma once


// CBtnDlg �Ի���

class CBtnDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBtnDlg)

public:
	CBtnDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBtnDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_BTN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
private:
	void CBtnDlg::InitChks();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadioPortal();
	afx_msg void OnBnClickedRadioForum();
	afx_msg void OnBnClickedRadioBlog();
	afx_msg void OnBnClickedOk();
};
