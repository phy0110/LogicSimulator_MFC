// TFF.cpp : ���� �����Դϴ�.
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



// TFF �޽��� ó�����Դϴ�.


/* ��Ʈ�� �̹��� ���� */
void TFF::Paint(CClientDC* dc) {
	/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapTFF;
	pBitmapTFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_TFF));
	ScreenG.DrawImage(pBitmapTFF, Rect(point.x, point.y, pBitmapTFF->GetWidth(), pBitmapTFF->GetHeight()), 0, 0, pBitmapTFF->GetWidth(), pBitmapTFF->GetHeight(), UnitPixel);

	delete pBitmapTFF;

	//���� ����(���� �ϼ�)
	if (UpWire == point.x + 3 && UpWire == point.y + 18 && CLKWire == point.x + 3 && CLKWire == point.y + 49) { // TFF�� �� ���� ����
		connect = TRUE;
	}
}

void TFF::function() {
	//��� ����
	if (CLK == 1) { // ��¿���
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

/* ��Ʈ�� �̹��� ������ */
void TFF::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapTFF;
	pBitmapTFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_TFF));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapTFF->GetWidth() / 2), (float)(pBitmapTFF->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapTFF, 0, 0);

	delete pBitmapTFF;
}

/* �� ��� */
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
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}