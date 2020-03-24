
// MFCApplication5View.cpp: CMFCApplication5View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication5View 构造/析构

CMFCApplication5View::CMFCApplication5View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication5View 绘图

void CMFCApplication5View::OnDraw(CDC* pDC)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s.Format(_T("发生次数为：%d"), pDoc->a);
	int count= pDoc->m.x - pDoc->n.x;
	CString s1;
	s1.Format(_T("像素：%d"), count);
	/*CString s2;
	s2.Format(_T("x=%d,y=%d"), pDoc->c.x, pDoc->c.y);*/
	pDC->TextOutW(20, 20, s);
	pDC->TextOutW(50, 50, s1);
}

void CMFCApplication5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication5View 诊断

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5View 消息处理程序


void CMFCApplication5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication5Doc* pDoc = GetDocument();
	if (nFlags && WM_LBUTTONDOWN) {
		pDoc->a += 1;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication5Doc* pDoc = GetDocument();
	pDoc->m.x = point.x;
	pDoc->m.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication5Doc* pDoc = GetDocument();
	pDoc->n.x = point.x;
	pDoc->n.y = point.y;
	CView::OnLButtonUp(nFlags, point);
}
