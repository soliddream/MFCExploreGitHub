#include "stdafx.h"

#include "MyPropertySheet.h"
#include "DialogAddContact.h"
#include "MFCExplore.h"

CMyPropertySheet::CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd)
	:CPropertySheet(pszCaption, pParentWnd, 0),
	m_firstPage(m_contactsDB)
{
	//�������ҳ
	AddPage(&m_firstPage);
	AddPage(&m_secondPage);
}


CMyPropertySheet::~CMyPropertySheet()
{
	
}


BOOL CMyPropertySheet::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();	

	//���ز���ʾ�˵�
	CMenu menu;
	menu.LoadMenuW(IDR_MENU_MAIN);
	SetMenu(&menu);
	menu.Detach();

	CreateStatusBar();
	m_wndStatusBar.SetPaneText(0, _T("����"));

	ResizeWindow();
	//ˢ����ʾ
	//Invalidate();



	return bResult;
}

//������Ӳ˵���Ҫ���µ������ڴ�С
void CMyPropertySheet::ResizeWindow()
{
	CRect myRect;
	GetWindowRect(&myRect);
	myRect.bottom += 20;
	//ClientToScreen(myRect);
	MoveWindow(myRect.left, myRect.top,
		myRect.Width(), myRect.Height());
}

BEGIN_MESSAGE_MAP(CMyPropertySheet, CPropertySheet)
	ON_COMMAND(ID_CONTACT_ADD, &CMyPropertySheet::OnContactAdd)
	ON_COMMAND(ID_CALL, &CMyPropertySheet::OnCall)
END_MESSAGE_MAP()




void CMyPropertySheet::OnContactAdd()
{
	//��Ӧ�����ϵ�˲˵�����
	TRACE("�����ϵ��");
	m_firstPage.AddContact();
}


// �����ͳ�ʼ��״̬��
bool CMyPropertySheet::CreateStatusBar()
{
	static UINT nIndicators[] = { ID_CALL_STATUS
	};

	if (!m_wndStatusBar.Create(this))
		return false;

	m_wndStatusBar.SetIndicators(nIndicators, 1);

	CRect rect;
	GetClientRect(&rect);
	m_wndStatusBar.SetPaneInfo(0, ID_CALL_STATUS, SBPS_STRETCH | SBPS_NOBORDERS, rect.Width());

	//m_wndStatusBar.GetStatusBarCtrl().SetBkColor(RGB(180,180,180));
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	
	return true;
}


LRESULT CMyPropertySheet::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case LBD_SET_CALL_STATE_MESSAGE:
	{		
		CString *pStr = (CString*)lParam;
		
		if (pStr != NULL)
		{ 
			m_wndStatusBar.SetPaneText(0, *pStr);
			delete pStr;
		}
	}
	break;
	}

	return CPropertySheet::WindowProc(message, wParam, lParam);
}


void CMyPropertySheet::OnCall()
{
	m_firstPage.Call();
}
