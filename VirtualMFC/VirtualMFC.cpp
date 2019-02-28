// VirtualMFC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MFC.h"
#include "MyMFC.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//类似工厂模式
	minimfc::CWinApp* pMyApp = minimfc::AfxGetApp();
	pMyApp->InitApplication();
	pMyApp->InitInstance();
	pMyApp->Run();

	system("pause");
	return 0;
}

