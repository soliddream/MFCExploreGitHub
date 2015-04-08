
// MFCExplore.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "MFCExplore.h"
#include "MFCExploreDlg.h"
#include "MyPropertySheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExploreApp

BEGIN_MESSAGE_MAP(CMFCExploreApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCExploreApp ����

CMFCExploreApp::CMFCExploreApp()
	: m_pDB(NULL)
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMFCExploreApp ����

CMFCExploreApp theApp;


// CMFCExploreApp ��ʼ��

BOOL CMFCExploreApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	//����MySQL���ݿ�
	
	CString strConnection = _T("");

	/*strConnection = _T("Provider=MSDASQL.1;Password=314353;Persist Security Info=True;User ID=root;")
		_T("Extended Properties=\"Driver = MySQL ODBC 5.3 Unicode Driver; SERVER = localhost; UID = root; PWD = 314353; DATABASE = conference; PORT = 3306\"";)
		_T("Initial Catalog=conference");*/
	//TODO: �ǵ��ϴ�����֮ǰ�����޸�һ��
	//mysql�����ַ�����λ����ο� http://blog.csdn.net/zyq5945/article/details/5486393
	strConnection = _T("Driver=MySQL ODBC 5.3 Unicode Driver;SERVER=localhost;UID=root;PWD=root;DATABASE=mfcexplore;PORT=3306");
	ConnectDatabase(strConnection);
	

	//CMFCExploreDlg dlg;
	//m_pMainWnd = &dlg;
	//INT_PTR nResponse = dlg.DoModal();

	CMyPropertySheet ps(_T("MFC ̽��"));
	m_pMainWnd = &ps;
	INT_PTR nResponse = ps.DoModal();
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	CloseDatabase();

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}



int CMFCExploreApp::ConnectDatabase(LPCTSTR lpstrConnection)
{
	try
	{
		if (m_pDB==NULL)
		{
			m_pDB = new CADODatabase();
			m_pDB->Open(lpstrConnection);
		}
		
	}
	catch (CADOException &e)
	{
		TRACE(e.GetErrorMessage());
	}

	return 0;
}


int CMFCExploreApp::CloseDatabase()
{
	if (m_pDB!=NULL)
	{
		m_pDB->Close();
		delete m_pDB;
		m_pDB = NULL;
	}
	return 0;
}
