#pragma once
#include "afxcmn.h"
#include "MFCApplication12Dlg.h"

// CSlider 대화 상자입니다.

class CSlider : public CDialogEx
{
	DECLARE_DYNAMIC(CSlider)

public:
	CSlider(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSlider();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SLIDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CSliderCtrl m_sliderA;
	CSliderCtrl m_sliderB;
	CSliderCtrl m_sliderC;

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnClickedButtonOpen();
	CMFCApplication12Dlg* pMainDlg;
};
