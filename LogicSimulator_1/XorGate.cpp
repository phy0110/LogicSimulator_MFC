// XorGate.cpp : ���� �����Դϴ�.
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



// XorGate �޽��� ó�����Դϴ�.
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

/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapXOR;
	pBitmapXOR = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_XOR));

	ScreenG.DrawImage(pBitmapXOR, Rect(point.x, point.y, pBitmapXOR->GetWidth(), pBitmapXOR->GetHeight()), 0, 0, pBitmapXOR->GetWidth(), pBitmapXOR->GetHeight(), UnitPixel);

	Width = pBitmapXOR->GetWidth();
	Height = pBitmapXOR->GetHeight();
	
	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 20) { // XOR ����Ʈ�� �� ���� ����
		connect = TRUE;
	}
}

int XorGate::rectWidth() {
	return Width;
}

int XorGate::rectHeight() {
	return Height;
}

/* ���̾ ������ �����帧 */
void XorGate::function() {
	//��� ����
	if (UpInput == DownInput) {// 00 -> 0  11 -> 0
		Output = 0;
	}
	else // 01 -> 1  10 -> 1
		Output = 1;
}

/* ��Ʈ�� �̹��� ������ */
void XorGate::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_XOR));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}

/* �� ��� */
void XorGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 68, point.y + 13, outPut);
}

BOOL XorGate::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}