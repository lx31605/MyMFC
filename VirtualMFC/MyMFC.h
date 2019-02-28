/***********************************************************************************
*auth£ºleonli@futunn.com
*date:2019/02/28
*name:D:\MyProject\VirtualMFC\VirtualMFC\MyMFC.h
*Ver: V1.0.0
***********************************************************************************/
#pragma once
#include "MFC.h"

struct CWinMyApp:public minimfc::CWinApp
{
	CWinMyApp();
	~CWinMyApp();

	virtual void InitApplication();
	virtual void InitInstance();
};