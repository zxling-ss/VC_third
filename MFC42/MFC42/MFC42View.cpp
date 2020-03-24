﻿
// MFC42View.cpp: CMFC42View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42.h"
#endif

#include "MFC42Doc.h"
#include "MFC42View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42View

IMPLEMENT_DYNCREATE(CMFC42View, CView)

BEGIN_MESSAGE_MAP(CMFC42View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC42View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC42View 构造/析构

CMFC42View::CMFC42View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC42View::~CMFC42View()
{
}

BOOL CMFC42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42View 绘图

void CMFC42View::OnDraw(CDC* pDC)
{
	CMFC42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->a);
}


// CMFC42View 打印


void CMFC42View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC42View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC42View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC42View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFC42View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC42View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC42View 诊断

#ifdef _DEBUG
void CMFC42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42Doc* CMFC42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42Doc)));
	return (CMFC42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42View 消息处理程序


void CMFC42View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect b;
	CMFC42Doc* pDoc = GetDocument();
	GetClientRect(&b);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->a.left > 0) {
			pDoc->a.left -= 5;
			pDoc->a.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->a.right < b.right - b.left) {
			pDoc->a.left += 5;
			pDoc->a.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->a.top > 0) {
			pDoc->a.top -= 5;
			pDoc->a.bottom -= 5;
		}
	case VK_DOWN:
		if (pDoc->a.bottom < (b.bottom - b.top)) {
			pDoc->a.top += 5;
			pDoc->a.bottom += 5;
		}
		break;
	case VK_HOME:
		if (pDoc->a.left > 0 && pDoc->a.top > 0) {
			pDoc->a.left -= 5;
			pDoc->a.top -= 5;
		}
		break;
	case VK_END:
		if (pDoc->a.left < b.right && pDoc->a.top < b.bottom) {
			pDoc->a.left += 5;
			pDoc->a.top += 5;
		}
	default:
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC42Doc* pDoc = GetDocument();
	pDoc->a.left = 550;
	pDoc->a.top = 150;
	pDoc->a.right = 850;
	pDoc->a.bottom = 400;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
