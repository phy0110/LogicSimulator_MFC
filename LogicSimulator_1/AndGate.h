#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"
#include <gdiplus.h>
using namespace Gdiplus;

// AndGate

class AndGate : public CWnd
{
	DECLARE_DYNAMIC(AndGate)

public:
	AndGate(CPoint point/*, BOOL connect*/);
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
	void AndGate::TextLabel(CClientDC* dc);
	BOOL AndGate::Connect(CClientDC* dc);
	void AndGate::function();
	int Width;
	int Height;
	int AndGate::rectWidth();
	int AndGate::rectHeight();
protected:
	DECLARE_MESSAGE_MAP()
public:
};


