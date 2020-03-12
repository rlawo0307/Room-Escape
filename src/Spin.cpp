// Spin.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Spin.h"
#include "afxdialogex.h"
#include "MFCApplication12Dlg.h"

// CSpin ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSpin, CDialogEx)

CSpin::CSpin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CSpin::~CSpin()
{
}

void CSpin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_A, m_spinA);
	DDX_Control(pDX, IDC_SPIN_B, m_spinB);
	DDX_Control(pDX, IDC_SPIN_C, m_spinC);
}


BEGIN_MESSAGE_MAP(CSpin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSpin::OnClickedButton1)
END_MESSAGE_MAP()


// CSpin �޽��� ó�����Դϴ�.


BOOL CSpin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_spinA.SetRange(0, 9);
	m_spinB.SetRange(0, 9);
	m_spinC.SetRange(0, 9);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CSpin::OnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int checkA, checkB, checkC;
	CMFCApplication12Dlg* pMain = (CMFCApplication12Dlg*)GetParent();
	checkA = GetDlgItemInt(IDC_EDIT_SPINA);
	checkB = GetDlgItemInt(IDC_EDIT_SPINB);
	checkC = GetDlgItemInt(IDC_EDIT_SPINC);
	if (checkA == 8 && checkB == 1 && checkC == 0) {
		pMain->m_mon.LoadBitmaps(IDB_BITMAP_DOOROPEN, NULL, NULL, NULL);
		pMain->m_mon.SizeToContent();
		EndDialog(IDC_BUTTON1);
	}
		
}
