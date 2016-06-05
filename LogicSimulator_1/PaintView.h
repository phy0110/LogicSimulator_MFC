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
	void CPaintView::AndGate(CPoint point, CClientDC* dc);
	int Input; // 입력값
	int Output; // 출력값
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


