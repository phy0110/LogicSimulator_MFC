// PaintView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "PaintView.h"
#include "LogicSimulator_1Doc.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "XorGate.h"
#include "TFF.h"
#include "JKFF.h"
#include "DFF.h"

// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

CPaintView::CPaintView()
	: strGatename(_T(""))
{
	move = FALSE;
	connect = FALSE;
	current = -1;
}

CPaintView::~CPaintView()
{
}

BEGIN_MESSAGE_MAP(CPaintView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
//	ON_COMMAND(ID_FILE_SAVE, &CPaintView::OnFileSave)
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

CString mung;

void CPaintView::CheckSelect(CString select) {
	CPaintDC dc(this);
	mung = select;
}

// CPaintView 그리기입니다.
void CPaintView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CClientDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CPoint point;
	CString final_name;

	for (int i = 0; i < rects.GetCount(); i++) {
		final_name = names[i];
		point.x = rects[i].top;
		point.y = rects[i].left;
		WhatGate(final_name, point, &dc);
	}
}

// CPaintView 진단입니다.

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPaintView 메시지 처리기입니다.

//선 그리는 변수
CPoint point1;
CPoint point2;
BOOL check = TRUE;

void CPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	Draw = FALSE;
	WhatGate(strGatename, point, &dc);
	strGatename = "";
	Draw = TRUE;

	CView::OnLButtonUp(nFlags, point);
}

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CPen pen(PS_SOLID, 4, RGB(0, 0, 255)); // 펜 객체를 만든다.
	CPen *pOldPen = dc.SelectObject(&pen); // 새로운 펜 선택, 이전 펜 저장
	if (Draw == TRUE) {
		if (check == TRUE) {
			point1 = point;
			check = FALSE;
		}
		else if (check == FALSE) {
			point2 = point;
			check = TRUE;
			dc.MoveTo(point1.x, point1.y);
			dc.LineTo(point2.x, point2.y);
		}
	}
	
	CView::OnLButtonDown(nFlags, point);
}



void CPaintView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CString test;
	test.Format(_T("(%d , %d, %d, %d) "), rects[0].left, rects[0].right, rects[0].top, rects[0].bottom);
	dc.TextOut(50, 50, test);
	startx = point.x;
	starty = point.y;

	for (int i = 0; i < rects.GetCount(); i++) {
		if (rects[i].left <= point.x && point.x <= rects[i].right ||
			rects[i].right <= point.x && point.x <= rects[i].left) { // 양옆에 들어왔냐?
			if (rects[i].top <= point.y && point.y <= rects[i].bottom ||
				rects[i].bottom <= point.y && point.y <= rects[i].top) { // 위아래로 들어왔냐?
				move = TRUE;
				current = i;
				dc.FillSolidRect(rects[i].left, rects[i].top, rects[i].right, rects[i].bottom, RGB(255, 255, 255));
				break;
			}
		}
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if (move == TRUE && (nFlags & MK_LBUTTON==1)) {
		CString test1;
		test1.Format(_T("들어옴"));
		dc.TextOut(50, 50, test1);

		// 이동
		rects[current].left += point.x - startx;
		rects[current].top += point.y - starty;
		rects[current].right += point.x - startx;
		rects[current].bottom += point.y - starty;

		startx = point.x;
		starty = point.y;

		point.x = startx;
		point.y = starty;

		rectGate = names[current];

		strGatename = rectGate;

		
	}
	
	//움직이는 마우스 위치 출력
	CString temp;
	temp.Format(_T("(%4d , %4d) "), point.x, point.y);
	dc.TextOut(100, 100, temp);


	CView::OnMouseMove(nFlags, point);
	
}

void CPaintView::WhatGate(CString gateName, CPoint point, CClientDC* dc) {
	if (gateName == "AND 게이트") {
		//비트맵 출력
		AndGate and (point);
		and.Paint(dc);
		
		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, and.rectWidth(), and.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "OR 게이트") {
		//비트맵 출력
		OrGate or (point);
		or.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, or.rectWidth(), or.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "NOT 게이트") {
		//비트맵 출력
		NotGate not(point);
		not.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, not.rectWidth(), not.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "NAND 게이트") {
		NandGate nand(point);
		nand.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, nand.rectWidth(), nand.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "NOR 게이트") {
		NorGate nor(point);
		nor.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, nor.rectWidth(), nor.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "XOR 게이트") {
		XorGate xor (point);
		xor.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, xor.rectWidth(), xor.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "T-FF") {
		TFF tff(point);
		tff.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, tff.rectWidth(), tff.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "JK-FF") {
		JKFF jkff(point);
		jkff.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, jkff.rectWidth(), jkff.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
	else if (gateName == "D-FF") {
		DFF dff(point, clk);
		dff.Paint(dc);

		/* 영역 움직이는 거 설정 */
		CRect* rect = new CRect(point.x, point.y, dff.rectWidth(), dff.rectHeight());
		CString* name = new CString(gateName);

		rects.Add(*rect);
		names.Add(*name);
	}
}