#pragma once


// CBag ��ȭ �����Դϴ�.

class CBag : public CDialogEx
{
	DECLARE_DYNAMIC(CBag)

public:
	CBag(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBag();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BAG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
