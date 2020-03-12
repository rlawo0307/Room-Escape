// Maker.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Maker.h"
#include "afxdialogex.h"


// CMaker 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMaker, CDialogEx)

CMaker::CMaker(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_MAKER, pParent)
{

}

CMaker::~CMaker()
{
}

void CMaker::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMaker, CDialogEx)
END_MESSAGE_MAP()


// CMaker 메시지 처리기입니다.
