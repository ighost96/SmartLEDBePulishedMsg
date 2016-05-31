// AboutBox.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "AboutBox.h"
#include "afxdialogex.h"


// CAboutBox 对话框

IMPLEMENT_DYNAMIC(CAboutBox, CDialogEx)

CAboutBox::CAboutBox(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAboutBox::IDD, pParent)
{

}

CAboutBox::~CAboutBox()
{
}

void CAboutBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutBox, CDialogEx)
END_MESSAGE_MAP()


// CAboutBox 消息处理程序
