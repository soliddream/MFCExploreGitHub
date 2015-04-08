#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "ContactsDB.h"
// CFirstPage 对话框

class CFirstPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CFirstPage)

public:
	CFirstPage(CContactsDB& contactsDB);
	virtual ~CFirstPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_FIRST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_contacts;
	virtual BOOL OnInitDialog();
	// 添加联系人到列表控件中.另外这儿会添加数据到数据库中.
	bool AddContact();
	afx_msg void OnNMDblclkListContacts(NMHDR *pNMHDR, LRESULT *pResult);
	int Call();

private:
	CContactsDB m_contactsDB;
public:
	int AddContact(CString strName, CString strPhone);
	
};
