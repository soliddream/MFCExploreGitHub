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
	// ��һҳ����ҳ
	CFirstPage m_firstPage;
	// �ڶ�ҳ����ҳ
	CSecondPage m_secondPage;
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnContactAdd();
	
	void ResizeWindow();
	CStatusBar m_wndStatusBar;
	// �����ͳ�ʼ��״̬��
	bool CreateStatusBar();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnCall();
	CContactsDB m_contactsDB;
};

