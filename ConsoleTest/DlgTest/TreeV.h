#pragma once
#include "afxcmn.h"


// CTreeV �Ի���

class CTreeV : public CDialog
{
	DECLARE_DYNAMIC(CTreeV)

public:
	CImageList m_imageList;
	CTreeV(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTreeV();

// �Ի�������
	enum { IDD = IDD_DIALOG_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTreeCtrl tree;
};
