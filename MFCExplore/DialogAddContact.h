#pragma once


// CDialogAddContact �Ի���

class CDialogAddContact : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogAddContact)

public:
	CDialogAddContact(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogAddContact();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_CONTACT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ��ϵ������
	CString m_strName;
	// ��ϵ�˵绰
	CString m_strPhone;
};
