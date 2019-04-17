/***********************************************************************************
*auth：leonli@futunn.com
*date:2019/02/28
*name:D:\MyProject\VirtualMFC\VirtualMFC\MFC.cpp
*Ver: V1.0.0
***********************************************************************************/
#include "stdafx.h"
#include "MFC.h"
#include "MyMFC.h"

extern CWinMyApp theApp;

NAMESPACE_BEGIN

CRunTimeClass* CRunTimeClass::pFirstClass = nullptr;

MY_IMPLEMENT_DYNAMIC(CCmdTarget, CObject)
MY_IMPLEMENT_DYNAMIC(CWinThread, CCmdTarget)
MY_IMPLEMENT_DYNAMIC(CWinApp, CWinThread)
MY_IMPLEMENT_DYNAMIC(CView, CWnd)
MY_IMPLEMENT_DYNAMIC(CDocument, CCmdTarget)
MY_IMPLEMENT_DYNCREATE(CWnd, CCmdTarget)
MY_IMPLEMENT_DYNCREATE(CFrameWnd, CWnd)

CObject::CObject()
{

}

CObject::~CObject()
{

}

bool CObject::IsKindOf(CRunTimeClass *pClass)
{
	//虚函数，基类可以拿到自己的静态成员变量
	auto pCurClass = GetRunTimeClass();
	while (pCurClass)
	{
		if (pCurClass == pClass)
		{
			return true;
		}
		pCurClass = pCurClass->pBaseClass;
	}
	return false;
}

CRunTimeClass CObject::classCObject = { "CObject", sizeof(CObject), NULL };
static MyStruct initCObject(&CObject::classCObject);

CRunTimeClass* CObject::GetRunTimeClass() const
{
	return &CObject::classCObject;
}

CCmdTarget::CCmdTarget()
{

}

CCmdTarget::~CCmdTarget()
{

}

CWinThread::CWinThread()
{

}

CWinThread::~CWinThread()
{

}

CWinApp::CWinApp()
{
	m_pCurWinApp = this;
}

CWinApp::~CWinApp()
{

}

void CWinApp::Run()
{
	std::cout << "CWinApp::Run! \n";
}

CWnd::CWnd()
{
	Create();
}

CWnd::~CWnd()
{

}

void CWnd::Create()
{
	std::cout << "CWnd::Create! \n";
}

void CWnd::CreateEx()
{
	std::cout << "CWnd::CreateEx! \n";
	PreCreateWnd();
}

void CWnd::PreCreateWnd()
{
	std::cout << "CWnd::PreCreateWnd! \n";
}

CView::CView()
{

}

CView::~CView()
{

}

CFrameWnd::CFrameWnd()
{
	Create();
}

CFrameWnd::~CFrameWnd()
{

}

void CFrameWnd::Create()
{
	std::cout << "CFrameWnd::Create! \n";
	CreateEx();
}

void CFrameWnd::PreCreateWnd()
{
	std::cout << "CFrameWnd::PreCreateWnd! \n";
}

CDocument::CDocument()
{

}

CDocument::~CDocument()
{

}

CWinApp* AfxGetApp()
{
	return theApp.m_pCurWinApp;
}



NAMESPACE_END