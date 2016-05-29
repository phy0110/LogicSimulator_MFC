
// LogicSimulator_1View.cpp : CLogicSimulator_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CLogicSimulator_1View 생성/소멸

CLogicSimulator_1View::CLogicSimulator_1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLogicSimulator_1View::~CLogicSimulator_1View()
{
}

BOOL CLogicSimulator_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CTreeView::PreCreateWindow(cs);
}

void CLogicSimulator_1View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

}


// CLogicSimulator_1View 진단

#ifdef _DEBUG
void CLogicSimulator_1View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLogicSimulator_1View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CLogicSimulator_1Doc* CLogicSimulator_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogicSimulator_1Doc)));
	return (CLogicSimulator_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CLogicSimulator_1View 메시지 처리기
