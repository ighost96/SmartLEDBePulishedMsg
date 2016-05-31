// AddAffirmDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "AddAffirmDlg.h"
#include "afxdialogex.h"
#include "SingleDemonDlg.h"


// CAddAffirmDlg 对话框

IMPLEMENT_DYNAMIC(CAddAffirmDlg, CDialogEx)

CAddAffirmDlg::CAddAffirmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddAffirmDlg::IDD, pParent)
{

}

CAddAffirmDlg::~CAddAffirmDlg()
{
}

void CAddAffirmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_, m_edtAdd);
}


BEGIN_MESSAGE_MAP(CAddAffirmDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_ADD, &CAddAffirmDlg::OnBnClickedButtAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddAffirmDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAddAffirmDlg 消息处理程序


void CAddAffirmDlg::OnBnClickedButtAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edtAdd.GetWindowText(strEditAdd);
	strEditAdd.Replace(" ","");
	if (strEditAdd.IsEmpty())
	{
		MessageBox("输入框为空,请输入内容","温馨提示",MB_OK);
		return;
	}
	else
	{
		CDialogEx::OnOK();
	}
}


BOOL CAddAffirmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_edtAdd.LimitText(25);

	GetDlgItem(IDC_BUTT_ADD)->SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CAddAffirmDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CAddAffirmDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


BOOL CAddAffirmDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message==WM_KEYDOWN &&pMsg->wParam==VK_RETURN)
	{
		OnBnClickedButtAdd();
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
