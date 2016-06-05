// PaintView.cpp : ���� �����Դϴ�.
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

// CPaintView �׸����Դϴ�.
void CPaintView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

	//dc.SelectStockObject(NULL_BRUSH);
	//dc.SetROP2(R2_COPYPEN);
	/*
	for (int i = 0; i<boxes.GetCount(); i++) {
		dc.Rectangle(boxes[i].left, boxes[i].top, boxes[i].right, boxes[i].bottom);
	}*/
}

// CPaintView �����Դϴ�.

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


// CPaintView �޽��� ó�����Դϴ�.

//�� �׸��� ����
CPoint point1;
CPoint point2;
BOOL check = TRUE;

void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CPen pen(PS_SOLID, 4, RGB(0, 0, 255)); // �� ��ü�� �����.
	CPen *pOldPen = dc.SelectObject(&pen); // ���ο� �� ����, ���� �� ����
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
	if (strGatename == "AND ����Ʈ") {
		//��Ʈ�� ���
		AndGate and (point);
		and.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "OR ����Ʈ") {
		//��Ʈ�� ���
		OrGate or (point);
		or .Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "NOT ����Ʈ") {
		//��Ʈ�� ���
		NotGate not(point);
		not.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "NAND ����Ʈ") {
		NandGate nand(point);
		nand.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "NOR ����Ʈ") {
		NorGate nor(point);
		nor.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "XOR ����Ʈ") {
		XorGate xor (point);
		xor.Paint(&dc);
		strGatename = "";
	}
	else if (strGatename == "�ؽ�Ʈ ��") {
		//�ؽ�Ʈ ���� ��� ����?
		CString a = _T("name"); // ���⿡ �̸� ��� ������ �ؾ��ϴµ�,,,
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

		// �̵�
		boxes[current].left += point.x - startx;
		boxes[current].top += point.y - starty;
		boxes[current].right += point.x - startx;
		boxes[current].bottom += point.y - starty;

		startx = point.x;
		starty = point.y;

		dc.Rectangle(boxes[current].left, boxes[current].top, boxes[current].right, boxes[current].bottom);
	}*/
	//�����̴� ���콺 ��ġ ���
	CClientDC dc(this);
	CString temp;
	temp.Format(_T("(%4d , %4d) "), point.x, point.y);
	dc.TextOut(100, 100, temp);

	CView::OnMouseMove(nFlags, point);

	CView::OnMouseMove(nFlags, point);
}


void CPaintView::OnFileSave()
{
	// ����
}