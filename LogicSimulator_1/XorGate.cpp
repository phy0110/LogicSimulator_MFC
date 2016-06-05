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
	Bitmap* pBitmapNOT;
	pBitmapNOT = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_XOR));

	ScreenG.DrawImage(pBitmapNOT, Rect(point.x, point.y, pBitmapNOT->GetWidth(), pBitmapNOT->GetHeight()), 0, 0, pBitmapNOT->GetWidth(), pBitmapNOT->GetHeight(), UnitPixel);


	//��� ����
	if (UpInput == 0) { // �Է°� 0
		Output = 1;
	}
	else //�Է°� 1
		Output = 0;

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 19) { // NOTGate�� �� ���� ����
		connect = TRUE;
	}
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

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL XorGate::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}