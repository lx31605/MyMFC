/***********************************************************************************
*auth£ºleonli@futunn.com
*date:2019/02/28
*name:D:\MyProject\VirtualMFC\VirtualMFC\MFC.h
*Ver: V1.0.0
***********************************************************************************/
#pragma once
#include <iostream>

namespace minimfc
{
	struct CObject
	{
		CObject();
		~CObject();
	};

	struct CCmdTarget :public CObject
	{
		CCmdTarget();
		~CCmdTarget();
	};

	struct CWinThread :public CCmdTarget
	{
		CWinThread();
		~CWinThread();
	};

	struct CWnd :public CCmdTarget
	{
		CWnd();
		~CWnd();

		virtual void Create();
		virtual void CreateEx();
		virtual void PreCreateWnd();
	};

	struct CWinApp :public CWinThread
	{
		CWinApp();
		~CWinApp();
		CWinApp* m_pCurWinApp = nullptr;
		CWnd* m_pWnd = nullptr;

		virtual void InitApplication() = 0;
		virtual void InitInstance() = 0;
		virtual void Run();
	};

	struct CView :public CWnd
	{
		CView();
		~CView();
	};

	struct CFrameWnd :public CWnd
	{
		CFrameWnd();
		~CFrameWnd();

		virtual void Create();
		virtual void PreCreateWnd();
	};

	struct CDocument :public CCmdTarget
	{
		CDocument();
		~CDocument();
	};

	//È«¾Öº¯Êý
	CWinApp* AfxGetApp();
}
