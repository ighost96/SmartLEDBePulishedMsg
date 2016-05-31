// DeviceQueryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "DeviceQueryDlg.h"
#include "afxdialogex.h"
#include "MessageListDlg.h"


#define CID 1052672  

// CDeviceQueryDlg 对话框

IMPLEMENT_DYNAMIC(CDeviceQueryDlg, CDialogEx)

CDeviceQueryDlg::CDeviceQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceQueryDlg::IDD, pParent)
{

}

CDeviceQueryDlg::~CDeviceQueryDlg()
{
}

void CDeviceQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listDevice);
	DDX_Control(pDX, IDC_COMBPROVINCE, m_combProvince);
	DDX_Control(pDX, IDC_COMBCITY, m_combCity);
	DDX_Control(pDX, IDC_CHECKALL, m_checkAll);
	DDX_Control(pDX, IDC_BUTTON6, m_butt_NextStep);
	DDX_Control(pDX, IDC_EDIT_DEVICEID, m_edtDevSID);
	DDX_Control(pDX, IDC_EDIT_DEVICEDID, m_edtID);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_edtAddress);
	DDX_Control(pDX, IDC_STATIC_HIGHQUERY, m_stcQuery);
	DDX_Control(pDX, IDC_EDIT_DEVICENAME, m_edtDeviceName);
}


BEGIN_MESSAGE_MAP(CDeviceQueryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &CDeviceQueryDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CDeviceQueryDlg::OnClickedButtonLastStep)
	ON_BN_CLICKED(IDC_BUTT_DEVICELIST, &CDeviceQueryDlg::OnClickedButtDevicelist)
	ON_CBN_SELCHANGE(IDC_COMBPROVINCE, &CDeviceQueryDlg::OnSelchangeCombProvince)
	ON_BN_CLICKED(IDC_RADIO1, &CDeviceQueryDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_CHECKALL, &CDeviceQueryDlg::OnClickedCheckAll)
	ON_BN_CLICKED(IDC_BUTT_STATUS, &CDeviceQueryDlg::OnClickedButtStatusFlag)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDeviceQueryDlg::OnClickList1)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDeviceQueryDlg::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &CDeviceQueryDlg::OnColumnclickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CDeviceQueryDlg::OnDblclkListDoubleClick)
	ON_EN_KILLFOCUS(IDC_EDIT_LISTEDIT,&CDeviceQueryDlg::OnKillFocusListEdit)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CDeviceQueryDlg::OnRclickListChangeName)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_STATIC_HIGHQUERY, &CDeviceQueryDlg::OnClickedStaticHighquery)
	ON_MESSAGE(WM_PULISHMESSAGE,OnRecVPulishMSG)
END_MESSAGE_MAP()


//使用EasySize来控制控件位置及缩放
BEGIN_EASYSIZE_MAP(CDeviceQueryDlg)
	/*EASYSIZE(IDC_EDIT_ADDRESS,ES_BORDER,ES_BORDER,ES_BORDER,ES_KEEPSIZE,ES_HCENTER)
	EASYSIZE(IDC_STATIC_DID,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,0)
	EASYSIZE(IDC_EDIT_DEVICEID,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,0)
	EASYSIZE(IDC_BUTT_DEVICELIST,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_ADDRESS,IDC_EDIT_ADDRESS,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_EDIT_DEVICEDID,IDC_STATIC_ADDRESS,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_DEVICEDID,IDC_EDIT_DEVICEDID,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_EDIT_DEVICENAME,IDC_STATIC_DEVICEDID,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_DEVICENAME,IDC_EDIT_DEVICENAME,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,0)*/
	//EASYSIZE(IDC_STATIC_HIGHQUERY,ES_KEEPSIZE,ES_BORDER,IDC_EDIT_ADDRESS,ES_KEEPSIZE,ES_HCENTER)
	EASYSIZE(IDC_STATIC_TOP,ES_BORDER,ES_BORDER,ES_BORDER,IDC_LIST1,0)
	EASYSIZE(IDC_CHECKALL,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_TOP,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_PROVINCE,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_TOP,ES_KEEPSIZE,0)
	EASYSIZE(IDC_COMBPROVINCE,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_PROVINCE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_CITY,ES_KEEPSIZE,ES_BORDER,IDC_COMBPROVINCE,ES_KEEPSIZE,0)
	EASYSIZE(IDC_COMBCITY,ES_KEEPSIZE,ES_BORDER,IDC_STATIC_CITY,ES_KEEPSIZE,0)
	EASYSIZE(IDC_RADIO1,ES_KEEPSIZE,ES_BORDER,IDC_COMBCITY,ES_KEEPSIZE,0)
	EASYSIZE(IDC_RADIO2,ES_KEEPSIZE,ES_BORDER,IDC_RADIO1,ES_KEEPSIZE,0)
	EASYSIZE(IDC_STATIC_BOTTOM,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDC_BUTT_STATUS,ES_KEEPSIZE,ES_KEEPSIZE,IDC_STATIC_BOTTOM,ES_BORDER,0)
	EASYSIZE(IDC_BUTTON5,ES_KEEPSIZE,ES_KEEPSIZE,IDC_BUTT_STATUS,ES_BORDER,0)
	EASYSIZE(IDC_BUTTON6,ES_KEEPSIZE,ES_KEEPSIZE,IDC_BUTTON5,ES_BORDER,0)
	EASYSIZE(IDC_LIST1,ES_BORDER,ES_BORDER,ES_BORDER,IDC_STATIC_BOTTOM,0)
END_EASYSIZE_MAP



// CDeviceQueryDlg 消息处理程序



void CDeviceQueryDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码	
	/*int nCheck=0;
	for (int i=0;i<m_listDevice.GetItemCount();i++)
	{
	if (m_listDevice.GetCheck(i))
	{
	nCheck++;
	}
	}
	if (nCheck==0)
	{
	MessageBox("当前未选中任何信息","温馨提示");
	return;
	}*/
	
	CMessageListDlg *pMSGDlg=new CMessageListDlg;
	pMSGDlg->pQueryDlg=this;
	//pMSGDlg->DoModal();
	if (IDCANCEL==pMSGDlg->DoModal())
	{
		GetDlgItem(IDC_BUTT_DEVICELIST)->SetFocus();
	}
	
}


void CDeviceQueryDlg::OnClickedButtonLastStep()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL CDeviceQueryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	INIT_EASYSIZE;

	//设备列表初始化设置
	CRect rect;
	m_listDevice.GetClientRect(&rect);
	m_listDevice.SetExtendedStyle(m_listDevice.GetExtendedStyle()|LVS_EX_FULLROWSELECT/*|LVS_EX_GRIDLINES*/|LVS_EX_CHECKBOXES);

	int nIndex=0;
	m_listDevice.InsertColumn(nIndex++,"设备ID",LVCFMT_CENTER,100);
	m_listDevice.InsertColumn(nIndex++,"使用状态",LVCFMT_LEFT,100);
	m_listDevice.InsertColumn(nIndex++,"设备Mac",LVCFMT_LEFT,170);
	m_listDevice.InsertColumn(nIndex++,"自定义设备名",LVCFMT_LEFT,150);
	m_listDevice.InsertColumn(nIndex++,"省份",LVCFMT_LEFT,0);
	m_listDevice.InsertColumn(nIndex++,"市区",LVCFMT_LEFT,0);
	m_listDevice.InsertColumn(nIndex++,"县区",LVCFMT_LEFT,130);
	m_listDevice.InsertColumn(nIndex++,"设置的字模",LVCFMT_LEFT,250);
	m_listDevice.InsertColumn(nIndex++,"字模数据包",LVCFMT_LEFT,0);
	m_listDevice.InsertColumn(nIndex++,"地址",LVCFMT_LEFT,480);

	//省下拉框
	m_combProvince.AddString("全部");
	CString strSqlp,strProvince;
	strSqlp.Format("select distinct 省份 from DeviceRegisted");
	theApp.m_ado.ExecuteSelect(strSqlp);
	while(!theApp.m_ado.IsEOF())
	{
		theApp.m_ado.GetString("省份",strProvince);
		m_combProvince.AddString(strProvince);
		theApp.m_ado.MoveNext();
	}
	m_combProvince.SetCurSel(0);
	m_combCity.AddString(_T("全部"));
	m_combCity.SetCurSel(0);

	//下一步按钮初始化为不可点击
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTT_STATUS)->EnableWindow(FALSE);

	//窗体随分辨率变动
	CRect rect1;      
	GetClientRect(&rect1);     //取客户区大小    
	old.x=rect1.right-rect1.left;  
	old.y=rect1.bottom-rect.top;  
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);  
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);  
	CRect rt;  
	SystemParametersInfo(SPI_GETWORKAREA,0,&rt,0);  
	cy = rt.bottom;  
	MoveWindow(0, 0, cx, cy);  
//////////////////////////////////////////////////////////////////////////
	m_brush.CreateSolidBrush(RGB(255,255,255));
//////////////////////
	nPress=0;
	bHaveBeenCreate=FALSE;
///////////////////////////
	m_edtID.SetLimitText(8);
	m_edtAddress.SetLimitText(30);
	m_edtDevSID.SetLimitText(12);
//////////////////////////////////////////////////////////////////////////
	SetTimer(1,7,NULL);
	
	GetDlgItem(IDC_STATIC_TOP)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DEVICEDID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DEVICEDID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DEVICEID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DEVICENAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DEVICENAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_HIGHQUERY)->SetWindowTextA(_T(">>高级查询"));
//////////////////////////////////////////////////////////////////////////
	iPressHigh=0;

	GetDlgItem(IDC_BUTT_DEVICELIST)->SetFocus();
//////////////////////////////////////////////////////////////////////////
	m_pStatBar=new CStatusBarCtrl;
	RECT recta;
	GetClientRect(&recta);
	recta.top=recta.bottom-20;
	m_pStatBar->Create(WS_BORDER|WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,recta,this,4);
	int nP1=(int)cx/2;
	int nP2=(int)nP1/4+nP1;
	int nP3=(int)nP1/4+nP2;
	int nP4=(int)nP1/4+nP3;
	int nPart[5]={nP1,nP2,nP3,nP4,-1};
	m_pStatBar->SetParts(5,nPart);
	m_pStatBar->SetText(_T("发布条数：0 条"),1,1);
	m_pStatBar->SetText(_T("成功下载：0 条"),2,2);
	m_pStatBar->SetText(_T("成功刷屏：0 条"),3,3);
	m_pStatBar->SetText(_T("无"),4,4);
	//--------------ToolTip---------------------
	m_TlTips.Create(this);
	m_TlTips.AddTool(GetDlgItem(IDC_STATIC_HIGHQUERY),TEXT(_T("输入包含关键字可实现模糊查询")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_STATUS),TEXT(_T("切换设备状态为可用或者闲置")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTTON5),TEXT(_T("单击返回主界面")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTTON6),TEXT(_T("单击进入消息添加,处理,发布界面")));
	m_TlTips.AddTool(GetDlgItem(IDC_BUTT_DEVICELIST),TEXT(_T("刷新列表或者查询满足所选条件的设备")));
//////////////////////////////////////////////////////////////////////////
	return FALSE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDeviceQueryDlg::OnClickedButtDevicelist()
{
	// TODO: 在此添加控件通知处理程序代码
	nPress=0;
	m_listDevice.DeleteAllItems();
	m_checkAll.SetCheck(FALSE);

	CString strSQL,strsqlL,strDeviceID,strStatus,strDeviceDMAC,strProvinceL,strCityL,strCountryL,strSetinFont,strFontPacket,strAdress;
	strSQL.Format("select 设备DID,使用状态,设备DMAC,设备DMAC别名,省份,市区,县区,设置的字模,字模数据包,地址 from DeviceRegisted   where  1=1 ");
	//客户CID='1052672'  
	//省,市条件
	int iCity,iProV;
	CString strsqlPro,strsqlCit;
	iProV=m_combProvince.GetCurSel();
	iCity=m_combCity.GetCurSel();
	if (iProV>0)
	{
		m_combProvince.GetLBText(iProV,strProvinceL);
		strsqlPro.Format(" and 省份='%s'",strProvinceL);
		strSQL +=strsqlPro;
	}
	if (iCity>0)
	{
		m_combCity.GetLBText(iCity,strCityL);
		strsqlCit.Format(" and 市区='%s'",strCityL);
		strSQL +=strsqlCit;
	}

	//设备状态
	CString strsqla;
	BOOL bCheck=FALSE;
	if (BST_CHECKED==IsDlgButtonChecked(IDC_RADIO1))
	{
		bCheck=TRUE;
		strsqla.Format(" and 使用状态='可用' ");
	}
	else if(BST_CHECKED==IsDlgButtonChecked(IDC_RADIO2))
	{
		bCheck=TRUE;
		strsqla.Format(" and 使用状态='闲置' ");
	}
	strSQL +=strsqla;

	//设备名
	CString strDeviceName,strsqlName;
	m_edtDeviceName.GetWindowTextA(strDeviceName);
	if (!strDeviceName.IsEmpty())
	{
		strsqlName.Format(" and 设备DMAC别名 like '%%"+strDeviceName+"%%'");
		strSQL +=strsqlName;
	}

	//设备ID
	CString strsqlID,strEdtID;
	m_edtID.GetWindowTextA(strEdtID);
	if (!strEdtID.IsEmpty())
	{
		strsqlID.Format(" and 设备DID like '%%"+strEdtID+"%%'");
		strSQL +=strsqlID;
	}

	//设备DMAC
	CString strsqld,strEdtDMac;
	m_edtDevSID.GetWindowTextA(strEdtDMac);
	if (strEdtDMac!=_T(""))
	{
		strsqld.Format("and 设备DMAC like '%%"+strEdtDMac+"%%'");
		strSQL +=strsqld;
	}

	//地址
	CString strsqladdr,strEdtAddr;
	m_edtAddress.GetWindowTextA(strEdtAddr);
	if (!strEdtAddr.IsEmpty())
	{
		strsqladdr.Format(" and 地址 like '%%"+strEdtAddr+"%%'");
		strSQL +=strsqladdr;
	}

	//排序
	CString strsqlOrder;
	strsqlOrder.Format(" order by 县区");
	strSQL +=strsqlOrder;

	if (theApp.m_ado.ExecuteSelect(strSQL))
	{
		while(!theApp.m_ado.IsEOF())
		{
			theApp.m_ado.GetString("设备DID",strDeviceID);
			int n=m_listDevice.GetItemCount();
			m_listDevice.InsertItem(n,strDeviceID);

			theApp.m_ado.GetString("使用状态",strStatus);
			strStatus.Replace(" ","");
			m_listDevice.SetItemText(n,1,strStatus);

			theApp.m_ado.GetString("设备DMAC",strDeviceDMAC);
			m_listDevice.SetItemText(n,2,strDeviceDMAC);

			CString strDMacAli;
			theApp.m_ado.GetString("设备DMAC别名",strDMacAli);
			strDMacAli.Replace(" ","");
			m_listDevice.SetItemText(n,3,strDMacAli);

			theApp.m_ado.GetString("省份",strProvinceL);
			m_listDevice.SetItemText(n,4,strProvinceL);

			theApp.m_ado.GetString("市区",strCityL);
			m_listDevice.SetItemText(n,5,strCityL);

			theApp.m_ado.GetString("县区",strCountryL);
			strCountryL.Replace(" ","");
			m_listDevice.SetItemText(n,6,strCountryL);

			theApp.m_ado.GetString("设置的字模",strSetinFont);
			strSetinFont.Replace(" ","");
			m_listDevice.SetItemText(n,7,strSetinFont);

			theApp.m_ado.GetString("字模数据包",strFontPacket);
			m_listDevice.SetItemText(n,8,strFontPacket);

			theApp.m_ado.GetString("地址",strAdress);
			strAdress.Replace(" ","");
			m_listDevice.SetItemText(n,9,strAdress);

			theApp.m_ado.MoveNext();
		}
	}
	int iCounts=m_listDevice.GetItemCount();
	CString strCounts;
	strCounts.Format(_T("当前显示信息数:%d"),iCounts);
	m_pStatBar->SetText(strCounts,0,0);
}


void CDeviceQueryDlg::OnSelchangeCombProvince()
{
	// TODO: 在此添加控件通知处理程序代码
	//市下拉框
	CString strSqlc,strCity,strProvince;
	int iProv;
	iProv=m_combProvince.GetCurSel();
	m_combProvince.GetLBText(iProv,strProvince);
	if (strProvince==_T("全部"))
	{
		m_combCity.AddString(_T("全部"));
		m_combCity.SetCurSel(0);
	}
	int iIndex =m_combCity.GetCount();
	while(iIndex--)
		m_combCity.DeleteString(iIndex);
	
	strSqlc.Format("select distinct 市区 from DeviceRegisted where 省份='%s' ",strProvince);
	theApp.m_ado.ExecuteSelect(strSqlc);
	m_combCity.AddString(_T("全部"));
	while(!theApp.m_ado.IsEOF())
	{
		m_combCity.SetCurSel(0);
		theApp.m_ado.GetString("市区",strCity);
		m_combCity.AddString(strCity);
		theApp.m_ado.MoveNext();
	}
}

//点击在用按钮
void CDeviceQueryDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDeviceQueryDlg::OnClickedCheckAll()
{
	// TODO: 在此添加控件通知处理程序代码
	int iCount=m_listDevice.GetItemCount();
	BOOL bCheck=FALSE;
	if (BST_CHECKED==IsDlgButtonChecked(IDC_CHECKALL))
	{
		bCheck=TRUE;
		GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	}
	else
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		
	for (int i=0;i<iCount;i++)
	{
		m_listDevice.SetCheck(i,bCheck);
	}

}

//使用状态改变
void CDeviceQueryDlg::OnClickedButtStatusFlag()
{
	// TODO: 在此添加控件通知处理程序代码

	for (int i=0;i<m_listDevice.GetItemCount();i++)
	{
		if (m_listDevice.GetCheck(i))
		{
			int iCheck=m_listDevice.GetItemCount();
			CString strsqlCheck,strDeviceDID,strDeviceStatus;
			strDeviceDID=m_listDevice.GetItemText(i,0);
			strDeviceStatus=m_listDevice.GetItemText(i,1);
			if (strDeviceStatus==_T("可用"))
			{
				strsqlCheck.Format("update DeviceRegisted set 使用状态='闲置'   where 设备DID='%s' ",strDeviceDID);
				if (theApp.m_ado.ExecuteSql(strsqlCheck))
				{
					m_listDevice.SetItemText(i,1,"闲置");
					m_listDevice.SetCheck(i,FALSE);
				}
			}
			else 
			{
				strsqlCheck.Format("update DeviceRegisted set 使用状态='可用'   where 设备DID='%s' ",strDeviceDID);
				if (theApp.m_ado.ExecuteSql(strsqlCheck))
				{
					m_listDevice.SetItemText(i,1,"可用");
					m_listDevice.SetCheck(i,FALSE);
				}
			}
		}
	}
	UpdateData();
}


//判断LIST表是否被点击勾选，勾选则可以点击下一步按钮
void CDeviceQueryDlg::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	 //TODO: 在此添加控件通知处理程序代码
	
	///////////////////////////////////////////////////////
	
	

	*pResult = 0;
}


HBRUSH CDeviceQueryDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性


	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_PROVINCE || pWnd-> GetDlgCtrlID() == IDC_STATIC_CITY|| pWnd-> GetDlgCtrlID() ==IDC_STATIC_DevStat||
		pWnd-> GetDlgCtrlID() ==IDC_STATIC_DID|| pWnd-> GetDlgCtrlID() == IDC_STATIC_DEVICEDID || pWnd-> GetDlgCtrlID() == IDC_STATIC_ADDRESS||
		pWnd->GetDlgCtrlID()==IDC_STATIC_DEVICENAME)
	{
		//pDC->SetTextColor(RGB(255,255,255)); //设置字体为白色

		pDC->SetBkMode(TRANSPARENT);         //设置背景为透明
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID()==IDC_STATIC_HIGHQUERY)
	{
		pDC->SetTextColor(RGB(0,0,255));
		//pDC->SetBkMode(TRANSPARENT);
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	return m_brush;

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDeviceQueryDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */ 
		) 
	{ 
		GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
		nItem=pNMLV->iItem;
		GetDlgItem(IDC_BUTT_STATUS)->EnableWindow(TRUE);
	} 
	else if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */ 
		&& (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */ 
		) 
	{ 
		//TRACE("Item %d is unchecked\n", pNMLV->iItem);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTT_STATUS)->EnableWindow(FALSE);
	} 
	else 
	{ 
		//TRACE("Item %d does't change the check-status\n", pNMLV->iItem); 
	} 

	*pResult = 0;
}

//列表排序的回调函数
int CALLBACK  CDeviceQueryDlg::ListCompare(LPARAM lParam1,LPARAM lParam2,LPARAM lParamSort)
{
	int row1=(int)lParam1;
	int row2=(int)lParam2;

	CListCtrl *pLc=(CListCtrl *)lParamSort;
	CString str1=pLc->GetItemText(row1,0);
	CString str2=pLc->GetItemText(row2,0);

	if (bSort)
	{
		return strcmp(str1,str2);
	}
	else
		return strcmp(str2,str1);
}

//点击列表标题栏第一栏排序
void CDeviceQueryDlg::OnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (pNMLV->iSubItem==0)
	{
		bSort=!bSort;
		int nCount=m_listDevice.GetItemCount();
		for (int i=0;i<nCount;i++)
		{
			m_listDevice.SetItemData(i,i);
		}
		m_listDevice.SortItems(ListCompare,(LPARAM)&m_listDevice);
	}
	*pResult = 0;
}


void CDeviceQueryDlg::OnDblclkListDoubleClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW *pEditCtrl=(NM_LISTVIEW *)pNMHDR;
	printf("行:%d,列:%d\n",pEditCtrl->iItem,pEditCtrl->iSubItem);
	if (pEditCtrl->iItem==-1)
	{
		if (bHaveBeenCreate==TRUE)
		{
			DestroyEdit(&m_listDevice,&m_edit,e_iTem,e_SubItem);
			bHaveBeenCreate=FALSE;
		}
	}	
	else if (pEditCtrl->iSubItem==3)
	{
		if (bHaveBeenCreate==TRUE)
		{
			if (e_iTem!=pEditCtrl->iItem&&e_SubItem!=pEditCtrl->iSubItem)
			{
				DestroyEdit(&m_listDevice,&m_edit,e_iTem,e_SubItem);
				bHaveBeenCreate=FALSE;
				CreateEdit(pEditCtrl,&m_edit,e_iTem,e_SubItem,bHaveBeenCreate);
			}
			else
			{
				m_edit.SetFocus();
			}
		}
		else
		{
			e_iTem=pEditCtrl->iItem;
			e_SubItem=pEditCtrl->iSubItem;
			CreateEdit(pEditCtrl,&m_edit,e_iTem,e_SubItem,bHaveBeenCreate);
		}
	}

	*pResult = 0;
}

void CDeviceQueryDlg::OnRclickListChangeName(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	

	*pResult = 0;
}


void CDeviceQueryDlg::DestroyEdit(CListCtrl *list, CEdit* destroyEdit, int &Item, int &SubItem)
{
	CString strEditData;
	destroyEdit->GetWindowTextA(strEditData);
	m_listDevice.SetItemText(Item,SubItem,strEditData);     //获得相应单元格字符 
	destroyEdit->DestroyWindow();                           //销毁对象，有创建就要有销毁，不然会报错
}

void CDeviceQueryDlg::CreateEdit(NM_LISTVIEW *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool bHadCreate)
{
	Item=pEditCtrl->iItem;                         //将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem=pEditCtrl->iSubItem;
	createdit->Create(ES_AUTOHSCROLL| WS_CHILD | ES_LEFT | ES_WANTRETURN ,CRect(0,0,0,0),this,IDC_EDIT_LISTEDIT);    //创建编辑框对象,IDC_EDIT_CREATEID为控件ID号1141,在Resource.h中定义
	bHadCreate=TRUE;
	createdit->SetFont(this->GetFont(),FALSE);  //设置字体,不设置这里的话上面的字会很突兀的感觉
	createdit->SetParent(&m_listDevice);                     //将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要  
	CRect editRect;
	m_listDevice.GetSubItemRect(e_iTem,e_SubItem,LVIR_LABEL,editRect);    //获取单元格的空间位置信息 
	editRect.SetRect(editRect.left,editRect.top,editRect.left+m_listDevice.GetColumnWidth(e_SubItem)-1,editRect.bottom-1);        //+1和-1可以让编辑框不至于挡住列表框中的网格线  
	CString strItem=m_listDevice.GetItemText(e_iTem,e_SubItem);     //获得相应单元格字符 
	createdit->SetWindowTextA(strItem);                                    //将单元格字符显示在编辑框上
	createdit->MoveWindow(&editRect);                                  //将编辑框位置放在相应单元格上 
	createdit->ShowWindow(SW_SHOW);                               //显示编辑框在单元格上面 
	createdit->SetLimitText(10);												  //编辑框设置字符限制
	createdit->SetFocus();                                                        //设置为焦点
	createdit->SetSel(-1);															//设置光标在文本框文字的最后
}

void CDeviceQueryDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void CDeviceQueryDlg::OnKillFocusListEdit()
{
	DestroyEdit(&m_listDevice,&m_edit,e_iTem,e_SubItem);
	bHaveBeenCreate=FALSE;
	CString strAli,strSql,strDeV,strDMac;
	strAli=m_listDevice.GetItemText(e_iTem,e_SubItem);
	try
	{
		if (!strAli.IsEmpty())
		{
			strDeV=m_listDevice.GetItemText(e_iTem,0);               //获取相应行设备DID
			strDeV.Replace(" ","");
			strDMac=m_listDevice.GetItemText(e_iTem,2);            //获得相应设备DMAC
			strSql.Format("update DeviceRegisted set 设备DMAC别名='%s' where 设备DID='%s' and 设备DMAC='%s' ",strAli,strDeV,strDMac);
			if (IDCANCEL==MessageBox("确定自定义此设备名称吗？","温馨提示",MB_OKCANCEL))
			{
				m_listDevice.SetItemText(e_iTem,3,"");
				return ;
			}
			else
				theApp.m_ado.ExecuteSql(strSql);
		}
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return ;
	}
}




void CDeviceQueryDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	UPDATE_EASYSIZE; //更新窗口大小
}


void CDeviceQueryDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: 在此处添加消息处理程序代码
	EASYSIZE_MINSIZE(1263,694,fwSide,pRect);
}


void CDeviceQueryDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nIDEvent)
	{
	case 1:
		OnClickedButtDevicelist();
		KillTimer(1);
		break;
	case 2:
		OnRecVPulishMSG(ncheck,num);
		if (bFlag==TRUE )
		{
			KillTimer(1);
		}
		break;
	default: break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CDeviceQueryDlg::OnClickedStaticHighquery()
{
	// TODO: 在此添加控件通知处理程序代码
	iPressHigh++;
	if (iPressHigh%2==0)
	{
		GetDlgItem(IDC_STATIC_DEVICEDID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DEVICEDID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DEVICEID)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DEVICENAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DEVICENAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HIGHQUERY)->SetWindowTextA(_T(">>"));
	}
	else
	{
		GetDlgItem(IDC_STATIC_DEVICEDID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DEVICEDID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DEVICEID)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DEVICENAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DEVICENAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_HIGHQUERY)->SetWindowTextA(_T("<<"));
	}
}




BOOL CDeviceQueryDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_RETURN)
	{
		GetNextDlgTabItem(GetFocus())->SetFocus();
	}

	if (pMsg->message==WM_MOUSEMOVE)
	{
		m_TlTips.RelayEvent(pMsg);
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


LRESULT CDeviceQueryDlg::OnRecVPulishMSG(WPARAM wParam,LPARAM lParam)
{
	SetTimer(2,3000,NULL);
	ncheck=wParam;
	num=lParam;
	int x=0,y=0;
	int iPlsSuccess,iSetSuccess,iUser;
	iUser=atoi(theApp.strUserName);
	int nPlsCount=num*ncheck;
	CString strsqlp,strPlsSuccess,strSetSuccess;
	strsqlp.Format("select top %d 发布方SID,发布日期,成功发送字模数,成功设置字模数  from MessageBuffer where 发布方SID=%d  order by 发布日期 desc ",ncheck,iUser);
	if (theApp.m_ado.ExecuteSelect(strsqlp))
	{
		while(!theApp.m_ado.IsEOF())
		{
			theApp.m_ado.GetInt("成功发送字模数",iPlsSuccess);
			x+=iPlsSuccess;
			theApp.m_ado.GetInt("成功设置字模数",iSetSuccess);
			y+=iSetSuccess;
			theApp.m_ado.MoveNext();
		}
		CString strPlsCount,strPhone,strLED;
		strPlsCount.Format(_T("发布条数:%d 条"),nPlsCount);
		strPhone.Format(_T("成功下载：%d 条"),x);
		strLED.Format(_T("成功刷屏：%d 条"),y);
		m_pStatBar->SetText(strPlsCount,1,1);
		m_pStatBar->SetText(strPhone,2,2);
		m_pStatBar->SetText(strLED,3,3);
		if (nPlsCount==x&&nPlsCount==y)
		{
			bFlag=TRUE;
			m_pStatBar->SetText(_T("已完成"),4,4);
		}
		else
		{
			bFlag=FALSE;
			m_pStatBar->SetText(_T("进行中..."),4,4);
		}

	}
	return TRUE;
}

