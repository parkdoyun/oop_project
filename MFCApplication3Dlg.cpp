
// MFCApplication3Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 대화 상자



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
	, m_cal(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	sOR_count = 0;
	calculation_count = 0;
	sSize[5] = { 0 };
	sValue[5] = { 0 };
	num_count = 0;
	sign_count[5] = { 0 };
	point_idx[0] = -1;
	point_idx[1] = -1;
	point_idx[2] = -1;
	point_idx[3] = -1;
	point_idx[4] = -1;
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_cal);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication3Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication3Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication3Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication3Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication3Dlg::OnBnClickedButtonPLUS)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication3Dlg::OnBnClickedButtonEQUAL)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication3Dlg::OnBnClickedButtonMINUS)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication3Dlg::OnBnClickedButtonMULTIPLY)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication3Dlg::OnBnClickedButtonDIVIDE)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 메시지 처리기

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "1";
	EditText(str);
	
	if (sOR_count == 0)
	{
		s[0].push(1);
		sSize[0]++;
	}
	else if(sOR_count == 1)
	{
		s[1].push(1);
		sSize[1]++;
	}
	else if (sOR_count == 2)
	{
		s[2].push(1);
		sSize[2]++;
	}
	else if (sOR_count == 3)
	{
		s[3].push(1);
		sSize[3]++;
	}
	else if (sOR_count == 4)
	{
		s[4].push(1);
		sSize[4]++;
	}
	
}

void CMFCApplication3Dlg::EditText(CString str)
{
	m_cal += str;
	//계산하는 함수
	SetDlgItemText(IDC_EDIT1, m_cal);
}


void CMFCApplication3Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "2";
	EditText(str);

	if (sOR_count == 0)
	{
		s[0].push(2);
		sSize[0]++;
	}
	else if (sOR_count == 1)
	{
		s[1].push(2);
		sSize[1]++;
	}
	else if (sOR_count == 2)
	{
		s[2].push(2);
		sSize[2]++;
	}
	else if (sOR_count == 3)
	{
		s[3].push(2);
		sSize[3]++;
	}
	else if (sOR_count == 4)
	{
		s[4].push(2);
		sSize[4]++;
	}

}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "3";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(3);
			sSize[i]++;
			return;
		}
	}
	
}


void CMFCApplication3Dlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "4";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(4);
			sSize[i]++;
			return;
		}
	}

}


void CMFCApplication3Dlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "5";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(5);
			sSize[i]++;
			return;
		}
	}

}


void CMFCApplication3Dlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "6";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(6);
			sSize[i]++;
			return;
		}
	}

}


void CMFCApplication3Dlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "7";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(7);
			sSize[i]++;
			return;
		}
	}

}


void CMFCApplication3Dlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "8";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(8);
			sSize[i]++;
			return;
		}
	}

}


void CMFCApplication3Dlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "9";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(9);
			sSize[i]++;
			return;
		}
	}

}


void CMFCApplication3Dlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count == 0 && sSize[0] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[1] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[2] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[3] > 4)
	{
		return;
	}
	else if (calculation_count != 0 && sSize[4] > 4)
	{
		return;
	}
	CString str;
	str = "0";
	EditText(str);
	for (int i = 0; i < 5; i++)
	{
		if (sOR_count == i)
		{
			s[i].push(0);
			sSize[i]++;
			return;
		}
	}

}


void CMFCApplication3Dlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_cal = "";
	//계산하는 함수
	SetDlgItemText(IDC_EDIT1, m_cal);
	for (int i = 0; i <= sOR_count; i++)
	{
		for (int j = 0; j <= sSize[i]; j++)
		{
			s[i].s[j] = 0;
		}
		sSize[i] = 0;
		s[i].top = -1;
		sValue[i] = 0;
		point_idx[i] = -1;
		sign_count[i] = 0;
		
	}
	
	
	
	sOR_count = 0;
	
	calculation_count = 0;
}


void CMFCApplication3Dlg::OnBnClickedButton12()//-> 점
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str = ".";
	EditText(str);
	point_idx[sOR_count] = sSize[sOR_count];
}


void CMFCApplication3Dlg::OnBnClickedButtonPLUS() //-> 여러개의 숫자 더하기도 할 수 있어야함.
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str = "+";
	EditText(str);
	if (sSize[0] == 0)
	{
		return;
	}
	
	sOR_count++;
	calculation_count = 1;
}

#include <cmath>
void CMFCApplication3Dlg::OnBnClickedButtonEQUAL()
{
	
	
	
	double value = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (calculation_count != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			
			if (sSize[i] == 0)
			{
				break;
			}
			if (point_idx[i] != -1)
			{
				for (int j = 0; j <= sSize[i]; j++)
				{
					sValue[i] += s[i].s[j] * pow(10, (sSize[i] - j - 1)  + ( point_idx[i]  - sSize[i]));
					
				}
			}
			else if(point_idx[i] == -1)
			{
				for (int j = 0; j <= sSize[i]; j++)
				{
					sValue[i] += s[i].s[j] * pow(10, sSize[i] - j - 1);
				}
			}
			
		}
		
	}
	else if (calculation_count == 0)
	{
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (sSize[i] == 0)
			break;
		if (sign_count[i] == -1)
		{
			sValue[i] = sValue[i] * -1;
		}
	}
	if (calculation_count == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (sSize[i] == 0)
			{
				break;
			}
			value += sValue[i];
		}
		
	}
	else if (calculation_count == 2)
	{

		
		for (int i = 0; i < 5; i++)
		{
			if (sSize[i] == 0)
			{
				break;
			}
			
			
			if (i == 0)
			{
				value = sValue[0];
				continue;
			}
			value = value - sValue[i];
		}
		
	}
	else if (calculation_count == 3)
	{
		
		for (int i = 0; i < 5; i++)
		{
			if (sSize[i] == 0)
			{
				break;
			}
			if (i == 0)
			{
				value = sValue[0];
				continue;
			}
			value *= sValue[i];
		}
	}
	else if (calculation_count == 4)
	{
		
		for (int i = 0; i < 5; i++)
		{
			if (sSize[i] == 0)
			{
				break;
			}
			if (sValue[i] == 0) // 0-division error.
			{
				CString errorDIVIDE = _T("0으로 나눌 수 없습니다. 계산기를 종료합니다.");
				AfxMessageBox(errorDIVIDE);
				CDialogEx::OnOK();
			}
			if (i == 0)
			{
				value = sValue[0];
				continue;
			}
			value /= sValue[i];
		}
	}
		CString str;
		str.Format(_T("%f"), value); //-> double string으로 형변환. (int->string은 f대신에 d넣어야함)
		
		OnBnClickedButton11();
		EditText(str);
		int num = 0; //나눈 몫push할 수.
		double equal_value = 0;// 나머지 수
		if (value >= 0)
		{
			for (int i = 0; i < 12; i++)
			{

				if (i == 0)
				{
					num = value / pow(10, 6 - i);
					equal_value = value - num * pow(10, 6 - i);

				}
				else
				{

					num = equal_value / pow(10, 6 - i);
					equal_value = equal_value - num * pow(10, 6 - i);

				}
				s[0].push(num);
				if (equal_value >= 0 && equal_value < 1)
				{
					point_idx[0] = i - 4;
				}

			}
			
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{

				if (i == 0)
				{
					num = (value * -1) / pow(10, 6 - i);
					equal_value = (value * -1) - num * pow(10, 6 - i);

				}
				else
				{

					num = equal_value / pow(10, 6 - i);
					equal_value = equal_value - num * pow(10, 6 - i);

				}
				s[0].push(num);
				if (equal_value >= 0 && equal_value < 1)
				{
					point_idx[0] = i - 4;
				}

			}
			sign_count[0] = -1;
		}
		
		sSize[0] = 11;
		
	
}


void CMFCApplication3Dlg::OnBnClickedButtonMINUS()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str = "-";
	EditText(str);
	if (sSize[sOR_count] == 0)
	{
		sign_count[sOR_count] = -1;
		return;
	}
	sOR_count++;
	calculation_count = 2;
	
}


void CMFCApplication3Dlg::OnBnClickedButtonMULTIPLY()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str = "*";
	EditText(str);
	sOR_count++;
	calculation_count = 3;
	
}


void CMFCApplication3Dlg::OnBnClickedButtonDIVIDE()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str = "/";
	EditText(str);
	sOR_count++;
	calculation_count = 4;
	
}
