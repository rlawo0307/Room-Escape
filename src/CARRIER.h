#pragma once
#include "afxext.h"
#include "MFCApplication12Dlg.h"

// CCARRIER ��ȭ �����Դϴ�.

class CCARRIER : public CDialogEx
{
	DECLARE_DYNAMIC(CCARRIER)

public:
	CCARRIER(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCARRIER();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CARRIER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CBitmapButton m_item1;
	CBitmapButton m_item2;
	CBitmapButton m_item3;
	CBitmapButton m_item4;
	CBitmapButton m_item5;
	CBitmapButton m_item6;
	CBitmapButton m_item7;
	CBitmapButton m_item8;
	CBitmapButton m_item9;
	CBitmapButton m_item10;
	CBitmapButton m_item11;
	CBitmapButton m_item12;
	CBitmapButton m_item13;
	CBitmapButton m_item14;
	CBitmapButton m_item15;
	virtual BOOL OnInitDialog();
	BOOL m_item1_check;
	afx_msg void OnBnClickedButtonItem1();
	CMFCApplication12Dlg* pMainDlg;
	afx_msg void OnBnClickedButtonUse();
	bool m_cursor;
	afx_msg void OnClickedButtonItem2();
	BOOL m_item2_check;
	afx_msg void OnClickedButtonItem3();
	BOOL m_item3_check;
	afx_msg void OnClickedButtonItem4();
	BOOL m_item4_check;
	BOOL m_item6_check;
	afx_msg void OnClickedButtonItem6();
};
