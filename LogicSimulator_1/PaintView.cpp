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
#include "TFF.h"
#include "JKFF.h"
#include "DFF.h"
#include "InputSwitch.h"
#include "OutputLamp.h"
#include "Wire.h"

// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

CPaintView::CPaintView()
	: strGatename(_T(""))
{
	move = FALSE;
	connect = FALSE;
	current = -1;
	INput = 0;
	OUTput = 0;
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

// CPaintView �׸����Դϴ�.
void CPaintView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CClientDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	CPoint point;
	CString final_name;

	for (int i = 0; i < rects.GetCount(); i++) {
		final_name = names[i];
		point.x = rects[i].top;
		point.y = rects[i].left;
		WhatGate(final_name, point, &dc);
	}
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
	CPen pen(PS_SOLID, 4, RGB(0, 0, 255)); // �� ��ü�� �����.
	CPen *pOldPen = dc.SelectObject(&pen); // ���ο� �� ����, ���� �� ����
	/*
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
	}*/
	
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
			rects[i].right <= point.x && point.x <= rects[i].left) { // �翷�� ���Գ�?
			if (rects[i].top <= point.y && point.y <= rects[i].bottom ||
				rects[i].bottom <= point.y && point.y <= rects[i].top) { // ���Ʒ��� ���Գ�?
				move = TRUE;
				current = i;
				dc.FillSolidRect(rects[i].left, rects[i].top, rects[i].right, rects[i].bottom, RGB(255, 255, 255));
				rectGate = names[current];
				break;
			}
		}
	}

	if (rectGate == "�Է� ����ġ") {
		if (INput == 0) {
			INput = 1;
			InputSwitch inputSwitch(point, INput);
			inputSwitch.Label(&dc);
		}
		else {
			INput = 0;
			InputSwitch inputSwitch(point, INput);
			inputSwitch.Label(&dc);
		}
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if (move == TRUE && (nFlags & MK_LBUTTON==1)) {
		CString test1;
		test1.Format(_T("����"));
		dc.TextOut(50, 50, test1);

		// �̵�
		rects[current].left += point.x - startx;
		rects[current].top += point.y - starty;
		rects[current].right += point.x - startx;
		rects[current].bottom += point.y - starty;

		startx = point.x;
		starty = point.y;

		point.x = startx;
		point.y = starty;


		strGatename = rectGate;

		
	}
	
	//�����̴� ���콺 ��ġ ���
	CString temp;
	temp.Format(_T("(%4d , %4d) "), point.x, point.y);
	dc.TextOut(100, 100, temp);


	CView::OnMouseMove(nFlags, point);
	
}

void CPaintView::WhatGate(CString gateName, CPoint point, CClientDC* dc) {
	if (gateName == "AND ����Ʈ") {
		//��Ʈ�� ���
		AndGate and (point);
		and.Paint(dc);
		
		/* ���� �����̴� �� ���� */
		CRect* rect_AND = new CRect(point.x, point.y, and.rectWidth(), and.rectHeight());
		CString* name_AND = new CString(gateName);

		rects.Add(*rect_AND);
		names.Add(*name_AND);
	}
	else if (gateName == "OR ����Ʈ") {
		//��Ʈ�� ���
		OrGate or (point);
		or.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_OR = new CRect(point.x, point.y, or.rectWidth(), or.rectHeight());
		CString* name_OR = new CString(gateName);

		rects.Add(*rect_OR);
		names.Add(*name_OR);
	}
	else if (gateName == "NOT ����Ʈ") {
		//��Ʈ�� ���
		NotGate not(point);
		not.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_NOT = new CRect(point.x, point.y, not.rectWidth(), not.rectHeight());
		CString* name_NOT = new CString(gateName);

		rects.Add(*rect_NOT);
		names.Add(*name_NOT);
	}
	else if (gateName == "NAND ����Ʈ") {
		NandGate nand(point);
		nand.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_NAND = new CRect(point.x, point.y, nand.rectWidth(), nand.rectHeight());
		CString* name_NAND = new CString(gateName);

		rects.Add(*rect_NAND);
		names.Add(*name_NAND);
	}
	else if (gateName == "NOR ����Ʈ") {
		NorGate nor(point);
		nor.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_NOR = new CRect(point.x, point.y, nor.rectWidth(), nor.rectHeight());
		CString* name_NOR = new CString(gateName);

		rects.Add(*rect_NOR);
		names.Add(*name_NOR);
	}
	else if (gateName == "XOR ����Ʈ") {
		XorGate xor (point);
		xor.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_XOR = new CRect(point.x, point.y, xor.rectWidth(), xor.rectHeight());
		CString* name_XOR = new CString(gateName);

		rects.Add(*rect_XOR);
		names.Add(*name_XOR);
	}
	else if (gateName == "T-FF") {
		TFF tff(point);
		tff.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_TFF = new CRect(point.x, point.y, tff.rectWidth(), tff.rectHeight());
		CString* name_TFF = new CString(gateName);

		rects.Add(*rect_TFF);
		names.Add(*name_TFF);
	}
	else if (gateName == "JK-FF") {
		JKFF jkff(point);
		jkff.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_JKFF = new CRect(point.x, point.y, jkff.rectWidth(), jkff.rectHeight());
		CString* name_JKFF = new CString(gateName);

		rects.Add(*rect_JKFF);
		names.Add(*name_JKFF);
	}
	else if (gateName == "D-FF") {
		DFF dff(point, clk);
		dff.Paint(dc);

		/* ���� �����̴� �� ���� */
		CRect* rect_DFF = new CRect(point.x, point.y, dff.rectWidth(), dff.rectHeight());
		CString* name_DFF = new CString(gateName);

		rects.Add(*rect_DFF);
		names.Add(*name_DFF);
	}
	else if (gateName == "�Է� ����ġ") {
		InputSwitch inputSwitch(point, INput);

		CRect* rect_SWITCH = new CRect(point.x, point.y, point.x + 15, point.y + 15);
		CString* name_SWITCH = new CString(gateName);

		rects.Add(*rect_SWITCH);
		names.Add(*name_SWITCH);

		inputSwitch.paint(dc);
	}
	else if (gateName == "��� ����") {
		OutputLamp outputLamp(point, OUTput);

		CRect* rect_SWITCH = new CRect(point.x, point.y, point.x + 15, point.y + 15);
		CString* name_SWITCH = new CString(gateName);

		rects.Add(*rect_SWITCH);
		names.Add(*name_SWITCH);

		outputLamp.paint(dc);
	}
	else {

	}
}