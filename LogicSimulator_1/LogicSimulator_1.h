
// LogicSimulator_1.h : LogicSimulator_1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLogicSimulator_1App:
// �� Ŭ������ ������ ���ؼ��� LogicSimulator_1.cpp�� �����Ͻʽÿ�.
//

class CLogicSimulator_1App : public CWinApp
{
public:
	CLogicSimulator_1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLogicSimulator_1App theApp;
