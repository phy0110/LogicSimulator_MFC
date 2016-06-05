// JKFF.cpp : ���� �����Դϴ�.
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



// JKFF �޽��� ó�����Դϴ�.


/* ��Ʈ�� �̹��� ���� */
void JKFF::Paint(CClientDC* dc) {
	/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapJKFF;
	pBitmapJKFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_JKFF));
	ScreenG.DrawImage(pBitmapJKFF, Rect(point.x, point.y, pBitmapJKFF->GetWidth(), pBitmapJKFF->GetHeight()), 0, 0, pBitmapJKFF->GetWidth(), pBitmapJKFF->GetHeight(), UnitPixel);

	delete pBitmapJKFF;


	//��� ����
	if (UpInput == 0 || DownInput == 0) {// 00 -> 0  01 -> 0  10 -> 0
		Output = 0;
	}
	else // 11 -> 1
		Output = 1;

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 28) { // ANDGate�� �� ���� ����
		connect = TRUE;
	}
}

/* ��Ʈ�� �̹��� ������ */
void JKFF::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapJKFF;
	pBitmapJKFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_JKFF));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapJKFF->GetWidth() / 2), (float)(pBitmapJKFF->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapJKFF, 0, 0);

	delete pBitmapJKFF;
}

/* �� ��� */
void JKFF::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL JKFF::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}