
// ������ʵ����View.cpp : C������ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ����.h"
#endif

#include "������ʵ����Doc.h"
#include "������ʵ����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ����View

IMPLEMENT_DYNCREATE(C������ʵ����View, CView)

BEGIN_MESSAGE_MAP(C������ʵ����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C������ʵ����View ����/����

C������ʵ����View::C������ʵ����View()
{
	// TODO: �ڴ˴���ӹ������
	a = 0; b = 0;
}

C������ʵ����View::~C������ʵ����View()
{
}

BOOL C������ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ����View ����

void C������ʵ����View::OnDraw(CDC* pDC)
{
	C������ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->re1);
	pDC->Rectangle(pDoc->re2);
	pDC->Rectangle(pDoc->re3);
}


// C������ʵ����View ��ӡ

BOOL C������ʵ����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ����View ���

#ifdef _DEBUG
void C������ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ����Doc* C������ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ����Doc)));
	return (C������ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ����View ��Ϣ�������


void C������ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ����Doc* pDoc = GetDocument();
	/*CString s;
	int sum;
	sum = pDoc->A + pDoc->B;
	s = _T("�����������");
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


void C������ʵ����View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*CString s;
	s = _T("�������̧��");
	CClientDC dc(this);
	dc.TextOutW(100,400, s);*/
	CView::OnLButtonUp(nFlags, point);
}
