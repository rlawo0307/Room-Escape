#pragma once
#include "afxcmn.h"


// CSpin ��ȭ �����Դϴ�.

class CSpin : public CDialogEx
{
	DECLARE_DYNAMIC(CSpin)

public:
	CSpin(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSpin();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_spinA;
	CSpinButtonCtrl m_spinB;
	CSpinButtonCtrl m_spinC;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButton1();
};
