
// DlgTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDlgTestApp: 
// �йش����ʵ�֣������ DlgTest.cpp
//

class CDlgTestApp : public CWinApp
{
public:
	CDlgTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDlgTestApp theApp;