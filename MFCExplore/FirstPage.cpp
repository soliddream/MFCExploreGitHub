// FirstPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExplore.h"
#include "FirstPage.h"
#include "afxdialogex.h"
#include "DialogAddContact.h"
#include <list>
using namespace std;
// CFirstPage 对话框

IMPLEMENT_DYNAMIC(CFirstPage, CPropertyPage)

CFirstPage::CFirstPage(CContactsDB& contactsDB)
	: CPropertyPage(CFirstPage::IDD),
	m_contactsDB(contactsDB)
{

}

CFirstPage::~CFirstPage()
{
}

void CFirstPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CONTACTS, m_contacts);
}


BEGIN_MESSAGE_MAP(CFirstPage, CPropertyPage)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CONTACTS, &CFirstPage::OnNMDblclkListContacts)
END_MESSAGE_MAP()


// CFirstPage 消息处理程序


BOOL CFirstPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// 添加列
	CRect rect;
	m_contacts.GetClientRect(&rect);
	m_contacts.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, rect.Width() * 3 / 5);
	m_contacts.InsertColumn(1, _T("电话"), LVCFMT_LEFT, rect.Width() * 5);	

	//添加sample项
	/*
	CString data[2] = { _T("张三"), _T("1234") };
	LV_ITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
	lvi.iSubItem = 0;
	lvi.pszText = data[0].GetBuffer(0);
	lvi.iImage = 0;
	lvi.iItem = 0;
	m_contacts.InsertItem(&lvi);
	for (int i = 0; i<2; i++) m_contacts.SetItemText(0, i, data[i]);
	*/

	//从数据库联系人表中载入数据
	
	list<CContactsDB::Contact>contacts = m_contactsDB.getContacts();
	list<CContactsDB::Contact>::iterator it = contacts.begin();
	while (it != contacts.end())
	{
		AddContact(it->name,it->mobilephone);
		it++;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


// 添加联系人到列表控件中.另外这儿会添加数据到数据库中.
bool CFirstPage::AddContact()
{
	CDialogAddContact dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		CString strName = dlg.m_strName;
		CString strPhone = dlg.m_strPhone;
		if (!strName.IsEmpty() && !strPhone.IsEmpty())
		{
			AddContact(strName, strPhone);
			m_contactsDB.AddContact(CContactsDB::Contact(strName, strPhone));
			
			return true;
		}

	}
	else if (nResponse == IDCANCEL)
	{

	}
	
	return false;
}


void CFirstPage::OnNMDblclkListContacts(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CDialogAddContact dlg;
	int nIndex = pNMItemActivate->iItem;	
	dlg.m_strName = m_contacts.GetItemText(nIndex, 0);
	CString originName = dlg.m_strName;
	dlg.m_strPhone = m_contacts.GetItemText(nIndex, 1);
	CString originPhone = dlg.m_strPhone;
	TRACE(_T("修改%d联系人.姓名:%s,电话:%s"), nIndex, dlg.m_strName, dlg.m_strPhone);
	
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		CString strName = dlg.m_strName;
		CString strPhone = dlg.m_strPhone;
		if (!strName.IsEmpty() && !strPhone.IsEmpty())
		{
			//删除再添加,同时数据库中更新
			m_contacts.DeleteItem(nIndex);
			m_contactsDB.RemoveContact(CContactsDB::Contact(originName, originPhone));
			AddContact(strName, strPhone);
			m_contactsDB.AddContact(CContactsDB::Contact(strName, strPhone));
		}

	}
	else if (nResponse == IDCANCEL)
	{

	}
	
	*pResult = 0;
}


int CFirstPage::Call()
{
	TRACE("呼叫\n");
	//列表控件获得选中项参考自https://msdn.microsoft.com/zh-cn/library/vstudio/hdxt1akf(v=vs.110).aspx
	POSITION pos = m_contacts.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("没有选择联系人,请在联系人列表中选择一个联系人"));
	}
	else
	{
		if (pos)  //如需拨打多个联系人,使用while
		{
			//
			int nItem = m_contacts.GetNextSelectedItem(pos);
			CString strName = m_contacts.GetItemText(nItem, 0);
			CString strPhone = m_contacts.GetItemText(nItem, 1);
			TRACE(_T("选择联系人 %d !姓名:%s,电话:%s\n"), nItem, strName, strPhone);

			CString* pStr = new CString(_T("呼叫") + strPhone);
			::SendMessage(GetParent()->GetSafeHwnd(), LBD_SET_CALL_STATE_MESSAGE, NULL, (LPARAM)pStr);
		}
	}
	return 0;
}


int CFirstPage::AddContact(CString strName, CString strPhone)
{
	LV_ITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
	lvi.iSubItem = 0;
	lvi.pszText = strName.GetBuffer(0);
	lvi.iImage = 0;
	lvi.iItem = 0;
	int nRow = m_contacts.InsertItem(&lvi);
	m_contacts.SetItemText(nRow, 0, strName);
	m_contacts.SetItemText(nRow, 1, strPhone);
	return 0;
}
