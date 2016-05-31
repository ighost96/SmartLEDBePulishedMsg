#include "StdAfx.h"
#include "Config.h"

#define INIFILE "\\Config.ini"
#define LENGTH 1024

CConfig::CConfig(void)
{
	TCHAR chPath[MAX_PATH] = {0};
	GetModuleFileName(NULL, chPath, MAX_PATH);
	m_strAppPath = chPath;
	m_strAppPath = m_strAppPath.Left(m_strAppPath.ReverseFind('\\'));
	m_nDefaultMerge = 0;
}


CConfig::~CConfig(void)
{
}

BOOL CConfig::ReadIni()
{
	CString strIniFileName = m_strAppPath + INIFILE;
	CFileFind fd;
	BOOL bFind = fd.FindFile(strIniFileName);
	fd.Close();
	if (!bFind)
	{
		MessageBox(NULL, "配置文件不存在！", "提示", MB_OK);
		return FALSE;
	}
	
	m_databaseinfo.m_nDBType = GetPrivateProfileInt("Database", "DBType", 0, strIniFileName);//数据库类型 0=SqlServer 1=Access 2=Oracle
	TCHAR chTemp[LENGTH] = {0};
	GetPrivateProfileString("Database", "DBServer", "", chTemp, LENGTH, strIniFileName);
	m_databaseinfo.sDBServer = chTemp;

	GetPrivateProfileString("Database", "DBName", "", chTemp, LENGTH, strIniFileName);
	m_databaseinfo.sDBName = chTemp;

	GetPrivateProfileString("Database", "UserID", "", chTemp, LENGTH, strIniFileName);
	m_databaseinfo.sDBUser = chTemp;

	GetPrivateProfileString("Database", "Password", "", chTemp, LENGTH, strIniFileName);
	m_databaseinfo.sDBPsw = chTemp;

	GetPrivateProfileString("Database", "FailoverPartner", "", chTemp, LENGTH, strIniFileName);
	m_databaseinfo.sFailover_Partner = chTemp;

	GetPrivateProfileString("System", "HospitalName", "", chTemp, LENGTH, strIniFileName);
	m_strHospitalName = chTemp;

	m_nDefaultMerge = GetPrivateProfileInt("System", "DefaultMerge", 0, strIniFileName);

	return TRUE;
}
