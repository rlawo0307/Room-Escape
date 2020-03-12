#pragma once


// CHelp 대화 상자입니다.

class CHelp : public CDialogEx
{
	DECLARE_DYNAMIC(CHelp)

public:
	CHelp(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHelp();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HELP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
