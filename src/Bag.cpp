// Bag.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Bag.h"
#include "afxdialogex.h"
#include "MFCApplication12Dlg.h"


// CBag 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBag, CDialogEx)

CBag::CBag(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_BAG, pParent)
{

}

CBag::~CBag()
{
}

void CBag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBag, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CBag::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBag 메시지 처리기입니다.


void CBag::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCApplication12Dlg * m_dlg;
	m_dlg= (CMFCApplication12Dlg *)::AfxGetMainWnd();
	m_dlg->m_cursor = true;
}
