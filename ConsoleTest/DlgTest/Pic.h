#pragma once
#include "afxcmn.h"


// CPic 对话框

class CPic : public CDialogEx
{
	DECLARE_DYNAMIC(CPic)

public:
	CPic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPic();

// 对话框数据
	enum { IDD = IDD_DIALOG_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_colorlist;
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult);
};
