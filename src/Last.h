#pragma once


// CLast ��ȭ �����Դϴ�.

class CLast : public CDialogEx
{
	DECLARE_DYNAMIC(CLast)

public:
	CLast(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLast();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
