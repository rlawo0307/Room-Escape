#pragma once


// CMaker 대화 상자입니다.

class CMaker : public CDialogEx
{
	DECLARE_DYNAMIC(CMaker)

public:
	CMaker(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMaker();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAKER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
