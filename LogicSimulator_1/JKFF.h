#pragma once

#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

#include <gdiplus.h>
using namespace Gdiplus;

// JKFF

class JKFF : public CWnd
{
	DECLARE_DYNAMIC(JKFF)

public:
	JKFF(CPoint point);
	virtual ~JKFF();
	int Input; // ����ġ �Է°�
	int Output; // ��°�
	int UpInput; // �Է°�1
	int DownInput; // �Է°�2
	int UpWire; //���̾1
	int DownWire; //���̾2
	BOOL connect; // ����
	CPoint point;
	void JKFF::Paint(CClientDC* dc);
	void JKFF::Rotate(CClientDC* dc);
	void JKFF::TextLabel(CClientDC* dc);
	BOOL JKFF::Connect(CClientDC* dc);
	int Width;
	int Height;
	int JKFF::rectWidth();
	int JKFF::rectHeight();
protected:
	DECLARE_MESSAGE_MAP()
};


