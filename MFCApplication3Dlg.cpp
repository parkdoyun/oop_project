
// MFCApplication3Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFCApplication3Dlg ��ȭ ����



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


// CMFCApplication3Dlg �޽��� ó����

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	//����ϴ� �Լ�
	SetDlgItemText(IDC_EDIT1, m_cal);
}


void CMFCApplication3Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_cal = "";
	//����ϴ� �Լ�
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


void CMFCApplication3Dlg::OnBnClickedButton12()//-> ��
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str = ".";
	EditText(str);
	point_idx[sOR_count] = sSize[sOR_count];
}


void CMFCApplication3Dlg::OnBnClickedButtonPLUS() //-> �������� ���� ���ϱ⵵ �� �� �־����.
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
				CString errorDIVIDE = _T("0���� ���� �� �����ϴ�. ���⸦ �����մϴ�.");
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
		str.Format(_T("%f"), value); //-> double string���� ����ȯ. (int->string�� f��ſ� d�־����)
		
		OnBnClickedButton11();
		EditText(str);
		int num = 0; //���� ��push�� ��.
		double equal_value = 0;// ������ ��
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str = "*";
	EditText(str);
	sOR_count++;
	calculation_count = 3;
	
}


void CMFCApplication3Dlg::OnBnClickedButtonDIVIDE()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	str = "/";
	EditText(str);
	sOR_count++;
	calculation_count = 4;
	
}
