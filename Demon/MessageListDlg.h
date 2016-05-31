#pragma once
#include "DeviceQueryDlg.h"
#include "afxwin.h"
#include "AffirmManage.h"
#include "afxcmn.h"

#define WM_PULISHMESSAGE WM_USER+201 //对话框关闭之后传递消息

extern afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
// CMessageListDlg 对话框

class CMessageListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMessageListDlg)

public:
	CMessageListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMessageListDlg();


// 对话框数据
	enum { IDD = IDD_MESSAGELIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtLastStep();
	afx_msg void OnClickedButtAddAffirm();
	afx_msg void OnBnClickedButtLeadin();
	virtual BOOL OnInitDialog();

	CDeviceQueryDlg *pQueryDlg;

	afx_msg void OnClickedButtDisplay();
	CStatic m_staMSG1;
	CStatic m_staMSG2;
	CStatic m_staMSG3;
	CStatic m_staMSG4;
	CStatic m_staMSG5;
	CStatic m_staMSG6;
	CStatic m_staMSG7;
	CStatic m_staMSG8;
	CComboBox m_combMode1;
	CComboBox m_combMode2;
	CComboBox m_combMode3;
	CComboBox m_combMode4;
	CComboBox m_combMode5;
	CComboBox m_combMode6;
	CComboBox m_combMode7;
	CComboBox m_combMode8;
	CComboBox m_combTemplate1;
	CComboBox m_combTemplate2;
	CComboBox m_combTemplate3;
	CComboBox m_combTemplate4;
	CComboBox m_combTemplate5;
	CComboBox m_combTemplate6;
	CComboBox m_combTemplate7;
	CComboBox m_combTemplate8;
	CComboBox m_combTime1;
	CComboBox m_combTime2;
	CComboBox m_combTime3;
	CComboBox m_combTime4;
	CComboBox m_combTime5;
	CComboBox m_combTime6;
	CComboBox m_combTime7;
	CComboBox m_combTime8;
	CComboBox m_combSpeed1;
	CComboBox m_combSpeed2;
	CComboBox m_combSpeed3;
	CComboBox m_combSpeed4;
	CComboBox m_combSpeed5;
	CComboBox m_combSpeed6;
	CComboBox m_combSpeed7;
	CComboBox m_combSpeed8;

	afx_msg void OnBnClickedButtPulish();
	POINT old;

	void ReSizeMSG(void);
	afx_msg void OnBnClickedButtClear1();
	afx_msg void OnBnClickedButtClear2();
	afx_msg void OnBnClickedButtClear3();
	afx_msg void OnBnClickedButtClear4();
	afx_msg void OnBnClickedButtClear05();
	afx_msg void OnBnClickedButtClear06();
	afx_msg void OnBnClickedButtClear7();
	afx_msg void OnBnClickedButtClear8();
	afx_msg void OnBnClickedButtAllclear();
	CProgressCtrl m_ProgBPulish;
	CStatic m_staBPulis;
	CProgressCtrl m_progSetLED;

	int iPulishSID;

	BOOL bLeadin;

	afx_msg void OnBnClickedButtMatrlib();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnCancel();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
protected:
	CBrush m_brush;
	CStatusBar  *m_pStatBar;
	CToolTipCtrl m_TlTips;
public:
	afx_msg void OnSelchangeCombMode1();
	afx_msg void OnSelchangeCombMode2();
	afx_msg void OnSelchangeCombMode3();
	afx_msg void OnSelchangeCombMode4();
	afx_msg void OnSelchangeCombMode5();
	afx_msg void OnSelchangeCombMode6();
	afx_msg void OnSelchangeCombMode7();
	afx_msg void OnSelchangeCombMode8();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
