// XorGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "XorGate.h"

ULONG_PTR g_GdiPlusTokenBoxData_XOR;

// XorGate

IMPLEMENT_DYNAMIC(XorGate, CWnd)

XorGate::XorGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_XOR, &GdiplusStartupInput, NULL);
}

XorGate::~XorGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_XOR);
}


BEGIN_MESSAGE_MAP(XorGate, CWnd)
END_MESSAGE_MAP()



// XorGate 메시지 처리기입니다.
void XorGate::Paint(CClientDC* dc) {
	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_XOR);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
*/

/* GDI+ 구현 */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapNOT;
	pBitmapNOT = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_XOR));

	ScreenG.DrawImage(pBitmapNOT, Rect(point.x, point.y, pBitmapNOT->GetWidth(), pBitmapNOT->GetHeight()), 0, 0, pBitmapNOT->GetWidth(), pBitmapNOT->GetHeight(), UnitPixel);

	//연결 구현
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 20) { // XOR 게이트와 선 연결 성공
		connect = TRUE;
	}
}

/* 와이어링 성공시 전류흐름 */
void XorGate::function() {
	//기능 구현
	if (UpInput == DownInput) {// 00 -> 0  11 -> 0
		Output = 0;
	}
	else // 01 -> 1  10 -> 1
		Output = 1;
}

/* 비트맵 이미지 돌리기 */
void XorGate::Rotate(CClientDC* dc) {
	//이미지 돌려주고 나서 돌리기 전 그 영역의 이미지는 없애고 싶은데...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_XOR));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}

/* 라벨 출력 */
void XorGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // 출력값이 1일 경우
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // 출력값이 0일 경우
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 68, point.y + 13, outPut);
}

BOOL XorGate::Connect(CClientDC* dc) {
	//잠깐 연결시키는데 그걸 저장하고 있어야하지않나?point.x랑 point.y는 항상 변하자나... 따로 객체를 선언해야하나
	return FALSE;
}