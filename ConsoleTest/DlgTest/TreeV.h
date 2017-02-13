#pragma once
#include "afxcmn.h"


// CTreeV 对话框

class CTreeV : public CDialog
{
	DECLARE_DYNAMIC(CTreeV)

public:
	CImageList m_imageList;
	CTreeV(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTreeV();

// 对话框数据
	enum { IDD = IDD_DIALOG_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTreeCtrl tree;
};
