#pragma once
#include "LogicSimulator_1View.h"
#include "LogicSimulator_1Doc.h"
// CPaintView ���Դϴ�.

class CPaintView : public CView
{
	DECLARE_DYNCREATE(CPaintView)

protected:
	CPaintView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CPaintView();
public:
	void CPaintView::CheckSelect(CString select);
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	CString strGatename;
//	void CPaintView::AndGate(CPoint point, CClientDC* dc);
	int Input; // ����ġ �Է°�
	int Output; // ��°�
	int UpInput; // �Է°�1
	int DownInput; // �Է°�2
	int UpWire; //���̾1
	int DownWire; //���̾2
	BOOL connect; // ����
	CArray<CRect, CRect&> rects; // ���� ��ü ����Ʈ(�̰Ŷ� �ؿ����� ���� �ؼ� ���� �޾ƿ���)
	CArray<CString, CString&> names; // �̸� ��ü ����Ʈ
	int current;
	BOOL move;
	int startx;
	int starty;
	int clk; //FF�� ���� Ŭ�� ��ȣ
	CString rectGate;
	void CPaintView::WhatGate(CString gateName, CPoint point, CClientDC* dc); // ����Ʈ ����
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


