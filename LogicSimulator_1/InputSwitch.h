#pragma once


// InputSwitch

class InputSwitch : public CWnd
{
	DECLARE_DYNAMIC(InputSwitch)

public:
	InputSwitch(CPoint point, int INput);
	virtual ~InputSwitch();
	void InputSwitch::paint(CClientDC* dc);
	CPoint point;
	void InputSwitch::Label(CClientDC* dc);
	int INput;
protected:
	DECLARE_MESSAGE_MAP()
};


