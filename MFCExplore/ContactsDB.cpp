#include "stdafx.h"
#include "ContactsDB.h"
#include "ado2.h"
#include "MFCExplore.h"
using namespace std;

CContactsDB::CContactsDB()
{
	
}


CContactsDB::~CContactsDB()
{
}


// 添加联系人到数据库的联系人表中
int CContactsDB::AddContact(Contact contact)
{
	CADODatabase* pDB = ((CMFCExploreApp*)AfxGetApp())->m_pDB;
	if (pDB != NULL && pDB->IsOpen())
	{	
		TCHAR sql[256];
		_stprintf_s(sql, 256, _T("INSERT INTO contacts(name,mobilephone) VALUES ('%s','%s') ON DUPLICATE KEY UPDATE mobilephone='%s'"),
			contact.name, contact.mobilephone, contact.mobilephone);
		pDB->Execute(sql);
	}
	return 0;
}


// 从数据库联系人表获取联系人列表
list<CContactsDB::Contact> CContactsDB::getContacts()
{
	list<Contact> contacts = list<Contact>();
	CADODatabase* pDB = ((CMFCExploreApp*)AfxGetApp())->m_pDB;
	if (pDB!=NULL && pDB->IsOpen())
	{
		CADORecordset* pRs = new CADORecordset(pDB);

		TCHAR sql[256];
		_stprintf_s(sql, 256, _T("SELECT name,mobilephone FROM contacts"));
		if (!pRs->Open(sql))
		{
			delete pRs;
		}
		else
		{
			while (!pRs->IsEOF())
			{
				Contact contact = Contact();

				pRs->GetFieldValue(_T("name"), contact.name);
				pRs->GetFieldValue(_T("mobilephone"), contact.mobilephone);
				contacts.push_back(contact);
				pRs->MoveNext();
			}
			pRs->Close();
			delete pRs;
			pRs = NULL;
		}
	}
	return contacts;
}


// 从数据库联系人表删除指定联系人
int CContactsDB::RemoveContact(Contact contact)
{
	CADODatabase* pDB = ((CMFCExploreApp*)AfxGetApp())->m_pDB;
	if (pDB != NULL)
	{
		TCHAR sql[256];
		_stprintf_s(sql, 256, _T("DELETE FROM contacts WHERE name='%s'"), contact.name);
		pDB->Execute(sql);
	}
	return 0;
}
