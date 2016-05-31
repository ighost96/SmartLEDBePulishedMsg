// AffirmManage.cpp : 实现文件
//

#include "stdafx.h"
#include "SingleDemon.h"
#include "AffirmManage.h"
#include "afxdialogex.h"
#include "MessageListDlg.h"
#include "SingleDemonDlg.h"
#include "AddAffirmDlg.h"

// CAffirmManage 对话框

IMPLEMENT_DYNAMIC(CAffirmManage, CDialogEx)

CAffirmManage::CAffirmManage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAffirmManage::IDD, pParent)
{
	
}

CAffirmManage::~CAffirmManage()
{
}

void CAffirmManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTAFFIRM, m_listMatrix);
}


BEGIN_MESSAGE_MAP(CAffirmManage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_CANCERA, &CAffirmManage::OnClickedButtCancerA)
	ON_BN_CLICKED(IDC_BUTT_QUERYMATRIX,&CAffirmManage::OnBnClickedQueryMatrixButton)
	ON_NOTIFY(NM_CLICK, IDC_LISTAFFIRM, &CAffirmManage::OnClickListChooseMatrix)
	ON_BN_CLICKED(IDC_BUTT_LEAD_IN, &CAffirmManage::OnClickedButtLeadIn)
	ON_BN_CLICKED(IDC_BUTT_ADDMATRIX, &CAffirmManage::OnBnClickedButtAddmatrix)
	ON_BN_CLICKED(IDC_BUTT_DELETE, &CAffirmManage::OnBnClickedButtDelete)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CAffirmManage 消息处理程序


void CAffirmManage::OnClickedButtCancerA()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL CAffirmManage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	m_listMatrix.GetClientRect(&rect);
	m_listMatrix.SetExtendedStyle(m_listMatrix.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES);

	int nIndex=0;
	m_listMatrix.InsertColumn(nIndex++,"字模编号",LVCFMT_LEFT,150);
	m_listMatrix.InsertColumn(nIndex++,"显示内容",LVCFMT_LEFT,580);

	OnBnClickedQueryMatrixButton();
	
	CSingleDemonDlg *pMain=(CSingleDemonDlg *)GetParent();
	if (pMain->bClick==TRUE)
	{
		GetDlgItem(IDC_BUTT_LEAD_IN)->ShowWindow(SW_HIDE);
	}
	CMessageListDlg *pMsgs=(CMessageListDlg *)GetParent();
	if (pMsgs->bLeadin==TRUE)
	{
		GetDlgItem(IDC_BUTT_ADDMATRIX)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTT_DELETE)->ShowWindow(SW_HIDE);
	}

	m_brushe.CreateSolidBrush(RGB(255,255,255));
	iClick=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CAffirmManage::OnBnClickedQueryMatrixButton()
{
	Sleep(10);
	try
	{
		m_listMatrix.DeleteAllItems();

		CString strsql,strSerialNo,strMatrContent;
		int iSeriaNo;
		strsql.Format("SELECT 字模编号,显示内容 FROM DotDisplayData where 使用标志 = 1");//
		if (theApp.m_ado.ExecuteSelect(strsql))
		{
			while(!theApp.m_ado.IsEOF())
			{
				theApp.m_ado.GetInt("字模编号",iSeriaNo);
				strSerialNo.Format("%d",iSeriaNo);
				int n=m_listMatrix.GetItemCount();
				m_listMatrix.InsertItem(n,strSerialNo);

				theApp.m_ado.GetString("显示内容",strMatrContent);
				m_listMatrix.SetItemText(n,1,strMatrContent);

				theApp.m_ado.MoveNext();
			}
		}
	}
	catch(_com_error &e)
	{
		AfxMessageBox(e.Description());
	}
}

void CAffirmManage::OnClickListChooseMatrix(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//DWORD dwPos = GetMessagePos();
	//CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
	// ScreenToClient(&point);
	//LVHITTESTINFO lvinfo;
	//lvinfo.pt = point;
	//CRect rcCtrl;
	//int nitem = m_listMatrix.SubItemHitTest(&lvinfo);//得到单击的点行号
	//if (nitem!=-1)
	//{
	//	iClick++;
	//	if (iClick==1)
	//	{
	//		m_listMatrix.SetCheck(nitem,TRUE);
	//	}
	//	if (iClick>1)
	//	{
	//		if (m_listMatrix.GetCheck(nitem)==TRUE)
	//		{
	//			m_listMatrix.SetCheck(nitem,FALSE);
	//		}
	//		else
	//			m_listMatrix.SetCheck(nitem,TRUE);
	//	}
	//}
	*pResult = 0;
}


void CAffirmManage::OnClickedButtLeadIn()
{
	// TODO: 在此添加控件通知处理程序代码

	int iSum=0;
	icount=m_listMatrix.GetItemCount();
	for (int i=0;i<icount;i++)
	{
		if (m_listMatrix.GetCheck(i))
		{
			iSum++;
		}
	}
	if (iSum==0)
	{
		MessageBox("当前列表未选择任何信息","温馨提示");
	}
	else
	{
		for (int i=0;i<icount;i++)
		{
			if (m_listMatrix.GetCheck(i))
			{
				strMSG=m_listMatrix.GetItemText(i,1);
				strArray.Add(strMSG);
			}
		}
		CDialogEx::OnOK();
	}
	
}


void CAffirmManage::OnBnClickedButtAddmatrix()
{
	// TODO: 在此添加控件通知处理程序代码
	CAddAffirmDlg Add;
	if (IDOK==Add.DoModal())
	{
		CString strAdd=Add.strEditAdd;
		CSingleDemonDlg *pHomeDlg=(CSingleDemonDlg *)GetParent();
		pHomeDlg->strContentTest=strAdd;
		pHomeDlg->OnBnClickedButton00();
		int iLatticeL,iLatticeW;
		iLatticeL=80;
		iLatticeW=16;
		try
		{
			UpdateData(TRUE);
			//m_listMatrix.DeleteAllItems();
			CString strSQL;
			strSQL.Format("insert into DotDisplayData(点阵尺寸长,点阵尺寸宽,取模方式,显示内容查长度,显示内容,字模数据长度,字模数据,单条信息支持长度,使用标志) values('%d','%d',1,'%d','%s','%d','%s',8,1)"
				,iLatticeL,iLatticeW,pHomeDlg->iChaChang,pHomeDlg->strContentTest,pHomeDlg->iLengthTest,pHomeDlg->zimuDianzhenStr);
			if (theApp.m_ado.ExecuteSql(strSQL))
			{
				MessageBox("添加字模成功！","温馨提示");
				OnBnClickedQueryMatrixButton();
				UpdateData(TRUE);
			}
		}
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
			return;
		}
	}
}


void CAffirmManage::OnBnClickedButtDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strsqlDe,strBH,strNR;
	int nSum=0;
	for (int i=0;i<m_listMatrix.GetItemCount();i++)
	{
		if (m_listMatrix.GetCheck(i))
		{
			nSum++;
		}
	}
	if (nSum==0)
	{
		MessageBox("当前未选中任何信息","温馨提示");
		return;
	}

	if (IDCANCEL==MessageBox("确认删除已选信息吗?","警告!!",MB_OKCANCEL))
	{
		return;
	}
	for (int i=0;i<m_listMatrix.GetItemCount();i++)
	{
		if (m_listMatrix.GetCheck(i))
		{
			strBH=m_listMatrix.GetItemText(i,0);
			strNR=m_listMatrix.GetItemText(i,1);
			int iBH=atoi(strBH);
			strsqlDe.Format("update DotDisplayData set 使用标志=0 where 字模编号=%d and 显示内容='%s'",iBH,strNR);
			if (theApp.m_ado.ExecuteSql(strsqlDe))
			{
				m_listMatrix.DeleteItem(i);
				i--;
			}
		}
	}
	UpdateData(TRUE);
}


HBRUSH CAffirmManage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	return m_brushe;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
