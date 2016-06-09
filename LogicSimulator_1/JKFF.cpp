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

	Width = pBitmapJKFF->GetWidth();
	Height = pBitmapJKFF->GetHeight();

	delete pBitmapJKFF;

	//���� ����(���� �ϼ�_x�� y���� �α�)
	if (UpWire == point.x + 3 && UpWire == point.y + 13 && DownWire == point.x + 3 && DownWire == point.y + 49 && CLKWire == point.x + 5 && CLKWire == point.y + 30) { // JKFF�� �� ���� ����
		connect = TRUE;
	}
}

int JKFF::rectWidth() {
	return Width;
}

int JKFF::rectHeight() {
	return Height;
}

void JKFF::function() {
	if (CLK == 1) { // ��¿���
		//��� ����
		if (J == 0 && K == 1) {// ����
			Output_J = 0;
			Output_K = 0;
		}
		else if (J == 1 & &K == 0) { // ��Ʈ
			Output_J = 1;
			Output_K = 1;
		}
		else if (J == 1 && K == 1) {//���
			if (Output_J == 1) {
				Output_J = 0;
			}
			else if (Output_J == 0) {
				Output_J = 1;
			}
			if (Output_K == 1) {
				Output_K = 0;
			}
			else if (Output_K == 0) {
				Output_K = 1;
			}
		}
	}
	else { // �ϰ�����
		if (J == 0 && K == 1) {// ����
			Output_J = 0;
			Output_K = 0;
		}
		else if (J == 1 & &K == 0) { // ��Ʈ
			Output_J = 1;
			Output_K = 1;
		}
		else if (J == 1 && K == 1) {//���
			if (Output_J == 1) {
				Output_J = 0;
			}
			else if (Output_J == 0) {
				Output_J = 1;
			}
			if (Output_K == 1) {
				Output_K = 0;
			}
			else if (Output_K == 0) {
				Output_K = 1;
			}
		}
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
	CString outPut_J;
	CString outPut_K;

	if (connect == TRUE && Output_J == 1) { // ��°��� 1�� ���
		outPut_J = _T("1");
	}
	else if (connect == TRUE && Output_J == 0) { // ��°��� 0�� ���
		outPut_J = _T("0");
	}
	if (connect == TRUE && Output_K == 1) { // ��°��� 1�� ���
		outPut_K = _T("1");
	}
	else if (connect == TRUE && Output_K == 0) { // ��°��� 0�� ���
		outPut_K = _T("0");
	}

	dc->TextOutW(point.x + 74, point.y + 13, outPut_J);
	dc->TextOutW(point.x + 74, point.y + 49, outPut_K);
}

BOOL JKFF::Connect(CClientDC* dc) {
	//��� �����Ű�µ� �װ� �����ϰ� �־�������ʳ�?point.x�� point.y�� �׻� �����ڳ�... ���� ��ü�� �����ؾ��ϳ�
	return FALSE;
}