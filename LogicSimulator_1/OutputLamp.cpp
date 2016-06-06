// OutputLamp.cpp : 구현 파일입니다.
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



// OutputLamp 메시지 처리기입니다.
void OutputLamp::paint(CClientDC* dc) {
	if (OUTput == 1) { // 불켜짐
		CBrush brush_light(RGB(255, 255, 0));
		dc->SelectObject(&brush_light);
		dc->Rectangle(point.x, point.y, point.x + 30, point.y + 30);
	}
	else { // 불꺼짐
		CBrush brush_light(RGB(128, 128, 128));
		dc->SelectObject(&brush_light);
		dc->Rectangle(point.x, point.y, point.x + 30, point.y + 30);
	}
}

/* 라벨 설정 */
void OutputLamp::Label(CClientDC* dc) {
	CString InSwitch;
	if (OUTput == 1)
		InSwitch.Format(_T("1"));
	else
		InSwitch.Format(_T("0"));

	dc->TextOutW(point.x + 15, point.y + 15, InSwitch);
}

/* 와이어링 설정 */
void OutputLamp::wire(CClientDC* dc) {
}