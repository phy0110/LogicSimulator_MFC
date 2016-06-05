// OrGate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "OrGate.h"


ULONG_PTR g_GdiPlusTokenBoxData_OR;

// OrGate

IMPLEMENT_DYNAMIC(OrGate, CWnd)

OrGate::OrGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_OR, &GdiplusStartupInput, NULL);
}

OrGate::~OrGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_OR);
}


BEGIN_MESSAGE_MAP(OrGate, CWnd)
END_MESSAGE_MAP()



// OrGate �޽��� ó�����Դϴ�.
void OrGate::Paint(CClientDC* dc) {
	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_OR);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
*/

/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapOR;
	pBitmapOR = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_OR));

	ScreenG.DrawImage(pBitmapOR, Rect(point.x, point.y, pBitmapOR->GetWidth(), pBitmapOR->GetHeight()), 0, 0, pBitmapOR->GetWidth(), pBitmapOR->GetHeight(), UnitPixel);


	//��� ����
	if (UpInput == 1 || DownInput == 1) {// 10 -> 1  01 -> 1  11 -> 1
		Output = 0;
	}
	else // 00 -> 0
		Output = 0;

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 7 && DownWire == point.x + 3 && DownWire == point.y + 19) { // ORGate�� �� ���� ����
		connect = TRUE;
	}
}


/* ��Ʈ�� �̹��� ������ */
void OrGate::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_OR));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}

/* �� ��� */
void OrGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL OrGate::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}