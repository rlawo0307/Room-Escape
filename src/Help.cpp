// Help.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Help.h"
#include "afxdialogex.h"


// CHelp 대화 상자입니다.

IMPLEMENT_DYNAMIC(CHelp, CDialogEx)

CHelp::CHelp(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_HELP, pParent)
{

}

CHelp::~CHelp()
{
}

void CHelp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHelp, CDialogEx)
END_MESSAGE_MAP()


// CHelp 메시지 처리기입니다.
