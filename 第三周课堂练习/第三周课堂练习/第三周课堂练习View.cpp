
// �����ܿ�����ϰView.cpp : C�����ܿ�����ϰView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ�����ϰ.h"
#endif

#include "�����ܿ�����ϰDoc.h"
#include "�����ܿ�����ϰView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ�����ϰView

IMPLEMENT_DYNCREATE(C�����ܿ�����ϰView, CView)

BEGIN_MESSAGE_MAP(C�����ܿ�����ϰView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C�����ܿ�����ϰView ����/����

C�����ܿ�����ϰView::C�����ܿ�����ϰView()
{
	// TODO: �ڴ˴���ӹ������


}

C�����ܿ�����ϰView::~C�����ܿ�����ϰView()
{
}

BOOL C�����ܿ�����ϰView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ�����ϰView ����
//�������, ��ȡ�ͻ�����Ϣ���ڿͻ�����������Բ,  ȷ�������ػ��������Բ����ʾ����

 //   (2)    ��ǰ������������(2)��(3), ֻ�������Ĳ��������ζ�����Բ(ÿ����Բ��������������ͬ�������ȷ��)
void C�����ܿ�����ϰView::OnDraw(CDC* pDC)
{
	C�����ܿ�����ϰDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//pDC->Ellipse(x1,y1,x2,y2);
}


// C�����ܿ�����ϰView ��ӡ

BOOL C�����ܿ�����ϰView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�����ܿ�����ϰView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�����ܿ�����ϰView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�����ܿ�����ϰView ���

#ifdef _DEBUG
void C�����ܿ�����ϰView::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ�����ϰView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ�����ϰDoc* C�����ܿ�����ϰView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ�����ϰDoc)));
	return (C�����ܿ�����ϰDoc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ�����ϰView ��Ϣ�������


void C�����ܿ�����ϰView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
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
