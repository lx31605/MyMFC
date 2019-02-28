/***********************************************************************************
*auth£ºleonli@futunn.com
*date:2019/02/28
*name:D:\MyProject\VirtualMFC\VirtualMFC\MFC.cpp
*Ver: V1.0.0
***********************************************************************************/
#include "stdafx.h"
#include "MFC.h"
#include "MyMFC.h"

extern CWinMyApp theApp;

minimfc::CObject::CObject()
{

}

minimfc::CObject::~CObject()
{

}

minimfc::CCmdTarget::CCmdTarget()
{

}

minimfc::CCmdTarget::~CCmdTarget()
{

}

minimfc::CWinThread::CWinThread()
{

}

minimfc::CWinThread::~CWinThread()
{

}

minimfc::CWinApp::CWinApp()
{
	m_pCurWinApp = this;
}

minimfc::CWinApp::~CWinApp()
{

}

void minimfc::CWinApp::Run()
{
	std::cout << "CWinApp::Run! \n";
}

minimfc::CWnd::CWnd()
{

}

minimfc::CWnd::~CWnd()
{

}

void minimfc::CWnd::Create()
{
	std::cout << "CWnd::Create! \n";
}

void minimfc::CWnd::CreateEx()
{
	std::cout << "CWnd::CreateEx! \n";
	PreCreateWnd();
}

void minimfc::CWnd::PreCreateWnd()
{
	std::cout << "CWnd::PreCreateWnd! \n";
}

minimfc::CView::CView()
{

}

minimfc::CView::~CView()
{

}

minimfc::CFrameWnd::CFrameWnd()
{
	Create();
}

minimfc::CFrameWnd::~CFrameWnd()
{

}

void minimfc::CFrameWnd::Create()
{
	std::cout << "CFrameWnd::Create! \n";
	CreateEx();
}

void minimfc::CFrameWnd::PreCreateWnd()
{
	std::cout << "CFrameWnd::PreCreateWnd! \n";
}

minimfc::CDocument::CDocument()
{

}

minimfc::CDocument::~CDocument()
{

}

minimfc::CWinApp* minimfc::AfxGetApp()
{
	return theApp.m_pCurWinApp;
}
