// OutputLamp.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "OutputLamp.h"


// OutputLamp

IMPLEMENT_DYNAMIC(OutputLamp, CWnd)

OutputLamp::OutputLamp(CPoint point, int OUTput)
{
	this->point = point;
	this->OUTput = OUTput;
}

OutputLamp::~OutputLamp()
{
}


BEGIN_MESSAGE_MAP(OutputLamp, CWnd)
END_MESSAGE_MAP()



// OutputLamp �޽��� ó�����Դϴ�.
void OutputLamp::paint(CClientDC* dc) {
	if (OUTput == 1) { // ������
		CBrush brush_light(RGB(255, 255, 0));
		dc->SelectObject(&brush_light);
		dc->Rectangle(point.x, point.y, point.x + 30, point.y + 30);
	}
	else { // �Ҳ���
		CBrush brush_light(RGB(128, 128, 128));
		dc->SelectObject(&brush_light);
		dc->Rectangle(point.x, point.y, point.x + 30, point.y + 30);
	}
}

/* �� ���� */
void OutputLamp::Label(CClientDC* dc) {
	CString InSwitch;
	if (OUTput == 1)
		InSwitch.Format(_T("1"));
	else
		InSwitch.Format(_T("0"));

	dc->TextOutW(point.x + 15, point.y + 15, InSwitch);
}

/* ���̾ ���� */
void OutputLamp::wire(CClientDC* dc) {
}