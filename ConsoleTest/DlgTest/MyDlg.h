#pragma once


// CMyDlg 对话框

class CMyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg)

public:
	CMyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlg();

// 对话框数据
	enum { IDD = IDD_DIALOGNEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
