// PaintView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LogicSimulator_1.h"
#include "PaintView.h"

// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

CPaintView::CPaintView()
{

}

CPaintView::~CPaintView()
{
}

BEGIN_MESSAGE_MAP(CPaintView, CView)
END_MESSAGE_MAP()


// CPaintView 그리기입니다.

void CPaintView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
}


// CPaintView 진단입니다.

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPaintView 메시지 처리기입니다.
