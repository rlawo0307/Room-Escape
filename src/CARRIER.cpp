// CARRIER.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication12.h"
#include "CARRIER.h"
#include "afxdialogex.h"
#include "MFCApplication12Dlg.h"


// CCARRIER 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCARRIER, CDialogEx)

CCARRIER::CCARRIER(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CARRIER, pParent)

	, m_item1_check(FALSE)
	, pMainDlg(NULL)
	, m_cursor(false)
	, m_item2_check(FALSE)
	, m_item3_check(FALSE)
	, m_item4_check(FALSE)
	, m_item6_check(FALSE)
{

}

CCARRIER::~CCARRIER()
{
}

void CCARRIER::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_ITEM1, m_item1);
	DDX_Control(pDX, IDC_BUTTON_ITEM2, m_item2);
	DDX_Control(pDX, IDC_BUTTON_ITEM3, m_item3);
	DDX_Control(pDX, IDC_BUTTON_ITEM4, m_item4);
	DDX_Control(pDX, IDC_BUTTON_ITEM5, m_item5);
	DDX_Control(pDX, IDC_BUTTON_ITEM6, m_item6);
	DDX_Control(pDX, IDC_BUTTON_ITEM7, m_item7);
	DDX_Control(pDX, IDC_BUTTON_ITEM8, m_item8);
	DDX_Control(pDX, IDC_BUTTON_ITEM9, m_item9);
	DDX_Control(pDX, IDC_BUTTON_ITEM10, m_item10);
	DDX_Control(pDX, IDC_BUTTON_ITEM11, m_item11);
	DDX_Control(pDX, IDC_BUTTON_ITEM12, m_item12);
	DDX_Control(pDX, IDC_BUTTON_ITEM13, m_item13);
	DDX_Control(pDX, IDC_BUTTON_ITEM14, m_item14);
	DDX_Control(pDX, IDC_BUTTON_ITEM15, m_item15);


}

BEGIN_MESSAGE_MAP(CCARRIER, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ITEM1, &CCARRIER::OnBnClickedButtonItem1)
	ON_BN_CLICKED(IDC_BUTTON_USE, &CCARRIER::OnBnClickedButtonUse)
	ON_BN_CLICKED(IDC_BUTTON_ITEM2, &CCARRIER::OnClickedButtonItem2)
	ON_BN_CLICKED(IDC_BUTTON_ITEM3, &CCARRIER::OnClickedButtonItem3)
	ON_BN_CLICKED(IDC_BUTTON_ITEM4, &CCARRIER::OnClickedButtonItem4)
	ON_BN_CLICKED(IDC_BUTTON_ITEM6, &CCARRIER::OnClickedButtonItem6)
END_MESSAGE_MAP()


// CCARRIER 메시지 처리기입니다.


BOOL CCARRIER::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pMainDlg = (CMFCApplication12Dlg*)GetParent();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_item1.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item1.SizeToContent();
	m_item2.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item2.SizeToContent();
	m_item3.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item3.SizeToContent();
	m_item4.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item4.SizeToContent();
	m_item5.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item5.SizeToContent();
	m_item6.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item6.SizeToContent();
	m_item7.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item7.SizeToContent();
	m_item8.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item8.SizeToContent();
	m_item9.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item9.SizeToContent();
	m_item10.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item10.SizeToContent();
	m_item11.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item11.SizeToContent();
	m_item12.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item12.SizeToContent();
	m_item13.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item13.SizeToContent();
	m_item14.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item14.SizeToContent();
	m_item15.LoadBitmaps(IDB_BITMAP_ITEM_EMPTY, NULL, NULL, NULL);
	m_item15.SizeToContent();
	if (pMainDlg->m_item1_afxcheck == true) {
		m_item1.LoadBitmaps(IDB_BITMAP_ITEM1_0, NULL, NULL, NULL);
		m_item1.SizeToContent();
	}
	if (pMainDlg->m_item2_afxcheck == true) {
		m_item2.LoadBitmaps(IDB_BITMAP_ITEM2_0, NULL, NULL, NULL);
		m_item2.SizeToContent();
	}
	if (pMainDlg->m_item3_afxcheck == true) {
		m_item3.LoadBitmaps(IDB_BITMAP_ITEM3_0, NULL, NULL, NULL);
		m_item3.SizeToContent();
	}
	if (pMainDlg->m_item4_afxcheck == true) {
		m_item4.LoadBitmaps(IDB_BITMAP_ITEM4_0, NULL, NULL, NULL);
		m_item4.SizeToContent();
	}
	if (pMainDlg->m_item6_afxcheck == true) {
		m_item6.LoadBitmaps(IDB_BITMAP_ITEM6_0, NULL, NULL, NULL);
		m_item6.SizeToContent();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CCARRIER::OnBnClickedButtonUse()
{
	CMFCApplication12Dlg* m_MainDlg = (CMFCApplication12Dlg*)GetParent();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int a = 0;
	if (pMainDlg->m_item1_afxcheck == true) {
		if (m_item1_check == true) {
			//커서 바꾸는 부분
			m_MainDlg->m_cursor = true;
			m_cursor = true;
			EndDialog(IDC_BUTTON_USE);
			m_MainDlg->m_selectitem[1] = true;
			a++;
		}
	}
	if (pMainDlg->m_item2_afxcheck == true) {
		if (m_item2_check == true) {
			//커서 바꾸는 부분
			m_MainDlg->m_cursor = true;
			m_cursor = true;
			EndDialog(IDC_BUTTON_USE);
			m_MainDlg->m_selectitem[2] = true;
			a++;
		}
	}
	if (pMainDlg->m_item3_afxcheck == true) {
		if (m_item3_check == true) {
			//커서 바꾸는 부분
			m_MainDlg->m_cursor = true;
			m_cursor = true;
			EndDialog(IDC_BUTTON_USE);
			m_MainDlg->m_selectitem[3] = true;
			a++;
		}
	}
	if (pMainDlg->m_item4_afxcheck == true) {
		if (m_item4_check == true) {
			//커서 바꾸는 부분
			m_MainDlg->m_cursor = true;
			m_cursor = true;
			EndDialog(IDC_BUTTON_USE);
			m_MainDlg->m_selectitem[4] = true;
			a++;
		}
	}
	if (pMainDlg->m_item6_afxcheck == true) {
		if (m_item6_check == true) {
			//커서 바꾸는 부분
			m_MainDlg->m_cursor = true;
			m_cursor = true;
			EndDialog(IDC_BUTTON_USE);
			m_MainDlg->m_selectitem[6] = true;
			a++;
		}
	}
	if(a==0){
		AfxMessageBox(_T("아이템을 선택해주세요"));
	}
}

void CCARRIER::OnBnClickedButtonItem1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pMainDlg->m_item1_afxcheck == true) {
		if (m_item1_check == false) {
			m_item1.LoadBitmaps(IDB_BITMAP_ITEM1_1, NULL, NULL, NULL);
			m_item1.SizeToContent();
			m_item1_check = !m_item1_check;
		}
		else if (m_item1_check == true) {
			m_item1.LoadBitmaps(IDB_BITMAP_ITEM1_0, NULL, NULL, NULL);
			m_item1.SizeToContent();
			m_item1_check = !m_item1_check;
		}
	}
}





void CCARRIER::OnClickedButtonItem2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
		if (m_item2_check == false) {
			m_item2.LoadBitmaps(IDB_BITMAP_ITEM2_1, NULL, NULL, NULL);
			m_item2.SizeToContent();
			m_item2_check = !m_item2_check;
		}
		else if (m_item2_check == true) {
			m_item2.LoadBitmaps(IDB_BITMAP_ITEM2_0, NULL, NULL, NULL);
			m_item2.SizeToContent();
			m_item2_check = !m_item2_check;
		}


}


void CCARRIER::OnClickedButtonItem3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pMainDlg->m_item3_afxcheck == true) {
		if (m_item3_check == false) {
			m_item3.LoadBitmaps(IDB_BITMAP_ITEM3_1, NULL, NULL, NULL);
			m_item3.SizeToContent();
			m_item3_check = !m_item3_check;
		}
		else if (m_item3_check == true) {
			m_item3.LoadBitmaps(IDB_BITMAP_ITEM3_0, NULL, NULL, NULL);
			m_item3.SizeToContent();
			m_item3_check = !m_item3_check;
		}
	}
}


void CCARRIER::OnClickedButtonItem4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(pMainDlg->m_item4_afxcheck == true) {
		if (m_item4_check == false) {
			m_item4.LoadBitmaps(IDB_BITMAP_ITEM4_1, NULL, NULL, NULL);
			m_item4.SizeToContent();
			m_item4_check = !m_item4_check;
		}
		else if (m_item4_check == true) {
			m_item4.LoadBitmaps(IDB_BITMAP_ITEM4_0, NULL, NULL, NULL);
			m_item4.SizeToContent();
			m_item4_check = !m_item4_check;
		}
	}
}


void CCARRIER::OnClickedButtonItem6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pMainDlg->m_item6_afxcheck == true) {
		if (m_item6_check == false) {
			m_item6.LoadBitmaps(IDB_BITMAP_ITEM6_1, NULL, NULL, NULL);
			m_item6.SizeToContent();
			m_item6_check = !m_item6_check;
		}
		else if (m_item6_check == true) {
			m_item6.LoadBitmaps(IDB_BITMAP_ITEM6_0, NULL, NULL, NULL);
			m_item6.SizeToContent();
			m_item6_check = !m_item6_check;
		}
	}
}
