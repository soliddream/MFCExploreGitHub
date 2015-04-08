// DialogAddContact.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCExplore.h"
#include "DialogAddContact.h"
#include "afxdialogex.h"


// CDialogAddContact �Ի���

IMPLEMENT_DYNAMIC(CDialogAddContact, CDialogEx)

CDialogAddContact::CDialogAddContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogAddContact::IDD, pParent)
	, m_strName(_T(""))
	, m_strPhone(_T(""))
{

}

CDialogAddContact::~CDialogAddContact()
{
}

void CDialogAddContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
}


BEGIN_MESSAGE_MAP(CDialogAddContact, CDialogEx)
//	ON_WM_CHAR()
END_MESSAGE_MAP()


// CDialogAddContact ��Ϣ�������


//void CDialogAddContact::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//}
