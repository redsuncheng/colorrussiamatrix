// MatrixView.cpp : implementation file
//

#include "stdafx.h"
#include "RussiaMatrix.h"
#include "MatrixView.h"
#include "math.h"
#include "time.h"
int ypos=1;
// CMatrixView
int BoundFlag=0;
IMPLEMENT_DYNAMIC(CMatrixView, CStatic)

CMatrixView::CMatrixView()
{
	IsInitial=FALSE;
	IsRunning=FALSE;
	IsPause=FALSE;
	NeedRedraw=TRUE;
	score=0;
	srand( (unsigned)time( NULL ) );
	colormatrix[0]=RED;
	colormatrix[1]=GREEN;
	colormatrix[2]=BLUE;
	colormatrix[3]=RGB(255,255,0);
	colormatrix[4]=RGB(255,0,255);
	colormatrix[5]=RGB(0,255,255);
	colormatrix[6]=::GetSysColor(COLOR_WINDOW);


	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
		{
			this->mbArray[i][j]=new CMatricBox();
			this->mbArray[i][j]->UpdatePos(i,j);
			this->mbArray[i][j]->SetColor(RGB(0,0,0));
			this->mbArray[i][j]->SetInvisible(FALSE);
		}

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			this->mbArray2[i][j]=new CMatricBox();
			this->mbArray2[i][j]->UpdatePos(i+10,j);
			this->mbArray2[i][j]->SetColor(RGB(0,0,0));
			this->mbArray2[i][j]->SetInvisible(TRUE);
		}
	GenerateNewElement();
}

CMatrixView::~CMatrixView()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
		{
			delete this->mbArray[i][j];
		}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			delete this->mbArray2[i][j];
		}
	delete m_pMDC;
}


BEGIN_MESSAGE_MAP(CMatrixView, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_TIMER()
//	ON_WM_CHAR()
//ON_WM_SIZE()
//ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()



// CMatrixView message handlers



BOOL CMatrixView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return CStatic::OnEraseBkgnd(pDC);
}

void CMatrixView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages
	CRect rt;
	//if(NeedRedraw)
	{
		CBrush br_bk;
		CPen   pen;
		pen.CreatePen(PS_SOLID,1,RGB(0,255,0));
		br_bk.CreateSolidBrush(RGB(0,0,0));//::GetSysColor(COLOR_WINDOW));

		this->GetClientRect(&rt);
		/***********Draw the BackGround*************/
		m_pMDC->FillRect(&rt,&br_bk);
		m_pMDC->SelectObject(&pen);
		m_pMDC->SelectObject(&br_bk);
		m_pMDC->Rectangle(0,0,14*BOX_WIDTH,20*BOX_WIDTH);
		m_pMDC->Rectangle(0,0,10*BOX_WIDTH,20*BOX_WIDTH);
		NeedRedraw=FALSE;
	}
	/***********Draw the ClientArea*************/
	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
		{
			if(this->mbArray[i][j]->IsVisible)
				this->mbArray[i][j]->DrawBox(m_pMDC);
		}

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(this->mbArray2[i][j]->IsVisible)
				this->mbArray2[i][j]->DrawBox(m_pMDC);
		}

	mae.DrawElement(m_pMDC);
	/***********Drawing the score infomation*************/
	m_pMDC->SetBkMode(TRANSPARENT);
	m_pMDC->SetTextColor(RGB(255,255,255));
	m_pMDC->TextOut(10*BOX_WIDTH,4*BOX_WIDTH+10,"SCORE:");
	CString str;
	str.Format("%d",score);
	m_pMDC->TextOut(10*BOX_WIDTH,4*BOX_WIDTH+30,str);
	/***********Finish Drawing on the Screen*************/
	dc.BitBlt(0, 0, rt.Width(),rt.Height(), m_pMDC, 0, 0, SRCCOPY);
}

int CMatrixView::SetMyTimer(void)
{
	this->SetTimer(0,500,NULL);
	IsRunning=TRUE;
	return 0;
}

void CMatrixView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	this->DropDown(1);
	this->DealWinner(0);
}

int CMatrixView::MoveLeft(int steps)
{
	if(IsPause)return 0;
	int i,j;
	if(mae.IsStone)return 0;

	i=mae.mb[0].xpos;
	j=mae.mb[0].ypos;
	if(i==0)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i-1][j]->IsVisible==TRUE)
		return TRUE;

	i=mae.mb[1].xpos;
	j=mae.mb[1].ypos;
	if(i==0)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i-1][j]->IsVisible==TRUE)
		return TRUE;

	i=mae.mb[2].xpos;
	j=mae.mb[2].ypos;
	if(i==0)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i-1][j]->IsVisible==TRUE)
		return TRUE;
	
	i=mae.mb[3].xpos;
	j=mae.mb[3].ypos;
	if(i==0)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i-1][j]->IsVisible==TRUE)
		return TRUE;

	mae.SetInvisible(FALSE);
	mae.MoveLeft(steps);
	mae.SetInvisible(TRUE);
	this->RedrawWindow();
	return 0;
}

int CMatrixView::MoveRight(int steps)
{
	if(IsPause)return 0;
	int i,j;

	if(mae.IsStone)return 0;

	i=mae.mb[0].xpos;
	j=mae.mb[0].ypos;
	if(i==9)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i+1][j]->IsVisible==TRUE)
		return TRUE;

	i=mae.mb[1].xpos;
	j=mae.mb[1].ypos;
	if(i==9)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i+1][j]->IsVisible==TRUE)
		return TRUE;

	i=mae.mb[2].xpos;
	j=mae.mb[2].ypos;
	if(i==9)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i+1][j]->IsVisible==TRUE)
		return TRUE;
	
	i=mae.mb[3].xpos;
	j=mae.mb[3].ypos;
	if(i==9)return FALSE;
	if(j<0)return FALSE;
	if(mbArray[i+1][j]->IsVisible==TRUE)
		return TRUE;

	mae.SetInvisible(FALSE);
	mae.MoveRight(steps);
	mae.SetInvisible(TRUE);
	this->RedrawWindow();
	return 0;
}

int CMatrixView::Roate(void)
{
	if(IsPause)return 0;
	if(mae.IsStone)return 0;

	mae.Roate();
	this->RedrawWindow();
	return 0;
}


BOOL CMatrixView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_SPACE	:	
			{
				if(!IsRunning)
				{
					IsInitial=FALSE;NewGame();this->SetMyTimer();
				}
				else
				{
					if(!IsPause)
					{
						this->KillTimer(0);
						IsPause=TRUE;
					}
					else
					{
						this->SetTimer(0,500,NULL);
						IsPause=FALSE;
					}
				}
				break;
			}
		case VK_UP		:	if(IsPause)return 0;this->Roate();break;
		case VK_LEFT	:	if(IsPause)return 0;this->MoveLeft(1);break;
		case VK_RIGHT	:	if(IsPause)return 0;this->MoveRight(1);break;
		case VK_DOWN	:	if(IsPause)return 0;this->DropDown(1);break;
		}
	}
	if(pMsg->message==WM_KEYUP)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:{ 
							HWND hw=::FindWindow("shell_traywnd",NULL);
							if(::IsWindowVisible(hw))
							{
								::ShowWindow(hw,SW_HIDE);
								long style=GetWindowLong(GetParent()->m_hWnd,GWL_STYLE);   
								style&=~(WS_CAPTION);   
								SetWindowLong(GetParent()->m_hWnd,GWL_STYLE,style);  
								WINDOWPLACEMENT wp;
								this->GetParent()->GetWindowPlacement(&wp);
								wp.showCmd=SW_SHOWMAXIMIZED;
								this->GetParent()->SetWindowPlacement(&wp);
							}
							else
							{
								::ShowWindow(hw,SW_SHOW);
								long style=GetWindowLong(GetParent()->m_hWnd,GWL_STYLE);   
								style|=(WS_CAPTION);   
								SetWindowLong(GetParent()->m_hWnd,GWL_STYLE,style); 
								WINDOWPLACEMENT wp;
								this->GetParent()->GetWindowPlacement(&wp);
								wp.showCmd=SW_SHOWNORMAL;
								this->GetParent()->SetWindowPlacement(&wp);
								
							}
							break;
					  }
		}
	}
	return CStatic::PreTranslateMessage(pMsg);
}

CSize CMatrixView::GetViewSize(void)
{
	CSize sz;
	sz.cx=14*BOX_WIDTH;
	sz.cy=20*BOX_WIDTH;
	return sz;
}
void CMatrixView::DropDown(int steps)
{
	if(CheckStone())
	{	
		if(mae.posy<=3)
		{
			IsRunning=FALSE;
			this->KillTimer(0);
			::AfxMessageBox("你输了，按空格再来一局~");
		}
		NeedRedraw=TRUE;
		this->StoneElement();
		GenerateNewElement();
		return;
	}

	mae.SetInvisible(FALSE);
	mae.DropDown(steps);
	mae.SetInvisible(TRUE);
	this->RedrawWindow();
}

void CMatrixView::StoneElement(void)
{
	mae.IsStone=TRUE;
	int i,j;
	i=mae.mb[0].xpos;
	j=mae.mb[0].ypos;
	this->mbArray[i][j]->SetInvisible(TRUE);
	this->mbArray[i][j]->SetColor(mae.color);

	i=mae.mb[1].xpos;
	j=mae.mb[1].ypos;
	this->mbArray[i][j]->SetInvisible(TRUE);
	this->mbArray[i][j]->SetColor(mae.color);

	i=mae.mb[2].xpos;
	j=mae.mb[2].ypos;
	this->mbArray[i][j]->SetInvisible(TRUE);
	this->mbArray[i][j]->SetColor(mae.color);

	i=mae.mb[3].xpos;
	j=mae.mb[3].ypos;
	this->mbArray[i][j]->SetInvisible(TRUE);
	this->mbArray[i][j]->SetColor(mae.color);


}

BOOL CMatrixView::CheckStone(void)
{
	int i,j;

	if(mae.posy>=19)
		return TRUE;

	i=mae.mb[0].xpos;
	j=mae.mb[0].ypos;
	if(mbArray[i][j+1]->IsVisible==TRUE)
		return TRUE;

	i=mae.mb[1].xpos;
	j=mae.mb[1].ypos;
	if(mbArray[i][j+1]->IsVisible==TRUE)
		return TRUE;

	i=mae.mb[2].xpos;
	j=mae.mb[2].ypos;
	if(mbArray[i][j+1]->IsVisible==TRUE)
		return TRUE;
	i=mae.mb[3].xpos;
	j=mae.mb[3].ypos;
	if(mbArray[i][j+1]->IsVisible==TRUE)
		return TRUE;

	return FALSE;
}

int CMatrixView::CheckWinner(void)
{
	BOOL flag;
	int counter=0;
	for(int j=0;j<20;j++)
	{
		flag=TRUE;
		for(int i=0;i<10;i++)
		{
			flag&=(this->mbArray[i][j]->IsVisible);
		}
		if(flag)
			counter++;
	}
	return counter;
}
void CMatrixView::GenerateNewElement()
{
	int stype,rtype,color;
	stype=1+rand()%7;
	rtype=1+rand()%4;
	color=colormatrix[rand()%7];
	if(!IsInitial)
	{
		oldstype=stype;
		oldrtype=rtype;
		oldcolor=color;	
		stype=1+rand()%7;
		rtype=1+rand()%4;
		color=colormatrix[rand()%7];
	}

	mae.UpdateElement(0,3,stype,rtype,color);
	
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			this->mbArray2[i][j]->SetInvisible(FALSE);

	int i,j;
	i=mae.mb[0].xpos;
	j=mae.mb[0].ypos;
	this->mbArray2[i][j]->SetInvisible(TRUE);
	this->mbArray2[i][j]->SetColor(mae.color);

	i=mae.mb[1].xpos;
	j=mae.mb[1].ypos;
	this->mbArray2[i][j]->SetInvisible(TRUE);
	this->mbArray2[i][j]->SetColor(mae.color);

	i=mae.mb[2].xpos;
	j=mae.mb[2].ypos;
	this->mbArray2[i][j]->SetInvisible(TRUE);
	this->mbArray2[i][j]->SetColor(mae.color);

	i=mae.mb[3].xpos;
	j=mae.mb[3].ypos;
	this->mbArray2[i][j]->SetInvisible(TRUE);
	this->mbArray2[i][j]->SetColor(mae.color);	

	mae.UpdateElement(5,3,oldstype,oldrtype,oldcolor);

	if(!IsInitial)
	{
		mae.SetInvisible(FALSE);
		IsInitial=TRUE;
	}
		oldstype=stype;
		oldrtype=rtype;
		oldcolor=color;	
}

void CMatrixView::DealWinner(int num)
{
	BOOL flag;
	int counter=CheckWinner();
	switch(counter)
	{
		case 0:break;
		case 1:score+=1;break;
		case 2:score+=4;break;
		case 3:score+=9;break;
		case 4:score+=16;break;
	}
	for(int j=0;j<20;j++)
	{
		flag=TRUE;
		for(int i=0;i<10;i++)
		{
			flag&=(this->mbArray[i][j]->IsVisible);
		}
		if(flag)
		{
			for(int m=j-1;m>=0;m--)
			{
				for(int n=0;n<10;n++)
				{
					this->mbArray[n][m+1]->IsVisible=this->mbArray[n][m]->IsVisible;
					this->mbArray[n][m+1]->m_color=this->mbArray[n][m]->m_color;
				}
			}
		}

		this->RedrawWindow();
	}
}
void CMatrixView::NewGame(void)
{
	IsInitial=FALSE;
	IsPause=FALSE;
	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
		{
			this->mbArray[i][j]->UpdatePos(i,j);
			this->mbArray[i][j]->SetColor(RGB(0,0,0));
			this->mbArray[i][j]->SetInvisible(FALSE);
		}

	score=0;
	GenerateNewElement();
}

void CMatrixView::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	
	CStatic::PreSubclassWindow();
}
