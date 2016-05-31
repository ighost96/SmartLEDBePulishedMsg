// GetMessage.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "GetMessage.h"


// CGetMessage

IMPLEMENT_DYNCREATE(CGetMessage, CWinThread)

CGetMessage::CGetMessage()
{
	
}

CGetMessage::~CGetMessage()
{
}

BOOL CGetMessage::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	m_dlg.Create(IDD_AFFIRMMANAGE_DIALOG);
	m_dlg.ShowWindow(SW_HIDE);
	m_pMainWnd=&m_dlg;
	return TRUE;
}

int CGetMessage::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	m_dlg.DestroyWindow();

	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CGetMessage, CWinThread)
END_MESSAGE_MAP()


// CGetMessage 消息处理程序
