// NandGate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "NandGate.h"


// NandGate

IMPLEMENT_DYNAMIC(NandGate, CWnd)

NandGate::NandGate(CPoint point)
{
	this->point = point;
}

NandGate::~NandGate()
{
}


BEGIN_MESSAGE_MAP(NandGate, CWnd)
END_MESSAGE_MAP()



// NandGate �޽��� ó�����Դϴ�.
void NandGate::Paint(CClientDC* dc) {
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_NAND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);

	//��� ����
	if (UpInput == 0) { // �Է°� 0
		Output = 1;
	}
	else //�Է°� 1
		Output = 0;

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 19) { // NOTGate�� �� ���� ����
		connect = TRUE;
	}
}

