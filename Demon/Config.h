#pragma once

typedef struct _TagDataBaseInfo
{
	CString sDBServer;//数据库服务器
	CString sDBName; //数据库名称，如果数据库服务器为空，则该项为ODBC数据源
	CString sFailover_Partner;//镜像数据库实例
	CString sDBUser; //数据库用户名
	CString sDBPsw; //数据库密码
	int     m_nDBType;//数据库类型 0=SqlServer 1=Access 2=Oracle
} DATABASEINFO;


class CConfig
{
public:
	CConfig(void);
	~CConfig(void);

	BOOL ReadIni();

public:
	CString m_strAppPath;
	CString m_strHospitalName;
	int m_nDefaultMerge;		// 0:不合并 1：自动合并  2：手动合并
	DATABASEINFO m_databaseinfo;
};

