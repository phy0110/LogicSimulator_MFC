// AndGate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "AndGate.h"
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

ULONG_PTR g_GdiPlusTokenBoxData_AND;
// AndGate

IMPLEMENT_DYNAMIC(AndGate, CWnd)

AndGate::AndGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_AND, &GdiplusStartupInput, NULL);
}

AndGate::~AndGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_AND);
}


BEGIN_MESSAGE_MAP(AndGate, CWnd)
END_MESSAGE_MAP()



// AndGate �޽��� ó�����Դϴ�.

/* ��Ʈ�� �̹��� ���� */
void AndGate::Paint(CClientDC* dc) {
	/*
	//GDI
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_AND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	CBrush brush(&bitmap);

	
	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	
	CRect* box = new CRect(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight);
	dc->FillRect(box, &brush); //rect�� bitmap ����
	
	CPaintView* pv;
	pv->boxes.Add(*box);
	pv->current = pv->boxes.GetCount() - 1; */

	/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));

	ScreenG.DrawImage(pBitmapAND, Rect(point.x, point.y, pBitmapAND->GetWidth(), pBitmapAND->GetHeight()), 0, 0, pBitmapAND->GetWidth(), pBitmapAND->GetHeight(), UnitPixel);

	pBitmapAND->Clone(Rect(point.x, point.y, pBitmapAND->GetWidth(), pBitmapAND->GetHeight()), IDB_AND);

//	ScreenG.DrawImage(pBitmapAND->Clone(Rect(point.x, point.y, pBitmapAND->GetWidth(), pBitmapAND->GetHeight()), IDB_AND), point.x, point.y);

	delete pBitmapAND;

	
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
void AndGate::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}

/* �� ��� */
void AndGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL AndGate::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}