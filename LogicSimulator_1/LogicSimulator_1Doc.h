
// LogicSimulator_1Doc.h : CLogicSimulator_1Doc Ŭ������ �������̽�
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

protected: // serialization������ ��������ϴ�.
	CLogicSimulator_1Doc();
	DECLARE_DYNCREATE(CLogicSimulator_1Doc)

public:
	void SelectTreeViewFolder(CString strFullName);

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

//	CTreeView& getDrawObjects();

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CLogicSimulator_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
