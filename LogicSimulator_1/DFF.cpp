// DFF.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "DFF.h"

ULONG_PTR g_GdiPlusTokenBoxData_DFF;


// DFF

IMPLEMENT_DYNAMIC(DFF, CWnd)

DFF::DFF(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_DFF, &GdiplusStartupInput, NULL);

}

DFF::~DFF()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_DFF);
}


BEGIN_MESSAGE_MAP(DFF, CWnd)
END_MESSAGE_MAP()



// DFF 메시지 처리기입니다.



/* 비트맵 이미지 구현 */
void DFF::Paint(CClientDC* dc) {
	/* GDI+ 구현 */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapDFF;
	pBitmapDFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_DFF));
	ScreenG.DrawImage(pBitmapDFF, Rect(point.x, point.y, pBitmapDFF->GetWidth(), pBitmapDFF->GetHeight()), 0, 0, pBitmapDFF->GetWidth(), pBitmapDFF->GetHeight(), UnitPixel);

	delete pBitmapDFF;


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

/* 비트맵 이미지 돌리기 */
void DFF::Rotate(CClientDC* dc) {
	//이미지 돌려주고 나서 돌리기 전 그 영역의 이미지는 없애고 싶은데...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapDFF;
	pBitmapDFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_DFF));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapDFF->GetWidth() / 2), (float)(pBitmapDFF->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapDFF, 0, 0);

	delete pBitmapDFF;
}

/* 라벨 출력 */
void DFF::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // 출력값이 1일 경우
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // 출력값이 0일 경우
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL DFF::Connect(CClientDC* dc) {
	//잠깐 연결시키는데 그걸 저장하고 있어야하지않나?point.x랑 point.y는 항상 변하자나... 따로 객체를 선언해야하나
	return FALSE;
}