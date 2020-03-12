// KEYGAME.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "KEYGAME.h"
#include "afxdialogex.h"
#include "time.h"
#include "MFCApplication12Dlg.h"

// CKEYGAME ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CKEYGAME, CDialogEx)

CKEYGAME::CKEYGAME(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_KEYGAME, pParent)
	, m_game(0)
	, m_ptClientSize(0)
	, timer(0)
	, keynum(0)
	, success(0)
{

}

CKEYGAME::~CKEYGAME()
{
}

void CKEYGAME::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKEYGAME, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CKEYGAME::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CKEYGAME::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CKEYGAME::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_HINT, &CKEYGAME::OnBnClickedButtonHint)
END_MESSAGE_MAP()


// CKEYGAME �޽��� ó�����Դϴ�.


void CKEYGAME::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	if (m_game == 1 || m_game == 4 || m_game == 5) { // ������ �������� ��
		if (keynum == 0 || keynum == 7) {
			GetDlgItem(IDC_COMMAND1)->ShowWindow(TRUE);
			GetDlgItem(IDC_COMMAND2)->ShowWindow(TRUE);
			GetDlgItem(IDC_COMMAND3)->ShowWindow(TRUE);
			GetDlgItem(IDC_COMMAND4)->ShowWindow(TRUE);
			GetDlgItem(IDC_COMMAND5)->ShowWindow(TRUE);
			GetDlgItem(IDC_COMMAND6)->ShowWindow(TRUE);
			GetDlgItem(IDC_COMMAND7)->ShowWindow(TRUE);
		}
		else if (keynum == 1) GetDlgItem(IDC_COMMAND1)->ShowWindow(FALSE);
		else if (keynum == 2) GetDlgItem(IDC_COMMAND2)->ShowWindow(FALSE);
		else if (keynum == 3) GetDlgItem(IDC_COMMAND3)->ShowWindow(FALSE);
		else if (keynum == 4) GetDlgItem(IDC_COMMAND4)->ShowWindow(FALSE);
		else if (keynum == 5) GetDlgItem(IDC_COMMAND5)->ShowWindow(FALSE);
		else if (keynum == 6) GetDlgItem(IDC_COMMAND6)->ShowWindow(FALSE);
	}
	else if (m_game == 2) { // ����Ŭ����
		GetDlgItem(IDC_COMMAND1)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMMAND2)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMMAND3)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMMAND4)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMMAND5)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMMAND6)->ShowWindow(FALSE);
		GetDlgItem(IDC_COMMAND7)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_HINT)->ShowWindow(TRUE);

		CString str;
		str.Format(_T("���� ����! �ɸ� �ð��� %d �� �Դϴ�"), record);
		SetDlgItemText(IDC_EDIT_CAPTION, str);
		SetDlgItemText(IDC_BUTTON3, _T("�ٽ��ϱ�"));
	}
	else if (m_game == 3) { // ���ӽ���
		CString str;
		str.Format(_T("���� ����! 15�ʰ� �������ϴ�~~"));
		SetDlgItemText(IDC_EDIT_CAPTION, str);
		SetDlgItemText(IDC_EDIT1, _T(""));
		SetDlgItemText(IDC_EDIT2, _T(""));
		SetDlgItemText(IDC_BUTTON3, _T("�ٽ��ϱ�"));
	}
}


void CKEYGAME::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;

	Invalidate();
}


void CKEYGAME::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CString strTime;
	timer = CTime::GetCurrentTime();
	record = timer.GetTime() - start;
	strTime.Format(_T("%d ��"), record);
	SetDlgItemText(IDC_EDIT1, strTime);
	if (record > 15) {
		m_game = 3;
		KillTimer(0);
		Invalidate();
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CKEYGAME::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	//CDialogEx::OnCancel();
}


BOOL CKEYGAME::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	GetDlgItem(IDC_COMMAND1)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMMAND2)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMMAND3)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMMAND4)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMMAND5)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMMAND6)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMMAND7)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_HINT)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(FALSE);

	srand(time(NULL));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BOOL CKEYGAME::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) {
		if (m_game == 0)
			SetDlgItemText(IDC_EDIT_CAPTION, _T("���� ������ �������� �ʾҽ��ϴ�"));
		else if (m_game == 1) {
			if (pMsg->wParam == m_KeyInput[keynum]) {
				SetDlgItemText(IDC_EDIT_CAPTION, _T(" "));
				keynum++;
				if (keynum < 7) Invalidate();
				else {
					success++;
					SetDlgItemInt(IDC_EDIT2, success);
					Invalidate();
					keynum = 0;
					random();
				}
			}
			else {
				SetDlgItemText(IDC_EDIT_CAPTION, _T("Ʋ�Ƚ��ϴ�!!"));
				keynum = 0;
				random();
			}
			if (success == 5) {
				KillTimer(0);
				if (record > 15) m_game = 3;
				else m_game = 2;
				Invalidate();
			}
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CKEYGAME::random()
{
	int tmp;
	for (int i = 0; i < 7; i++) {
		tmp = rand() % 4;
		switch (tmp) {
		case 0:
			m_key[i] = "��";
			m_KeyInput[i] = VK_UP;
			break;

		case 1:
			m_key[i] = "��";
			m_KeyInput[i] = VK_DOWN;
			break;

		case 2:
			m_key[i] = "��";
			m_KeyInput[i] = VK_LEFT;
			break;

		case 3:
			m_key[i] = "��";
			m_KeyInput[i] = VK_RIGHT;
			break;
		}
	}
	SetDlgItemText(IDC_COMMAND1, m_key[0]);
	SetDlgItemText(IDC_COMMAND2, m_key[1]);
	SetDlgItemText(IDC_COMMAND3, m_key[2]);
	SetDlgItemText(IDC_COMMAND4, m_key[3]);
	SetDlgItemText(IDC_COMMAND5, m_key[4]);
	SetDlgItemText(IDC_COMMAND6, m_key[5]);
	SetDlgItemText(IDC_COMMAND7, m_key[6]);

	Invalidate();
}


void CKEYGAME::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_game = 1;
	SetDlgItemText(IDC_EDIT_CAPTION, (_T("")));
	SetDlgItemInt(IDC_EDIT2, success);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
	timer = CTime::GetCurrentTime();
	start = timer.GetTime();
	SetTimer(0, 1000, NULL);
	random();
}


void CKEYGAME::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_game = 0;
	keynum = 0;
	success = 0;
	EndDialog(IDC_BUTTON2);
}

void CKEYGAME::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_game = 1;
	keynum = 0;
	success = 0;
	SetDlgItemText(IDC_EDIT_CAPTION, (_T("������ ó������ �ٽ� �����մϴ�")));
	GetDlgItem(IDC_BUTTON_HINT)->ShowWindow(FALSE);
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemInt(IDC_EDIT2, success);
	KillTimer(0);
	timer = CTime::GetCurrentTime();
	start = timer.GetTime();
	SetTimer(0, 1000, NULL);
	random();
}


void CKEYGAME::OnBnClickedButtonHint()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMFCApplication12Dlg *pMain = (CMFCApplication12Dlg*)GetParent();

	pMain -> m_frame.LoadBitmaps(IDB_BITMAP_FRAME1_1, NULL, NULL, NULL);
	pMain -> m_frame.SizeToContent();
	EndDialog(IDC_BUTTON_HINT);

}
