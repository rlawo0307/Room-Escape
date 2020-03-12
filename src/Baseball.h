#pragma once
#include "Help.h"

// CBaseball ��ȭ �����Դϴ�.

class CBaseball : public CDialogEx
{
	DECLARE_DYNAMIC(CBaseball)

public:
	CBaseball(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBaseball();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BASEBALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int m_baseA;
	int m_baseB;
	int m_baseC;
	int m_chance;
	afx_msg void OnClickedButtonBasecheck();
	CHelp m_dlghelp;
	bool m_bviewHelp;
	afx_msg void OnClickedButtonBasehint();
	afx_msg void OnClickedButtonHelp();
};
