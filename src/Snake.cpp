// Snake.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Snake.h"
#include "afxdialogex.h"
#include "SnakeGamesCtrl.h"
#include "MFCApplication12Dlg.h"
//static BODY *g_SnakeHead = NULL; 
//static BODY g_Body;					  // 뱀 리스트 머릿 부분과, 몸통.
//static BLOCK g_Field[FILED_HEIGHT][FILED_WIDTH];	  // 화면에 보여질 필드
//static int g_speed = 400;							//  이동 속도
//static int g_GetBody = 0;							// 몸통 먹은 갯수


// CSnake 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSnake, CDialogEx)

CSnake::CSnake(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SNAKE, pParent)
	, g_SnakeHead(NULL)
	, g_speed(400)
	, g_GetBody(0)
{

}

CSnake::~CSnake()
{
}

void CSnake::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSnake, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSnake 메시지 처리기입니다.


void CSnake::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	DrawGameView();
	
}



void CSnake::DrawGameView()
{
	CPaintDC dc(this);

	int i, j, StrLen;
	CDC      dcBuffer;
	RECT   rcClient;
	CBitmap bitBuffer;
	HBRUSH   hBrush, oldBrush;
	wchar_t Str[50];

	GetClientRect(&rcClient);
	dcBuffer.CreateCompatibleDC(&dc);
	bitBuffer.CreateCompatibleBitmap(&dc, rcClient.right, rcClient.bottom);
	dcBuffer.SelectObject(bitBuffer);

	dcBuffer.Rectangle(0, 0, rcClient.right, rcClient.bottom);

	for (i = 0; i < FILED_HEIGHT; i++)
	{
		for (j = 0; j < FILED_WIDTH; j++)
		{
			switch (g_Field[i][j])
			{
				// 추가 몸통 그리기
			case BLOCK_Body:
				hBrush = CreateSolidBrush(RGB(255, 255, 0));
				oldBrush = (HBRUSH)SelectObject(dcBuffer, hBrush);
				dcBuffer.Rectangle(j * 17, i * 17, j * 17 + 17, i * 17 + 17);
				//dcBuffer.Draw3dRect(j * 17, i * 17, j * 17 + 17, i * 17 + 17, RGB(255, 255, 255), RGB(160, 160, 160));
				dcBuffer.SelectObject(oldBrush);
				DeleteObject(hBrush);
				break;

				// 벽 그리기
			case BLOCK_WALL:
				hBrush = CreateSolidBrush(RGB(50, 50, 50));
				oldBrush = (HBRUSH)SelectObject(dcBuffer, hBrush);
				dcBuffer.Rectangle(j * 17, i * 17, j * 17 + 17, i * 17 + 17);
				dcBuffer.SelectObject(oldBrush);
				DeleteObject(hBrush);
				break;

				// 뱀 몸통 그리기
			case BLOCK_SNAKE:
				hBrush = CreateSolidBrush(RGB(50, 200, 50));
				oldBrush = (HBRUSH)SelectObject(dcBuffer, hBrush);
				dcBuffer.Rectangle(j * 17, i * 17, j * 17 + 17, i * 17 + 17);
				dcBuffer.SelectObject(oldBrush);
				DeleteObject(hBrush);
				break;

			}
		}
	}

	dcBuffer.SetBkMode(TRANSPARENT);

	StrLen = wsprintf(Str, L"길이 : %d", g_GetBody + 3);      // 3은 기본 몸통 길이
												  //StrLen = wsprintf(Str, L"현재 길이 : %d", g_GetBody + 3);      // 3은 기본 몸통 길이
	dcBuffer.SetTextColor(RGB(150, 50, 150));
	dcBuffer.TextOut(10, i * 17, Str, StrLen);


	StrLen = wsprintf(Str, L"이동 속도 : %d ms", g_speed);
	dcBuffer.SetTextColor(RGB(50, 50, 255));
	dcBuffer.TextOut(150, i * 17, Str, StrLen);

	dcBuffer.SetTextColor(RGB(0, 0, 0));

	dc.BitBlt(0, 0, rcClient.right, rcClient.bottom, &dcBuffer, 0, 0, SRCCOPY);
	CMFCApplication12Dlg* pMain = (CMFCApplication12Dlg*)GetParent();

	dcBuffer.DeleteDC();
	bitBuffer.DeleteObject();
	if (g_GetBody > 5)	//바꿔야함
	{
		KillTimer(1);
		MessageBox(L":: 밧줄을 얻었다 ::", L"Clear", MB_OK);
		//GetDlgItem(IDC_BUTTON_SNAKEROPE)->ShowWindow(TRUE);
		//SendMessage(WM_DESTROY, NULL, NULL);

		pMain->m_item6_afxcheck = TRUE;

		pMain->GetDlgItem(IDC_BUTTON_ROPE)->ShowWindow(false);

		EndDialog(IDD_DIALOG_SNAKE);

	}
}

// 벽 및 몸통과 충돌 체크
BOOL CSnake::Check()
{
	if (HitBody(g_SnakeHead) || HitWall(g_SnakeHead))
	{
		return FALSE;
	}

	if (EatBody(&g_SnakeHead, &g_Body))
	{
		g_GetBody++;
		if (g_speed > 50) g_speed -= 20;      // 이동 속도 증가

		KillTimer(1);
		SetTimer(1, g_speed, NULL);

	}

	RenewField(g_Field, g_SnakeHead, &g_Body);

	return TRUE;
}


void CSnake::InitGame()
{
	// 기본적인 몸통 구성.
	CreateSnake(&g_SnakeHead, 2);

	// 시작위치 무작위 지정
	g_Body.x = rand() % (FILED_WIDTH - 4) + 2;
	g_Body.y = rand() % (FILED_HEIGHT - 4) + 2;

	RenewField(g_Field, g_SnakeHead, &g_Body);

	// 먹은 몸통 갯수
	g_GetBody = 0;
	g_speed = 400;
	Invalidate();
}


void CSnake::EndGame()
{
	DeleteSnake(&g_SnakeHead);
}


int CSnake::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	MessageBox(L"뱀게임을 통해,\n밧줄을 엮어보자.",L"뱀꼬리물기 :: 게임 설명", MB_OK);

	SetTimer(1, g_speed, NULL);
	InitGame();

	return 0;
}


void CSnake::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	EndGame();
}


void CSnake::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	MoveSnake(nChar, g_SnakeHead);
	

	if (Check() == FALSE)
	{
		KillTimer(1);
		MessageBox(L":: 게임 오버 ::", L"Game Over", MB_OK);

		EndGame();
		InitGame();

		SetTimer(1, g_speed, NULL);
	}

	InvalidateRgn(NULL, FALSE);

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CSnake::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	UINT keyInput = 0;

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			return true;
			break;
		case VK_ESCAPE:
			return true;
			break;
		case VK_LEFT:
			keyInput = VK_LEFT;
			break;
		case VK_RIGHT:
			keyInput = VK_RIGHT;
			break;
		case VK_UP:
			keyInput = VK_UP;
			break;
		case VK_DOWN:
			keyInput = VK_DOWN;
			break;
		}
		/*
		VK_LEFT     0x25
		VK_UP      0x26
		VK_RIGHT    0x27
		VK_DOWN     0x28
		*/
		// 현재 방향에서 곧바로 반대방향 회전 불가.
		if (g_SnakeHead->direction - keyInput != 0x02 && g_SnakeHead->direction - keyInput != -0x02)
		{
			MoveSnake(keyInput, g_SnakeHead);
			Check();
			InvalidateRgn(NULL, FALSE);
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CSnake::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SendMessage(WM_KEYDOWN, NULL, NULL);

	CDialogEx::OnTimer(nIDEvent);
}
