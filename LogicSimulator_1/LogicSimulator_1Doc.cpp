
// LogicSimulator_1Doc.cpp : CLogicSimulator_1Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "LogicSimulator_1.h"
#endif

#include "LogicSimulator_1Doc.h"
#include "MainFrm.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLogicSimulator_1Doc

IMPLEMENT_DYNCREATE(CLogicSimulator_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CLogicSimulator_1Doc, CDocument)
END_MESSAGE_MAP()

// CLogicSimulator_1Doc 생성/소멸

CLogicSimulator_1Doc::CLogicSimulator_1Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

} 

CLogicSimulator_1Doc::~CLogicSimulator_1Doc()
{
}

BOOL CLogicSimulator_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	/*
	CPaintView* p_pv;
	CLogicSimulator_1View* p_tv;
	POSITION pos = m_doc->GetFirstViewPosition();
	while (pos != NULL) {
		p_pv = (CPaintView*)m_doc->GetNextView(pos);
		delete *p_pv;
	}
	m_doc->RemoveView(p_pv);
	m_doc->RemoveView(p_tv);


	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CLogicSimulator_1View* pView = (CLogicSimulator_1View*)pFrame->GetActiveView();
*/
//	CLogicSimulator_1App* app = (CLogicSimulator_1App*)AfxGetApp();
	//app->CreateFile();
//	app->InitInstance();

	return TRUE;
}

// 트리뷰에 항목 선택시 리스트뷰 항목 변경
void CLogicSimulator_1Doc::SelectTreeViewFolder(CString select)
{
	CPaintView* pv = (CPaintView*)m_viewList.GetHead();
	pv->CheckSelect(select);
}


// CLogicSimulator_1Doc serialization

void CLogicSimulator_1Doc::Serialize(CArchive& ar)
{/*
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		POSITION pos = m_DrawObjs.GetHeadPosition();
		while (pos != NULL) {
			((DrawObject*)m_DrawObjs.GetNext(pos))->serialize(ar);
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
	//옵션 선택 부분.
	if (dlgFileSave.DoModal() == IDOK)
	{
		vector::iterator EffectItr;
		EffectItr = DTool.m_DEffect.m_Effect.begin();

		CString Temp;
		Temp.Format(L"%s%s", dlgFileSave.GetFileName(), L".ds");

		HANDLE  hFile;
		DWORD  dwRead;

		//파일저장 시작 
		hFile = CreateFile(Temp, GENERIC_WRITE, 0, NULL,
			CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


		//애니메이션 관련 정보 저장 
		WriteFile(hFile, &EffectItr[m_nEffectListSelect].AniControl.m_TGaro, sizeof(int), &dwRead, NULL);
		WriteFile(hFile, &EffectItr[m_nEffectListSelect].AniControl.m_TSaro, sizeof(int), &dwRead, NULL);
		CloseHandle(hFile);*/
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CLogicSimulator_1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CLogicSimulator_1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLogicSimulator_1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLogicSimulator_1Doc 진단

#ifdef _DEBUG
void CLogicSimulator_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLogicSimulator_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLogicSimulator_1Doc 명령
