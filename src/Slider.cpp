// Slider.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Slider.h"
#include "afxdialogex.h"
#include "MFCApplication12Dlg.h"

// CSlider 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSlider, CDialogEx)

CSlider::CSlider(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SLIDER, pParent)

	, pMainDlg(NULL)
{

}

CSlider::~CSlider()
{
}

void CSlider::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_A, m_sliderA);
	DDX_Control(pDX, IDC_SLIDER_B, m_sliderB);
	DDX_Control(pDX, IDC_SLIDER_C, m_sliderC);

}


BEGIN_MESSAGE_MAP(CSlider, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CSlider::OnClickedButtonOpen)
END_MESSAGE_MAP()


// CSlider 메시지 처리기입니다.


BOOL CSlider::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_sliderA.SetRange(1, 26);
	m_sliderB.SetRange(1, 26);
	m_sliderC.SetRange(1, 26);
	int a = 1;
	SetDlgItemInt(IDC_EDIT_SLIDERA, a);
	SetDlgItemInt(IDC_EDIT_SLIDERB, a);
	SetDlgItemInt(IDC_EDIT_SLIDERC, a);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSlider::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nA = m_sliderA.GetPos();
	int nB = m_sliderB.GetPos();
	int nC = m_sliderC.GetPos();
	SetDlgItemInt(IDC_EDIT_SLIDERA, nA);
	SetDlgItemInt(IDC_EDIT_SLIDERB, nB);
	SetDlgItemInt(IDC_EDIT_SLIDERC, nC);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CSlider::OnClickedButtonOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCApplication12Dlg* pMain = (CMFCApplication12Dlg*)GetParent();
	CDialogEx::OnInitDialog();
	pMainDlg = (CMFCApplication12Dlg*)GetParent();
	
	int nA, nB, nC;
	nA = GetDlgItemInt(IDC_EDIT_SLIDERA);
	nB = GetDlgItemInt(IDC_EDIT_SLIDERB);
	nC = GetDlgItemInt(IDC_EDIT_SLIDERC);
	if (nA == 11 && nB == 5 && nC == 25){
		pMainDlg->m_item3_afxcheck = TRUE;
		pMain->m_lock.LoadBitmaps(IDB_BITMAP_LOCK_OPEN, NULL, NULL, NULL);
		pMain->m_lock.SizeToContent();
		EndDialog(IDC_BUTTON_OPEN);
		pMainDlg->caption.Format(_T("열쇠을 찾았다"));
	}

	else
		AfxMessageBox(_T("틀렸습니다."));
}
