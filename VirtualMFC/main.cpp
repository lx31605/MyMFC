// VirtualMFC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MFC.h"
#include "MyMFC.h"
#include "CommonDefine.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace minimfc;
	//类似工厂模式
	CWinApp* pMyApp = AfxGetApp();
	pMyApp->InitApplication();
	pMyApp->InitInstance();
	pMyApp->Run();

	auto pFirst = CRunTimeClass::pFirstClass;
	while (pFirst)
	{
		std::cout << "className = " << pFirst->pClassName << ":" << std::endl;

		int i = 0;
		auto pBaseClass = pFirst->pBaseClass;
		while (pBaseClass)
		{
			std::cout << "	baseClass" << i << " = " << pBaseClass->pClassName << std::endl;
			++i;
			pBaseClass = pBaseClass->pBaseClass;
		}

		pFirst = pFirst->pNextClass;
	}

	CObject *pWnd = new CWnd;
	bool bRet1 = pWnd->IsKindOf(MY_RUNTIME_CLASS(CObject));
	bool bRet2 = pWnd->IsKindOf(MY_RUNTIME_CLASS(CCmdTarget));
	bool bRet3 = pWnd->IsKindOf(MY_RUNTIME_CLASS(CWinThread));
	std::cout << "bRet1 = " << bRet1 << " bRet2 = " << bRet2 << " bRet3 = " << bRet3 << std::endl;

	std::cout << "Enter the className U want Dynamic Create : " << std::endl;
	char szBuffer[100];
	std::cin >> szBuffer;

	bool bFind = false;
	CRunTimeClass* pFirst1 = CRunTimeClass::pFirstClass;
	CRunTimeClass* pFindClass = nullptr;
	while (pFirst1)
	{
		if (strcmp(pFirst1->pClassName, szBuffer) == 0)
		{
			bFind = true;
			pFindClass = pFirst1;
			break;
		}
		pFirst1 = pFirst1->pNextClass;
	}

	if (bFind)
	{
		CObject *pObject = pFindClass->CreateObject();
	}
	else
	{
		std::cout << "Cannot Find The ClassName!" << std::endl;
	}

	system("pause");
	return 0;
}

