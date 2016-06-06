#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

#include <gdiplus.h>
using namespace Gdiplus;

// TFF

class TFF : public CWnd
{
	DECLARE_DYNAMIC(TFF)

public:
	TFF(CPoint point);
	virtual ~TFF();
	int Input; // ����ġ �Է°�
	int Output; // ��°�
	int UpInput; // �Է°�1
	int DownInput; // �Է°�2
	int UpWire; //���̾1
	int DownWire; //���̾2
	BOOL connect; // ����
	CPoint point;
	void TFF::Paint(CClientDC* dc);
	void TFF::Rotate(CClientDC* dc);
	void TFF::TextLabel(CClientDC* dc);
	BOOL TFF::Connect(CClientDC* dc);
	int Width;
	int Height;
	int TFF::rectWidth();
	int TFF::rectHeight();
protected:
	DECLARE_MESSAGE_MAP()
};


