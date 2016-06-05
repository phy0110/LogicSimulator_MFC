#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"


// OrGate

class OrGate : public CWnd
{
	DECLARE_DYNAMIC(OrGate)

public:
	OrGate(CPoint point);
	virtual ~OrGate();
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
	void OrGate::Paint(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
};


