#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "ContactsDB.h"
// CFirstPage �Ի���

class CFirstPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CFirstPage)

public:
	CFirstPage(CContactsDB& contactsDB);
	virtual ~CFirstPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_FIRST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_contacts;
	virtual BOOL OnInitDialog();
	// �����ϵ�˵��б�ؼ���.���������������ݵ����ݿ���.
	bool AddContact();
	afx_msg void OnNMDblclkListContacts(NMHDR *pNMHDR, LRESULT *pResult);
	int Call();

private:
	CContactsDB m_contactsDB;
public:
	int AddContact(CString strName, CString strPhone);
	
};
