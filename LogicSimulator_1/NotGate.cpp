// NotGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "NotGate.h"


// NotGate

IMPLEMENT_DYNAMIC(NotGate, CWnd)

NotGate::NotGate(CPoint point)
{
	this->point = point;
}

NotGate::~NotGate()
{
}


BEGIN_MESSAGE_MAP(NotGate, CWnd)
END_MESSAGE_MAP()



// NotGate 메시지 처리기입니다.
void NotGate::Paint(CClientDC* dc) {
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_NOT);
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

