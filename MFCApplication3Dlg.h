
// MFCApplication3Dlg.h : ��� ����
//
#include <cmath>
#pragma once

class stack
{
public:
	int top = -1;
	int s[100];
	stack()
	{

	}
	void push(int a)
	{
		top++;
		s[top] = a;
		return;
	}
};
// CMFCApplication3Dlg ��ȭ ����
class CMFCApplication3Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void EditText(CString str);
	afx_msg void OnEnChangeEdit1();
	CString m_cal;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	int point_idx[5] = { -1 }; // �Ҽ��� ���� �ε��� ���� �迭.
	stack s[5];
	int sOR_count; //-> s1�� ���� ���� ���� s2�� ���� ���� ���� ǥ���ϴ� ����.
	int calculation_count;//-> ��Ģ���� �� = ���� �� � ������ �� �� ǥ���ϴ� ����.
	                      //-> 0 -> s1�� �� �װ�, 1 -> ����, 2 -> ����, 3 -> ����, 4 -> ������.
	double sValue[5];
	int num_count; //-> ���� � �ִ��� ���� ����.
	int sSize[5];
	int sign_count[5]; //-> ���� ī��Ʈ.
	afx_msg void OnBnClickedButtonPLUS();
	afx_msg void OnBnClickedButtonEQUAL();
	afx_msg void OnBnClickedButtonMINUS();
	afx_msg void OnBnClickedButtonMULTIPLY();
	afx_msg void OnBnClickedButtonDIVIDE();
};
