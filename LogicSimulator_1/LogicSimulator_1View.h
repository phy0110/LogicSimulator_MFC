
// LogicSimulator_1View.h : CLogicSimulator_1View 클래스의 인터페이스
//

#pragma once


class CLogicSimulator_1View : public CTreeView
{
protected: // serialization에서만 만들어집니다.
	CLogicSimulator_1View();
	DECLARE_DYNCREATE(CLogicSimulator_1View)

// 특성입니다.
public:
	CLogicSimulator_1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CLogicSimulator_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LogicSimulator_1View.cpp의 디버그 버전
inline CLogicSimulator_1Doc* CLogicSimulator_1View::GetDocument() const
   { return reinterpret_cast<CLogicSimulator_1Doc*>(m_pDocument); }
#endif

