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


	//기능 구현(수정 하센)
	if (UpInput == 0 || DownInput == 0) {// 00 -> 0  01 -> 0  10 -> 0
		Output = 0;
	}
	else // 11 -> 1
		Output = 1;

	//연결 구현(수정 하센)
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 28) { // ANDGate와 선 연결 성공
		connect = TRUE;
	}
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
	CString outPut;

	if (connect == TRUE && Output == 1) { // 출력값이 1일 경우
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // 출력값이 0일 경우
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL TFF::Connect(CClientDC* dc) {
	//잠깐 연결시키는데 그걸 저장하고 있어야하지않나?point.x랑 point.y는 항상 변하자나... 따로 객체를 선언해야하나
	return FALSE;
}