#pragma once
#include <gdiplus.h>
using namespace Gdiplus;

// AndGate

class AndGate : public CWnd
{
	DECLARE_DYNAMIC(AndGate)

public:
	AndGate(CPoint point);
	virtual ~AndGate();
	int Input; // ����ġ �Է°�
	int Output; // ��°�
	int UpInput; // �Է°�1
	int DownInput; // �Է°�2
	int UpWire; //���̾1
	int DownWire; //���̾2
	BOOL connect; // ����
	CPoint point;
	void AndGate::Paint(CClientDC* dc);
	void AndGate::Rotate(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
public:
};


