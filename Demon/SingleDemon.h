
// SingleDemon.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "ADOInterface.h"
#include "Config.h"

// CSingleDemonApp:
// 有关此类的实现，请参阅 SingleDemon.cpp
//

class CSingleDemonApp : public CWinApp
{
public:
	CSingleDemonApp();

// 重写
public:
	virtual BOOL InitInstance();
	
	BOOL OpenDataBase(DATABASEINFO databaseinfo);


// 实现

	ADOInterface m_ado;
	CConfig m_config;


	//选中的发布字模编号
	CString strMSGNum1;
	CString strMSGNum2;
	CString strMSGNum3;
	CString strMSGNum4;
	CString strMSGNum5;
	CString strMSGNum6;
	CString strMSGNum7;
	CString strMSGNum8;
	//选中的发布字模内容
	CString strMSGContent1;
	CString strMSGContent2;
	CString strMSGContent3;
	CString strMSGContent4;
	CString strMSGContent5;
	CString strMSGContent6;
	CString strMSGContent7;
	CString strMSGContent8;
	
	//当前登陆用户名:
	CString strUserName;


	DECLARE_MESSAGE_MAP()
};

extern CSingleDemonApp theApp;