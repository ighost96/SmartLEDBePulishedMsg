//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
#define AFX_ADOINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _DBOPERATE
#define ADODB_CLS __declspec(dllexport)
#else
#define ADODB_CLS __declspec(dllimport)
#endif

#include "DBBaseInterface.h"
//**********************************************************************************
class ADODB_CLS ADOInterface : public DBBaseInterface
{
public:
	ADOInterface();
	virtual ~ADOInterface();

public:
	BOOL SetDatabase(_ConnectionPtr pConn);//jia080325设置外部数据库指针，不需要内部建立新连接
//打开连接字符串为sConnect的数据库
	BOOL OpenConnect(const CString &sConnect);
//打开ODBC数据源,sDataSource, 用户名sUserId, 密码sPassword
	BOOL OpenODBC(const CString & sDataSource, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const BOOL bSQLRSet = 0);
//打开ACCESS数据库,文件绝对路径sFilename, 用户名sUserId, 密码sPassword.ACCESS版本属性iVersionFlag
	BOOL OpenAccess(const CString & sFilename, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const int iVersionFlag = 0);
//打开SQL Server数据库,服务器名称sServer, 数据库名称sDatabaseName, 用户名sUserId, 密码sPassword
	//jia081118增加对镜像库的连接支持
	BOOL OpenSQLServer(const CString & sServer, const CString & sDatabaseName, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const CString& sMirror=_T(""));
//打开Oracle数据库,数据库实例sDSN, 用户名sUserId, 密码sPassword
	BOOL OpenOracle(const CString & sDSN, const CString & sUserId = _T(""), const CString & sPassword = _T(""));
//重新打开数据库
	BOOL ReOpen(void);

//关闭数据库
	BOOL CloseDatabase(void);
//关闭记录集
	BOOL CloseRecord(void);
//从其他DBBaseInterface对象dbbaseinterface拷贝一个连接
	BOOL CopyDatabase(const DBBaseInterface * pDBBaseInterface);

//执行查询语句为sql的查询操作,指定查询属性flag
	BOOL ExecuteSelect(const CString & sql, const long flag = 0);
//执行insert, update, delete的sql的操作,指定执行属性flag
	BOOL ExecuteSql(const CString & sql, const long flag = 0);
//执行insert, update, delete的sql的操作,指定执行属性flag. arraySql中是sql语句的数组
	BOOL ExecuteSql(const CStringArray & arraySql, const long flag = 0);

//执行存储过程 add by qinwl 2014-3-1 只支持两种类型参数 int,char
	BOOL ExecuteStoreProc(CString sql,CString& err);

//获取字符字段sField的值，放入sVal里,由bEmpty控制是否默认为空
	BOOL GetString(const CString & sField, CString &sVal, BOOL bEmpty = TRUE);
//获取任意类型字段sField的值,放入sVal中,VT_NULL,VT_EMPTY返回空字串 add by qinwl 2012-6-11
	BOOL GetStringEx(const CString & sField, CString &sVal);
//获取字段名称 add by qinwl 2014-2-25
	BOOL GetFieldNames(CStringArray& ar);
//获取整形字段sField的值，放入nVal里,由bReset控制是否默认为0
	BOOL GetInt(const CString & sField, int &nVal, BOOL bReset = TRUE);
//获取时间字段sField的值，放入Val里,由bDefault控制是否默认为当前时间
	BOOL GetDateTime(const CString & sField, COleDateTime & Val, BOOL bDefault = TRUE);
//获取浮点字段sField的值，放入dVal里,由bReset控制是否默认为0
	BOOL GetFloat(const CString & sField, double & dVal, BOOL bReset = TRUE);
//获取货币字段sField的值，放入Val里,由bReset控制是否默认为0
	BOOL GetCurrency(const CString & sField, COleCurrency & Val, BOOL bReset = TRUE);
//获取BOOL字段sField的值，放入bVal里,由bReset控制是否默认为假
	BOOL GetBOOL(const CString & sField, BOOL & bVal, BOOL bReset = TRUE);

//查看是否到了记录集尾部
	BOOL IsEOF(void);
//将记录集向下移动一条记录
	BOOL MoveNext(void);
//获取连接指针
	_ConnectionPtr GetConnect(void){return m_pConnection;};
//获取记录指针
	_RecordsetPtr GetRecordSet(void){return m_pSet;};
//获取数据库连接字符串
	CString GetConnectString(void){return m_sConnect;};
//测试数据库是否已经连接
	BOOL isDbOpen();
private:
	_ConnectionPtr m_pConnection;			//ADO指针
	_ConnectionPtr m_pLocalConnection;		//保持本地自己打开的数据库指针，用于比较和关闭判断//jia081118
	_RecordsetPtr  m_pSet;					//ADO记录集指针	
	BOOL m_bADOOpenByMySelf;				//是否数据库由本身打开
	CString		   m_sConnect;				//数据库连接字符串
};

#endif // !defined(AFX_ADOINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
