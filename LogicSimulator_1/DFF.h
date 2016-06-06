#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

#include <gdiplus.h>
using namespace Gdiplus;


// DFF

class DFF : public CWnd
{
	DECLARE_DYNAMIC(DFF)

public:
	DFF(CPoint point, int clk);
	virtual ~DFF();
	int Input; // 스위치 입력값
	int Output; // 출력값
	int UpInput; // 입력값1
	int DownInput; // 입력값2
	int UpWire; // 와이어링1
	int DownWire; // 와이어링2
	BOOL connect; // 연결
	int clk; // 클록
	CPoint point;
	void DFF::Paint(CClientDC* dc);
	void DFF::Rotate(CClientDC* dc);
	void DFF::TextLabel(CClientDC* dc);
	BOOL DFF::Connect(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
};


