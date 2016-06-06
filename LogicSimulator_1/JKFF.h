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
	int Output_J; // 출력값
	int Output_K; // 출력값
	int J; // 입력값1
	int K; // 입력값2
	int UpWire; //와이어링1
	int DownWire; //와이어링2
	int CLKWire; //클록 와이어링
	BOOL connect; // 연결
	CPoint point;
	void JKFF::Paint(CClientDC* dc);
	void JKFF::Rotate(CClientDC* dc);
	void JKFF::TextLabel(CClientDC* dc);
	BOOL JKFF::Connect(CClientDC* dc);
	void JKFF::function();
	int Width;
	int Height;
	int JKFF::rectWidth();
	int JKFF::rectHeight();
	int CLK; // 클록신호
protected:
	DECLARE_MESSAGE_MAP()
};


