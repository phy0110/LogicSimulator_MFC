// AndGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "AndGate.h"
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"


// AndGate

IMPLEMENT_DYNAMIC(AndGate, CWnd)

AndGate::AndGate(CPoint point)
{
	this->point = point;
}

AndGate::~AndGate()
{
}


BEGIN_MESSAGE_MAP(AndGate, CWnd)
END_MESSAGE_MAP()



// AndGate 메시지 처리기입니다.
void AndGate::Paint(CClientDC* dc) {

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_AND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);

	//기능 구현
	if (UpInput == 0 || DownInput == 0) {// 00 -> 0  01 -> 0  10 -> 0
		Output = 0;
	}
	else // 11 -> 1
		Output = 1;

	//연결 구현
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 28) { // ANDGate와 선 연결 성공
		connect = TRUE;
	}
}