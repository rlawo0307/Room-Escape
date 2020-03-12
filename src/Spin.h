#pragma once
#include "afxcmn.h"


// CSpin 대화 상자입니다.

class CSpin : public CDialogEx
{
	DECLARE_DYNAMIC(CSpin)

public:
	CSpin(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSpin();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_spinA;
	CSpinButtonCtrl m_spinB;
	CSpinButtonCtrl m_spinC;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButton1();
};
