
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
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLogicSimulator_1View

IMPLEMENT_DYNCREATE(CLogicSimulator_1View, CTreeView)

BEGIN_MESSAGE_MAP(CLogicSimulator_1View, CTreeView)
ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CLogicSimulator_1View::OnTvnSelchanged)
END_MESSAGE_MAP()

// CLogicSimulator_1View 생성/소멸

CLogicSimulator_1View::CLogicSimulator_1View()
{
	

}

CLogicSimulator_1View::~CLogicSimulator_1View()
{
}

BOOL CLogicSimulator_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= TVS_HASBUTTONS;
	cs.style |= TVS_HASLINES;
	cs.style |= TVS_LINESATROOT;
	cs.style |= TVS_TRACKSELECT;

	return CTreeView::PreCreateWindow(cs);
}

CString select_tree;

void CLogicSimulator_1View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& tree = GetTreeCtrl();

	// 게이트 추가
	/* 1-레벨 초기화 */
	HTREEITEM hGate = tree.InsertItem(_T("게이트"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-레벨 초기화 */
	HTREEITEM hLogicGate = tree.InsertItem(_T("논리게이트"), 1, 1, hGate, TVI_LAST);
	HTREEITEM hFFGate = tree.InsertItem(_T("플립플롭"), 1, 1, hGate, TVI_LAST);

	/* 3-레벨 초기화*/
	HTREEITEM hLogicGates[6];
	CString logicGates[] = { _T("AND 게이트"), _T("OR 게이트"), _T("NOT 게이트"), _T("NAND 게이트"), _T("NOR 게이트"), _T("XOR 게이트") };
	for (int i = 0; i < 6; i++) {
		hLogicGates[i] = tree.InsertItem(logicGates[i], 2, 2, hLogicGate, TVI_LAST);
	}
	HTREEITEM hFFGates[3];
	CString FFGates[] = { _T("D-FF"), _T("JK-FF"), _T("T-FF") };
	for (int i = 0; i < 3; i++) {
		hFFGates[i] = tree.InsertItem(FFGates[i], 2, 2, hFFGate, TVI_LAST);
	}

	// 입력 추가
	/* 1-레벨 초기화 */
	HTREEITEM hInPut = tree.InsertItem(_T("입력"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-레벨 초기화 */
	HTREEITEM hSwitch = tree.InsertItem(_T("입력 스위치"), 1, 1, hInPut, TVI_LAST);
	HTREEITEM hClk = tree.InsertItem(_T("클럭"), 1, 1, hInPut, TVI_LAST);

	// 출력 추가
	/* 1-레벨 초기화 */
	HTREEITEM hOutPut = tree.InsertItem(_T("출력"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-레벨 초기화 */
	HTREEITEM hLamp = tree.InsertItem(_T("출력 램프"), 1, 1, hOutPut, TVI_LAST);
	HTREEITEM hSegment = tree.InsertItem(_T("7-세그먼트"), 1, 1, hOutPut, TVI_LAST);

	// 라이브 박스 추가
	/* 1-레벨 초기화 */
	HTREEITEM hLib = tree.InsertItem(_T("라이브러리 박스"), 0, 0, TVI_ROOT, TVI_LAST);

	// 텍스트 라벨 추가
	/* 1-레벨 초기화 */
	HTREEITEM hText = tree.InsertItem(_T("텍스트 라벨"), 0, 0, TVI_ROOT, TVI_LAST);

	// 선 추가
	/* 1-레벨 초기화 */
	HTREEITEM hWire = tree.InsertItem(_T("선 연결"), 0, 0, TVI_ROOT, TVI_LAST);
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
/*
CLogicSimulator_1Doc* CLogicSimulator_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogicSimulator_1Doc)));
	return (CLogicSimulator_1Doc*)m_pDocument;
}*/
#endif //_DEBUG

// CLogicSimulator_1View 메시지 처리기
CPaintView* cv;
CLogicSimulator_1View* csv;
void CLogicSimulator_1View::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	TVITEM tvi = pNMTreeView->itemNew;
	CTreeCtrl& tree = GetTreeCtrl();
	CLogicSimulator_1Doc* pDoc = (CLogicSimulator_1Doc*)GetDocument();
	select_tree = tree.GetItemText(tvi.hItem);
	pDoc->SelectTreeViewFolder(select_tree);

	*pResult = 0;
}


void CLogicSimulator_1View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTreeCtrl & tree = GetTreeCtrl();
	HTREEITEM hItem = tree.GetSelectedItem();

	CString str = tree.GetItemText(hItem);

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_pPaintView->strGatename = str;
	*pResult = 0;
}
