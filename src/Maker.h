#pragma once


// CMaker ��ȭ �����Դϴ�.

class CMaker : public CDialogEx
{
	DECLARE_DYNAMIC(CMaker)

public:
	CMaker(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMaker();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAKER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
