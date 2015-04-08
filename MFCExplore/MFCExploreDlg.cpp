
// MFCExploreDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCExplore.h"
#include "MFCExploreDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExploreDlg 对话框



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


// CMFCExploreDlg 消息处理程序

BOOL CMFCExploreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
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


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCExploreDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCExploreDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// 示例方法,供测试调用.调用后日志hello,world
void CMFCExploreDlg::SampleMethod()
{
	//TRACE("hello,world!");
	mHelloWorldCtl.SetWindowText(_T("hello,world"));
}
