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
	int Output_J; // ��°�
	int Output_K; // ��°�
	int J; // �Է°�1
	int K; // �Է°�2
	int UpWire; //���̾1
	int DownWire; //���̾2
	int CLKWire; //Ŭ�� ���̾
	BOOL connect; // ����
	CPoint point;
	void JKFF::Paint(CClientDC* dc);
	void JKFF::Rotate(CClientDC* dc);
	void JKFF::TextLabel(CClientDC* dc);
	BOOL JKFF::Connect(CClientDC* dc);
	void JKFF::function();
	int Width;
	int Height;
	int JKFF::rectWidth();
	int JKFF::rectHeight();
	int CLK; // Ŭ�Ͻ�ȣ
protected:
	DECLARE_MESSAGE_MAP()
};


