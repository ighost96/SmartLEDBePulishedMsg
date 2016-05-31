
// SingleDemonDlg.h : 头文件
//



#pragma once
#include "afxwin.h"

#if _MSC_VER > 1000
#endif // _MSC_VER > 1000


#define WM_RECVDATA  WM_USER+200 //定义接收线程用户消息

//定义接收线程消息传递结构体
struct RECVPARAM
{
	SOCKET sock;
	HWND hwnd;
};

// CSingleDemonDlg 对话框
class CSingleDemonDlg : public CDialogEx
{
// 构造
public:
	CSingleDemonDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SINGLEDEMON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg LRESULT  OnRecvData(WPARAM wParam,LPARAM lParam);//声明接收线程消息处理函数

	afx_msg LRESULT  OnRecVPulishMSG(WPARAM wParam,LPARAM lParam);//发布窗口关闭接收消息

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtPulish();
	afx_msg void OnClickedButtMatrixManage();
	afx_msg void OnBnClickedButton00();
	CString strPassWord;
	CString strAddAffirm;
	CString strContentTest;
	void Bytes_Display(char* const chs);
	afx_msg void OnClickedButtLogin();
	//void Bytes_Read_from_HZK16(unsigned char *s, char* const chs);
	afx_msg void OnBnClickedSend();   //发送
	BOOL InitSocket();       //初始化Socket
	static DWORD WINAPI RecvProc(LPVOID lpParameter);//定义接收线程
	afx_msg void OnBnClickedStartButton();	//监听

	unsigned char CheckSumCal(unsigned char *p,int len);


	CRect m_rect;
	//字模数据长度
	long sql_zimudatasize;
	//字模点阵数据字符串
	CString zimuDianzhenStr;
	int iChaChang;
	int iLengthTest;

	CBrush m_brBk;

protected:
	CEdit m_edtUserName;
	CEdit m_edtPassWord;

private:
	SOCKET m_socket;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CStatusBarCtrl  *m_pStatBar;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int ncheck;
	int num;
	BOOL bFlag;
	afx_msg void OnClickedStaticVersion();
	afx_msg void OnBnClickedButtHistory();

	BOOL bClick;
	BOOL bCliiick;
	CToolTipCtrl m_TlTips;
};
