#pragma once

#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

#include <gdiplus.h>
using namespace Gdiplus;

// XorGate

class XorGate : public CWnd
{
	DECLARE_DYNAMIC(XorGate)

public:
	XorGate(CPoint point);
	virtual ~XorGate();
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
	void XorGate::Paint(CClientDC* dc);
	void XorGate::Rotate(CClientDC* dc);
	void XorGate::TextLabel(CClientDC* dc);
	BOOL XorGate::Connect(CClientDC* dc);
	void XorGate::function();
protected:
	DECLARE_MESSAGE_MAP()
};


