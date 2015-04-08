#pragma once
#include "resource.h"

// CSecondPage 对话框

class CSecondPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSecondPage)

public:
	CSecondPage();
	virtual ~CSecondPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_SECOND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
