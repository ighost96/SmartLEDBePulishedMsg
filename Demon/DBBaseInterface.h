//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBBASEINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
#define AFX_DBBASEINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _DBOPERATE
#define DBBASEINTERFACE_CLS __declspec(dllexport)
#else
#define DBBASEINTERFACE_CLS __declspec(dllimport)
#endif

class CLogFileInterface;
//**********************************************************************************
class DBBASEINTERFACE_CLS DBBaseInterface  
{
public:
	DBBaseInterface();
	virtual ~DBBaseInterface();

public:
//打开连接字符串为sConnect的数据库
	virtual BOOL OpenConnect(const CString &sConnect) = 0;
//打开ODBC数据源,sDataSource, 用户名sUserId, 密码sPassword
	virtual BOOL OpenODBC(const CString & sDataSource, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const BOOL bSQLRSet = 0) = 0;
//打开ACCESS数据库,文件绝对路径sFilename, 用户名sUserId, 密码sPassword.ACCESS版本属性iVersionFlag
	virtual BOOL OpenAccess(const CString & sFilename, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const int iVersionFlag = 0) = 0;
//打开SQL Server数据库,服务器名称sServer, 数据库名称sDatabaseName, 用户名sUserId, 密码sPassword
	virtual BOOL OpenSQLServer(const CString & sServer, const CString & sDatabaseName, const CString & sUserId = _T(""), const CString & sPassword = _T(""), const CString& sMirror= _T("")) = 0;
//打开Oracle数据库,实例名称sDSN, 用户名sUserId, 密码sPassword
	virtual BOOL OpenOracle(const CString & sDSN, const CString & sUserId = _T(""), const CString & sPassword = _T("")) = 0;
//重新打开数据库
	virtual BOOL ReOpen(void) = 0;
//关闭记录集
	virtual BOOL CloseRecord(void) = 0;
//关闭数据库
	virtual BOOL CloseDatabase(void) = 0;
//从其他DBBaseInterface对象dbbaseinterface拷贝一个连接
	virtual BOOL CopyDatabase(const DBBaseInterface * pDBBaseInterface) = 0;

//执行查询语句为sql的查询操作,指定查询属性flag
	virtual BOOL ExecuteSelect(const CString & sql, const long flag = 0) = 0;
//执行insert, update, delete的sql的操作,指定执行属性flag
	virtual BOOL ExecuteSql(const CString & sql, const long flag) = 0;
//执行insert, update, delete的sql的操作,指定执行属性flag. arraySql中是sql语句的数组
	virtual BOOL ExecuteSql(const CStringArray & arraySql, const long flag) = 0;

//获取字符字段sField的值，放入sVal里,由bEmpty控制是否默认为空
	virtual BOOL GetString(const CString & sField, CString &sVal, BOOL bEmpty = TRUE) = 0;
//获取整形字段sField的值，放入nVal里,由bReset控制是否默认为0
	virtual BOOL GetInt(const CString & sField, int &nVal, BOOL bReset = TRUE) = 0;
//获取时间字段sField的值，放入Val里,由bDefault控制是否默认为当前时间
	virtual BOOL GetDateTime(const CString & sField, COleDateTime & Val, BOOL bDefault = TRUE) = 0;
//获取浮点字段sField的值，放入dVal里,由bReset控制是否默认为0
	virtual BOOL GetFloat(const CString & sField, double & dVal, BOOL bReset = TRUE) = 0;
//获取货币字段sField的值，放入Val里,由bReset控制是否默认为0
	virtual BOOL GetCurrency(const CString & sField, COleCurrency & Val, BOOL bReset = TRUE) = 0;
//获取BOOL字段sField的值，放入bVal里,由bReset控制是否默认为假
	virtual BOOL GetBOOL(const CString & sField, BOOL & bVal, BOOL bReset = TRUE) = 0;

//查看是否到了记录集尾部
	virtual BOOL IsEOF(void) = 0;
//将记录集向下移动一条记录
	virtual BOOL MoveNext(void) = 0;

//设置执行sql语句的日志记录文件
	void SetLogFile(const CString &sFilename);
//获取日志文件名
	CString GetLogFile(void);
protected:
	CLogFileInterface*		m_pLogfileinterface;	//执行SQL语句的日志文件接口
public:
	int						m_iClsID;				//类的ID	
};

#endif // !defined(AFX_DBBASEINTERFACE_H__744EC655_C78A_41AC_AF67_DFB150D67A3A__INCLUDED_)
