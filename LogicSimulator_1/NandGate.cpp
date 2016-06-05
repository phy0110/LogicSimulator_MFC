// NandGate.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "NandGate.h"

ULONG_PTR g_GdiPlusTokenBoxData_NAND;

// NandGate

IMPLEMENT_DYNAMIC(NandGate, CWnd)

NandGate::NandGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_NAND, &GdiplusStartupInput, NULL);
}

NandGate::~NandGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_NAND);
}


BEGIN_MESSAGE_MAP(NandGate, CWnd)
END_MESSAGE_MAP()



// NandGate 메시지 처리기입니다.
void NandGate::Paint(CClientDC* dc) {
	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_NAND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
*/

/* GDI+ 구현 */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapNAND;
	pBitmapNAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));

	ScreenG.DrawImage(pBitmapNAND, Rect(point.x, point.y, pBitmapNAND->GetWidth(), pBitmapNAND->GetHeight()), 0, 0, pBitmapNAND->GetWidth(), pBitmapNAND->GetHeight(), UnitPixel);

	pBitmapNAND->Clone(Rect(point.x, point.y, pBitmapNAND->GetWidth(), pBitmapNAND->GetHeight()), IDB_OR);

	//기능 구현
	if (UpInput == 0) { // 입력값 0
		Output = 1;
	}
	else //입력값 1
		Output = 0;

	//연결 구현
	if (UpWire == point.x + 3 && UpWire == point.y + 19) { // NOTGate와 선 연결 성공
		connect = TRUE;
	}
}

/* 비트맵 이미지 돌리기 */
void NandGate::Rotate(CClientDC* dc) {
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

/* 라벨 출력 */
void NandGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // 출력값이 1일 경우
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // 출력값이 0일 경우
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL NandGate::Connect(CClientDC* dc) {
	//잠깐 연결시키는데 그걸 저장하고 있어야하지않나?point.x랑 point.y는 항상 변하자나... 따로 객체를 선언해야하나
	return FALSE;
}