
// LogicSimulator_1View.cpp : CLogicSimulator_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "LogicSimulator_1.h"
#endif

#include "LogicSimulator_1Doc.h"
#include "LogicSimulator_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLogicSimulator_1View

IMPLEMENT_DYNCREATE(CLogicSimulator_1View, CTreeView)

BEGIN_MESSAGE_MAP(CLogicSimulator_1View, CTreeView)
END_MESSAGE_MAP()

// CLogicSimulator_1View ����/�Ҹ�

CLogicSimulator_1View::CLogicSimulator_1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CLogicSimulator_1View::~CLogicSimulator_1View()
{
}

BOOL CLogicSimulator_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CTreeView::PreCreateWindow(cs);
}

void CLogicSimulator_1View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

}


// CLogicSimulator_1View ����

#ifdef _DEBUG
void CLogicSimulator_1View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLogicSimulator_1View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CLogicSimulator_1Doc* CLogicSimulator_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogicSimulator_1Doc)));
	return (CLogicSimulator_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CLogicSimulator_1View �޽��� ó����
