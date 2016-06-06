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
	int Input; // 스위치 입력값
	int Output; // 출력값
	int UpInput; // 입력값1
	int DownInput; // 입력값2
	int UpWire; //와이어링1
	int DownWire; //와이어링2
	BOOL connect; // 연결
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


