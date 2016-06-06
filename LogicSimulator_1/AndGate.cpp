// AndGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "MainFrm.h"
#include "AndGate.h"

ULONG_PTR g_GdiPlusTokenBoxData_AND;
// AndGate

CPaintView* pv = (CPaintView*)AfxGetApp();

IMPLEMENT_DYNAMIC(AndGate, CWnd)

AndGate::AndGate(CPoint point/*, BOOL connect*/)
{
	this->point = point;
	this->connect = connect;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_AND, &GdiplusStartupInput, NULL);
}

AndGate::~AndGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_AND);
}


BEGIN_MESSAGE_MAP(AndGate, CWnd)
END_MESSAGE_MAP()



// AndGate 메시지 처리기입니다.

/* 비트맵 이미지 구현 */
void AndGate::Paint(CClientDC* dc) {
	/*
	//GDI
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
	pv->boxes.Add(*);
	pv->current = pv->boxes.GetCount() - 1;
	*/

	/* GDI+ 구현 */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));
	ScreenG.DrawImage(pBitmapAND, Rect(point.x, point.y, pBitmapAND->GetWidth(), pBitmapAND->GetHeight()), 0, 0, pBitmapAND->GetWidth(), pBitmapAND->GetHeight(), UnitPixel);
	
	
	// 영역과 gateName 수동으로 설정(이렇게 해서 영역을 가져오는 걸로)
	//CPaintView* pv;
	Width = pBitmapAND->GetWidth();
	Height = pBitmapAND->GetHeight();
	
//	pBitmapAND->Clone(Rect(point.x, point.y, pBitmapAND->GetWidth(), pBitmapAND->GetHeight()), IDB_AND);

//	ScreenG.DrawImage(pBitmapAND->Clone(Rect(point.x, point.y, pBitmapAND->GetWidth(), pBitmapAND->GetHeight()), IDB_AND), point.x, point.y);

	delete pBitmapAND;

	//연결 구현( 연결 구현 같은 경우는 CPaintView가 낫지않으까? 나중에 와이어링 할 때 다시 생각하는걸로)
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 28) { // ANDGate와 선 연결 성공
		connect = TRUE;
	}
}

int AndGate::rectWidth() {
	return Width;
}

int AndGate::rectHeight() {
	return Height;
}

/* 와이어링 성공시 전류흐름 */
void AndGate::function() {
	//기능 구현
	if (UpInput == 0 || DownInput == 0) {// 00 -> 0  01 -> 0  10 -> 0
		Output = 0;
	}
	else // 11 -> 1
		Output = 1;
}

/* 비트맵 이미지 돌리기 */
void AndGate::Rotate(CClientDC* dc) {
	//이미지 돌려주고 나서 돌리기 전 그 영역의 이미지는 없애고 싶은데...( CPaintView에서 고쳐주자)
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}

/* 라벨 출력 */
void AndGate::TextLabel(CClientDC* dc) { // 나중에 point값을 어떻게 바꿔줘야할거같은데 비트맵의 맨 첨으로
	CString outPut;

	if (connect == TRUE && Output == 1) { // 출력값이 1일 경우
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // 출력값이 0일 경우
		outPut = _T("0");
	}
	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL AndGate::Connect(CClientDC* dc) {
	//잠깐 연결시키는데 그걸 저장하고 있어야하지않나?point.x랑 point.y는 항상 변하자나... 따로 객체를 선언해야하나
	return FALSE;
}