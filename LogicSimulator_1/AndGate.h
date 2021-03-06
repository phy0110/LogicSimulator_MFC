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
	int Input; // 스위치 입력값
	int Output; // 출력값
	int UpInput; // 입력값1
	int DownInput; // 입력값2
	int UpWire; //와이어링1
	int DownWire; //와이어링2
	BOOL connect; // 연결
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


