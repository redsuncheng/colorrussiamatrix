#include "MatricBox.h"

#pragma once

// CMatrixElement command target

//element type that means not exists
#define TYPE_NULL	0
//basic element types
#define TYPE_I		1
#define TYPE_O		2
#define TYPE_T		3
#define TYPE_J		4
#define TYPE_L		5
#define TYPE_Z		6
#define TYPE_S		7

#define ROT_1		1
#define ROT_2		2
#define ROT_3		3
#define ROT_4		4

class CMatrixElement : public CObject
{
public:
	CMatricBox mb[4];
	int posx,posy;
	int color;
	int eletype,rottype;
	BOOL IsStone;
	CMatrixElement();
	virtual ~CMatrixElement();
	void UpdateElement(int x, int y, int elementtype,int roatetype,int color);
	void DrawElement(CDC * pDC);
	void Roate(void);
	int DropDown(int steps);
	int MoveLeft(int steps);
	int MoveRight(int steps);
	void SetInvisible(BOOL types);

};


