#pragma once
#include "MatricBox.h"
#include "MatrixElement.h"
#include "MemDC.h"
// CMatrixView

#define RED			RGB(255,0,0)
#define GREEN		RGB(0,255,0)
#define BLUE		RGB(0,0,255)

class CMatrixView : public CStatic
{
	DECLARE_DYNAMIC(CMatrixView)

public:
	CMatrixView();
	virtual ~CMatrixView();
	CMatricBox * mbArray[10][20];
	CMatricBox * mbArray2[4][4];
	CMatrixElement mae;
	int oldstype,oldrtype,oldcolor;
	BOOL IsInitial;
	BOOL IsRunning;
	BOOL IsPause;
	BOOL NeedRedraw;
	int colormatrix[7];
	int score;
	CMemDC * m_pMDC;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	int SetMyTimer(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int MoveLeft(int steps);
	int MoveRight(int steps);
	int Roate(void);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	CSize GetViewSize(void);
	void DropDown(int steps);
	void StoneElement(void);
	BOOL CheckStone(void);
	int CheckWinner(void);
	void GenerateNewElement(void);
	void DealWinner(int num);
	void NewGame(void);
protected:
	virtual void PreSubclassWindow();
};


