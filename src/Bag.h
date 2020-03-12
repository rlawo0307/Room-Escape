#pragma once


// CBag 대화 상자입니다.

class CBag : public CDialogEx
{
	DECLARE_DYNAMIC(CBag)

public:
	CBag(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBag();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BAG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
