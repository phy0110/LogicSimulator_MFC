
// LogicSimulator_1Doc.h : CLogicSimulator_1Doc 클래스의 인터페이스
//


#pragma once
#include "PaintView.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "XorGate.h"
#include "TFF.h"
#include "JKFF.h"
#include "DFF.h"
#include "InputSwitch.h"

class CLogicSimulator_1Doc : public CDocument
{
private:
	CLogicSimulator_1Doc* m_doc;

protected: // serialization에서만 만들어집니다.
	CLogicSimulator_1Doc();
	DECLARE_DYNCREATE(CLogicSimulator_1Doc)

public:
	void SelectTreeViewFolder(CString strFullName);

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

//	CTreeView& getDrawObjects();

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CLogicSimulator_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
