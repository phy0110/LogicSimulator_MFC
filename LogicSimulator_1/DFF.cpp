// DFF.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "DFF.h"

ULONG_PTR g_GdiPlusTokenBoxData_DFF;


// DFF

IMPLEMENT_DYNAMIC(DFF, CWnd)

DFF::DFF(CPoint point, int clk)
{
	this->point = point;
	this->clk = clk;
	GdiplusStartupInput GdiplusStartupInput;
	GdiplusStartup(&g_GdiPlusTokenBoxData_DFF, &GdiplusStartupInput, NULL);
}

DFF::~DFF()
{
	GdiplusShutdown(g_GdiPlusTokenBoxData_DFF);
}


BEGIN_MESSAGE_MAP(DFF, CWnd)
END_MESSAGE_MAP()



// DFF �޽��� ó�����Դϴ�.



/* ��Ʈ�� �̹��� ���� */
void DFF::Paint(CClientDC* dc) {
	/* GDI+ ���� */
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapDFF;
	pBitmapDFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_DFF));
	ScreenG.DrawImage(pBitmapDFF, Rect(0, 0, pBitmapDFF->GetWidth(), pBitmapDFF->GetHeight()), 0, 0, pBitmapDFF->GetWidth(), pBitmapDFF->GetHeight(), UnitPixel);

	delete pBitmapDFF;

	//���� ����
	if (UpWire == point.x + 3 && UpWire == point.y + 6 && DownWire == point.x + 3 && DownWire == point.y + 41) { // DFF�� �� ���� ����
		connect = TRUE;
	}
}

/* connect == TRUE�� ��� ���� */
void DFF::function() {
	//��� ����
	if (clk == 1) { // ��� ����
		if (UpInput == 0) {// 00 -> 0  01 -> 0  10 -> 0
			Output = 0;
		}
		else // 11 -> 1
			Output = 1;
	}
	else { // �ϰ� ����

	}
}

/* ��Ʈ�� �̹��� ������ */
void DFF::Rotate(CClientDC* dc) {
	//�̹��� �����ְ� ���� ������ �� �� ������ �̹����� ���ְ� ������...!!! �κй�ȿȭ����!!!>��<(PaintView ��������)
	Graphics ScreenG(dc->GetSafeHdc());
	Bitmap* pBitmapDFF;
	pBitmapDFF = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_DFF));
	Gdiplus::Matrix matrix;
	matrix.RotateAt(90, Gdiplus::PointF((float)(pBitmapDFF->GetWidth() / 2), (float)(pBitmapDFF->GetHeight() / 2)));
	ScreenG.SetTransform(&matrix);
	ScreenG.DrawImage(pBitmapDFF, 0, 0);

	delete pBitmapDFF;
}

/* �� ��� */
void DFF::TextLabel(CClientDC* dc) {
	CString outPut;
	CString outPut2;

	if (connect == TRUE && Output == 1) { // ��°��� 1�� ���
		outPut = _T("1");
	}
	else if (connect == TRUE && Output == 0) { // ��°��� 0�� ���
		outPut = _T("0");
	}
	if (connect == TRUE && Output2 == 1) {
		outPut2 = _T("1");
	}
	else if (connect == TRUE && Output2 == 0) {
		outPut2 = _T("0");
	}

	dc->TextOutW(point.x + 70, point.y + 13, outPut);
	dc->TextOutW(point.x + 70, point.y + 49, outPut2);
}

BOOL DFF::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}