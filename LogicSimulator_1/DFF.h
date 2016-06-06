#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

#include <gdiplus.h>
using namespace Gdiplus;


// DFF

class DFF : public CWnd
{
	DECLARE_DYNAMIC(DFF)

public:
	DFF(CPoint point, int clk);
	virtual ~DFF();
	int Input; // ����ġ �Է°�
	int Output; // ��°�
	int UpInput; // �Է°�1
	int DownInput; // �Է°�2
	int UpWire; // ���̾1
	int DownWire; // ���̾2
	BOOL connect; // ����
	int clk; // Ŭ��
	CPoint point;
	void DFF::Paint(CClientDC* dc);
	void DFF::Rotate(CClientDC* dc);
	void DFF::TextLabel(CClientDC* dc);
	BOOL DFF::Connect(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
};


