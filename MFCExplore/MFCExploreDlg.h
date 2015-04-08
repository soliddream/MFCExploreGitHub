
// MFCExploreDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFCExploreDlg 对话框
class CMFCExploreDlg : public CDialogEx
{
// 构造
public:
	CMFCExploreDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCEXPLORE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 示例方法,供测试调用.调用后日志hello,world
	void SampleMethod();
	// 通过调用sampleMethod,显示Hello,world.
	CStatic mHelloWorldCtl;
};
