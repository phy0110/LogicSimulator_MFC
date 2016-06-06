#pragma once


// InputSwitch

class InputSwitch : public CWnd
{
	DECLARE_DYNAMIC(InputSwitch)

public:
	InputSwitch(CPoint point, int INput);
	virtual ~InputSwitch();
	void InputSwitch::paint(CClientDC* dc);
	void InputSwitch::Label(CClientDC* dc);
	CPoint point;
	int INput;
protected:
	DECLARE_MESSAGE_MAP()
};


