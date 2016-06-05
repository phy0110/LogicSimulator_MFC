// OrGate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "OrGate.h"


// OrGate

IMPLEMENT_DYNAMIC(OrGate, CWnd)

OrGate::OrGate(CPoint point)
{
	this->point = point;
}

OrGate::~OrGate()
{
}


BEGIN_MESSAGE_MAP(OrGate, CWnd)
END_MESSAGE_MAP()



// OrGate �޽��� ó�����Դϴ�.
void OrGate::Paint(CClientDC* dc) {
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_OR);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);

	//��� ����
	if (UpInput == 1 || DownInput == 1) {// 10 -> 1  01 -> 1  11 -> 1
		Output = 0;
	}
	else // 00 -> 0
		Output = 0;

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 7 && DownWire == point.x + 3 && DownWire == point.y + 19) { // ORGate�� �� ���� ����
		connect = TRUE;
	}
}

