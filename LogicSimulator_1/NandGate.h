#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

// NandGate

class NandGate : public CWnd
{
	DECLARE_DYNAMIC(NandGate)

public:
	NandGate(CPoint point);
	virtual ~NandGate();
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
	void NandGate::Paint(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
};


