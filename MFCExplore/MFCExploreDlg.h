
// MFCExploreDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCExploreDlg �Ի���
class CMFCExploreDlg : public CDialogEx
{
// ����
public:
	CMFCExploreDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCEXPLORE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// ʾ������,�����Ե���.���ú���־hello,world
	void SampleMethod();
	// ͨ������sampleMethod,��ʾHello,world.
	CStatic mHelloWorldCtl;
};
