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
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


