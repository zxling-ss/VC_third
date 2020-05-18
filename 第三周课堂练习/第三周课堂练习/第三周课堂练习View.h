
// 第三周课堂练习View.h : C第三周课堂练习View 类的接口
//

#pragma once


class C第三周课堂练习View : public CView
{
protected: // 仅从序列化创建
	C第三周课堂练习View();
	DECLARE_DYNCREATE(C第三周课堂练习View)

// 特性
public:
	C第三周课堂练习Doc* GetDocument() const;
	CRect re;
	int x1, x2, y1, y2;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C第三周课堂练习View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 第三周课堂练习View.cpp 中的调试版本
inline C第三周课堂练习Doc* C第三周课堂练习View::GetDocument() const
   { return reinterpret_cast<C第三周课堂练习Doc*>(m_pDocument); }
#endif

