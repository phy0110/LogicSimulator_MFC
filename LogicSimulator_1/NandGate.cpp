// NandGate.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "NandGate.h"

ULONG_PTR g_GdiPlusTokenBoxData_NAND;

// NandGate

IMPLEMENT_DYNAMIC(NandGate, CWnd)

NandGate::NandGate(CPoint point)
{
	this->point = point;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_NAND, &GdiplusStartupInput, NULL);
}

NandGate::~NandGate()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_NAND);
}


BEGIN_MESSAGE_MAP(NandGate, CWnd)
END_MESSAGE_MAP()



// NandGate �޽��� ó�����Դϴ�.
void NandGate::Paint(CClientDC* dc) {
	/*
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_NAND);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);

	dc->BitBlt(point.x, point.y, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
*/

/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapNAND;
	pBitmapNAND = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_AND));

	ScreenG.DrawImage(pBitmapNAND, Rect(point.x, point.y, pBitmapNAND->GetWidth(), pBitmapNAND->GetHeight()), 0, 0, pBitmapNAND->GetWidth(), pBitmapNAND->GetHeight(), UnitPixel);

	pBitmapNAND->Clone(Rect(point.x, point.y, pBitmapNAND->GetWidth(), pBitmapNAND->GetHeight()), IDB_OR);

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
void NandGate::Rotate(CClientDC* dc) {
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
void NandGate::TextLabel(CClientDC* dc) {
	CString outPut;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE&&Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}

	dc->TextOutW(point.x + 72, point.y + 18, outPut);
}

BOOL NandGate::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}