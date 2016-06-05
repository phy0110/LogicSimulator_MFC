// NorGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "NorGate.h"


// NorGate

IMPLEMENT_DYNAMIC(NorGate, CWnd)

NorGate::NorGate(CPoint point)
{
	this->point = point;
}

NorGate::~NorGate()
{
}


BEGIN_MESSAGE_MAP(NorGate, CWnd)
END_MESSAGE_MAP()



// NorGate 메시지 처리기입니다.
void NorGate::Paint(CClientDC* dc) {
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_NOR);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);

	//기능 구현
	if (UpInput == 0) { // 입력값 0
		Output = 1;
	}
	else //입력값 1
		Output = 0;

	//연결 구현
	if (UpWire == point.x + 3 && UpWire == point.y + 19) { // NOTGate와 선 연결 성공
		connect = TRUE;
	}
}

