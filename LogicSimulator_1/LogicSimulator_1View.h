
// LogicSimulator_1View.h : CLogicSimulator_1View Ŭ������ �������̽�
//

#pragma once

class CLogicSimulator_1View : public CTreeView
{
protected: // serialization������ ��������ϴ�.
	CLogicSimulator_1View();
	DECLARE_DYNCREATE(CLogicSimulator_1View)

// Ư���Դϴ�.
public:
//	CLogicSimulator_1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CLogicSimulator_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // LogicSimulator_1View.cpp�� ����� ����
inline CLogicSimulator_1Doc* CLogicSimulator_1View::GetDocument() const
   { return reinterpret_cast<CLogicSimulator_1Doc*>(m_pDocument); }
#endif

