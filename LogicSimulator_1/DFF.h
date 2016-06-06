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
	int Output; // ��°�1
	int Output2; // ��°�2
	int UpInput; // �Է°�
	int UpWire; // ���̾1
	int DownWire; // ���̾2
	BOOL connect; // ����
	int clk; // Ŭ��
	CPoint point;
	void DFF::Paint(CClientDC* dc);
	void DFF::Rotate(CClientDC* dc);
	void DFF::TextLabel(CClientDC* dc);
	BOOL DFF::Connect(CClientDC* dc);
	void DFF::function();
protected:
	DECLARE_MESSAGE_MAP()
};


