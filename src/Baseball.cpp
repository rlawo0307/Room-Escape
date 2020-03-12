// Baseball.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Baseball.h"
#include "afxdialogex.h"
#include "Maker.h"

// CBaseball 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBaseball, CDialogEx)

CBaseball::CBaseball(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_BASEBALL, pParent)
	, m_baseA(0)
	, m_baseB(0)
	, m_baseC(0)
	, m_chance(5)
	, m_bviewHelp(false)
{

}

CBaseball::~CBaseball()
{
}

void CBaseball::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBaseball, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BASECHECK, &CBaseball::OnClickedButtonBasecheck)
	ON_BN_CLICKED(IDC_BUTTON_BASEHINT, &CBaseball::OnClickedButtonBasehint)
	ON_BN_CLICKED(IDC_BUTTON_HELP, &CBaseball::OnClickedButtonHelp)
END_MESSAGE_MAP()


// CBaseball 메시지 처리기입니다.


BOOL CBaseball::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemInt(IDC_EDIT_BASEA, 0);
	SetDlgItemInt(IDC_EDIT_BASEB, 0);
	SetDlgItemInt(IDC_EDIT_BASEC, 0);
	SetDlgItemInt(IDC_EDIT_STRIKE, 0);
	SetDlgItemInt(IDC_EDIT_BALL, 0);
	SetDlgItemInt(IDC_EDIT_CHANCE, 5);
	srand((unsigned)time(NULL));
	m_baseA = rand() % 10;
	m_baseB = rand() % 10;
	m_baseC = rand() % 10;
	while (TRUE) {
		if (m_baseB != m_baseA)
			break;
		m_baseB = rand() % 10;
	}
	while (TRUE) {
		if (m_baseC != m_baseA&& m_baseC != m_baseB)
			break;
		m_baseC = rand() % 10;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBaseball::OnClickedButtonBasecheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int a, b, c;
	int strike = 0, ball = 0;
	a = GetDlgItemInt(IDC_EDIT_BASEA);
	b = GetDlgItemInt(IDC_EDIT_BASEB);
	c = GetDlgItemInt(IDC_EDIT_BASEC);


	
	if (a == m_baseA)
		strike++;
	else if (a == m_baseB || a == m_baseC)
		ball++;

	if (b == m_baseB)
		strike++;
	else if (b == m_baseA || b == m_baseC)
		ball++;


	if (c == m_baseC)
		strike++;
	else if (c == m_baseA || c == m_baseB)
		ball++;
	SetDlgItemInt(IDC_EDIT_STRIKE, strike);
	SetDlgItemInt(IDC_EDIT_BALL, ball);

	if (a == m_baseA && b == m_baseB && c == m_baseC) {
		AfxMessageBox(_T("성공"));
		GetDlgItem(IDC_BUTTON_BASEHINT)->ShowWindow(true);
	}

	else if (m_chance == 1) {
		AfxMessageBox(_T("실패"));
		EndDialog(IDC_BUTTON_BASECHECK);
	}
	m_chance= m_chance - 1;
	SetDlgItemInt(IDC_EDIT_CHANCE, m_chance);
}


void CBaseball::OnClickedButtonBasehint()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMaker maker;
	maker.DoModal();
}


void CBaseball::OnClickedButtonHelp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bviewHelp == false) {
		m_dlghelp.Create(IDD_DIALOG_HELP, this);

		CRect rectMain, rectHelp;
		GetWindowRect(&rectMain);

		m_dlghelp.GetWindowRect(&rectHelp);
		m_dlghelp.MoveWindow(rectMain.right, rectMain.top, rectHelp.Width(), rectHelp.Height());

		m_dlghelp.ShowWindow(SW_SHOW);
		m_bviewHelp = true;
	}
	else {
		m_dlghelp.ShowWindow(SW_HIDE);
		m_dlghelp.DestroyWindow();
		m_bviewHelp = false;
	}
}
