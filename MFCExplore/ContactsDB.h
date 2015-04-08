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
	// �����ϵ�˵����ݿ����ϵ�˱���
	int AddContact(Contact contact);
	// �����ݿ���ϵ�˱��ȡ��ϵ���б�
	std::list<Contact> getContacts();
	// �����ݿ���ϵ�˱�ɾ��ָ����ϵ��
	int RemoveContact(Contact contact);
};

