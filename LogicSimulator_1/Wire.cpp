// Wire.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "Wire.h"


// Wire

IMPLEMENT_DYNAMIC(Wire, CWnd)

Wire::Wire(CPoint point, BOOL count)
{
	this->count = count;
	this->point = point;
}

Wire::~Wire()
{
}


BEGIN_MESSAGE_MAP(Wire, CWnd)
END_MESSAGE_MAP()



// Wire 메시지 처리기입니다.
/* 점 찍기 */
void Wire::point_line() {
/*	if (count == FALSE) { // 첫 번째 점 찍기
		point1 = point;
		check = FALSE;
	}
	else if (check == FALSE) {
		point2 = point;
		check = TRUE;
		dc.MoveTo(point1.x, point1.y);
		dc.LineTo(point2.x, point2.y);
	}*/
}

