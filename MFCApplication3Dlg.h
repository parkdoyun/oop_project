
// MFCApplication3Dlg.h : 헤더 파일
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
// CMFCApplication3Dlg 대화 상자
class CMFCApplication3Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
	int point_idx[5] = { -1 }; // 소수점 찍을 인덱스 저장 배열.
	stack s[5];
	int sOR_count; //-> s1에 수를 쌓을 건지 s2에 수를 쌓을 건지 표시하는 변수.
	int calculation_count;//-> 사칙연산 중 = 했을 때 어떤 연산을 할 지 표시하는 변수.
	                      //-> 0 -> s1에 수 쌓고, 1 -> 덧셈, 2 -> 뺄셈, 3 -> 곱셈, 4 -> 나눗셈.
	double sValue[5];
	int num_count; //-> 수가 몇개 있는지 세는 변수.
	int sSize[5];
	int sign_count[5]; //-> 음수 카운트.
	afx_msg void OnBnClickedButtonPLUS();
	afx_msg void OnBnClickedButtonEQUAL();
	afx_msg void OnBnClickedButtonMINUS();
	afx_msg void OnBnClickedButtonMULTIPLY();
	afx_msg void OnBnClickedButtonDIVIDE();
};
