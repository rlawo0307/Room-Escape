// Maker.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Maker.h"
#include "afxdialogex.h"


// CMaker ��ȭ �����Դϴ�.

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


// CMaker �޽��� ó�����Դϴ�.
