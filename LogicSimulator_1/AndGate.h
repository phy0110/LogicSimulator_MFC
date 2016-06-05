#pragma once


// AndGate

class AndGate : public CWnd
{
	DECLARE_DYNAMIC(AndGate)

public:
	AndGate(CPoint point);
	virtual ~AndGate();
	int Input; // 스위치 입력값
	int Output; // 출력값
	int UpInput; // 입력값1
	int DownInput; // 입력값2
	int UpWire; //와이어링1
	int DownWire; //와이어링2
	BOOL connect; // 연결
	int current;
	BOOL move;
	int startx;
	int starty;
	CPoint point;
	void AndGate::Paint(CClientDC* dc);
protected:
	DECLARE_MESSAGE_MAP()
public:
};


