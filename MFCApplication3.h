
// MFCApplication3.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCApplication3App:
// �� Ŭ������ ������ ���ؼ��� MFCApplication3.cpp�� �����Ͻʽÿ�.
//

class CMFCApplication3App : public CWinApp
{
public:
	CMFCApplication3App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication3App theApp;