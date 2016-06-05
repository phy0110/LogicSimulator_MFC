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

					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
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
	else {
		point2 = point;
		check = TRUE;
		dc.MoveTo(point1.x, point1.y);
		dc.LineTo(point2.x, point2.y);
	}

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

	CView::OnLButtonUp(nFlags, point);
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{

	CView::OnMouseMove(nFlags, point);
}


void CPaintView::OnFileSave()
{
	// 저장
}