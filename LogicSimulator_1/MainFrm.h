
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư���Դϴ�.
protected:
	CSplitterWnd m_wndSplitter;
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CToolBar          m_wndToolBar;

// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};

