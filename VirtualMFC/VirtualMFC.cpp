// VirtualMFC.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MFC.h"
#include "MyMFC.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//���ƹ���ģʽ
	minimfc::CWinApp* pMyApp = minimfc::AfxGetApp();
	pMyApp->InitApplication();
	pMyApp->InitInstance();
	pMyApp->Run();

	system("pause");
	return 0;
}

