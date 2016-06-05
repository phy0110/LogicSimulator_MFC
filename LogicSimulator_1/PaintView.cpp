// PaintView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "PaintView.h"

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
	CPaintDC dc(this);
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


void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if (strGatename == "AND 게이트") {
		//비트맵 출력
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_AND);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);

		CDC dcmem;
		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);

		dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		
		//기능 구현
		
	}

	if (strGatename == "OR 게이트") {
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_OR);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);

		CDC dcmem;
		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);

		dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	}

	if (strGatename == "NOT 게이트") {
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_NOT);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);

		CDC dcmem;
		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);

		dc.BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	}
	/*
	if (selected) {
		dc.TextOutW(200, 300, _T("TURE"));
	}
	else
		dc.TextOutW(200, 300, _T("FALSE"));
		*/
	CView::OnLButtonDown(nFlags, point);
}


void CPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CBitmap bitmap;
	if (strGatename == "AND") {
		AndGate(point, &dc);
		strGatename = "";
	}/*
	else if (strGatename == "OR") {
		ORGATE or (point, IDB_OR);
		or .Paint(dc);
		strGatename = "";
	}
	else if (strGatename == "NOT") {
		NOTGATE not(point, IDB_NOT);
		not.Paint(dc);
		strGatename = "";
	}
	else if (strGatename == "NAND") {
		NANDGATE nand(point, IDB_NAND);
		nand.Paint(dc);
		strGatename = "";
	}
	else if (strGatename == "NOR") {
		NORGATE nor(point, IDB_NOR);
		nor.Paint(dc);
		strGatename = "";
	}
	else if (strGatename == "XOR") {
		XORGATE xor (point, IDB_XOR);
		xor.Paint(dc);
		strGatename = "";
	}*/

	CView::OnLButtonUp(nFlags, point);
}

void CPaintView::AndGate(CPoint point, CClientDC* dc) {

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_AND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
}
