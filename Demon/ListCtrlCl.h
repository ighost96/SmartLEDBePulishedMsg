#pragma once
#include "HeaderCtrlCl.h"
#include <vector>
using namespace std;
// CListCtrlCl

//List按键类型
typedef enum 
{
	KEY_RETURN = 0,
	KEY_UP = 1,
	KEY_DWON = 2
}KEY_TYPE;

#define MLSM_ITEMCHANGED (WM_USER + 200)

class CListCtrlCl : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlCl)

public:
	CHeaderCtrlCl m_Header;
	CListCtrlCl();
	virtual ~CListCtrlCl();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
public:
	// 行高
	int m_nRowHeight;
	CFont m_font;
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading,
		int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);
	BOOL DeleteAllItems(void);
public:
	// Gradient - 渐变系数，立体背景用,不用渐变设为0
	void SetHeaderBKColor(int R, int G, int B, int Gradient);
public:
	// 设置表头高度
	void SetHeaderHeight(float Height);
	CPtrList m_ptrListCol;  //保存列颜色
	CPtrList m_ptrListItem; //保存Item颜色表
	CPtrList m_colTextColor; //保存列字体颜色
	CPtrList m_ItemTextColor; //保存单元格字体颜色
	bool FindColColor(int col ,COLORREF &color); //查找列颜色
	bool FindItemColor(int col,int row,COLORREF &color);
	bool FindColTextColor(int col,COLORREF &color); //查找列字体颜色
	bool FindItemTextColor(int col,int row,COLORREF &color);
	void SetColColor(int col,COLORREF color);  //设置列颜色
	void SetItemColor(int col,int row,COLORREF color); //设置Item颜色
	void SetColTextColor(int col,COLORREF color);   //设置列文本颜色
	void SetItemTextColor(int col,int row,COLORREF color);
	void SetRowHeigt(int nHeight); //设置行高
	void SetHeaderFontHW(int nHeight,int nWith); //设置表头字体大小
	void SetHeaderTextColor(COLORREF color);
	COLORREF m_color;
	BOOL SetTextColor(COLORREF cr);
	void SetFontHW(int nHeight,int nWith);  //设置字体的高和宽
	void SetEditColumn(int iColumn);
public:
	// 字体高度
	int m_fontHeight;
public:
	// 字体宽度
	int m_fontWith;
    BOOL m_BChanged;
protected:
	CEdit m_EditItem;
	BOOL m_bEditing;
	int m_Row;
	int m_Col;
	vector<int> m_vcEditColumn;
	int m_SortCol;
	bool m_Ascending;
private:
	BOOL IsEditColumn(int iColumn);
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult);
	LRESULT InsertGroupHeader(int nIndex, int nGroupID, const CString& strHeader, DWORD dwState = LVGS_NORMAL, DWORD dwAlign = LVGA_HEADER_LEFT);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	CString GetGroupHeader(int nGroupID);
	int GetRowGroupId(int nRow);
	BOOL SetRowGroupId(int nRow, int nGroupID);
	int GroupHitTest(const CPoint& point);

	BOOL GroupByColumn(int nCol);
	void DeleteEntireGroup(int nGroupId);
	BOOL HasGroupState(int nGroupID, DWORD dwState);
	BOOL SetGroupState(int nGroupID, DWORD dwState);
	BOOL IsGroupStateEnabled();
	BOOL SetGroupFooter(int nGroupID, const CString& footer, DWORD dwAlign = LVGA_FOOTER_CENTER);
	BOOL SetGroupTask(int nGroupID, const CString& task);
	BOOL SetGroupSubtitle(int nGroupID, const CString& subtitle);
	void CheckEntireGroup(int nGroupId, bool bChecked);
public:
	//
	BOOL CheckTime(CString time);
    void SetChanged(BOOL bIsChanged);
	bool SortColumn(int columnIndex, bool ascending);
	void ListEditItem(int nRow, int nCol);
};


