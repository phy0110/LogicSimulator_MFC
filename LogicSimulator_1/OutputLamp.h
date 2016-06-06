#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

// OutputLamp

class OutputLamp : public CWnd
{
	DECLARE_DYNAMIC(OutputLamp)

public:
	OutputLamp(CPoint point, int OUTput);
	virtual ~OutputLamp();
	int OUTput;
	CPoint point;
	void OutputLamp::paint(CClientDC* dc);
	void OutputLamp::Label(CClientDC* dc);
	void OutputLamp::wire(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
};


