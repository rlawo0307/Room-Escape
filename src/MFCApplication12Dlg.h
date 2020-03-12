
// MFCApplication12Dlg.h : 헤더 파일
//

#pragma once
#include "afxext.h"
#include "afxcmn.h"


// CMFCApplication12Dlg 대화 상자
class CMFCApplication12Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication12Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION12_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
//	bool m_cursor;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonBall();
//	afx_msg void OnBnClickedButton4();
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	CBitmapButton m_bag;
	CBitmapButton m_ball;
//	CBitmapButton m_newspaper;
	CBitmapButton m_door;

	afx_msg void OnBnClickedButtonCarrier();
	BOOL m_item1_afxcheck;
	CBitmapButton m_frame;
	bool m_cursor;

	afx_msg void OnBnClickedButton11();
	afx_msg void OnClickedButtonSlider();
	afx_msg void OnClickedButtonSpin();
	CBitmapButton m_lock;
	BOOL m_item3_afxcheck;
	CBitmapButton m_rope;
	afx_msg void OnClickedButtonBand();
	BOOL m_item4_afxcheck;
	afx_msg void OnClickedButtonRope();
//	BOOL m_afxitem6_check;
	BOOL m_item6_afxcheck;
	CBitmapButton m_case2;
	CBitmapButton m_case1;
	CBitmapButton m_ventilater;
	CBitmapButton m_gori;
	afx_msg void OnClickedButtonLongrope();
	CBitmapButton m_mon;
	afx_msg void OnClickedButtonVentilator();
	bool HPTimerRun;
	int drink;
	CProgressCtrl m_progress;
	afx_msg void OnBnClickedButton2();
//	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CBitmapButton m_water;
	afx_msg void OnClickedButtonLight();
	BOOL m_item2_afxcheck;
	CBitmapButton m_computer;
	afx_msg void OnClickedButtonComputer();
	bool m_selectitem[7];
	bool m_longrope;
	CString caption;
	bool CaptionOnGo;
	int replay;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	bool oldcheck[4];
	bool newcheck[4];
	CBitmapButton m_carrierpicture;
};
