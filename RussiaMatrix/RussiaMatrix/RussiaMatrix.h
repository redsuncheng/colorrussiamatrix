// RussiaMatrix.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRussiaMatrixApp:
// �йش����ʵ�֣������ RussiaMatrix.cpp
//

class CRussiaMatrixApp : public CWinApp
{
public:
	CRussiaMatrixApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRussiaMatrixApp theApp;