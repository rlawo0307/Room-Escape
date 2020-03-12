#pragma once
#include "SnakeGamesCtrl.h"


// CSnake ��ȭ �����Դϴ�.

class CSnake : public CDialogEx
{
	DECLARE_DYNAMIC(CSnake)

public:
	CSnake(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSnake();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SNAKE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void DrawGameView();
	BOOL Check();
	void InitGame();
	void EndGame();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	struct BODY* g_SnakeHead;
	struct BODY g_Body;
	BLOCK g_Field[FILED_HEIGHT][FILED_WIDTH];
	int g_speed;
	int g_GetBody;
};
