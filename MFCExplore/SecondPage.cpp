// SecondPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExplore.h"
#include "SecondPage.h"
#include "afxdialogex.h"


// CSecondPage 对话框

IMPLEMENT_DYNAMIC(CSecondPage, CPropertyPage)

CSecondPage::CSecondPage()
	: CPropertyPage(CSecondPage::IDD)
{

}

CSecondPage::~CSecondPage()
{
}

void CSecondPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecondPage, CPropertyPage)
END_MESSAGE_MAP()


// CSecondPage 消息处理程序
