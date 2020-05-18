
// 第三周课堂练习View.cpp : C第三周课堂练习View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第三周课堂练习.h"
#endif

#include "第三周课堂练习Doc.h"
#include "第三周课堂练习View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第三周课堂练习View

IMPLEMENT_DYNCREATE(C第三周课堂练习View, CView)

BEGIN_MESSAGE_MAP(C第三周课堂练习View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第三周课堂练习View 构造/析构

C第三周课堂练习View::C第三周课堂练习View()
{
	// TODO: 在此处添加构造代码


}

C第三周课堂练习View::~C第三周课堂练习View()
{
}

BOOL C第三周课堂练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第三周课堂练习View 绘制
//　鼠标点击, 获取客户区信息后，在客户区画出最大的圆,  确保窗口重绘后所画的圆能显示出来

 //   (2)    仿前面所讲的例子(2)和(3), 只是所画的不是正方形而是椭圆(每个椭圆长短轴由两个不同的随机数确定)
void C第三周课堂练习View::OnDraw(CDC* pDC)
{
	C第三周课堂练习Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//pDC->Ellipse(x1,y1,x2,y2);
}


// C第三周课堂练习View 打印

BOOL C第三周课堂练习View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第三周课堂练习View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第三周课堂练习View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第三周课堂练习View 诊断

#ifdef _DEBUG
void C第三周课堂练习View::AssertValid() const
{
	CView::AssertValid();
}

void C第三周课堂练习View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第三周课堂练习Doc* C第三周课堂练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第三周课堂练习Doc)));
	return (C第三周课堂练习Doc*)m_pDocument;
}
#endif //_DEBUG


// C第三周课堂练习View 消息处理程序


void C第三周课堂练习View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CClientDC dc(this);
	GetClientRect(&re);

	/*dc.Ellipse(re.top,re.left,re.right,re.bottom);*/
	x1 = re.top;
	y1 = re.left;
	x2 = re.right;
	y2 = re.bottom;


	int a = abs(re.right-re.left);
	int b = abs(re.bottom-re.top);
	dc.Ellipse(a + 100, b + 100, a - 100, b - 100);
	//if (a > b) {
	//	/*dc.Ellipse(a-a/2, b-a/2, a+a / 2, b+a / 2);*/
	//	dc.Ellipse(a - 100, b - 100, a + 100, b + 100);
	//}
	//else {
	//	/*dc.Ellipse(a - b / 2, b - b/ 2, a + b / 2, b + b / 2);*/

	//}
	
	CView::OnLButtonDown(nFlags, point);
}
