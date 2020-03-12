// Spin.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Spin.h"
#include "afxdialogex.h"
#include "MFCApplication12Dlg.h"

// CSpin 대화 상자입니다.

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


// CSpin 메시지 처리기입니다.


BOOL CSpin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_spinA.SetRange(0, 9);
	m_spinB.SetRange(0, 9);
	m_spinC.SetRange(0, 9);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSpin::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
