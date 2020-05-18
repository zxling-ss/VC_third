
// 第三周实验题View.cpp : C第三周实验题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第三周实验题.h"
#endif

#include "第三周实验题Doc.h"
#include "第三周实验题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第三周实验题View

IMPLEMENT_DYNCREATE(C第三周实验题View, CView)

BEGIN_MESSAGE_MAP(C第三周实验题View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第三周实验题View 构造/析构

C第三周实验题View::C第三周实验题View()
{
	// TODO: 在此处添加构造代码
	a = 0; b = 0;
}

C第三周实验题View::~C第三周实验题View()
{
}

BOOL C第三周实验题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第三周实验题View 绘制

void C第三周实验题View::OnDraw(CDC* pDC)
{
	C第三周实验题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->re1);
	pDC->Rectangle(pDoc->re2);
	pDC->Rectangle(pDoc->re3);
}


// C第三周实验题View 打印

BOOL C第三周实验题View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第三周实验题View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第三周实验题View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第三周实验题View 诊断

#ifdef _DEBUG
void C第三周实验题View::AssertValid() const
{
	CView::AssertValid();
}

void C第三周实验题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第三周实验题Doc* C第三周实验题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第三周实验题Doc)));
	return (C第三周实验题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第三周实验题View 消息处理程序


void C第三周实验题View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第三周实验题Doc* pDoc = GetDocument();
	/*CString s;
	int sum;
	sum = pDoc->A + pDoc->B;
	s = _T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);
	s.Format(_T("A+B= %d"), sum);
	dc.TextOutW(250, 450, s);*/
	CClientDC dc(this);
	CString s;
	int r = rand() % 50 + 5;
	s.Format(_T("%d"), r);
	
	if (point.x > 30 && point.x < 150 && point.y>30 && point.y < 300)
	{
      dc.TextOutW(100, 70,s);
	  a = _ttoi(s);
	}
	   
	if (point.x > 200 && point.x < 400 && point.y>30 && point.y < 400)
	{
     dc.TextOutW(300, 70, s);
	b = _ttoi(s);
	}
		 
	if (point.x > 500 && point.x < 650 && point.y>30 && point.y < 650)
	{
       s.Format(_T("%d"), a + b);
		dc.TextOutW(550, 70, s);
	}
		
	
	CView::OnLButtonDown(nFlags, point);
}


void C第三周实验题View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CString s;
	s = _T("左键正被抬起");
	CClientDC dc(this);
	dc.TextOutW(100,400, s);*/
	CView::OnLButtonUp(nFlags, point);
}
