// Last.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Last.h"
#include "afxdialogex.h"


// CLast 대화 상자입니다.

IMPLEMENT_DYNAMIC(CLast, CDialogEx)

CLast::CLast(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CLast::~CLast()
{
}

void CLast::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLast, CDialogEx)
END_MESSAGE_MAP()


// CLast 메시지 처리기입니다.
