
// MFCApplication12.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCApplication12App:
// �� Ŭ������ ������ ���ؼ��� MFCApplication12.cpp�� �����Ͻʽÿ�.
//

class CMFCApplication12App : public CWinApp
{
public:
	CMFCApplication12App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication12App theApp;