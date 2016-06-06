// TFF.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "TFF.h"

ULONG_PTR g_GdiPlusTokenBoxData_TFF;

// TFF

IMPLEMENT_DYNAMIC(TFF, CWnd)

TFF::TFF(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_TFF, &GdiplusStartupInput, NULL);
}

TFF::~TFF()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_TFF);
}


BEGIN_MESSAGE_MAP(TFF, CWnd)
END_MESSAGE_MAP()



// TFF 메시지 처리기입니다.


/* 비트맵 이미지 구현 */
void TFF::Paint(CClientDC* dc) {
	/* GDI+ 구현 */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapTFF;
	pBitmapTFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_TFF));
	ScreenG.DrawImage(pBitmapTFF, Rect(point.x, point.y, pBitmapTFF->GetWidth(), pBitmapTFF->GetHeight()), 0, 0, pBitmapTFF->GetWidth(), pBitmapTFF->GetHeight(), UnitPixel);

	delete pBitmapTFF;

	//연결 구현(수정 하센)
	if (UpWire == point.x + 3 && UpWire == point.y + 18 && CLKWire == point.x + 3 && CLKWire == point.y + 49) { // TFF와 선 연결 성공
		connect = TRUE;
	}
}

void TFF::function() {
	//기능 구현
	if (CLK == 1) { // 상승에지
		if (T == 1) {
			if (T_i == 0)
				T_i == 1;
			else
				T_i == 0;
		}
		T_i = T;
	}
	else {
		if (T == 1) {
			if (T_i == 0)
				T_i == 1;
			else
				T_i == 0;
		}
		T_i = T;
	}
}

int TFF::rectWidth() {
	return Width;
}

int TFF::rectHeight() {
	return Height;
}

/* 비트맵 이미지 돌리기 */
void TFF::Rotate(CClientDC* dc) {
	//이미지 돌려주고 나서 돌리기 전 그 영역의 이미지는 없애고 싶은데...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapTFF;
	pBitmapTFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_TFF));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapTFF->GetWidth() / 2), (float)(pBitmapTFF->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapTFF, 0, 0);

	delete pBitmapTFF;
}

/* 라벨 출력 */
void TFF::TextLabel(CClientDC* dc) {
	CString Ts;
	CString Tis;

	if (connect == TRUE && T == 1) {
		Ts = _T("1");
	}
	else if (connect == TRUE && T == 0) {
		Ts = _T("0");
	}
	if (connect == TRUE && T_i == 1) {
		Tis = _T("1");
	}
	else if (connect == TRUE && T_i == 0) {
		Tis = _T("0");
	}

	dc->TextOutW(point.x + 75, point.y + 13, Ts);
	dc->TextOutW(point.x + 75, point.y + 49, Tis);
}

BOOL TFF::Connect(CClientDC* dc) {
	//잠깐 연결시키는데 그걸 저장하고 있어야하지않나?point.x랑 point.y는 항상 변하자나... 따로 객체를 선언해야하나
	return FALSE;
}