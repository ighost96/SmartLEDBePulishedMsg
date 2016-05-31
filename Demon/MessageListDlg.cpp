// MessageListDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "MessageListDlg.h"
#include "afxdialogex.h"
#include "AffirmManage.h"
#include "DeviceQueryDlg.h"
#include "SingleDemonDlg.h"

//每一列若有显示则为1,无则为0
BOOL b1; 
BOOL b2; 
BOOL b3; 
BOOL b4; 
BOOL b5; 
BOOL b6; 
BOOL b7; 
BOOL b8; 

int nPress=0;


// CMessageListDlg 对话框

IMPLEMENT_DYNAMIC(CMessageListDlg, CDialogEx)

CMessageListDlg::CMessageListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMessageListDlg::IDD, pParent)
{

}

CMessageListDlg::~CMessageListDlg()
{
}

void CMessageListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MSG1, m_staMSG1);
	DDX_Control(pDX, IDC_STATIC_MSG2, m_staMSG2);
	DDX_Control(pDX, IDC_STATIC_MSG3, m_staMSG3);
	DDX_Control(pDX, IDC_STATIC_MSG4, m_staMSG4);
	DDX_Control(pDX, IDC_STATIC_MSG5, m_staMSG5);
	DDX_Control(pDX, IDC_STATIC_MSG6, m_staMSG6);
	DDX_Control(pDX, IDC_STATIC_MSG7, m_staMSG7);
	DDX_Control(pDX, IDC_STATIC_MSG8, m_staMSG8);
	DDX_Control(pDX, IDC_COMB_MODE1, m_combMode1);
	DDX_Control(pDX, IDC_COMB_MODE2, m_combMode2);
	DDX_Control(pDX, IDC_COMB_MODE3, m_combMode3);
	DDX_Control(pDX, IDC_COMB_MODE4, m_combMode4);
	DDX_Control(pDX, IDC_COMB_MODE5, m_combMode5);
	DDX_Control(pDX, IDC_COMB_MODE6, m_combMode6);
	DDX_Control(pDX, IDC_COMB_MODE7, m_combMode7);
	DDX_Control(pDX, IDC_COMB_MODE8, m_combMode8);
	DDX_Control(pDX, IDC_COMB_TEMPLATE1, m_combTemplate1);
	DDX_Control(pDX, IDC_COMB_TEMPLATE2, m_combTemplate2);
	DDX_Control(pDX, IDC_COMB_TEMPLATE3, m_combTemplate3);
	DDX_Control(pDX, IDC_COMB_TEMPLATE4, m_combTemplate4);
	DDX_Control(pDX, IDC_COMB_TEMPLATE5, m_combTemplate5);
	DDX_Control(pDX, IDC_COMB_TEMPLATE6, m_combTemplate6);
	DDX_Control(pDX, IDC_COMB_TEMPLATE7, m_combTemplate7);
	DDX_Control(pDX, IDC_COMB_TEMPLATE8, m_combTemplate8);
	DDX_Control(pDX, IDC_COMB_TIME1, m_combTime1);
	DDX_Control(pDX, IDC_COMB_TIME2, m_combTime2);
	DDX_Control(pDX, IDC_COMB_TIME3, m_combTime3);
	DDX_Control(pDX, IDC_COMB_TIME4, m_combTime4);
	DDX_Control(pDX, IDC_COMB_TIME5, m_combTime5);
	DDX_Control(pDX, IDC_COMB_TIME6, m_combTime6);
	DDX_Control(pDX, IDC_COMB_TIME07, m_combTime7);
	DDX_Control(pDX, IDC_COMB_TIME8, m_combTime8);
	DDX_Control(pDX, IDC_COMB_SPEED1, m_combSpeed1);
	DDX_Control(pDX, IDC_COMB_SPEED2, m_combSpeed2);
	DDX_Control(pDX, IDC_COMB_SPEED3, m_combSpeed3);
	DDX_Control(pDX, IDC_COMB_SPEED4, m_combSpeed4);
	DDX_Control(pDX, IDC_COMB_SPEED5, m_combSpeed5);
	DDX_Control(pDX, IDC_COMB_SPEED6, m_combSpeed6);
	DDX_Control(pDX, IDC_COMB_SPEED7, m_combSpeed7);
	DDX_Control(pDX, IDC_COMB_SPEED8, m_combSpeed8);
	DDX_Control(pDX, IDC_PROGRESS_PULISHB, m_ProgBPulish);
	DDX_Control(pDX, IDC_STATIC_PULSTATUS, m_staBPulis);
	DDX_Control(pDX, IDC_PROGRESS_LEDB, m_progSetLED);
}


BEGIN_MESSAGE_MAP(CMessageListDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_LASTSTEP, &CMessageListDlg::OnClickedButtLastStep)
	ON_BN_CLICKED(IDC_BUTT_ADDAFFIRM, &CMessageListDlg::OnClickedButtAddAffirm)
	ON_BN_CLICKED(IDC_BUTT_LEADIN, &CMessageListDlg::OnBnClickedButtLeadin)
	ON_BN_CLICKED(IDC_BUTT_DISPLAY, &CMessageListDlg::OnClickedButtDisplay)
	ON_BN_CLICKED(IDC_BUTT_PULISH, &CMessageListDlg::OnBnClickedButtPulish)
	ON_BN_CLICKED(IDC_BUTT_CLEAR1, &CMessageListDlg::OnBnClickedButtClear1)
	ON_BN_CLICKED(IDC_BUTT_CLEAR2, &CMessageListDlg::OnBnClickedButtClear2)
	ON_BN_CLICKED(IDC_BUTT_CLEAR3, &CMessageListDlg::OnBnClickedButtClear3)
	ON_BN_CLICKED(IDC_BUTT_CLEAR4, &CMessageListDlg::OnBnClickedButtClear4)
	ON_BN_CLICKED(IDC_BUTT_CLEAR05, &CMessageListDlg::OnBnClickedButtClear05)
	ON_BN_CLICKED(IDC_BUTT_CLEAR06, &CMessageListDlg::OnBnClickedButtClear06)
	ON_BN_CLICKED(IDC_BUTT_CLEAR7, &CMessageListDlg::OnBnClickedButtClear7)
	ON_BN_CLICKED(IDC_BUTT_CLEAR8, &CMessageListDlg::OnBnClickedButtClear8)
	ON_BN_CLICKED(IDC_BUTT_ALLCLEAR, &CMessageListDlg::OnBnClickedButtAllclear)
	ON_BN_CLICKED(IDC_BUTT_MATRLIB, &CMessageListDlg::OnBnClickedButtMatrlib)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_COMB_MODE1, &CMessageListDlg::OnSelchangeCombMode1)
	ON_CBN_SELCHANGE(IDC_COMB_MODE2, &CMessageListDlg::OnSelchangeCombMode2)
	ON_CBN_SELCHANGE(IDC_COMB_MODE3, &CMessageListDlg::OnSelchangeCombMode3)
	ON_CBN_SELCHANGE(IDC_COMB_MODE4, &CMessageListDlg::OnSelchangeCombMode4)
	ON_CBN_SELCHANGE(IDC_COMB_MODE5, &CMessageListDlg::OnSelchangeCombMode5)
	ON_CBN_SELCHANGE(IDC_COMB_MODE6, &CMessageListDlg::OnSelchangeCombMode6)
	ON_CBN_SELCHANGE(IDC_COMB_MODE7, &CMessageListDlg::OnSelchangeCombMode7)
	ON_CBN_SELCHANGE(IDC_COMB_MODE8, &CMessageListDlg::OnSelchangeCombMode8)
END_MESSAGE_MAP()


// CMessageListDlg 消息处理程序


void CMessageListDlg::OnClickedButtLastStep()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMessageListDlg::OnClickedButtAddAffirm()
{
	// TODO: 在此添加控件通知处理程序代码
	////
}


void CMessageListDlg::OnBnClickedButtLeadin()
{
	// TODO: 在此添加控件通知处理程序代码
	bLeadin=TRUE;
	CAffirmManage MatrixDlg;
	if (IDOK==MatrixDlg.DoModal())
	{	
		CStringArray &strAA=MatrixDlg.strArray;
		int nsize=strAA.GetSize();
		for (int n=0;n<nsize;n++)
		{
			CString strM=strAA.GetAt(n);

			m_staMSG1.GetWindowTextA(theApp.strMSGContent1);
			m_staMSG2.GetWindowTextA(theApp.strMSGContent2);
			m_staMSG3.GetWindowTextA(theApp.strMSGContent3);
			m_staMSG4.GetWindowTextA(theApp.strMSGContent4);
			m_staMSG5.GetWindowTextA(theApp.strMSGContent5);
			m_staMSG6.GetWindowTextA(theApp.strMSGContent6);
			m_staMSG7.GetWindowTextA(theApp.strMSGContent7);
			m_staMSG8.GetWindowTextA(theApp.strMSGContent8);
			if (theApp.strMSGContent1.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_ONE)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG1)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE1)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE1)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME1)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC1)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED1)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR1)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG1,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE1))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE1))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME1))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED1))->SetCurSel(0);
				GetDlgItem(IDC_BUTT_PULISH)->EnableWindow(TRUE);
			}
			else if (theApp.strMSGContent2.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_TWO)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG2)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE2)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE2)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME2)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC2)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED2)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR2)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG2,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE2))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE2))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME2))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED2))->SetCurSel(0);
			}
			else if (theApp.strMSGContent3.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_THREE)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG3)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE3)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE3)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME3)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC3)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED3)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR3)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG3,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE3))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE3))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME3))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED3))->SetCurSel(0);
			}
			else if (theApp.strMSGContent4.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_FOUR)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG4)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE4)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE4)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME4)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC4)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED4)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR4)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG4,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE4))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE4))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME4))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED4))->SetCurSel(0);
			}
			else if (theApp.strMSGContent5.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_FIVE)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG5)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE5)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE5)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME5)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC5)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED5)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR05)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG5,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE5))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE5))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME5))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED5))->SetCurSel(0);
			}
			else if (theApp.strMSGContent6.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_SIX)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG6)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE6)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE6)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME6)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC6)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED6)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR06)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG6,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE6))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE6))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME6))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED6))->SetCurSel(0);
			}
			else if (theApp.strMSGContent7.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_SEVEN)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG7)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE7)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE7)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME07)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC7)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED7)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR7)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG7,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE7))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE7))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME07))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED7))->SetCurSel(0);
			}
			else if(theApp.strMSGContent8.IsEmpty())
			{
				GetDlgItem(IDC_STATIC_EIGHT)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_MSG8)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_MODE8)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TEMPLATE8)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_TIME8)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_STATIC_SEC8)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_COMB_SPEED8)->ShowWindow(SW_SHOW);
				GetDlgItem(IDC_BUTT_CLEAR8)->ShowWindow(SW_SHOW);
				SetDlgItemTextA(IDC_STATIC_MSG8,strM);
				((CComboBox *)GetDlgItem(IDC_COMB_MODE8))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE8))->SetCurSel(1);
				((CComboBox *)GetDlgItem(IDC_COMB_TIME8))->SetCurSel(0);
				((CComboBox *)GetDlgItem(IDC_COMB_SPEED8))->SetCurSel(0);
			}
			else
			{
				MessageBox("暂不支持更多信息数量","温馨提示");
				GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(FALSE);
				break;
			}
		}
		
	}
}


BOOL CMessageListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	GetDlgItem(IDC_BUTT_PULISH)->EnableWindow(FALSE);

	OnClickedButtDisplay();

	CRect rect;      
	GetClientRect(&rect);     //取客户区大小    
	old.x=rect.right-rect.left;  
	old.y=rect.bottom-rect.top;  
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);  
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);  
	CRect rt;  
	SystemParametersInfo(SPI_GETWORKAREA,0,&rt,0);  
	cy = rt.bottom;  
	MoveWindow(0, 0, cx, cy);  

	ReSizeMSG();

	b1=0; 
	b2=0; 
	b3=0; 
	b4=0; 
	b5=0; 
	b6=0; 
	b7=0; 
	b8=0; 
	m_brush.CreateSolidBrush(RGB(255,255,255));
//////////////////////////////////////////////////////////////////////////
	m_pStatBar=new CStatusBar;
	UINT Parts[5];
	for (int i=0;i<5;i++)
	{
		Parts[i]=cx/2+i;
	}
	m_pStatBar->Create(this);
	m_pStatBar->SetIndicators(Parts,sizeof(Parts)/sizeof(UINT));
	CRect rct;
	GetClientRect(&rct);
	for (int i=0;i<5;i++)
	{
		m_pStatBar->SetPaneInfo(i,Parts[i],0,rct.Width()/5);
	}
	m_pStatBar->SetPaneText(0,_T(""));
	m_pStatBar->SetPaneText(1,_T(""));
	m_pStatBar->SetPaneText(2,_T(""));
	m_pStatBar->SetPaneText(3,_T("消息写入服务器进度："));
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	RECT rtt;
	m_pStatBar->GetItemRect(4,&rtt);
	m_ProgBPulish.SetParent(m_pStatBar);
	m_ProgBPulish.MoveWindow(&rtt);
	//-----------------------ToolTips------------------------------//
	m_TlTips.Create(this);
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_ALLCLEAR),TEXT(_T("清除所有消息方便自主选择")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_LASTSTEP),TEXT(_T("返回设备列表选择界面重新选择")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_LEADIN),TEXT(_T("单击进入消息列表选择消息")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_PULISH),TEXT(_T("准备就绪，推送消息")));
	//m_TlTips.AddTool(GetDlgItem(),TEXT(_T("")));
/////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



void CMessageListDlg::OnClickedButtDisplay()
{
	// TODO: 在此添加控件通知处理程序代码
	/*HWND hWnd=::FindWindowA(NULL,"IDD_AFFIRMMANAGE_DIALOG");
	CAffirmManage *pwnd=(CAffirmManage *)FromHandle(hWnd); */      //获取字模库窗口句柄
	CString strSql,strsqlDATA;
	int iNo;
	CString strMatrixSeted,strMatrixData,strMode,strTemplate,strTime,strSpeed;
	strMatrixSeted=pQueryDlg->m_listDevice.GetItemText(pQueryDlg->nItem,7);
	strMatrixData=pQueryDlg->m_listDevice.GetItemText(pQueryDlg->nItem,8);
	CString strZero=_T("0");
	int iMode,iTemplate,iTime,iSpeed,ipos;

	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum1=strMatrixSeted.Left(ipos);
	if (theApp.strMSGNum1!=strZero)//消息1
	{
		iNo=atoi(theApp.strMSGNum1);
		strMode=strMatrixData.GetAt(12);
		strMode=strMode+strMatrixData.GetAt(13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(15);
		strTemplate=strTemplate+strMatrixData.GetAt(16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(18);
		strTime=strTime+strMatrixData.GetAt(19);
		strTime=strTime+strMatrixData.GetAt(21);
		strTime=strTime+strMatrixData.GetAt(22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(24);
		strSpeed=strSpeed+strMatrixData.GetAt(25);
		strSpeed=strSpeed+strMatrixData.GetAt(27);
		strSpeed=strSpeed+strMatrixData.GetAt(28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where  字模编号=%d",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG1.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_ONE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR1)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE1))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE1))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME1))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED1))->SetCurSel(iSpeed- 1);
		GetDlgItem(IDC_BUTT_PULISH)->EnableWindow(TRUE);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	strMatrixSeted=strMatrixSeted.Right(strMatrixSeted.GetLength()-ipos-1);
	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum2=strMatrixSeted.Left(ipos);//消息2
	if (theApp.strMSGNum2!=strZero)
	{
		iNo=atoi(theApp.strMSGNum2);
		strMode=strMatrixData.GetAt(30+12);
		strMode=strMode+strMatrixData.GetAt(30+13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(30+15);
		strTemplate=strTemplate+strMatrixData.GetAt(30+16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(30+18);
		strTime=strTime+strMatrixData.GetAt(30+19);
		strTime=strTime+strMatrixData.GetAt(30+21);
		strTime=strTime+strMatrixData.GetAt(30+22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(30+24);
		strSpeed=strSpeed+strMatrixData.GetAt(30+25);
		strSpeed=strSpeed+strMatrixData.GetAt(30+27);
		strSpeed=strSpeed+strMatrixData.GetAt(30+28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where 字模编号=%d ",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG2.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_TWO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR2)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE2))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE2))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME2))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED2))->SetCurSel(iSpeed- 1);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	strMatrixSeted=strMatrixSeted.Right(strMatrixSeted.GetLength()-ipos-1);
	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum3=strMatrixSeted.Left(ipos);//消息3
	if (theApp.strMSGNum3!=strZero)
	{
		iNo=atoi(theApp.strMSGNum3);
		strMode=strMatrixData.GetAt(60+12);
		strMode=strMode+strMatrixData.GetAt(60+13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(60+15);
		strTemplate=strTemplate+strMatrixData.GetAt(60+16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(60+18);
		strTime=strTime+strMatrixData.GetAt(60+19);
		strTime=strTime+strMatrixData.GetAt(60+21);
		strTime=strTime+strMatrixData.GetAt(60+22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(60+24);
		strSpeed=strSpeed+strMatrixData.GetAt(60+25);
		strSpeed=strSpeed+strMatrixData.GetAt(60+27);
		strSpeed=strSpeed+strMatrixData.GetAt(60+28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where  字模编号=%d",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG3.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_THREE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR3)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE3))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE3))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME3))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED3))->SetCurSel(iSpeed- 1);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	strMatrixSeted=strMatrixSeted.Right(strMatrixSeted.GetLength()-ipos-1);
	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum4=strMatrixSeted.Left(ipos);//消息4
	if (theApp.strMSGNum4!=strZero)
	{
		iNo=atoi(theApp.strMSGNum3);
		strMode=strMatrixData.GetAt(90+12);
		strMode=strMode+strMatrixData.GetAt(90+13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(90+15);
		strTemplate=strTemplate+strMatrixData.GetAt(90+16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(90+18);
		strTime=strTime+strMatrixData.GetAt(90+19);
		strTime=strTime+strMatrixData.GetAt(90+21);
		strTime=strTime+strMatrixData.GetAt(90+22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(90+24);
		strSpeed=strSpeed+strMatrixData.GetAt(90+25);
		strSpeed=strSpeed+strMatrixData.GetAt(90+27);
		strSpeed=strSpeed+strMatrixData.GetAt(90+28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where  字模编号=%d",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG4.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_FOUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR4)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE4))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE4))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME4))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED4))->SetCurSel(iSpeed- 1);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	strMatrixSeted=strMatrixSeted.Right(strMatrixSeted.GetLength()-ipos-1);
	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum5=strMatrixSeted.Left(ipos);//消息5
	if (theApp.strMSGNum5!=strZero)
	{
		iNo=atoi(theApp.strMSGNum5);
		strMode=strMatrixData.GetAt(120+12);
		strMode=strMode+strMatrixData.GetAt(120+13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(120+15);
		strTemplate=strTemplate+strMatrixData.GetAt(120+16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(120+18);
		strTime=strTime+strMatrixData.GetAt(120+19);
		strTime=strTime+strMatrixData.GetAt(120+21);
		strTime=strTime+strMatrixData.GetAt(120+22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(120+24);
		strSpeed=strSpeed+strMatrixData.GetAt(120+25);
		strSpeed=strSpeed+strMatrixData.GetAt(120+27);
		strSpeed=strSpeed+strMatrixData.GetAt(120+28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where  字模编号=%d",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG5.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_FIVE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR05)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE5))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE5))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME5))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED5))->SetCurSel(iSpeed- 1);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	strMatrixSeted=strMatrixSeted.Right(strMatrixSeted.GetLength()-ipos-1);
	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum6=strMatrixSeted.Left(ipos);//消息6
	if (theApp.strMSGNum6!=strZero)
	{
		iNo=atoi(theApp.strMSGNum6);
		strMode=strMatrixData.GetAt(150+12);
		strMode=strMode+strMatrixData.GetAt(150+13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(150+15);
		strTemplate=strTemplate+strMatrixData.GetAt(150+16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(150+18);
		strTime=strTime+strMatrixData.GetAt(150+19);
		strTime=strTime+strMatrixData.GetAt(150+21);
		strTime=strTime+strMatrixData.GetAt(150+22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(150+24);
		strSpeed=strSpeed+strMatrixData.GetAt(150+25);
		strSpeed=strSpeed+strMatrixData.GetAt(150+27);
		strSpeed=strSpeed+strMatrixData.GetAt(150+28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where  字模编号=%d",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG6.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_SIX)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR06)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE6))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE6))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME6))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED6))->SetCurSel(iSpeed- 1);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	strMatrixSeted=strMatrixSeted.Right(strMatrixSeted.GetLength()-ipos-1);
	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum7=strMatrixSeted.Left(ipos);//消息7
	if (theApp.strMSGNum7!=strZero)
	{
		iNo=atoi(theApp.strMSGNum7);
		strMode=strMatrixData.GetAt(180+12);
		strMode=strMode+strMatrixData.GetAt(180+13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(180+15);
		strTemplate=strTemplate+strMatrixData.GetAt(180+16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(180+18);
		strTime=strTime+strMatrixData.GetAt(180+19);
		strTime=strTime+strMatrixData.GetAt(180+21);
		strTime=strTime+strMatrixData.GetAt(180+22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(180+24);
		strSpeed=strSpeed+strMatrixData.GetAt(180+25);
		strSpeed=strSpeed+strMatrixData.GetAt(180+27);
		strSpeed=strSpeed+strMatrixData.GetAt(180+28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where  字模编号=%d",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG7.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_SEVEN)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME07)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR7)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE7))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE7))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME07))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED7))->SetCurSel(iSpeed- 1);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	strMatrixSeted=strMatrixSeted.Right(strMatrixSeted.GetLength()-ipos-1);
	ipos=strMatrixSeted.Find(":");
	theApp.strMSGNum8=strMatrixSeted.Left(ipos);//消息8
	if (theApp.strMSGNum8!=strZero)
	{
		iNo=atoi(theApp.strMSGNum8);
		strMode=strMatrixData.GetAt(210+12);
		strMode=strMode+strMatrixData.GetAt(210+13);
		iMode=atoi(strMode);
		strTemplate=strMatrixData.GetAt(210+15);
		strTemplate=strTemplate+strMatrixData.GetAt(210+16);
		iTemplate=atoi(strTemplate);
		strTime=strMatrixData.GetAt(210+18);
		strTime=strTime+strMatrixData.GetAt(210+19);
		strTime=strTime+strMatrixData.GetAt(210+21);
		strTime=strTime+strMatrixData.GetAt(210+22);
		iTime=atoi(strTime);
		strSpeed=strMatrixData.GetAt(210+24);
		strSpeed=strSpeed+strMatrixData.GetAt(210+25);
		strSpeed=strSpeed+strMatrixData.GetAt(210+27);
		strSpeed=strSpeed+strMatrixData.GetAt(210+28);
		iSpeed=atoi(strSpeed);

		strSql.Format("select 显示内容 from DotDisplayData where  字模编号=%d",iNo);
		if (theApp.m_ado.ExecuteSelect(strSql))
		{
			theApp.m_ado.GetString("显示内容",strsqlDATA);
			m_staMSG8.SetWindowTextA(strsqlDATA);
		}
		GetDlgItem(IDC_STATIC_EIGHT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MSG8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_MODE8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TEMPLATE8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_TIME8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SEC8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMB_SPEED8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTT_CLEAR8)->ShowWindow(SW_SHOW);
		((CComboBox *)GetDlgItem(IDC_COMB_MODE8))->SetCurSel(iMode - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE8))->SetCurSel(iTemplate - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_TIME8))->SetCurSel(iTime - 1);
		((CComboBox *)GetDlgItem(IDC_COMB_SPEED8))->SetCurSel(iSpeed- 1);
	}

}


void CMessageListDlg::OnBnClickedButtPulish()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  strDeviceDID,strDevieceDMAC,strSqlPul,strsql1,strsql2,strsql3,strsql4,strsql5,strsql6,strsql7,strsql8;
	CString  strMSG1,strMSG2,strMSG3,strMSG4,strMSG5,strMSG6,strMSG7,strMSG8;
	CString  strPulishMode1,strPulishMode2,strPulishMode3,strPulishMode4,strPulishMode5,strPulishMode6,strPulishMode7,strPulishMode8;
	CString strPulishTemp1,strPulishTemp2,strPulishTemp3,strPulishTemp4,strPulishTemp5,strPulishTemp6,strPulishTemp7,strPulishTemp8;
	CString strTime1,strTime2,strTime3,strTime4,strTime5,strTime6,strTime7,strTime8;
	CString strSpeed1,strSpeed2,strSpeed3,strSpeed4,strSpeed5,strSpeed6,strSpeed7,strSpeed8;
	CString strDataPacket,strDataPacket1,strDataPacket2,strDataPacket3,strDataPacket4,strDataPacket5,strDataPacket6,strDataPacket7,strDataPacket8;
	CString strSendFont,strSendFont1,strSendFont2,strSendFont3,strSendFont4,strSendFont5,strSendFont6,strSendFont7,strSendFont8;
	CString strDataCode,strDataCode1,strDataCode2,strDataCode3,strDataCode4,strDataCode5,strDataCode6,strDataCode7,strDataCode8;
	int iNo1,iNo2,iNo3,iNo4,iNo5,iNo6,iNo7,iNo8;
	CString strMessageList="";

	m_staMSG1.GetWindowTextA(strMSG1);
	if (strMSG1!=_T(""))
	{
		b1=1;
		strMessageList+=strMSG1+";";
		//字模编号
		strsql1.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG1);
		if (theApp.m_ado.ExecuteSelect(strsql1))
		{
			theApp.m_ado.GetInt("字模编号",iNo1);
		}
		//显示模式
		int iMd=m_combMode1.GetCurSel();
		if (iMd==0)
		{
			strPulishMode1=_T("01");
		}
		else if (iMd==1)
		{
			strPulishMode1=_T("02");
		}
		else if (iMd==2)
		{
			strPulishMode1=_T("03");
		}
		else if (iMd==3)
		{
			strPulishMode1=_T("04");
		}
		else if (iMd==4)
		{
			strPulishMode1=_T("05");
		}
		else if (iMd==5)
		{
			strPulishMode1=_T("06");
		}
		else
		{
			strPulishMode1=_T("00");
		}
///////////////////////////////////////////////////////////////////显示模板
		int iTemp=m_combTemplate1.GetCurSel();
		if (iTemp==0)
		{
			strPulishTemp1=_T("01");
		}
		else if (iTemp==1)
		{
			strPulishTemp1=_T("02");
		}
		else if (iTemp==2)
		{
			strPulishTemp1=_T("03");
		}
		else if (iTemp==3)
		{
			strPulishTemp1=_T("04");
		}
		else
		{
			strPulishTemp1=_T("00");
		}
		//////////////////////////////////////////////////////////////////////////停留时间
		int itm=m_combTime1.GetCurSel();
		if (itm==0)
		{
			strTime1=_T("00 01");
		}
		else if (itm==1)
		{
			strTime1=_T("00 02");
		}
		else if (itm==2)
		{
			strTime1=_T("00 03");
		}
		else if (itm==3)
		{
			strTime1=_T("00 04");
		}
		else if (itm==4)
		{
			strTime1=_T("00 05");
		}
		else if (itm==5)
		{
			strTime1=_T("06");
		}
		else if (itm==6)
		{
			strTime1=_T("00 07");
		}
		else if (itm==7)
		{
			strTime1=_T("00 08");
		}
		else if (itm==8)
		{
			strTime1=_T("00 09");
		}
		else if (itm==9)
		{
			strTime1=_T("00 0A");
		}
		else
		{
			strTime1=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////移动速度
		int ispd=m_combSpeed1.GetCurSel();
		if (ispd==0)
		{
			strSpeed1=_T("00 01");
		}
		else if (ispd==1)
		{
			strSpeed1=_T("00 02");
		}
		else if (ispd==2)
		{
			strSpeed1=_T("00 03");
		}
		else if (ispd==3)
		{
			strSpeed1=_T("00 04");
		}
		else if (ispd==4)
		{
			strSpeed1=_T("00 05");
		}
		else if (ispd==5)
		{
			strSpeed1=_T("00 06");
		}
		else if (ispd==6)
		{
			strSpeed1=_T("00 07");
		}
		else if (ispd==7)
		{
			strSpeed1=_T("00 08");
		}
		else if (ispd==8)
		{
			strSpeed1=_T("00 09");
		}
		else if (ispd==9)
		{
			strSpeed1=_T("00 0A");
		}
		else
		{
			strSpeed1=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
		strDataPacket1=_T("00 00 00 00 ")+strPulishMode1+_T(" ")+strPulishTemp1+_T(" ")+strTime1+_T(" ")+strSpeed1;
		strDataPacket=strDataPacket1;
		CString strNo1;
		strNo1.Format("%d",iNo1);
		strSendFont1=strNo1;
		strSendFont=strSendFont1;
		strDataCode1=_T("1");        
	}
	else
		strDataCode1=_T("0");

	//////////////////////////////////////////////////////////////////////////消息2
	m_staMSG2.GetWindowTextA(strMSG2);
	if (strMSG2!=_T(""))
	{
		b2=1;
		strMessageList+=strMSG2+";";
		//字模编号
		strsql2.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG2);
		if (theApp.m_ado.ExecuteSelect(strsql2))
		{
			theApp.m_ado.GetInt("字模编号",iNo2);
		}
		//显示模式
		int iMd=m_combMode2.GetCurSel();
		if (iMd==0)
		{
			strPulishMode2=_T("01");
		}
		else if (iMd==1)
		{
			strPulishMode2=_T("02");
		}
		else if (iMd==2)
		{
			strPulishMode2=_T("03");
		}
		else if (iMd==3)
		{
			strPulishMode2=_T("04");
		}
		else if (iMd==4)
		{
			strPulishMode2=_T("05");
		}
		else if (iMd==5)
		{
			strPulishMode2=_T("06");
		}
		else
		{
			strPulishMode2=_T("00");
		}
		///////////////////////////////////////////////////////////////////显示模板
		int iTemp=m_combTemplate2.GetCurSel();
		if (iTemp==0)
		{
			strPulishTemp2=_T("01");
		}
		else if (iTemp==1)
		{
			strPulishTemp2=_T("02");
		}
		else if (iTemp==2)
		{
			strPulishTemp2=_T("03");
		}
		else if (iTemp==3)
		{
			strPulishTemp2=_T("04");
		}
		else
		{
			strPulishTemp2=_T("00");
		}
		//////////////////////////////////////////////////////////////////////////停留时间
		int itm=m_combTime2.GetCurSel();
		if (itm==0)
		{
			strTime2=_T("00 01");
		}
		else if (itm==1)
		{
			strTime2=_T("00 02");
		}
		else if (itm==2)
		{
			strTime2=_T("00 03");
		}
		else if (itm==3)
		{
			strTime2=_T("00 04");
		}
		else if (itm==4)
		{
			strTime2=_T("00 05");
		}
		else if (itm==5)
		{
			strTime2=_T("06");
		}
		else if (itm==6)
		{
			strTime2=_T("00 07");
		}
		else if (itm==7)
		{
			strTime2=_T("00 08");
		}
		else if (itm==8)
		{
			strTime2=_T("00 09");
		}
		else if (itm==9)
		{
			strTime2=_T("00 0A");
		}
		else
		{
			strTime2=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////移动速度
		int ispd=m_combSpeed2.GetCurSel();
		if (ispd==0)
		{
			strSpeed2=_T("00 01");
		}
		else if (ispd==1)
		{
			strSpeed2=_T("00 02");
		}
		else if (ispd==2)
		{
			strSpeed2=_T("00 03");
		}
		else if (ispd==3)
		{
			strSpeed2=_T("00 04");
		}
		else if (ispd==4)
		{
			strSpeed2=_T("00 05");
		}
		else if (ispd==5)
		{
			strSpeed2=_T("00 06");
		}
		else if (ispd==6)
		{
			strSpeed2=_T("00 07");
		}
		else if (ispd==7)
		{
			strSpeed2=_T("00 08");
		}
		else if (ispd==8)
		{
			strSpeed2=_T("00 09");
		}
		else if (ispd==9)
		{
			strSpeed2=_T("00 0A");
		}
		else
		{
			strSpeed2=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
		strDataPacket2=_T("00 00 00 00 ")+strPulishMode2+_T(" ")+strPulishTemp2+_T(" ")+strTime2+_T(" ")+strSpeed2;
		strDataPacket +=_T(" ")+strDataPacket2;
		CString strNo2;
		strNo2.Format("%d",iNo2);
		strSendFont2=strNo2;
		strSendFont +=_T(":")+strSendFont2;
		strDataCode2=_T("1");
	} 
	else
		strDataCode2=_T("0");

	//////////////////////////////////////////////////////////////////////////消息3
	m_staMSG3.GetWindowTextA(strMSG3);
	if (strMSG3!=_T(""))
	{
		b3=1;
		strMessageList+=strMSG3+";";
		//字模编号
		strsql3.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG3);
		if (theApp.m_ado.ExecuteSelect(strsql3))
		{
			theApp.m_ado.GetInt("字模编号",iNo3);
		}
		//显示模式
		int iMd=m_combMode3.GetCurSel();
		if (iMd==0)
		{
			strPulishMode3=_T("01");
		}
		else if (iMd==1)
		{
			strPulishMode3=_T("02");
		}
		else if (iMd==2)
		{
			strPulishMode3=_T("03");
		}
		else if (iMd==3)
		{
			strPulishMode3=_T("04");
		}
		else if (iMd==4)
		{
			strPulishMode3=_T("05");
		}
		else if (iMd==5)
		{
			strPulishMode3=_T("06");
		}
		else
		{
			strPulishMode3=_T("00");
		}
		///////////////////////////////////////////////////////////////////显示模板
		int iTemp=m_combTemplate3.GetCurSel();
		if (iTemp==0)
		{
			strPulishTemp3=_T("01");
		}
		else if (iTemp==1)
		{
			strPulishTemp3=_T("02");
		}
		else if (iTemp==2)
		{
			strPulishTemp3=_T("03");
		}
		else if (iTemp==3)
		{
			strPulishTemp3=_T("04");
		}
		else
		{
			strPulishTemp3=_T("00");
		}
		//////////////////////////////////////////////////////////////////////////停留时间
		int itm=m_combTime3.GetCurSel();
		if (itm==0)
		{
			strTime3=_T("00 01");
		}
		else if (itm==1)
		{
			strTime3=_T("00 02");
		}
		else if (itm==2)
		{
			strTime3=_T("00 03");
		}
		else if (itm==3)
		{
			strTime3=_T("00 04");
		}
		else if (itm==4)
		{
			strTime3=_T("00 05");
		}
		else if (itm==5)
		{
			strTime3=_T("06");
		}
		else if (itm==6)
		{
			strTime3=_T("00 07");
		}
		else if (itm==7)
		{
			strTime3=_T("00 08");
		}
		else if (itm==8)
		{
			strTime3=_T("00 09");
		}
		else if (itm==9)
		{
			strTime3=_T("00 0A");
		}
		else
		{
			strTime3=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////移动速度
		int ispd=m_combSpeed3.GetCurSel();
		if (ispd==0)
		{
			strSpeed3=_T("00 01");
		}
		else if (ispd==1)
		{
			strSpeed3=_T("00 02");
		}
		else if (ispd==2)
		{
			strSpeed3=_T("00 03");
		}
		else if (ispd==3)
		{
			strSpeed3=_T("00 04");
		}
		else if (ispd==4)
		{
			strSpeed3=_T("00 05");
		}
		else if (ispd==5)
		{
			strSpeed3=_T("00 06");
		}
		else if (ispd==6)
		{
			strSpeed3=_T("00 07");
		}
		else if (ispd==7)
		{
			strSpeed3=_T("00 08");
		}
		else if (ispd==8)
		{
			strSpeed3=_T("00 09");
		}
		else if (ispd==9)
		{
			strSpeed3=_T("00 0A");
		}
		else
		{
			strSpeed3=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
		strDataPacket3=_T("00 00 00 00 ")+strPulishMode3+_T(" ")+strPulishTemp3+_T(" ")+strTime3+_T(" ")+strSpeed3;
		strDataPacket +=_T(" ")+strDataPacket3;
		CString strNo3;
		strNo3.Format("%d",iNo3);
		strSendFont3=strNo3;
		strSendFont +=_T(":")+strSendFont3;
		strDataCode3=_T("1");
	}
	else
		strDataCode3=_T("0");

	//////////////////////////////////////////////////////////////////////////消息4
	m_staMSG4.GetWindowTextA(strMSG4);
	if (strMSG4!=_T(""))
	{
		b4=1;
		strMessageList +=strMSG4+";";
		//字模编号
		strsql4.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG4);
		if (theApp.m_ado.ExecuteSelect(strsql4))
		{
			theApp.m_ado.GetInt("字模编号",iNo4);
		}
		//显示模式
		int iMd=m_combMode4.GetCurSel();
		if (iMd==0)
		{
			strPulishMode4=_T("01");
		}
		else if (iMd==1)
		{
			strPulishMode4=_T("02");
		}
		else if (iMd==2)
		{
			strPulishMode4=_T("03");
		}
		else if (iMd==3)
		{
			strPulishMode4=_T("04");
		}
		else if (iMd==4)
		{
			strPulishMode4=_T("05");
		}
		else if (iMd==5)
		{
			strPulishMode4=_T("06");
		}
		else
		{
			strPulishMode4=_T("00");
		}
		///////////////////////////////////////////////////////////////////显示模板
		int iTemp=m_combTemplate4.GetCurSel();
		if (iTemp==0)
		{
			strPulishTemp4=_T("01");
		}
		else if (iTemp==1)
		{
			strPulishTemp4=_T("02");
		}
		else if (iTemp==2)
		{
			strPulishTemp4=_T("03");
		}
		else if (iTemp==3)
		{
			strPulishTemp4=_T("04");
		}
		else
		{
			strPulishTemp4=_T("00");
		}
		//////////////////////////////////////////////////////////////////////////停留时间
		int itm=m_combTime4.GetCurSel();
		if (itm==0)
		{
			strTime4=_T("00 01");
		}
		else if (itm==1)
		{
			strTime4=_T("00 02");
		}
		else if (itm==2)
		{
			strTime4=_T("00 03");
		}
		else if (itm==3)
		{
			strTime4=_T("00 04");
		}
		else if (itm==4)
		{
			strTime4=_T("00 05");
		}
		else if (itm==5)
		{
			strTime4=_T("06");
		}
		else if (itm==6)
		{
			strTime4=_T("00 07");
		}
		else if (itm==7)
		{
			strTime4=_T("00 08");
		}
		else if (itm==8)
		{
			strTime4=_T("00 09");
		}
		else if (itm==9)
		{
			strTime4=_T("00 0A");
		}
		else
		{
			strTime4=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////移动速度
		int ispd=m_combSpeed4.GetCurSel();
		if (ispd==0)
		{
			strSpeed4=_T("00 01");
		}
		else if (ispd==1)
		{
			strSpeed4=_T("00 02");
		}
		else if (ispd==2)
		{
			strSpeed4=_T("00 03");
		}
		else if (ispd==3)
		{
			strSpeed4=_T("00 04");
		}
		else if (ispd==4)
		{
			strSpeed4=_T("00 05");
		}
		else if (ispd==5)
		{
			strSpeed4=_T("00 06");
		}
		else if (ispd==6)
		{
			strSpeed4=_T("00 07");
		}
		else if (ispd==7)
		{
			strSpeed4=_T("00 08");
		}
		else if (ispd==8)
		{
			strSpeed4=_T("00 09");
		}
		else if (ispd==9)
		{
			strSpeed4=_T("00 0A");
		}
		else
		{
			strSpeed4=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
		strDataPacket4=_T("00 00 00 00 ")+strPulishMode4+_T(" ")+strPulishTemp4+_T(" ")+strTime4+_T(" ")+strSpeed4;
		strDataPacket +=_T(" ")+strDataPacket4;
		CString strNo4;
		strNo4.Format("%d",iNo4);
		strSendFont4=strNo4;
		strSendFont +=_T(":")+strSendFont4;
		strDataCode4=_T("1");
	}
	else
		strDataCode4=_T("0");

	//////////////////////////////////////////////////////////////////////////消息5
	m_staMSG5.GetWindowTextA(strMSG5);
	if (strMSG5!=_T(""))
	{
		b5=1;
		strMessageList +=strMSG5+";";
		//字模编号
		strsql5.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG5);
		if (theApp.m_ado.ExecuteSelect(strsql5))
		{
			theApp.m_ado.GetInt("字模编号",iNo5);
		}
		//显示模式
		int iMd=m_combMode5.GetCurSel();
		if (iMd==0)
		{
			strPulishMode5=_T("01");
		}
		else if (iMd==1)
		{
			strPulishMode5=_T("02");
		}
		else if (iMd==2)
		{
			strPulishMode5=_T("03");
		}
		else if (iMd==3)
		{
			strPulishMode5=_T("04");
		}
		else if (iMd==4)
		{
			strPulishMode5=_T("05");
		}
		else if (iMd==5)
		{
			strPulishMode5=_T("06");
		}
		else
		{
			strPulishMode5=_T("00");
		}
		///////////////////////////////////////////////////////////////////显示模板
		int iTemp=m_combTemplate5.GetCurSel();
		if (iTemp==0)
		{
			strPulishTemp5=_T("01");
		}
		else if (iTemp==1)
		{
			strPulishTemp5=_T("02");
		}
		else if (iTemp==2)
		{
			strPulishTemp5=_T("03");
		}
		else if (iTemp==3)
		{
			strPulishTemp5=_T("04");
		}
		else
		{
			strPulishTemp5=_T("00");
		}
		//////////////////////////////////////////////////////////////////////////停留时间
		int itm=m_combTime5.GetCurSel();
		if (itm==0)
		{
			strTime5=_T("00 01");
		}
		else if (itm==1)
		{
			strTime5=_T("00 02");
		}
		else if (itm==2)
		{
			strTime5=_T("00 03");
		}
		else if (itm==3)
		{
			strTime5=_T("00 04");
		}
		else if (itm==4)
		{
			strTime5=_T("00 05");
		}
		else if (itm==5)
		{
			strTime5=_T("06");
		}
		else if (itm==6)
		{
			strTime5=_T("00 07");
		}
		else if (itm==7)
		{
			strTime5=_T("00 08");
		}
		else if (itm==8)
		{
			strTime5=_T("00 09");
		}
		else if (itm==9)
		{
			strTime5=_T("00 0A");
		}
		else
		{
			strTime5=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////移动速度
		int ispd=m_combSpeed5.GetCurSel();
		if (ispd==0)
		{
			strSpeed5=_T("00 01");
		}
		else if (ispd==1)
		{
			strSpeed5=_T("00 02");
		}
		else if (ispd==2)
		{
			strSpeed5=_T("00 03");
		}
		else if (ispd==3)
		{
			strSpeed5=_T("00 04");
		}
		else if (ispd==4)
		{
			strSpeed5=_T("00 05");
		}
		else if (ispd==5)
		{
			strSpeed5=_T("00 06");
		}
		else if (ispd==6)
		{
			strSpeed5=_T("00 07");
		}
		else if (ispd==7)
		{
			strSpeed5=_T("00 08");
		}
		else if (ispd==8)
		{
			strSpeed5=_T("00 09");
		}
		else if (ispd==9)
		{
			strSpeed5=_T("00 0A");
		}
		else
		{
			strSpeed5=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
		strDataPacket5=_T("00 00 00 00 ")+strPulishMode5+_T(" ")+strPulishTemp5+_T(" ")+strTime5+_T(" ")+strSpeed5;
		strDataPacket +=_T(" ")+strDataPacket5;
		CString strNo5;
		strNo5.Format("%d",iNo5);
		strSendFont5=strNo5;
		strSendFont +=_T(":")+strSendFont5;
		strDataCode5=_T("1");
	}
	else
		strDataCode5=_T("0");

	//////////////////////////////////////////////////////////////////////////消息6
	m_staMSG6.GetWindowTextA(strMSG6);
	if (strMSG6!=_T(""))
	{
		b6=1;
		strMessageList +=strMSG6+";";
		//字模编号
		strsql6.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG6);
		if (theApp.m_ado.ExecuteSelect(strsql6))
		{
			theApp.m_ado.GetInt("字模编号",iNo6);
		}
		//显示模式
		int iMd=m_combMode6.GetCurSel();
		if (iMd==0)
		{
			strPulishMode6=_T("01");
		}
		else if (iMd==1)
		{
			strPulishMode6=_T("02");
		}
		else if (iMd==2)
		{
			strPulishMode6=_T("03");
		}
		else if (iMd==3)
		{
			strPulishMode6=_T("04");
		}
		else if (iMd==4)
		{
			strPulishMode6=_T("05");
		}
		else if (iMd==5)
		{
			strPulishMode6=_T("06");
		}
		else
		{
			strPulishMode6=_T("00");
		}
		///////////////////////////////////////////////////////////////////显示模板
		int iTemp=m_combTemplate6.GetCurSel();
		if (iTemp==0)
		{
			strPulishTemp6=_T("01");
		}
		else if (iTemp==1)
		{
			strPulishTemp6=_T("02");
		}
		else if (iTemp==2)
		{
			strPulishTemp6=_T("03");
		}
		else if (iTemp==3)
		{
			strPulishTemp6=_T("04");
		}
		else
		{
			strPulishTemp6=_T("00");
		}
		//////////////////////////////////////////////////////////////////////////停留时间
		int itm=m_combTime6.GetCurSel();
		if (itm==0)
		{
			strTime6=_T("00 01");
		}
		else if (itm==1)
		{
			strTime6=_T("00 02");
		}
		else if (itm==2)
		{
			strTime6=_T("00 03");
		}
		else if (itm==3)
		{
			strTime6=_T("00 04");
		}
		else if (itm==4)
		{
			strTime6=_T("00 05");
		}
		else if (itm==5)
		{
			strTime6=_T("06");
		}
		else if (itm==6)
		{
			strTime6=_T("00 07");
		}
		else if (itm==7)
		{
			strTime6=_T("00 08");
		}
		else if (itm==8)
		{
			strTime6=_T("00 09");
		}
		else if (itm==9)
		{
			strTime6=_T("00 0A");
		}
		else
		{
			strTime6=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////移动速度
		int ispd=m_combSpeed6.GetCurSel();
		if (ispd==0)
		{
			strSpeed6=_T("00 01");
		}
		else if (ispd==1)
		{
			strSpeed6=_T("00 02");
		}
		else if (ispd==2)
		{
			strSpeed6=_T("00 03");
		}
		else if (ispd==3)
		{
			strSpeed6=_T("00 04");
		}
		else if (ispd==4)
		{
			strSpeed6=_T("00 05");
		}
		else if (ispd==5)
		{
			strSpeed6=_T("00 06");
		}
		else if (ispd==6)
		{
			strSpeed6=_T("00 07");
		}
		else if (ispd==7)
		{
			strSpeed6=_T("00 08");
		}
		else if (ispd==8)
		{
			strSpeed6=_T("00 09");
		}
		else if (ispd==9)
		{
			strSpeed6=_T("00 0A");
		}
		else
		{
			strSpeed6=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
		strDataPacket6=_T("00 00 00 00 ")+strPulishMode6+_T(" ")+strPulishTemp6+_T(" ")+strTime6+_T(" ")+strSpeed6;
		strDataPacket +=_T(" ")+strDataPacket6;
		CString strNo6;
		strNo6.Format("%d",iNo6);
		strSendFont6=strNo6;
		strSendFont +=+_T(":")+strSendFont6;
		strDataCode6=_T("1");
	}
	else
		strDataCode6=_T("0");

	//////////////////////////////////////////////////////////////////////////消息7
	m_staMSG7.GetWindowTextA(strMSG7);
	if (strMSG7!=_T(""))
	{
		b7=1;
		strMessageList +=strMSG7+";";
		//字模编号
		strsql7.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG7);
		if (theApp.m_ado.ExecuteSelect(strsql7))
		{
			theApp.m_ado.GetInt("字模编号",iNo7);
		}
		//显示模式
		int iMd=m_combMode7.GetCurSel();
		if (iMd==0)
		{
			strPulishMode7=_T("01");
		}
		else if (iMd==1)
		{
			strPulishMode7=_T("02");
		}
		else if (iMd==2)
		{
			strPulishMode7=_T("03");
		}
		else if (iMd==3)
		{
			strPulishMode7=_T("04");
		}
		else if (iMd==4)
		{
			strPulishMode7=_T("05");
		}
		else if (iMd==5)
		{
			strPulishMode7=_T("06");
		}
		else
		{
			strPulishMode7=_T("00");
		}
		///////////////////////////////////////////////////////////////////显示模板
		int iTemp=m_combTemplate7.GetCurSel();
		if (iTemp==0)
		{
			strPulishTemp7=_T("01");
		}
		else if (iTemp==1)
		{
			strPulishTemp7=_T("02");
		}
		else if (iTemp==2)
		{
			strPulishTemp7=_T("03");
		}
		else if (iTemp==3)
		{
			strPulishTemp7=_T("04");
		}
		else
		{
			strPulishTemp7=_T("00");
		}
		//////////////////////////////////////////////////////////////////////////停留时间
		int itm=m_combTime7.GetCurSel();
		if (itm==0)
		{
			strTime7=_T("00 01");
		}
		else if (itm==1)
		{
			strTime7=_T("00 02");
		}
		else if (itm==2)
		{
			strTime7=_T("00 03");
		}
		else if (itm==3)
		{
			strTime7=_T("00 04");
		}
		else if (itm==4)
		{
			strTime7=_T("00 05");
		}
		else if (itm==5)
		{
			strTime7=_T("06");
		}
		else if (itm==6)
		{
			strTime7=_T("00 07");
		}
		else if (itm==7)
		{
			strTime7=_T("00 08");
		}
		else if (itm==8)
		{
			strTime7=_T("00 09");
		}
		else if (itm==9)
		{
			strTime7=_T("00 0A");
		}
		else
		{
			strTime7=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////移动速度
		int ispd=m_combSpeed7.GetCurSel();
		if (ispd==0)
		{
			strSpeed7=_T("00 01");
		}
		else if (ispd==1)
		{
			strSpeed7=_T("00 02");
		}
		else if (ispd==2)
		{
			strSpeed7=_T("00 03");
		}
		else if (ispd==3)
		{
			strSpeed7=_T("00 04");
		}
		else if (ispd==4)
		{
			strSpeed7=_T("00 05");
		}
		else if (ispd==5)
		{
			strSpeed7=_T("00 06");
		}
		else if (ispd==6)
		{
			strSpeed7=_T("00 07");
		}
		else if (ispd==7)
		{
			strSpeed7=_T("00 08");
		}
		else if (ispd==8)
		{
			strSpeed7=_T("00 09");
		}
		else if (ispd==9)
		{
			strSpeed7=_T("00 0A");
		}
		else
		{
			strSpeed7=_T("00 00");
		}
		//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
		strDataPacket7=_T("00 00 00 00 ")+strPulishMode7+_T(" ")+strPulishTemp7+_T(" ")+strTime7+_T(" ")+strSpeed7;
		strDataPacket +=+_T(" ")+strDataPacket7;
		CString strNo7;
		strNo7.Format("%d",iNo7);
		strSendFont7=strNo7;
		strSendFont +=+_T(":")+strSendFont7;
		strDataCode7=_T("1");
	}
	else
		strDataCode7=_T("0");

		//////////////////////////////////////////////////////////////////////////消息8
	m_staMSG8.GetWindowTextA(strMSG8);
		if (strMSG8!=_T(""))
		{
			b8=1;
			strMessageList +=strMSG8+";";
			//字模编号
			strsql8.Format("select 字模编号 from DotDisplayData where 显示内容 ='%s'",strMSG8);
			if (theApp.m_ado.ExecuteSelect(strsql8))
			{
				theApp.m_ado.GetInt("字模编号",iNo8);
			}
			//显示模式
			int iMd=m_combMode8.GetCurSel();
			if (iMd==0)
			{
				strPulishMode8=_T("01");
			}
			else if (iMd==1)
			{
				strPulishMode8=_T("02");
			}
			else if (iMd==2)
			{
				strPulishMode8=_T("03");
			}
			else if (iMd==3)
			{
				strPulishMode8=_T("04");
			}
			else if (iMd==4)
			{
				strPulishMode8=_T("05");
			}
			else if (iMd==5)
			{
				strPulishMode8=_T("06");
			}
			else
			{
				strPulishMode8=_T("00");
			}
			///////////////////////////////////////////////////////////////////显示模板
			int iTemp=m_combTemplate8.GetCurSel();
			if (iTemp==0)
			{
				strPulishTemp8=_T("01");
			}
			else if (iTemp==1)
			{
				strPulishTemp8=_T("02");
			}
			else if (iTemp==2)
			{
				strPulishTemp8=_T("03");
			}
			else if (iTemp==3)
			{
				strPulishTemp8=_T("04");
			}
			else
			{
				strPulishTemp8=_T("00");
			}
			//////////////////////////////////////////////////////////////////////////停留时间
			int itm=m_combTime8.GetCurSel();
			if (itm==0)
			{
				strTime8=_T("00 01");
			}
			else if (itm==1)
			{
				strTime8=_T("00 02");
			}
			else if (itm==2)
			{
				strTime8=_T("00 03");
			}
			else if (itm==3)
			{
				strTime8=_T("00 04");
			}
			else if (itm==4)
			{
				strTime8=_T("00 05");
			}
			else if (itm==5)
			{
				strTime8=_T("06");
			}
			else if (itm==6)
			{
				strTime8=_T("00 07");
			}
			else if (itm==7)
			{
				strTime8=_T("00 08");
			}
			else if (itm==8)
			{
				strTime8=_T("00 09");
			}
			else if (itm==9)
			{
				strTime8=_T("00 0A");
			}
			else
			{
				strTime8=_T("00 00");
			}
			//////////////////////////////////////////////////////////////////////////移动速度
			int ispd=m_combSpeed8.GetCurSel();
			if (ispd==0)
			{
				strSpeed8=_T("00 01");
			}
			else if (ispd==1)
			{
				strSpeed8=_T("00 02");
			}
			else if (ispd==2)
			{
				strSpeed8=_T("00 03");
			}
			else if (ispd==3)
			{
				strSpeed8=_T("00 04");
			}
			else if (ispd==4)
			{
				strSpeed8=_T("00 05");
			}
			else if (ispd==5)
			{
				strSpeed8=_T("00 06");
			}
			else if (ispd==6)
			{
				strSpeed8=_T("00 07");
			}
			else if (ispd==7)
			{
				strSpeed8=_T("00 08");
			}
			else if (ispd==8)
			{
				strSpeed8=_T("00 09");
			}
			else if (ispd==9)
			{
				strSpeed8=_T("00 0A");
			}
			else
			{
				strSpeed8=_T("00 00");
			}
			//////////////////////////////////////////////////////////////////////////字模数据包,发送字模
			strDataPacket8=_T("00 00 00 00 ")+strPulishMode8+_T(" ")+strPulishTemp8+_T(" ")+strTime8+_T(" ")+strSpeed8;
			strDataPacket +=+_T(" ")+strDataPacket8;
			CString strNo8;
			strNo8.Format("%d",iNo8);
			strSendFont8=strNo8;
			strSendFont +=+_T(":")+strSendFont8;
			strDataCode8=_T("1");
	}
	else
	{
		strDataCode8=_T("0");
	}
/////////////////////////////////////////////////////////////////////////////////////////
	strDataCode=strDataCode1+strDataCode2+strDataCode3+strDataCode4+strDataCode5+strDataCode6+strDataCode7+strDataCode8+_T("00000000");
	CString strReceiveMAC,strPulishMask;
	int iFinishFlag,iCustomCID,iReceiveDID,iFontCount,iPulishID;
	iFinishFlag=0;
	iCustomCID=1052672;
	iPulishSID=atoi(theApp.strUserName);
	/*iPulishSID=0;*/
	strPulishMask=_T("FFC1");
	iPulishID=0;
	int iLength=strDataPacket.GetLength();
	iFontCount=0;
	if (iLength==29)
	{
		iFontCount=1;
	}
	else if (iLength==59)
	{
		iFontCount=2;
	}
	else if (iLength==89)
	{
		iFontCount=3;
	}
	else if (iLength==119)
	{
		iFontCount=4;
	}
	else if (iLength==149)
	{
		iFontCount=5;
	}
	else if (iLength==179)
	{
		iFontCount=6;
	}
	else if (iLength==209)
	{
		iFontCount=7;
	}
	else if (iLength==239)
	{
		iFontCount=8;
	}

	int nColumn=0;
	int n=b1+b2+b3+b4+b5+b6+b7+b8;
	for (int i=0;i<pQueryDlg->m_listDevice.GetItemCount();i++)
	{
		if (pQueryDlg->m_listDevice.GetCheck(i))
		{
			nColumn++;
		}
	}
	int isql=0;

	BOOL bSuccess=FALSE;
	if (b1!=1&&b2!=1&&b3!=1&&b4!=1&&b5!=1&&b6!=1&&b7!=1&&b8!=1)
	{
		MessageBox("发布消息列表为空,请重新选择消息","温馨提示");
		bSuccess=FALSE;
	}
	else
	{
		if (IDCANCEL==MessageBox("确定发布当前消息吗?","温馨提示",MB_OKCANCEL))
		{
			return;
		}
		m_ProgBPulish.SetRange32(0,nColumn);
		int iList=pQueryDlg->m_listDevice.GetItemCount();
		for (int i=0;i<iList;i++)
		{
			if (pQueryDlg->m_listDevice.GetCheck(i))
			{
				CString strDevName;
				strDeviceDID=pQueryDlg->m_listDevice.GetItemText(i,0);
				strDevieceDMAC=pQueryDlg->m_listDevice.GetItemText(i,2);
				strDevName=pQueryDlg->m_listDevice.GetItemText(i,3);
				iReceiveDID=atoi(strDeviceDID);
				strReceiveMAC=strDevieceDMAC;
				strSqlPul.Format("insert into MessageBuffer(完成标志,客户CID,发布方SID,接收方DID,接收方MAC,数据协议码,发送字模总数,发送掩码,发送字模,字模数据包,发送ID,MessageList,设备别名) values(%d,%d,%d,%d,'%s','%s',%d,'%s','%s','%s',%d,'%s','%s')"
					,iFinishFlag,iCustomCID,iPulishSID,iReceiveDID,strReceiveMAC,strPulishMask,iFontCount,strDataCode,strSendFont,strDataPacket,iPulishID,strMessageList,strDevName);
				if (theApp.m_ado.ExecuteSql(strSqlPul))
				{
					//GetDlgItem(IDC_PROGRESS_PULISHB)->ShowWindow(SW_SHOW);
					isql++;
					m_ProgBPulish.SetPos(isql);
					Sleep(1);
					if (isql==nColumn)
					{
						bSuccess=TRUE;
					}
				}
				else
				{
					CString strError;
					strError.Format("设备%d 写入数据库失败",iReceiveDID);
					if (IDCANCEL==MessageBox(strError,"提示",MB_RETRYCANCEL))
					{
						break;
					}
				}
			}
		}
		if (bSuccess==TRUE)
		{
			CString str;
			str.Format("已有%d个设备写入数据,等待设备下载",isql);
			MessageBox(str,"上传成功");
			CMessageListDlg::OnOK();
			//pQueryDlg->PostMessageA(WM_CLOSE);
			::SendMessage(pQueryDlg->m_hWnd,WM_PULISHMESSAGE,nColumn,n);
		}
	}




		
}


void CMessageListDlg::ReSizeMSG(void)
{
	float fsp[2];  
	POINT Newp; //获取现在对话框的大小  
	CRect recta;      
	GetClientRect(&recta);     //取客户区大小    
	Newp.x=recta.right-recta.left;  
	Newp.y=recta.bottom-recta.top;  
	fsp[0]=(float)Newp.x/old.x;  
	fsp[1]=(float)Newp.y/old.y;  
	CRect Rect;  
	int woc;  
	CPoint OldTLPoint,TLPoint; //左上角  
	CPoint OldBRPoint,BRPoint; //右下角  
	HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //列出所有控件    
	while(hwndChild)      
	{      
		woc=::GetDlgCtrlID(hwndChild);//取得ID  
		GetDlgItem(woc)->GetWindowRect(Rect);    
		ScreenToClient(Rect);    
		OldTLPoint = Rect.TopLeft();    
		TLPoint.x = long(OldTLPoint.x*fsp[0]);    
		TLPoint.y = long(OldTLPoint.y*fsp[1]);    
		OldBRPoint = Rect.BottomRight();    
		BRPoint.x = long(OldBRPoint.x *fsp[0]);    
		BRPoint.y = long(OldBRPoint.y *fsp[1]);    
		Rect.SetRect(TLPoint,BRPoint);    
		GetDlgItem(woc)->MoveWindow(Rect,TRUE);  
		hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);      
	}  
	old=Newp;
}




void CMessageListDlg::OnBnClickedButtClear1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage1;
	strMessage1=_T("");
	m_staMSG1.SetWindowTextA(strMessage1);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE1))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE1))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME1))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED1))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_ONE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtClear2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage2;
	strMessage2=_T("");
	m_staMSG2.SetWindowTextA(strMessage2);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE2))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE2))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME2))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED2))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_TWO)->ShowWindow(SW_HIDE);\
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtClear3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage3;
	strMessage3=_T("");
	m_staMSG3.SetWindowTextA(strMessage3);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE3))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE3))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME3))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED3))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_THREE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtClear4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage4;
	strMessage4=_T("");
	m_staMSG4.SetWindowTextA(strMessage4);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE4))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE4))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME4))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED4))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_FOUR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtClear05()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage5;
	strMessage5=_T("");
	m_staMSG5.SetWindowTextA(strMessage5);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE5))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE5))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME5))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED5))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR05)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_FIVE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtClear06()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage6;
	strMessage6=_T("");
	m_staMSG6.SetWindowTextA(strMessage6);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE6))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE6))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME6))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED6))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR06)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SIX)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtClear7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage7;
	strMessage7=_T("");
	m_staMSG7.SetWindowTextA(strMessage7);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE7))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE7))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME07))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED7))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME07)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEVEN)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtClear8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMessage8;
	strMessage8=_T("");
	m_staMSG8.SetWindowTextA(strMessage8);
	((CComboBox *)GetDlgItem(IDC_COMB_MODE8))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TEMPLATE8))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_TIME8))->SetCurSel(-1);
	((CComboBox *)GetDlgItem(IDC_COMB_SPEED8))->SetCurSel(-1);
	GetDlgItem(IDC_STATIC_MSG8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_MODE8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TEMPLATE8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_TIME8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SEC8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMB_SPEED8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_CLEAR8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_EIGHT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTT_LEADIN)->EnableWindow(TRUE);
}


void CMessageListDlg::OnBnClickedButtAllclear()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedButtClear1();
	OnBnClickedButtClear2();
	OnBnClickedButtClear3();
	OnBnClickedButtClear4();
	OnBnClickedButtClear05();
	OnBnClickedButtClear06();
	OnBnClickedButtClear7();
	OnBnClickedButtClear8();
	GetDlgItem(IDC_BUTT_PULISH)->EnableWindow(FALSE);
}


void CMessageListDlg::OnBnClickedButtMatrlib()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMessageListDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnTimer(nIDEvent);
}


void CMessageListDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}


HBRUSH CMessageListDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_PULISHMSGLST || pWnd-> GetDlgCtrlID() == IDC_STATIC_MODEDP|| pWnd-> GetDlgCtrlID() ==IDC_STATIC_TEMPLATEDP||
		pWnd-> GetDlgCtrlID() ==IDC_STATIC_TIMESTAY|| pWnd-> GetDlgCtrlID() == IDC_STATIC_SPEEDMOVE|| pWnd-> GetDlgCtrlID() == IDC_STATIC_ONE||
		pWnd-> GetDlgCtrlID() == IDC_STATIC_TWO|| pWnd-> GetDlgCtrlID() == IDC_STATIC_THREE|| pWnd-> GetDlgCtrlID() == IDC_STATIC_FOUR|| pWnd-> GetDlgCtrlID() == IDC_STATIC_FIVE||
		pWnd-> GetDlgCtrlID() == IDC_STATIC_SIX|| pWnd-> GetDlgCtrlID() == IDC_STATIC_SEVEN|| pWnd-> GetDlgCtrlID() == IDC_STATIC_EIGHT|| pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG1||
		pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG2|| pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG3|| pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG4|| pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG5
		|| pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG6|| pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG7|| pWnd-> GetDlgCtrlID() == IDC_STATIC_MSG8)
	{
		//pDC->SetTextColor(RGB(255,255,255)); //设置字体为白色

		pDC->SetBkMode(TRANSPARENT);         //设置背景为透明
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	return m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CMessageListDlg::OnSelchangeCombMode1()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode1=m_combMode1.GetCurSel();
	if (nMode1==1||nMode1==2||nMode1==3||nMode1==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE1)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE1)->EnableWindow(TRUE);
}


void CMessageListDlg::OnSelchangeCombMode2()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode2=m_combMode1.GetCurSel();
	if (nMode2==1||nMode2==2||nMode2==3||nMode2==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE2)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE2)->EnableWindow(TRUE);
}


void CMessageListDlg::OnSelchangeCombMode3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode3=m_combMode1.GetCurSel();
	if (nMode3==1||nMode3==2||nMode3==3||nMode3==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE3)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE3)->EnableWindow(TRUE);
}


void CMessageListDlg::OnSelchangeCombMode4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode4=m_combMode1.GetCurSel();
	if (nMode4==1||nMode4==2||nMode4==3||nMode4==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE4)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE4)->EnableWindow(TRUE);
}


void CMessageListDlg::OnSelchangeCombMode5()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode5=m_combMode1.GetCurSel();
	if (nMode5==1||nMode5==2||nMode5==3||nMode5==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE5)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE5)->EnableWindow(TRUE);
}


void CMessageListDlg::OnSelchangeCombMode6()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode6=m_combMode1.GetCurSel();
	if (nMode6==1||nMode6==2||nMode6==3||nMode6==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE6)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE6)->EnableWindow(TRUE);
}


void CMessageListDlg::OnSelchangeCombMode7()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode7=m_combMode1.GetCurSel();
	if (nMode7==1||nMode7==2||nMode7==3||nMode7==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE7)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE7)->EnableWindow(TRUE);
}


void CMessageListDlg::OnSelchangeCombMode8()
{
	// TODO: 在此添加控件通知处理程序代码
	int nMode8=m_combMode1.GetCurSel();
	if (nMode8==1||nMode8==2||nMode8==3||nMode8==4)
	{
		GetDlgItem(IDC_COMB_TEMPLATE8)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_COMB_TEMPLATE8)->EnableWindow(TRUE);
}


BOOL CMessageListDlg::PreTranslateMessage(MSG* pMsg)
{ 
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message==WM_MOUSEMOVE)
	{
		m_TlTips.RelayEvent(pMsg);
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
