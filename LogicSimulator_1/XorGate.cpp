// XorGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "XorGate.h"


// XorGate

IMPLEMENT_DYNAMIC(XorGate, CWnd)

XorGate::XorGate(CPoint point)
{
	this->point = point;
}

XorGate::~XorGate()
{
}


BEGIN_MESSAGE_MAP(XorGate, CWnd)
END_MESSAGE_MAP()



// XorGate 메시지 처리기입니다.
void XorGate::Paint(CClientDC* dc) {
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_XOR);
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

