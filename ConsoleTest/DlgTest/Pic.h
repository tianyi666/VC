#pragma once
#include "afxcmn.h"


// CPic �Ի���

class CPic : public CDialogEx
{
	DECLARE_DYNAMIC(CPic)

public:
	CPic(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPic();

// �Ի�������
	enum { IDD = IDD_DIALOG_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_colorlist;
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult);
};
