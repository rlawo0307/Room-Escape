
// MFCApplication12Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "MFCApplication12Dlg.h"
#include "afxdialogex.h"
#include "CARRIER.h"
#include "KEYGAME.h"
#include "Slider.h"
#include "Spin.h"
#include "Snake.h"
#include "Baseball.h"
#include "Last.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define HP_TIMER 1
#define CAPTION_TIMER 2
#define delay 3
#define err 10

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_SETCURSOR()
//ON_WM_SIZE()
END_MESSAGE_MAP()


// CMFCApplication12Dlg 대화 상자



CMFCApplication12Dlg::CMFCApplication12Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION12_DIALOG, pParent)
	, m_cursor(false)
	, m_item1_afxcheck(FALSE)
	, m_item3_afxcheck(FALSE)
	, m_item4_afxcheck(FALSE)
	, m_item6_afxcheck(FALSE)
	, HPTimerRun(false)
	, drink(0)
	, m_item2_afxcheck(FALSE)
	, m_longrope(false)
	, CaptionOnGo(false)
	, replay(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication12Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BUTTON1, m_bag);
	DDX_Control(pDX, IDC_BUTTON_BALL, m_ball);
	//  DDX_Control(pDX, IDC_BUTTON4, m_newspaper);
	//DDX_Control(pDX, IDC_BUTTON3, m_door);
	DDX_Control(pDX, IDC_BUTTON11, m_frame);
	DDX_Control(pDX, IDC_BUTTON_SLIDER, m_lock);
	DDX_Control(pDX, IDC_BUTTON_ROPE, m_rope);
	DDX_Control(pDX, IDC_BUTTON_BAND, m_case2);
	DDX_Control(pDX, IDC_BUTTON_LIGHT, m_case1);
	DDX_Control(pDX, IDC_BUTTON_VENTILATOR, m_ventilater);
	DDX_Control(pDX, IDC_BUTTON_LONGROPE, m_gori);
	DDX_Control(pDX, IDC_BUTTON_SPIN, m_mon);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_BUTTON2, m_water);
	DDX_Control(pDX, IDC_BUTTON_COMPUTER, m_computer);
	DDX_Control(pDX, IDC_BUTTON_CARRIER, m_carrierpicture);
}

BEGIN_MESSAGE_MAP(CMFCApplication12Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication12Dlg::OnBnClickedButton1)
	ON_WM_SETCURSOR()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_BALL, &CMFCApplication12Dlg::OnBnClickedButtonBall)
//	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication12Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_CARRIER, &CMFCApplication12Dlg::OnBnClickedButtonCarrier)

	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication12Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON_SLIDER, &CMFCApplication12Dlg::OnClickedButtonSlider)
	ON_BN_CLICKED(IDC_BUTTON_SPIN, &CMFCApplication12Dlg::OnClickedButtonSpin)
	ON_BN_CLICKED(IDC_BUTTON_BAND, &CMFCApplication12Dlg::OnClickedButtonBand)
	ON_BN_CLICKED(IDC_BUTTON_ROPE, &CMFCApplication12Dlg::OnClickedButtonRope)
	ON_BN_CLICKED(IDC_BUTTON_LONGROPE, &CMFCApplication12Dlg::OnClickedButtonLongrope)
	ON_BN_CLICKED(IDC_BUTTON_VENTILATOR, &CMFCApplication12Dlg::OnClickedButtonVentilator)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication12Dlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_LIGHT, &CMFCApplication12Dlg::OnClickedButtonLight)
	ON_BN_CLICKED(IDC_BUTTON_COMPUTER, &CMFCApplication12Dlg::OnClickedButtonComputer)
END_MESSAGE_MAP()


// CMFCApplication12Dlg 메시지 처리기

BOOL CMFCApplication12Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.


	m_ball.LoadBitmaps(IDB_BITMAP1, NULL, NULL, NULL);
	m_ball.SizeToContent();
	m_frame.LoadBitmaps(IDB_BITMAP_FRAME1_0, NULL, NULL, NULL);
	m_frame.SizeToContent();
	m_lock.LoadBitmaps(IDB_BITMAP_LOCK_CLOSE, NULL, NULL, NULL);
	m_lock.SizeToContent();
	m_rope.LoadBitmaps(IDB_BITMAP_ROPE, NULL, NULL, NULL);
	m_rope.SizeToContent();
	m_case1.LoadBitmaps(IDB_BITMAP_CASECLOSE, NULL, NULL, NULL);
	m_case1.SizeToContent();
	m_case2.LoadBitmaps(IDB_BITMAP_OPEN, NULL, NULL, NULL);
	m_case2.SizeToContent();
	m_ventilater.LoadBitmaps(IDB_BITMAP_VENTB, NULL, NULL, NULL);
	m_ventilater.SizeToContent();
	m_gori.LoadBitmaps(IDB_BITMAP_GORI, NULL, NULL, NULL);
	m_gori.SizeToContent();
	m_mon.LoadBitmaps(IDB_BITMAP_DOORCLOSE, NULL, NULL, NULL);
	m_mon.SizeToContent();
	m_water.LoadBitmaps(IDB_BITMAP_WATER, NULL, NULL, NULL);
	m_water.SizeToContent();
	m_computer.LoadBitmaps(IDB_BITMAP_COMPUTER, NULL, NULL, NULL);
	m_computer.SizeToContent();
	m_carrierpicture.LoadBitmaps(IDB_BITMAP_CARRIER, NULL, NULL, NULL);
	m_carrierpicture.SizeToContent();
	drink = 100;
	m_progress.SetRange(0, drink);
	m_progress.SetPos(drink);
	for (int i = 0; i < 4; i++) {
		oldcheck[i] = false;
		newcheck[i] = false;
	}
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication12Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication12Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	CDC MemDC;
	BITMAP bmpInfo;
	CRect rc;

	// 화면 DC와 호환되는 메모리 DC를 생성
	this->GetClientRect(rc);
	MemDC.CreateCompatibleDC(&dc);

	// 비트맵 리소스 로딩
	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_BITMAP_BACKGROUND);

	// 로딩된 비트맵 정보 확인
	bmp.GetBitmap(&bmpInfo);

	// 메모리 DC에 선택
	pOldBmp = MemDC.SelectObject(&bmp);

	// 메모리 DC에 들어 있는 비트맵을 화면 DC로 복사하여 출력
	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);


	dc.StretchBlt(0, 0, rc.Width(), rc.Height(), &MemDC, 0, 0, (int)bmpInfo.bmWidth,

		(int)bmpInfo.bmHeight, SRCCOPY);


	MemDC.SelectObject(pOldBmp);
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication12Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMFCApplication12Dlg::OnBnClickedButton1()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	CBag * m_bag;
//	m_bag = new CBag;
//	m_bag->Create(IDD_DIALOG_BAG, this);
//	m_bag->ShowWindow(SW_SHOW);
//}


BOOL CMFCApplication12Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_cursor)
	{
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
		return TRUE;
	}
	else {
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
		return TRUE;
	}
	
	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}


void CMFCApplication12Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	for (int i = 0; i <= 6; i++) {
		m_selectitem[i] = false;
	}
	m_cursor = false;

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMFCApplication12Dlg::OnBnClickedButtonBall()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BUTTON_BALL)->ShowWindow(FALSE);
	m_item1_afxcheck = TRUE;
	if (oldcheck[0] == false) caption.Format(_T("지우개를 찾았다"));
	else caption.Format(_T("아무것도 없는것같다"));
	oldcheck[0] = true;
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


//void CMFCApplication12Dlg::OnBnClickedButton4()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	CNewspaper * m_newspaper;
//	m_newspaper = new CNewspaper;
//	m_newspaper->Create(IDD_DIALOG_NEWSPAPER, this);
//	m_newspaper->ShowWindow(SW_SHOW);
//}



void CMFCApplication12Dlg::OnBnClickedButtonCarrier()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCARRIER carrier1;
	carrier1.DoModal();
}


void CMFCApplication12Dlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_item1_afxcheck ==true &&m_cursor == true&& m_selectitem[1] == true) {
		//지혜 클래스로 만들어서 DoModal();
		CKEYGAME game1;
		game1.DoModal();
	}
}


void CMFCApplication12Dlg::OnClickedButtonSlider()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSlider slider;
	slider.DoModal();
	newcheck[3] = true;
	if (oldcheck[3] == true) caption.Format(_T("아무것도 없는것같다"));
	oldcheck[3] = newcheck[3];
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


void CMFCApplication12Dlg::OnClickedButtonSpin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSpin spin;
	spin.DoModal();
}


void CMFCApplication12Dlg::OnClickedButtonBand()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_item4_afxcheck = TRUE;
	m_case2.LoadBitmaps(IDB_BITMAP_CLOSE, NULL, NULL, NULL);
	m_case2.SizeToContent();
	if (oldcheck[1] == false) caption.Format(_T("테이프를 찾았다"));
	else caption.Format(_T("아무것도 없는것같다"));
	oldcheck[1] = true;
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


void CMFCApplication12Dlg::OnClickedButtonRope()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (m_cursor == true && m_item4_afxcheck == TRUE && m_selectitem[4] == true) {
		CSnake snake;
		snake.DoModal();
	}
}


void CMFCApplication12Dlg::OnClickedButtonLongrope()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_cursor == true && m_item6_afxcheck == TRUE && m_selectitem[6] == true) {
		m_gori.LoadBitmaps(IDB_BITMAP_LASTROPE, NULL, NULL, NULL);
		m_gori.SizeToContent();
		m_longrope = true;
	}
}


void CMFCApplication12Dlg::OnClickedButtonVentilator()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_cursor == true && m_item2_afxcheck == TRUE && m_selectitem[2] == true&& m_longrope == true) {
		CLast last;
		last.DoModal();
	}
}


void CMFCApplication12Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	drink += 30;
	if (drink > 100)
		drink = 100;
	m_progress.SetPos(drink);
}


void CMFCApplication12Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (nIDEvent == HP_TIMER) {
		if (HPTimerRun) {
			if (drink >= 0) {
				drink -= 2;
				m_progress.SetPos(drink);
			}
			else {
				AfxMessageBox(_T("물을 먹어주세요"));
				drink += 6;
			}
		}
	}
	else if (nIDEvent == CAPTION_TIMER) {
		if (CaptionOnGo) {
			GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
			SetDlgItemText(IDC_EDIT4, caption);
			replay++;
			if (replay == delay*err) 
				CaptionOnGo = false;
		}
		if (!CaptionOnGo) {
			KillTimer(CAPTION_TIMER);
			GetDlgItem(IDC_EDIT4)->ShowWindow(FALSE);
			SetDlgItemText(IDC_EDIT4, _T(" "));
			replay = 0;
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


int CMFCApplication12Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	HPTimerRun = true;
	SetTimer(HP_TIMER, 1000, NULL);

	return 0;
}


void CMFCApplication12Dlg::OnClickedButtonLight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_cursor == true && m_item3_afxcheck == TRUE&& m_selectitem[3] == true ) {
		m_case1.LoadBitmaps(IDB_BITMAP_CASEOPEN, NULL, NULL, NULL);
		m_case1.SizeToContent();
		m_item2_afxcheck = true;
	};
	newcheck[0] = true;
	if (oldcheck[0] == false)
		if(m_selectitem[3] == false) caption.Format(_T("잠겨있다"));
		else caption.Format(_T("손전등을 찾았다"));
	else if (oldcheck[0] == true) caption.Format(_T("아무것도 없는것같다"));
	oldcheck[2] = newcheck[2];
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


void CMFCApplication12Dlg::OnClickedButtonComputer()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CBaseball baseball;
	baseball.DoModal();
}


BOOL CMFCApplication12Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_SPACE)) {
		if (CaptionOnGo == true) CaptionOnGo = false;
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}