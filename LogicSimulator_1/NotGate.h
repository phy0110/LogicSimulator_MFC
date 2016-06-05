#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"


// NotGate

class NotGate : public CWnd
{
	DECLARE_DYNAMIC(NotGate)

public:
	NotGate(CPoint point);
	virtual ~NotGate();
	int Input; // ����ġ �Է°�
	int Output; // ��°�
	int UpInput; // �Է°�1
	int DownInput; // �Է°�2
	int UpWire; //���̾1
	int DownWire; //���̾2
	BOOL connect; // ����
	int current;
	BOOL move;
	int startx;
	int starty;
	CPoint point;
	void NotGate::Paint(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
};


