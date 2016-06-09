// NorGate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "NorGate.h"

ULONG_PTR g_GdiPlusTokenBoxData_NOR;

// NorGate

IMPLEMENT_DYNAMIC(NorGate, CWnd)

NorGate::NorGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_NOR, &GdiplusStartupInput, NULL);
}

NorGate::~NorGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_NOR);
}


BEGIN_MESSAGE_MAP(NorGate, CWnd)
END_MESSAGE_MAP()



// NorGate �޽��� ó�����Դϴ�.
void NorGate::Paint(CClientDC* dc) {
	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_NOR);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
*/

/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapNOR;
	pBitmapNOR = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_NOR));

	ScreenG.DrawImage(pBitmapNOR, Rect(point.x, point.y, pBitmapNOR->GetWidth(), pBitmapNOR->GetHeight()), 0, 0, pBitmapNOR->GetWidth(), pBitmapNOR->GetHeight(), UnitPixel);

	Width = pBitmapNOR->GetWidth();
	Height = pBitmapNOR->GetHeight();

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 7 && DownWire == point.x + 3 && DownWire == point.y + 19) { // NORGate�� �� ���� ����
		connect = TRUE;
	}
}

int NorGate::rectWidth() {
	return Width;
}

int NorGate::rectHeight() {
	return Height;
}

/* ���̾ ������ �����帧 */
void NorGate::function() {
	//��� ����
	if (UpInput == 0 || DownInput == 0) {// 00 -> 1
		Output = 1;
	}
	else // 01 -> 0  10 -> 0  11 -> 0
		Output = 1;
}

/* ��Ʈ�� �̹��� ������ */
void NorGate::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_NOR));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}

/* �� ��� */
void NorGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE && Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 67, point.y + 13, outPut);
}

BOOL NorGate::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}