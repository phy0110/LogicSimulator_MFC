// NotGate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "NotGate.h"

ULONG_PTR g_GdiPlusTokenBoxData_NOT;

// NotGate

IMPLEMENT_DYNAMIC(NotGate, CWnd)

NotGate::NotGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_NOT, &GdiplusStartupInput, NULL);
}

NotGate::~NotGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_NOT);
}


BEGIN_MESSAGE_MAP(NotGate, CWnd)
END_MESSAGE_MAP()



// NotGate �޽��� ó�����Դϴ�.
void NotGate::Paint(CClientDC* dc) {
	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_NOT);
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
	pBitmapNOT = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_NOT));

	ScreenG.DrawImage(pBitmapNOT, Rect(point.x, point.y, pBitmapNOT->GetWidth(), pBitmapNOT->GetHeight()), 0, 0, pBitmapNOT->GetWidth(), pBitmapNOT->GetHeight(), UnitPixel);

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 19) { // NOTGate�� �� ���� ����
		connect = TRUE;
	}
}

int NotGate::rectWidth() {
	return Width;
}

int NotGate::rectHeight() {
	return Height;
}

/* ���̾ ������ �����帧 */
void NotGate::function() {
	//��� ����
	if (UpInput == 0) { // �Է°� 0
		Output = 1;
	}
	else //�Է°� 1
		Output = 0;
}

/* ��Ʈ�� �̹��� ������ */
void NotGate::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapAND;
	pBitmapAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_NOT));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapAND->GetWidth() / 2), (float)(pBitmapAND->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapAND, 0, 0);

	delete pBitmapAND;
}

/* �� ��� */
void NotGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL NotGate::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}