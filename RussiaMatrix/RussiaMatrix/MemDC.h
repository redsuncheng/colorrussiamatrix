// MemDC.h: interface for the CMemDC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMDC_H__CEC1006C_9254_4F54_ADA0_9438BCB93F87__INCLUDED_)
#define AFX_MEMDC_H__CEC1006C_9254_4F54_ADA0_9438BCB93F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMemDC : public CDC  
{
public:
	CMemDC(CWnd *pw);
	CBitmap * pbmp;
	virtual ~CMemDC();

};

#endif // !defined(AFX_MEMDC_H__CEC1006C_9254_4F54_ADA0_9438BCB93F87__INCLUDED_)
