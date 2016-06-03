
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
//	ON_NOTIFY_REFLECT(NM_DBLCLK, &CLogicSimulator_1View::OnNMDblclk)
ON_NOTIFY_REFLECT(NM_DBLCLK, &CLogicSimulator_1View::OnNMDblclk)
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
	cs.style |= TVS_HASBUTTONS;
	cs.style |= TVS_HASLINES;
	cs.style |= TVS_LINESATROOT;
	cs.style |= TVS_TRACKSELECT;

	return CTreeView::PreCreateWindow(cs);
}

void CLogicSimulator_1View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& tree = GetTreeCtrl();

	// ����Ʈ �߰�
	/* 1-���� �ʱ�ȭ */
	HTREEITEM hGate = tree.InsertItem(_T("����Ʈ"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-���� �ʱ�ȭ */
	HTREEITEM hLogicGate = tree.InsertItem(_T("������Ʈ"), 1, 1, hGate, TVI_LAST);
	HTREEITEM hFFGate = tree.InsertItem(_T("�ø��÷�"), 1, 1, hGate, TVI_LAST);

	/* 3-���� �ʱ�ȭ*/
	HTREEITEM hLogicGates[6];
	CString logicGates[] = { _T("AND ����Ʈ"), _T("OR ����Ʈ"), _T("NOT ����Ʈ"), _T("NAND ����Ʈ"), _T("NOR ����Ʈ"), _T("XOR ����Ʈ") };
	for (int i = 0; i < 6; i++) {
		hLogicGates[i] = tree.InsertItem(logicGates[i], 2, 2, hLogicGate, TVI_LAST);
	}
	HTREEITEM hFFGates[3];
	CString FFGates[] = { _T("D-FF"), _T("JK-FF"), _T("T - FF") };
	for (int i = 0; i < 3; i++) {
		hFFGates[i] = tree.InsertItem(FFGates[i], 2, 2, hFFGate, TVI_LAST);
	}

	// �Է� �߰�
	/* 1-���� �ʱ�ȭ */
	HTREEITEM hInPut = tree.InsertItem(_T("�Է�"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-���� �ʱ�ȭ */
	HTREEITEM hSwitch = tree.InsertItem(_T("�Է� ����ġ"), 1, 1, hInPut, TVI_LAST);
	HTREEITEM hClk = tree.InsertItem(_T("Ŭ��"), 1, 1, hInPut, TVI_LAST);

	// ��� �߰�
	/* 1-���� �ʱ�ȭ */
	HTREEITEM hOutPut = tree.InsertItem(_T("���"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2-���� �ʱ�ȭ */
	HTREEITEM hLamp = tree.InsertItem(_T("�Է� ����ġ"), 1, 1, hOutPut, TVI_LAST);
	HTREEITEM hSegment = tree.InsertItem(_T("7-���׸�Ʈ"), 1, 1, hOutPut, TVI_LAST);

	// ���̺� �ڽ� �߰�
	/* 1-���� �ʱ�ȭ */
	HTREEITEM hLib = tree.InsertItem(_T("���̺귯�� �ڽ�"), 0, 0, TVI_ROOT, TVI_LAST);
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
/*
CLogicSimulator_1Doc* CLogicSimulator_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogicSimulator_1Doc)));
	return (CLogicSimulator_1Doc*)m_pDocument;
}*/
#endif //_DEBUG


// CLogicSimulator_1View �޽��� ó����


//void clogicsimulator_1view::onnmdblclk(nmhdr *pnmhdr, lresult *presult)
//{
//	lpnmtreeview pnmtreeview = reinterpret_cast<lpnmtreeview>(pnmhdr);
//	// todo: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	
//
//	ctreectrl& tree = gettreectrl();
//	cstring gate = tree.getitemtext(tree.getselecteditem());
//
//
//	*presult = 0;
//}

void CLogicSimulator_1View::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

	CTreeCtrl& tree = GetTreeCtrl();
	CLogicSimulator_1Doc* pDoc = (CLogicSimulator_1Doc*)GetDocument();
//	= tree.GetItemText(tree.GetSelectedItem());

	*pResult = 0;
}
