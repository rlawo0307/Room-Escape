// Bag.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "Bag.h"
#include "afxdialogex.h"
#include "MFCApplication12Dlg.h"


// CBag ��ȭ �����Դϴ�.

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


// CBag �޽��� ó�����Դϴ�.


void CBag::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMFCApplication12Dlg * m_dlg;
	m_dlg= (CMFCApplication12Dlg *)::AfxGetMainWnd();
	m_dlg->m_cursor = true;
}
