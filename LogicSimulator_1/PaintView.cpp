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

// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

CPaintView::CPaintView()
	: strGatename(_T(""))
{
	current = -1;
	move = FALSE;
}

CPaintView::~CPaintView()
{
}

BEGIN_MESSAGE_MAP(CPaintView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_SAVE, &CPaintView::OnFileSave)
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	//dc.SelectStockObject(NULL_BRUSH);
	//dc.SetROP2(R2_COPYPEN);
	/*
	for (int i = 0; i<boxes.GetCount(); i++) {
		dc.Rectangle(boxes[i].left, boxes[i].top, boxes[i].right, boxes[i].bottom);
	}*/
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

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CPen pen(PS_SOLID, 4, RGB(0, 0, 255)); // 펜 객체를 만든다.
	CPen *pOldPen = dc.SelectObject(&pen); // 새로운 펜 선택, 이전 펜 저장
	if (check == TRUE) {
		point1 = point;
		check = FALSE;
	}
	else if (check == FALSE) {
		point2 = point;
		check = TRUE;
		dc.MoveTo(point1.x, point1.y);
		dc.LineTo(point2.x, point2.y);
	}/*
	else if (nFlags & MK_LBUTTON == 1) {
		current = -1;
		for (int i = 0; i<boxes.GetCount(); i++) {
			if (boxes[i].left <= point.x && point.x <= boxes[i].right ||
				boxes[i].right <= point.x && point.x <= boxes[i].left) {
				if (boxes[i].top <= point.y && point.y <= boxes[i].bottom ||
					boxes[i].bottom <= point.y && point.y <= boxes[i].top) {
					current = i;
					move = true;
					break;
				}
			}
		}
	}*/

	CView::OnLButtonDown(nFlags, point);
}


void CPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if (strGatename == "AND 게이트") {
		//비트맵 출력
		AndGate and (point);
		and.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "OR 게이트") {
		//비트맵 출력
		OrGate or (point);
		or .Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "NOT 게이트") {
		//비트맵 출력
		NotGate not(point);
		not.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "NAND 게이트") {
		NandGate nand(point);
		nand.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "NOR 게이트") {
		NorGate nor(point);
		nor.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "XOR 게이트") {
		XorGate xor (point);
		xor.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "텍스트 라벨") {
		//텍스트 라벨을 어떻게 넣지?
		CString a = _T("name"); // 여기에 이름 어떻게 넣을지 해야하는뎁,,,
		dc.TextOutW(point.x, point.y, a);
	}

	CView::OnLButtonUp(nFlags, point);
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{/*
	if (move == TRUE && nFlags & MK_LBUTTON == 1 && current != -1) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);

//		dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);

		// 이동
		boxes[current].left += point.x - startx;
		boxes[current].top += point.y - starty;
		boxes[current].right += point.x - startx;
		boxes[current].bottom += point.y - starty;

		startx = point.x;
		starty = point.y;

		dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);
	}*/
	//움직이는 마우스 위치 출력
	CClientDC dc(this);
	CString temp;
	temp.Format(_T("(%4d , %4d) "), point.x, point.y);
	dc.TextOut(100, 100, temp);

	CView::OnMouseMove(nFlags, point);

	CView::OnMouseMove(nFlags, point);
}


void CPaintView::OnFileSave()
{
	// 저장
}