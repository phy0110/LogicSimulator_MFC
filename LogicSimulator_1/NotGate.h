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
	void NotGate::Paint(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
};


