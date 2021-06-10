// MemDC.cpp: implementation of the CMemDC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemDC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CMemDC::CMemDC(CWnd *pw)
{
	CDC * pDC=pw->GetWindowDC();
	CRect rt;
	pw->GetClientRect(&rt);
	pbmp=new CBitmap;
	pbmp->CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
	this->CreateCompatibleDC(pDC);
	this->SelectObject(pbmp);
}

CMemDC::~CMemDC()
{
	delete pbmp;
}
