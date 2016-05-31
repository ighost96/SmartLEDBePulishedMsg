// VersionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "VersionDlg.h"
#include "afxdialogex.h"


// CVersionDlg 对话框

IMPLEMENT_DYNAMIC(CVersionDlg, CDialogEx)

CVersionDlg::CVersionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVersionDlg::IDD, pParent)
{

}

CVersionDlg::~CVersionDlg()
{
}

void CVersionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CONTRODUCE, m_edtVersion);
}


BEGIN_MESSAGE_MAP(CVersionDlg, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC_CLOSE1, &CVersionDlg::OnClickedStaticClose1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CVersionDlg 消息处理程序


BOOL CVersionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString strE=_T("(2016-4-15)更新日志\r\n\r\n\
1,登录部分添加用户名密码识别，未登记则无法登录，也无法使用产品功能。\r\n\r\n\
2,主页添加状态栏：\r\n\r\n\
	1）登录状态与网络连接状态；\r\n\r\n\
	2）主页每一个按钮的功能介绍，鼠标移动到按钮位置则出现提示；\r\n\r\n\
	3）后几栏主要显示发布消息的状态。\r\n\r\n\
3,省市下拉框选择省后自动出现对应市，不用再手动选择。\r\n\r\n\
4,启用/闲置按钮更改状态会实时修改所勾选区域的状态。\r\n\r\n\
5,选择设备界面点击下一步跳转到消息列表，再点击上一步回到选择设备界面，重复上述操作几次后会报错，   且消息列表里面的消息也会变化，已修复。\r\n\r\n\
6,完善信息库选择多条消息导入到消息列表，限制信息库添加模板内容长度。 \r\n\r\n\
7,完善信息库删除模板文字的警告。\r\n\r\n\
8,发布消息误操作提示，可以被返回，重新选择发布。\r\n\r\n\
9,发布消息后进度条撤销，关闭所有窗口，回到主页窗口，在主界面底部状态栏显示当前发布消息的状态。\r\n\r\n\
10,版本日志更新，点击主页面版本号即可查看版本更新日志。\r\n\r\n\
11,主页上增加历史发布消息记录查询，单击跳转到历史记录页面，通过选择发布时间等条件查询已发布消息的状态。\r\n\r\n\
12,除主页面以外所有窗口背景略微调整。\r\n\r\n\
13,查询设备页面与信息查询页面的表格已实现点击每一栏上就可以选择，而不是必须手动勾选。\r\n\r\n\
14,在查询设备页面右键点击自定义设备名一栏可实现修改设备别名。\r\n\r\n");
	CString strText;
	strText=_T("(2016-4-22)更新日志\r\n\r\n\
1,在查询设备页面右键点击自定义设备名一栏可实现修改设备别名。\r\n\r\n2,调整历史记录部分布局。\r\n\r\n\
3,修改发布任务是否成功显示方式，改文字显示为图片显示。\r\n\r\n\
4,增加发布消息状态进度条显示方式。\r\n\r\n\
5,历史记录栏增加设备别名与发布的消息文字显示。\r\n\r\n");
	CString strText29;
	strText29=_T("(2016-4-29)更新日志\r\n\r\n\
1,优化历史记录页面完成标识的图片和进度条显示。\r\n\r\n\
2,调整历史记录页面全屏后界面布局。\r\n\r\n\
3,选择发布设备界面全屏后布局调整。\r\n\r\n\
4,修复了选择设备的一些bug：当不选择任何条件刷新设备列表，选中一个设备（尽量靠后），然后选择省市条件，如四川等一些设备注册较少的省市，再次查询，选择列表中一行，点击下一步会报错。\r\n\r\n\
5,发布任务完成后，会回到主界面，在主界面增加了定时查询当前发布任务完成状态，并实时更新在主界面状态栏上。\r\n\r\n\
6,更改了在发布任务显示添加信息模板的功能，现在只能在主界面信息管理按钮进入才能添加信息模板。\r\n\r\n");

	CString strText24;
	strText24=_T("(2016-5-24)更新日志\r\n\r\n\
1,'设备列表'界面增加高级搜索功能，支持模糊查询，左键单击蓝色高级搜索按钮，出现相应选择条件，其中各编辑框无需输入完整条件，只需输入条件所包含有的字段即可搜索相关信息；\r\n\r\n\
2,自定义设备名改为双击修改，修复了修改设备名再发布消息会失败的bug，增加了修改名称后可回车响应修改；\r\n\r\n\
3,列表的展示更加鲜明，视觉效果更加，同时更改了勾选方式，以左键单击最右边框体表示选中，同时增加了列表按县区区域排列；\r\n\r\n\
4,修复了全选之后‘下一步’按钮无法恢复的显示的bug，优化了‘下一步’按钮随操作变化的可视化；\r\n\r\n\
5,“设备列表”界面添加了状态栏，以便于显示发布后信息状态；\r\n\r\n\
6,发布信息流程完毕后，程序将不再退回到主界面，更改为退回“设备列表”界面，消息状态也将在状态栏显示；\r\n\r\n\
7,“消息列表”界面中，停留时间暂定默认为1，同时，‘显示模式’中左移，右移，上滚，下滚皆改为不再选择‘显示模板’，同时现有的模式选择都能实现对智能屏模式控制；\r\n\r\n\
8,修复了选择多条信息，删除其中靠除头尾的信息再发布结果只有手机有显示，智能屏无法显示的bug；\r\n\r\n\
9,修复了导入信息超过8条会一直提示的bug；\r\n\r\n\
10,“历史记录”界面也增加了编辑框内支持模糊查询功能；\r\n\r\n\
11，优化了几乎所有界面，使之看上去更舒适，特别是表格内的显示，以及名称和风格的统一；\r\n\r\n");

	CString strText27=_T("(2016-5-27)更新日志\r\n\r\n\
1,主界面及发布消息流程界面全增加了Tips显示各个按钮的功能提示，鼠标移动至按钮处即可看到提示；\r\n\r\n\
2,增加了进度条显示发布状态，发布消息过程中，状态条会根据目前执行的数据指示进度；\r\n\r\n\
3,历史记录界面增加删除某条信息功能，同时也增加了全选功能，方便多条删除；\r\n\r\n\r\n\r\n");
	m_edtVersion.SetWindowTextA(strText27+strText24+strText29+strText+strE);

	m_brush.CreateSolidBrush(RGB(210,255,255));

//////////////////////////////////////////////////////////////////////////
	GetDlgItem(IDC_STATIC_CLOSE1)->SetFocus();

	return FALSE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CVersionDlg::OnClickedStaticClose1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


HBRUSH CVersionDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_VERS || pWnd-> GetDlgCtrlID() == IDC_STATIC_ED||pWnd-> GetDlgCtrlID() == IDC_STATIC_CLOSE1)
	{
		pDC->SetTextColor(RGB(255,0,0)); //设置字体为x色
		pDC->SetBkMode(TRANSPARENT);         //设置背景为透明
		return   HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if (pWnd->GetDlgCtrlID()==IDC_EDIT_CONTRODUCE&&nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(255,255,255));
		return ::CreateSolidBrush(RGB(255,255,255));
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkMode(TRANSPARENT);  
	}

	return m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}



BOOL CVersionDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::PreTranslateMessage(pMsg);
}
