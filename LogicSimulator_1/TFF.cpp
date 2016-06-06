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


	//��� ����(���� �ϼ�)
	if (UpInput == 0 || DownInput == 0) {// 00 -> 0  01 -> 0  10 -> 0
		Output = 0;
	}
	else // 11 -> 1
		Output = 1;

	//���� ����(���� �ϼ�)
	if (UpWire == point.x + 3 && UpWire == point.y + 8 && DownWire == point.x + 3 && DownWire == point.y + 28) { // ANDGate�� �� ���� ����
		connect = TRUE;
	}
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
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL TFF::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}