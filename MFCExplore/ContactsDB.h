#pragma once
#include <list>
class CContactsDB
{
public:
	CContactsDB();
	~CContactsDB();

	struct Contact
	{
		CString name;
		CString mobilephone;
		Contact(CString name, CString mobilephone){ this->name = name; this->mobilephone = mobilephone; }
		Contact(){}
	};


public:
	// 添加联系人到数据库的联系人表中
	int AddContact(Contact contact);
	// 从数据库联系人表获取联系人列表
	std::list<Contact> getContacts();
	// 从数据库联系人表删除指定联系人
	int RemoveContact(Contact contact);
};

