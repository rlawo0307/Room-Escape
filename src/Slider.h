#pragma once
#include "afxcmn.h"
#include "MFCApplication12Dlg.h"

// CSlider ��ȭ �����Դϴ�.

class CSlider : public CDialogEx
{
	DECLARE_DYNAMIC(CSlider)

public:
	CSlider(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSlider();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SLIDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
