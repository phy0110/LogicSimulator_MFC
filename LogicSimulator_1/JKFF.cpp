// JKFF.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "JKFF.h"

ULONG_PTR g_GdiPlusTokenBoxData_JKFF;


// JKFF

IMPLEMENT_DYNAMIC(JKFF, CWnd)

JKFF::JKFF(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_JKFF, &GdiplusStartupInput, NULL);
}

JKFF::~JKFF()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_JKFF);
}


BEGIN_MESSAGE_MAP(JKFF, CWnd)
END_MESSAGE_MAP()



// JKFF 메시지 처리기입니다.


/* 비트맵 이미지 구현 */
void JKFF::Paint(CClientDC* dc) {
	/* GDI+ 구현 */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapJKFF;
	pBitmapJKFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_JKFF));
	ScreenG.DrawImage(pBitmapJKFF, Rect(point.x, point.y, pBitmapJKFF->GetWidth(), pBitmapJKFF->GetHeight()), 0, 0, pBitmapJKFF->GetWidth(), pBitmapJKFF->GetHeight(), UnitPixel);

	Width = pBitmapJKFF->GetWidth();
	Height = pBitmapJKFF->GetHeight();

	delete pBitmapJKFF;

	//연결 구현(수정 하센_x랑 y따로 두기)
	if (UpWire == point.x + 3 && UpWire == point.y + 13 && DownWire == point.x + 3 && DownWire == point.y + 49 && CLKWire == point.x + 5 && CLKWire == point.y + 30) { // JKFF와 선 연결 성공
		connect = TRUE;
	}
}

int JKFF::rectWidth() {
	return Width;
}

int JKFF::rectHeight() {
	return Height;
}

void JKFF::function() {
	if (CLK == 1) { // 상승에지
		//기능 구현
		if (J == 0 && K == 1) {// 리셋
			Output_J = 0;
			Output_K = 0;
		}
		else if (J == 1 & &K == 0) { // 세트
			Output_J = 1;
			Output_K = 1;
		}
		else if (J == 1 && K == 1) {//토글
			if (Output_J == 1) {
				Output_J = 0;
			}
			else if (Output_J == 0) {
				Output_J = 1;
			}
			if (Output_K == 1) {
				Output_K = 0;
			}
			else if (Output_K == 0) {
				Output_K = 1;
			}
		}
	}
	else { // 하강에지
		if (J == 0 && K == 1) {// 리셋
			Output_J = 0;
			Output_K = 0;
		}
		else if (J == 1 & &K == 0) { // 세트
			Output_J = 1;
			Output_K = 1;
		}
		else if (J == 1 && K == 1) {//토글
			if (Output_J == 1) {
				Output_J = 0;
			}
			else if (Output_J == 0) {
				Output_J = 1;
			}
			if (Output_K == 1) {
				Output_K = 0;
			}
			else if (Output_K == 0) {
				Output_K = 1;
			}
		}
	}
}

/* 비트맵 이미지 돌리기 */
void JKFF::Rotate(CClientDC* dc) {
	//이미지 돌려주고 나서 돌리기 전 그 영역의 이미지는 없애고 싶은데...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapJKFF;
	pBitmapJKFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_JKFF));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapJKFF->GetWidth() / 2), (float)(pBitmapJKFF->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapJKFF, 0, 0);

	delete pBitmapJKFF;
}

/* 라벨 출력 */
void JKFF::TextLabel(CClientDC* dc) {
	CString outPut_J;
	CString outPut_K;

	if (connect == TRUE && Output_J == 1) { // 출력값이 1일 경우
		outPut_J = _T("1");
	}
	else if (connect == TRUE && Output_J == 0) { // 출력값이 0일 경우
		outPut_J = _T("0");
	}
	if (connect == TRUE && Output_K == 1) { // 출력값이 1일 경우
		outPut_K = _T("1");
	}
	else if (connect == TRUE && Output_K == 0) { // 출력값이 0일 경우
		outPut_K = _T("0");
	}

	dc->TextOutW(point.x + 74, point.y + 13, outPut_J);
	dc->TextOutW(point.x + 74, point.y + 49, outPut_K);
}

BOOL JKFF::Connect(CClientDC* dc) {
	//잠깐 연결시키는데 그걸 저장하고 있어야하지않나?point.x랑 point.y는 항상 변하자나... 따로 객체를 선언해야하나
	return FALSE;
}