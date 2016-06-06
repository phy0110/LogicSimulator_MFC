// InputSwitch.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "InputSwitch.h"
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"


// InputSwitch

IMPLEMENT_DYNAMIC(InputSwitch, CWnd)

InputSwitch::InputSwitch(CPoint point, int INput)
{
	this->point = point;
	this->INput = INput;
}

InputSwitch::~InputSwitch()
{
}


BEGIN_MESSAGE_MAP(InputSwitch, CWnd)
END_MESSAGE_MAP()



// InputSwitch �޽��� ó�����Դϴ�.
void InputSwitch::paint(CClientDC* dc) {
	dc->Rectangle(point.x, point.y, point.x + 30, point.y + 30);
}

/* �� ���� */
void InputSwitch::Label(CClientDC* dc) {
	CString InSwitch;
	if (INput == 1)
		InSwitch.Format(_T("1"));
	else
		InSwitch.Format(_T("0"));

	dc->TextOutW(point.x + 15, point.y + 15, InSwitch);
}