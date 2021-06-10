// MatricBox.cpp : implementation file
//

#include "stdafx.h"
#include "RussiaMatrix.h"
#include "MatricBox.h"
extern int BoundFlag;

// CMatricBox

CMatricBox::CMatricBox()
{
	this->IsVisible=TRUE;
}

CMatricBox::~CMatricBox()
{
}


// CMatricBox member functions
void CMatricBox::DrawBox(CDC * pDC)
{
	if(this->IsVisible)
		pDC->FillSolidRect(&m_rt,m_color);
}

void CMatricBox::UpdatePos(int x, int y)
{
	xpos=x;
	ypos=y;
	if(y<0)m_rt.SetRectEmpty();
	this->m_rt.left=x*BOX_WIDTH+1;
	this->m_rt.right=(x+1)*BOX_WIDTH-1;
	this->m_rt.top=y*BOX_WIDTH+1;
	this->m_rt.bottom=(y+1)*BOX_WIDTH-1;
	
}

void CMatricBox::SetColor(int color)
{
	m_color=color;
}

void CMatricBox::SetInvisible(BOOL types)
{
	this->IsVisible=types;
}

int CMatricBox::DropDown(int steps)
{
	if(ypos+steps>=20)
		return FALSE;
	ypos+=steps;
	UpdatePos(xpos,ypos);
	return TRUE;
}

int CMatricBox::MoveLeft(int steps)
{
	xpos-=steps;
	if(ypos<=0)
		return FALSE;
	UpdatePos(xpos,ypos);
	return TRUE;
}

int CMatricBox::MoveRight(int steps)
{
	xpos+=steps;
	if(ypos>=9)
		return FALSE;
	UpdatePos(xpos,ypos);
	return TRUE;
}
