#pragma once
#include "afxwin.h"


// CAddAffirmDlg 对话框

class CAddAffirmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAffirmDlg)

public:
	CAddAffirmDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddAffirmDlg();

// 对话框数据
	enum { IDD = IDD_ADDAFFIRM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtAdd;
	afx_msg void OnBnClickedButtAdd();
	CString strEditAdd;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
