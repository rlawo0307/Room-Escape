#pragma once
#include "atltypes.h"
#include "atltime.h"


// CKEYGAME ��ȭ �����Դϴ�.

class CKEYGAME : public CDialogEx
{
	DECLARE_DYNAMIC(CKEYGAME)

public:
	CKEYGAME(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CKEYGAME();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void random();
	int m_game;
	CPoint m_ptClientSize;
	CTime timer;
	time_t start;
	CString m_key[7];
	UINT m_KeyInput[7];
	int keynum;
	int success;
	time_t record;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonHint();
};
