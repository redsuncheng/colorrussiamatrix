// MatrixElement.cpp : implementation file
//

#include "stdafx.h"
#include "RussiaMatrix.h"
#include "MatrixElement.h"


// CMatrixElement

CMatrixElement::CMatrixElement()
{
	IsStone=FALSE;
}

CMatrixElement::~CMatrixElement()
{
}


// CMatrixElement member functions

void CMatrixElement::UpdateElement(int x, int y, int etype,int rtype,int color)
{
	if(x>9) x=9;
	if(x<0)	x=0;
	switch(etype)
	{
	case TYPE_I:
		{
			switch(rtype)
			{
			case 1 :
				{
					mb[0].UpdatePos(x,y-3);
					mb[1].UpdatePos(x,y-2);
					mb[2].UpdatePos(x,y-1);
					mb[3].UpdatePos(x,y);
					break;
				}
			case 2 :
				{
					if(x>=7)x=6;
					mb[0].UpdatePos(x,y);
					mb[1].UpdatePos(x+1,y);
					mb[2].UpdatePos(x+2,y);
					mb[3].UpdatePos(x+3,y);
					break;
				}
			case 3 :
				{
					mb[0].UpdatePos(x,y-3);
					mb[1].UpdatePos(x,y-2);
					mb[2].UpdatePos(x,y-1);
					mb[3].UpdatePos(x,y);
					break;
				}
			case 4 :
				{
					if(x>=7)x=6;
					mb[0].UpdatePos(x,y);
					mb[1].UpdatePos(x+1,y);
					mb[2].UpdatePos(x+2,y);
					mb[3].UpdatePos(x+3,y);
					break;
				}
			}
			break;
		}
	case TYPE_O:
		{
			if(x>=9)x=8;
			mb[0].UpdatePos(x,y-1);
			mb[1].UpdatePos(x,y);
			mb[2].UpdatePos(x+1,y-1);
			mb[3].UpdatePos(x+1,y);
			break;
		}
	case TYPE_T:
		{
			switch(rtype)
			{
			case 1 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+2,y-1);
					mb[3].UpdatePos(x+1,y);
					break;
				}
			case 2 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+1,y-2);
					mb[3].UpdatePos(x+1,y);
					break;
				}
			case 3 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x+1,y-1);
					mb[1].UpdatePos(x,y);
					mb[2].UpdatePos(x+1,y);
					mb[3].UpdatePos(x+2,y);
					break;
				}
			case 4 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x,y-2);
					mb[3].UpdatePos(x,y);
					break;
				}
			}
			break;		
		}
	case TYPE_L:
		{
			switch(rtype)
			{
			case 1 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-2);
					mb[1].UpdatePos(x+1,y-2);
					mb[2].UpdatePos(x+1,y-1);
					mb[3].UpdatePos(x+1,y);
					break;
				}
			case 2 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x+1,y);
					mb[1].UpdatePos(x,y);
					mb[2].UpdatePos(x+2,y);
					mb[3].UpdatePos(x+2,y-1);
					break;
				}
			case 3 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x,y-2);
					mb[2].UpdatePos(x,y);
					mb[3].UpdatePos(x+1,y);
					break;
				}
			case 4 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+2,y-1);
					mb[3].UpdatePos(x,y);
					break;
				}
			}
			break;		
		}
	case TYPE_J:
		{
			switch(rtype)
			{
			case 1 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x+1,y-1);
					mb[1].UpdatePos(x+1,y-2);
					mb[2].UpdatePos(x+1,y);
					mb[3].UpdatePos(x,y);
					break;
				}
			case 2 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x,y);
					mb[2].UpdatePos(x+1,y);
					mb[3].UpdatePos(x+2,y);
					break;
				}
			case 3 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x,y-2);
					mb[2].UpdatePos(x+1,y-2);
					mb[3].UpdatePos(x,y);
					break;
				}
			case 4 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+2,y-1);
					mb[3].UpdatePos(x+2,y);
					break;
				}
			}
			break;		
		}
	case TYPE_Z:
		{
			switch(rtype)
			{
			case 1 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+1,y);
					mb[3].UpdatePos(x+2,y);
					break;
				}
			case 2 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x,y);
					mb[2].UpdatePos(x+1,y-1);
					mb[3].UpdatePos(x+1,y-2);
					break;
				}
			case 3 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+1,y);
					mb[3].UpdatePos(x+2,y);
					break;
				}
			case 4 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x,y);
					mb[2].UpdatePos(x+1,y-1);
					mb[3].UpdatePos(x+1,y-2);
					break;
				}
			}
			break;	
		}
	case TYPE_S:
		{
			switch(rtype)
			{
			case 1 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x+1,y-1);
					mb[1].UpdatePos(x+1,y);
					mb[2].UpdatePos(x+2,y-1);
					mb[3].UpdatePos(x,y);
					break;
				}
			case 2 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+1,y);
					mb[3].UpdatePos(x,y-2);
					break;
				}
			case 3 :
				{
					if(x>=8)x=7;
					mb[0].UpdatePos(x+1,y-1);
					mb[1].UpdatePos(x+1,y);
					mb[2].UpdatePos(x+2,y-1);
					mb[3].UpdatePos(x,y);
					break;
				}
			case 4 :
				{
					if(x>=9)x=8;
					mb[0].UpdatePos(x,y-1);
					mb[1].UpdatePos(x+1,y-1);
					mb[2].UpdatePos(x+1,y);
					mb[3].UpdatePos(x,y-2);
					break;
				}
			}
			break;		
		}
	case TYPE_NULL:
		{
			mb[0].SetInvisible(FALSE);
			mb[1].SetInvisible(FALSE);
			mb[2].SetInvisible(FALSE);
			mb[3].SetInvisible(FALSE);
		}
	}
	mb[0].SetColor(color);
	mb[1].SetColor(color);
	mb[2].SetColor(color);
	mb[3].SetColor(color);

	this->posx=x;
	this->posy=y;
	this->color=color;
	this->eletype=etype;
	this->rottype=rtype;
	IsStone=FALSE;
}

void CMatrixElement::DrawElement(CDC * pDC)
{
	mb[0].DrawBox(pDC);
		mb[1].DrawBox(pDC);
			mb[2].DrawBox(pDC);
				mb[3].DrawBox(pDC);
}

void CMatrixElement::Roate(void)
{
	if(++rottype==5)
		rottype=1;
	UpdateElement(posx, posy, eletype,rottype,color);
}

int CMatrixElement::DropDown(int steps)
{
	BOOL	flag=TRUE;
	flag&=mb[0].DropDown(steps);
		flag&=mb[1].DropDown(steps);
			flag&=mb[2].DropDown(steps);
				flag&=mb[3].DropDown(steps);

	this->posy+=steps;
	return flag;
}

int CMatrixElement::MoveLeft(int steps)
{
	UpdateElement(--posx,posy,eletype,rottype,color);
	return 0;
}

int CMatrixElement::MoveRight(int steps)
{
	UpdateElement(++posx,posy,eletype,rottype,color);
	return 0;
}

void CMatrixElement::SetInvisible(BOOL types)
{
		mb[0].SetInvisible(types);
		mb[1].SetInvisible(types);
		mb[2].SetInvisible(types);
		mb[3].SetInvisible(types);
}


