
// DlgTestDlg.h : ͷ�ļ�
//

#pragma once


// CDlgTestDlg �Ի���
class CDlgTestDlg : public CDialogEx
{
// ����
public:
	CDlgTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DLGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
};
