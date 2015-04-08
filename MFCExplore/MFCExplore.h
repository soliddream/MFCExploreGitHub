
// MFCExplore.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "ado2.h"

// CMFCExploreApp: 
// 有关此类的实现，请参阅 MFCExplore.cpp
//

class CMFCExploreApp : public CWinApp
{
public:
	CMFCExploreApp();

// 重写
public:
	virtual BOOL InitInstance();
	CADODatabase* m_pDB;
// 实现

	DECLARE_MESSAGE_MAP()
	
	int ConnectDatabase(LPCTSTR lpstrConnection);
	int CloseDatabase();
};

extern CMFCExploreApp theApp;