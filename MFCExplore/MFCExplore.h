
// MFCExplore.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "ado2.h"

// CMFCExploreApp: 
// �йش����ʵ�֣������ MFCExplore.cpp
//

class CMFCExploreApp : public CWinApp
{
public:
	CMFCExploreApp();

// ��д
public:
	virtual BOOL InitInstance();
	CADODatabase* m_pDB;
// ʵ��

	DECLARE_MESSAGE_MAP()
	
	int ConnectDatabase(LPCTSTR lpstrConnection);
	int CloseDatabase();
};

extern CMFCExploreApp theApp;