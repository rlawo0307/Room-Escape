#pragma once
#include "Help.h"

// CBaseball 대화 상자입니다.

class CBaseball : public CDialogEx
{
	DECLARE_DYNAMIC(CBaseball)

public:
	CBaseball(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBaseball();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BASEBALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
