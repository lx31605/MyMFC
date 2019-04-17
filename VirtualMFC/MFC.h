/***********************************************************************************
*auth£ºleonli@futunn.com
*date:2019/02/28
*name:D:\MyProject\VirtualMFC\VirtualMFC\MFC.h
*Ver: V1.0.0
***********************************************************************************/
#pragma once
#include <iostream>
#include "commondefine.h"

NAMESPACE_BEGIN

struct CObject;
struct MyStruct;

#define MY_RUNTIME_CLASS(className) (&className::class##className)
#define MY_DECLARE_DYNAMIC(className) \
public:\
	static CRunTimeClass class##className; \
	virtual CRunTimeClass* GetRunTimeClass() const;\

#define MY_IMPLEMENT_DYNAMIC(className,baseClassName) \
	static char* sz##className = #className;\
	CRunTimeClass className::class##className = \
	{\
		sz##className,\
		sizeof(className),\
		MY_RUNTIME_CLASS(baseClassName),\
	};\
	static MyStruct init##className(&className::class##className);\
	CRunTimeClass* className::GetRunTimeClass() const\
	{\
		return &className::class##className;\
	}\

#define MY_DECLARE_DYNCREATE(className) \
	MY_DECLARE_DYNAMIC(className)\
	static CObject* CreateObject();\

#define MY_IMPLEMENT_DYNCREATE(className,baseClassName) \
	static char* sz##className = #className;\
	CRunTimeClass className::class##className = \
	{\
		sz##className,\
		sizeof(className),\
		MY_RUNTIME_CLASS(baseClassName),\
		className::CreateObject\
	};\
	static MyStruct init##className(&className::class##className);\
	CRunTimeClass* className::GetRunTimeClass() const\
	{\
		return &className::class##className;\
	}\
	CObject* className::CreateObject()\
	{\
		return new className;\
	}\


struct CRunTimeClass
{
	using FuncCreate = CObject*(*)(void);

	CRunTimeClass(){}
	CRunTimeClass(char* pName, int nClassSize, CRunTimeClass* pClass)
	{
		pClassName = pName;
		nSize = nClassSize;
		pBaseClass = pClass;
	}

	CRunTimeClass(char* pName, int nClassSize, CRunTimeClass* pClass, FuncCreate pFun)
	{
		pClassName = pName;
		nSize = nClassSize;
		pBaseClass = pClass;
		m_pfnCreateObject = pFun;
	}

	CObject* CreateObject()
	{
		if (m_pfnCreateObject)
		{
			return m_pfnCreateObject();
		}
		return nullptr;
	}

	static CRunTimeClass* pFirstClass;

	char* pClassName = nullptr;
	int nSize = 0;

	CRunTimeClass* pNextClass = nullptr;
	CRunTimeClass* pBaseClass = nullptr;
	FuncCreate m_pfnCreateObject = nullptr;
};

struct MyStruct
{
	MyStruct(CRunTimeClass *pClass)
	{
		pClass->pNextClass = CRunTimeClass::pFirstClass;
		CRunTimeClass::pFirstClass = pClass;
	};
};

struct CObject
{
	CObject();
	~CObject();

	bool IsKindOf(CRunTimeClass *pClass);

	static CRunTimeClass classCObject;
	virtual CRunTimeClass* GetRunTimeClass() const;
};

struct CCmdTarget :public CObject
{
	MY_DECLARE_DYNAMIC(CCmdTarget)
	CCmdTarget();
	~CCmdTarget();
};

struct CWinThread :public CCmdTarget
{
	MY_DECLARE_DYNAMIC(CWinThread)
	CWinThread();
	~CWinThread();
};

struct CWnd :public CCmdTarget
{
	MY_DECLARE_DYNCREATE(CWnd)
	CWnd();
	~CWnd();

	virtual void Create();
	virtual void CreateEx();
	virtual void PreCreateWnd();
};

struct CWinApp :public CWinThread
{
	MY_DECLARE_DYNAMIC(CWinApp)
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
	MY_DECLARE_DYNAMIC(CView)
	CView();
	~CView();
};

struct CFrameWnd :public CWnd
{
	MY_DECLARE_DYNCREATE(CFrameWnd)
	CFrameWnd();
	~CFrameWnd();

	virtual void Create();
	virtual void PreCreateWnd();
};

struct CDocument :public CCmdTarget
{
	MY_DECLARE_DYNAMIC(CDocument)
	CDocument();
	~CDocument();
};

//È«¾Öº¯Êý
CWinApp* AfxGetApp();

NAMESPACE_END
