
// 第三周实验题Doc.h : C第三周实验题Doc 类的接口
//


#pragma once


class C第三周实验题Doc : public CDocument
{
protected: // 仅从序列化创建
	C第三周实验题Doc();
	DECLARE_DYNCREATE(C第三周实验题Doc)

// 特性
public:
	int A, B;
	CRect re1, re2, re3;
	
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C第三周实验题Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
