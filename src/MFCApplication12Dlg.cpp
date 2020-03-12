
// MFCApplication12Dlg.cpp : ���� ����
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

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFCApplication12Dlg ��ȭ ����



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


// CMFCApplication12Dlg �޽��� ó����

BOOL CMFCApplication12Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.


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
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApplication12Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	CDC MemDC;
	BITMAP bmpInfo;
	CRect rc;

	// ȭ�� DC�� ȣȯ�Ǵ� �޸� DC�� ����
	this->GetClientRect(rc);
	MemDC.CreateCompatibleDC(&dc);

	// ��Ʈ�� ���ҽ� �ε�
	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_BITMAP_BACKGROUND);

	// �ε��� ��Ʈ�� ���� Ȯ��
	bmp.GetBitmap(&bmpInfo);

	// �޸� DC�� ����
	pOldBmp = MemDC.SelectObject(&bmp);

	// �޸� DC�� ��� �ִ� ��Ʈ���� ȭ�� DC�� �����Ͽ� ���
	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);


	dc.StretchBlt(0, 0, rc.Width(), rc.Height(), &MemDC, 0, 0, (int)bmpInfo.bmWidth,

		(int)bmpInfo.bmHeight, SRCCOPY);


	MemDC.SelectObject(pOldBmp);
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCApplication12Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMFCApplication12Dlg::OnBnClickedButton1()
//{
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	CBag * m_bag;
//	m_bag = new CBag;
//	m_bag->Create(IDD_DIALOG_BAG, this);
//	m_bag->ShowWindow(SW_SHOW);
//}


BOOL CMFCApplication12Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	for (int i = 0; i <= 6; i++) {
		m_selectitem[i] = false;
	}
	m_cursor = false;

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMFCApplication12Dlg::OnBnClickedButtonBall()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItem(IDC_BUTTON_BALL)->ShowWindow(FALSE);
	m_item1_afxcheck = TRUE;
	if (oldcheck[0] == false) caption.Format(_T("���찳�� ã�Ҵ�"));
	else caption.Format(_T("�ƹ��͵� ���°Ͱ���"));
	oldcheck[0] = true;
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


//void CMFCApplication12Dlg::OnBnClickedButton4()
//{
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	CNewspaper * m_newspaper;
//	m_newspaper = new CNewspaper;
//	m_newspaper->Create(IDD_DIALOG_NEWSPAPER, this);
//	m_newspaper->ShowWindow(SW_SHOW);
//}



void CMFCApplication12Dlg::OnBnClickedButtonCarrier()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CCARRIER carrier1;
	carrier1.DoModal();
}


void CMFCApplication12Dlg::OnBnClickedButton11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_item1_afxcheck ==true &&m_cursor == true&& m_selectitem[1] == true) {
		//���� Ŭ������ ���� DoModal();
		CKEYGAME game1;
		game1.DoModal();
	}
}


void CMFCApplication12Dlg::OnClickedButtonSlider()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CSlider slider;
	slider.DoModal();
	newcheck[3] = true;
	if (oldcheck[3] == true) caption.Format(_T("�ƹ��͵� ���°Ͱ���"));
	oldcheck[3] = newcheck[3];
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


void CMFCApplication12Dlg::OnClickedButtonSpin()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CSpin spin;
	spin.DoModal();
}


void CMFCApplication12Dlg::OnClickedButtonBand()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_item4_afxcheck = TRUE;
	m_case2.LoadBitmaps(IDB_BITMAP_CLOSE, NULL, NULL, NULL);
	m_case2.SizeToContent();
	if (oldcheck[1] == false) caption.Format(_T("�������� ã�Ҵ�"));
	else caption.Format(_T("�ƹ��͵� ���°Ͱ���"));
	oldcheck[1] = true;
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


void CMFCApplication12Dlg::OnClickedButtonRope()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	if (m_cursor == true && m_item4_afxcheck == TRUE && m_selectitem[4] == true) {
		CSnake snake;
		snake.DoModal();
	}
}


void CMFCApplication12Dlg::OnClickedButtonLongrope()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_cursor == true && m_item6_afxcheck == TRUE && m_selectitem[6] == true) {
		m_gori.LoadBitmaps(IDB_BITMAP_LASTROPE, NULL, NULL, NULL);
		m_gori.SizeToContent();
		m_longrope = true;
	}
}


void CMFCApplication12Dlg::OnClickedButtonVentilator()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_cursor == true && m_item2_afxcheck == TRUE && m_selectitem[2] == true&& m_longrope == true) {
		CLast last;
		last.DoModal();
	}
}


void CMFCApplication12Dlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	drink += 30;
	if (drink > 100)
		drink = 100;
	m_progress.SetPos(drink);
}


void CMFCApplication12Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	if (nIDEvent == HP_TIMER) {
		if (HPTimerRun) {
			if (drink >= 0) {
				drink -= 2;
				m_progress.SetPos(drink);
			}
			else {
				AfxMessageBox(_T("���� �Ծ��ּ���"));
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

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	HPTimerRun = true;
	SetTimer(HP_TIMER, 1000, NULL);

	return 0;
}


void CMFCApplication12Dlg::OnClickedButtonLight()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_cursor == true && m_item3_afxcheck == TRUE&& m_selectitem[3] == true ) {
		m_case1.LoadBitmaps(IDB_BITMAP_CASEOPEN, NULL, NULL, NULL);
		m_case1.SizeToContent();
		m_item2_afxcheck = true;
	};
	newcheck[0] = true;
	if (oldcheck[0] == false)
		if(m_selectitem[3] == false) caption.Format(_T("����ִ�"));
		else caption.Format(_T("�������� ã�Ҵ�"));
	else if (oldcheck[0] == true) caption.Format(_T("�ƹ��͵� ���°Ͱ���"));
	oldcheck[2] = newcheck[2];
	CaptionOnGo = true;
	SetTimer(CAPTION_TIMER, 1000 / err, NULL);
}


void CMFCApplication12Dlg::OnClickedButtonComputer()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CBaseball baseball;
	baseball.DoModal();
}


BOOL CMFCApplication12Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_SPACE)) {
		if (CaptionOnGo == true) CaptionOnGo = false;
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}