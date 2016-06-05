// AndGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "AndGate.h"
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

ULONG_PTR g_GdiPlusTokenBoxData;
// AndGate

IMPLEMENT_DYNAMIC(AndGate, CWnd)

AndGate::AndGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData, &GdiplusStartupInput, NULL);
}

AndGate::~AndGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData);
}


BEGIN_MESSAGE_MAP(AndGate, CWnd)
END_MESSAGE_MAP()



// AndGate 메시지 처리기입니다.
void AndGate::Paint(CClientDC* dc) {
	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_AND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CBrush brush(&bitmap);

	
	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	
	CRect* box = new CRect(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight);
	dc->FillRect(box, &brush); //rect와 bitmap 연결
	
	CPaintView* pv;
	pv->boxes.Add(*box);
	pv->current = pv->boxes.GetCount() - 1; */

	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));

	ScreenG.DrawImage(pBitmapAND, Rect(point.x, point.y, pBitmapAND->GetWidth(), pBitmapAND->GetHeight()), 0, 0, pBitmapAND->GetWidth(), pBitmapAND->GetHeight(), UnitPixel);

	delete pBitmapAND;

	
	//기능 구현
	if (UpInput == 0 || DownInput == 0) {// 00 -> 0  01 -> 0  10 -> 0
		Output = 0;
	}
	else // 11 -> 1
		Output = 1;

	//연결 구현
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 28) { // ANDGate와 선 연결 성공
		connect = TRUE;
	}
}

void AndGate::Rotate(CClientDC* dc) {
	//이미지 돌려주고 나서 돌리기 전 그 영역의 이미지는 없애고 싶은데...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}