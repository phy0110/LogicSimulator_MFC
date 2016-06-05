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
	void CPaintView::AndGate(CPoint point, CClientDC* dc);
	int Input; // �Է°�
	int Output; // ��°�
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
};


