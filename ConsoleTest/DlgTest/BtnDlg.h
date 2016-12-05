#pragma once


// CBtnDlg 对话框

class CBtnDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBtnDlg)

public:
	CBtnDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBtnDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_BTN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
private:
	void CBtnDlg::InitChks();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadioPortal();
	afx_msg void OnBnClickedRadioForum();
	afx_msg void OnBnClickedRadioBlog();
	afx_msg void OnBnClickedOk();
};
