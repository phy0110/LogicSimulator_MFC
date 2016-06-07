#pragma once
#include "LogicSimulator_1Doc.h"
#include "PaintView.h"

// Wire

class Wire : public CWnd
{
	DECLARE_DYNAMIC(Wire)

public:
	Wire(CPoint point, BOOL count);
	virtual ~Wire();
	void Wire::point_line();
	BOOL count;
	CPoint point;
protected:
	DECLARE_MESSAGE_MAP()
};


