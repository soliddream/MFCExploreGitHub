#pragma once
#include "resource.h"

// CSecondPage �Ի���

class CSecondPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSecondPage)

public:
	CSecondPage();
	virtual ~CSecondPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_SECOND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
