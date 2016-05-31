#pragma once

#include "AffirmManage.h"

// CGetMessage

class CGetMessage : public CWinThread
{
	DECLARE_DYNCREATE(CGetMessage)

protected:
	CGetMessage();           // 动态创建所使用的受保护的构造函数
	virtual ~CGetMessage();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()

protected:
	CAffirmManage m_dlg;
};


