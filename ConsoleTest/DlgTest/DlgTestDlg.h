
// DlgTestDlg.h : 头文件
//

#pragma once
#include "ConfirmDlg.h"
#include "PageSheet.h"
#include "atlimage.h"

// CDlgTestDlg 对话框
class CDlgTestDlg : public CDialogEx
{

// 构造
public:
	CDlgTestDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CDlgTestDlg();

// 对话框数据
	enum { IDD = IDD_DLGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
    CConfirmDlg* m_pDlg;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	int m_edit1;
	int m_edit2;
	int m_result;
	afx_msg void OnClickedBtnCal();

	
	afx_msg void OnBnClickedBtnHelp();
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnSave();
};
