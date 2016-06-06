#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

#include <gdiplus.h>
using namespace Gdiplus;

// TFF

class TFF : public CWnd
{
	DECLARE_DYNAMIC(TFF)

public:
	TFF(CPoint point);
	virtual ~TFF();
	int Input; // 스위치 입력값
	int Output; // 출력값
	int UpInput; // 입력값1
	int DownInput; // 입력값2
	int UpWire; //와이어링1
	int DownWire; //와이어링2
	BOOL connect; // 연결
	CPoint point;
	void TFF::Paint(CClientDC* dc);
	void TFF::Rotate(CClientDC* dc);
	void TFF::TextLabel(CClientDC* dc);
	BOOL TFF::Connect(CClientDC* dc);
	int Width;
	int Height;
	int TFF::rectWidth();
	int TFF::rectHeight();
protected:
	DECLARE_MESSAGE_MAP()
};


