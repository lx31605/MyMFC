/***********************************************************************************
*auth��leonli@futunn.com
*date:2019/02/28
*name:D:\MyProject\VirtualMFC\VirtualMFC\MyMFC.cpp
*Ver: V1.0.0
***********************************************************************************/
#include "stdafx.h"
#include "MyMFC.h"

CWinMyApp theApp;

CWinMyApp::CWinMyApp()
{

}

CWinMyApp::~CWinMyApp()
{
	delete m_pWnd;
	m_pWnd = nullptr;
}

void CWinMyApp::InitApplication()
{
	//ע�ᴰ��
	std::cout << "CWinMyApp::InitApplication! \n";
}

void CWinMyApp::InitInstance()
{
	//��������
	std::cout << "CWinMyApp::InitInstance! \n";
	m_pWnd = new minimfc::CFrameWnd;
}
