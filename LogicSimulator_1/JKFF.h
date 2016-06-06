#pragma once

#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

#include <gdiplus.h>
using namespace Gdiplus;

// JKFF

class JKFF : public CWnd
{
	DECLARE_DYNAMIC(JKFF)

public:
	JKFF(CPoint point);
	virtual ~JKFF();
	int Input; // 스위치 입력값
	int Output; // 출력값
	int UpInput; // 입력값1
	int DownInput; // 입력값2
	int UpWire; //와이어링1
	int DownWire; //와이어링2
	BOOL connect; // 연결
	CPoint point;
	void JKFF::Paint(CClientDC* dc);
	void JKFF::Rotate(CClientDC* dc);
	void JKFF::TextLabel(CClientDC* dc);
	BOOL JKFF::Connect(CClientDC* dc);
	int Width;
	int Height;
	int JKFF::rectWidth();
	int JKFF::rectHeight();
protected:
	DECLARE_MESSAGE_MAP()
};


