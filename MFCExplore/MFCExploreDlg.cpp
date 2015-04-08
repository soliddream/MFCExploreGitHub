
// MFCExploreDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCExplore.h"
#include "MFCExploreDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExploreDlg �Ի���



CMFCExploreDlg::CMFCExploreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCExploreDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCExploreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_HELLO_WORLD, mHelloWorldCtl);
}

BEGIN_MESSAGE_MAP(CMFCExploreDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCExploreDlg ��Ϣ�������

BOOL CMFCExploreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	/*tm t;
	CTime ct = CTime::GetCurrentTime();
	CString	strTime;

	ct.GetLocalTm(&t);	
	strTime.Format(_T("\n%d-%d-%d %d:%d:%d"), t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
	TRACE(strTime);
	strTime.Format(_T("\n%d-%d-%d %d:%d:%d"), ct.GetYear(), ct.GetMonth(), ct.GetDay(),
		ct.GetHour(), ct.GetMinute(), ct.GetSecond());
	TRACE(strTime);*/


	((CMFCExploreDlg*)AfxGetApp()->m_pMainWnd)->SampleMethod();
	//((CMFCExploreDlg*)AfxGetApp()->m_pMainWnd)->ShowWindow(SW_SHOWMAXIMIZED);

	CString str = _T("hello,world");
	TRACE(_T("%s"), str.operator LPCWSTR());
	TRACE(_T("%s"), (LPCTSTR)str);	


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCExploreDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCExploreDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// ʾ������,�����Ե���.���ú���־hello,world
void CMFCExploreDlg::SampleMethod()
{
	//TRACE("hello,world!");
	mHelloWorldCtl.SetWindowText(_T("hello,world"));
}
