#pragma once
#include "afxdlgs.h"
#include "FirstPage.h"
#include "SecondPage.h"
#include "afxext.h"
#include "ContactsDB.h"
#include "ado2.h"
class CMyPropertySheet :
	public CPropertySheet
{
public:
	CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL);
	~CMyPropertySheet();
	// 第一页属性页
	CFirstPage m_firstPage;
	// 第二页属性页
	CSecondPage m_secondPage;
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnContactAdd();
	
	void ResizeWindow();
	CStatusBar m_wndStatusBar;
	// 创建和初始化状态栏
	bool CreateStatusBar();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnCall();
	CContactsDB m_contactsDB;
};

