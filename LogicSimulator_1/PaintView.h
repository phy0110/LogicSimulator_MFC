#pragma once
#include "LogicSimulator_1View.h"
#include "LogicSimulator_1Doc.h"
// CPaintView 뷰입니다.

class CPaintView : public CView
{
	DECLARE_DYNCREATE(CPaintView)

protected:
	CPaintView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CPaintView();
public:
	void CPaintView::CheckSelect(CString select);
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
	CString strGatename;
//	void CPaintView::AndGate(CPoint point, CClientDC* dc);
	int Input; // 스위치 입력값
	int Output; // 출력값
	int UpInput; // 입력값1
	int DownInput; // 입력값2
	int UpWire; //와이어링1
	int DownWire; //와이어링2
	BOOL connect; // 연결
	CArray<CRect, CRect&> rects; // 영역 객체 리스트(이거랑 밑에꺼랑 같이 해서 영역 받아오자)
	CArray<CString, CString&> names; // 이름 객체 리스트
	int current;
	BOOL move;
	int startx;
	int starty;
	int clk; //FF을 위한 클록 신호
	CString rectGate;
	void CPaintView::WhatGate(CString gateName, CPoint point, CClientDC* dc); // 게이트 구별
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg void OnFileSave();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


