#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "EasySize.h"
#include "MyListCtrl.h"

//struct ThreadInfo
//{
//	CString strMacIp;
//	CString strMacName;
//};
void Function(LPVOID lpParam);
// CHistoryDlg 对话框

class CHistoryDlg : public CDialogEx
{
	DECLARE_EASYSIZE
	DECLARE_DYNAMIC(CHistoryDlg)

public:
	CHistoryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHistoryDlg();

// 对话框数据
	enum { IDD = IDD_HISTORY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyListCtrl m_listHis;
	//CReListCtrlEx m_listHis;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtQuerry();

	CBrush m_brushi;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_edtUserID;
	CComboBox m_combFlag;
	CDateTimeCtrl m_dateBeginDT;
	CDateTimeCtrl m_dateEndDT;

	CImageList m_imageLst;
	POINT oldPoint;
	void ReSize();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

//////////////////////////////////////////////////////////////////////////翻页
	int m_iStartNum;  
	int m_iPerPageNum;     //每页显示记录数
	int m_iRecordSum;      //总记录数量
	int m_iCurrPage;           //当前第几页
	int m_iPageSum;           //总页数

protected:
	//CWinThread *pThread;
public:
	afx_msg void OnClickListHistory(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//CFont m_fontEdt;    //编辑框字体
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	CEdit m_edtDeviName;
	CEdit m_edtMsgList;
	afx_msg void OnLvnItemchangedListHistory(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnClickedButtDeleteh();
	afx_msg void OnBnClickedButtShanchu();
	afx_msg void OnBnClickedCheckAllin();
};
