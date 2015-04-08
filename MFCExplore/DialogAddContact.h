#pragma once


// CDialogAddContact 对话框

class CDialogAddContact : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogAddContact)

public:
	CDialogAddContact(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogAddContact();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_CONTACT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 联系人姓名
	CString m_strName;
	// 联系人电话
	CString m_strPhone;
};
