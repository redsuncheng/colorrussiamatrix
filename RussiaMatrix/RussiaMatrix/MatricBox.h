#pragma once

// CMatricBox command target
#define BOX_WIDTH	50

class CMatricBox : public CObject
{
public:
	int m_color;
	BOOL IsVisible;
	int xpos;	//zero based width  from 0~9
	int ypos;	//zero based height from 0~19
	CRect m_rt;
	CMatricBox();
	virtual ~CMatricBox();

	void DrawBox(CDC * pDC);
	void UpdatePos(int x, int y);
	void SetColor(int color);
	void SetInvisible(BOOL types);
	int DropDown(int steps);
	int MoveLeft(int steps);
	int MoveRight(int steps);
};


