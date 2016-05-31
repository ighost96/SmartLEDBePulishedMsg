// ListCtrlCl.cpp : 实现文件
//

#include "stdafx.h"
//#include "DemoList.h"
#include "ListCtrlCl.h"
#include "Resource.h"


#define IDC_MY_LIST_EDITBOX 0xffff


struct stColor
{
	int nRow;
	int nCol;
	COLORREF rgb;
};
// CListCtrlCl

IMPLEMENT_DYNAMIC(CListCtrlCl, CListCtrl)

CListCtrlCl::CListCtrlCl()
: m_nRowHeight(0)
, m_fontHeight(12)
, m_fontWith(0)
{
	m_color = RGB(0,0,0);
	m_font.CreatePointFont(140, _T("宋体"), NULL);
    m_BChanged = FALSE;
	m_bEditing = FALSE;
}

CListCtrlCl::~CListCtrlCl()
{
	for (POSITION pos = m_ptrListCol.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListCol.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_ptrListCol.RemoveAll();
	for (POSITION pos = m_ptrListItem.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListItem.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_ptrListItem.RemoveAll();

	for (POSITION pos = m_colTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_colTextColor.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_colTextColor.RemoveAll();

	for (POSITION pos = m_ItemTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ItemTextColor.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_colTextColor.RemoveAll();
}


BEGIN_MESSAGE_MAP(CListCtrlCl, CListCtrl)
	ON_WM_MEASUREITEM()
	ON_WM_MEASUREITEM_REFLECT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, &CListCtrlCl::OnLvnColumnclick)
END_MESSAGE_MAP()



// CListCtrlCl 消息处理程序



void CListCtrlCl::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	ModifyStyle(0,LVS_OWNERDRAWFIXED);
	CListCtrl::PreSubclassWindow();
	CHeaderCtrl *pHeader = GetHeaderCtrl();
	m_Header.SubclassWindow(pHeader->GetSafeHwnd());
}

void CListCtrlCl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  添加您的代码以绘制指定项
	TCHAR lpBuffer[256];

	LV_ITEM lvi;

	lvi.mask = LVIF_TEXT | LVIF_PARAM ;
	lvi.iItem = lpDrawItemStruct->itemID ; 
	lvi.iSubItem = 0;
	lvi.pszText = lpBuffer ;
	lvi.cchTextMax = sizeof(lpBuffer);
	VERIFY(GetItem(&lvi));

	LV_COLUMN lvc, lvcprev ;
	::ZeroMemory(&lvc, sizeof(lvc));
	::ZeroMemory(&lvcprev, sizeof(lvcprev));
	lvc.mask = LVCF_WIDTH | LVCF_FMT;
	lvcprev.mask = LVCF_WIDTH | LVCF_FMT;

	CDC* pDC;
	pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rtClient;
	GetClientRect(&rtClient);
	for ( int nCol=0; GetColumn(nCol, &lvc); nCol++)
	{
		if ( nCol > 0 ) 
		{
			// Get Previous Column Width in order to move the next display item
			GetColumn(nCol-1, &lvcprev) ;
			lpDrawItemStruct->rcItem.left += lvcprev.cx ;
			lpDrawItemStruct->rcItem.right += lpDrawItemStruct->rcItem.left; 
		}	

		if (nCol == 0)
		{
			DWORD dwStyle = GetExtendedStyle();
			if((dwStyle & LVS_EX_CHECKBOXES) == LVS_EX_CHECKBOXES) 
			{  
				int nSize = GetSystemMetrics(SM_CYMENU);  
				CRect CheckRect(lpDrawItemStruct->rcItem.left + 2, lpDrawItemStruct->rcItem.top + (lpDrawItemStruct->rcItem.bottom -lpDrawItemStruct->rcItem.top-nSize)/2, 0, 0); 
				CheckRect.right = CheckRect.left + nSize;
				CheckRect.bottom = CheckRect.top + nSize;    
				pDC->DrawFrameControl(CheckRect, DFC_BUTTON, DFCS_BUTTONCHECK|(GetCheck(lpDrawItemStruct->itemID)? DFCS_CHECKED: 0));  
			} 
		}

		CRect rcItem;   
		if (!GetSubItemRect(lpDrawItemStruct->itemID,nCol,LVIR_LABEL,rcItem))   
			continue;   

		::ZeroMemory(&lvi, sizeof(lvi));
		lvi.iItem = lpDrawItemStruct->itemID;
		lvi.mask = LVIF_TEXT | LVIF_PARAM;
		lvi.iSubItem = nCol;
		lvi.pszText = lpBuffer;
		lvi.cchTextMax = sizeof(lpBuffer);
		VERIFY(GetItem(&lvi));
		CRect rcTemp;
		rcTemp = rcItem;

		if (nCol==0)
		{
			rcTemp.left -=2;
		}

		if ( lpDrawItemStruct->itemState & ODS_SELECTED )
		{
			pDC->FillSolidRect(&rcTemp, GetSysColor(COLOR_HIGHLIGHT)) ;
			pDC->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT)) ;
		}
		else
		{
			COLORREF color;
			color = GetBkColor();
			pDC->FillSolidRect(rcTemp,color);

			if (FindColColor(nCol,color))
			{
				pDC->FillSolidRect(rcTemp,color);
			}
			if (FindItemColor(nCol,lpDrawItemStruct->itemID,color))
			{
				pDC->FillSolidRect(rcTemp,color);
			}
			
			//pDC->SetTextColor(m_color);
		}		

		pDC->SelectObject(GetStockObject(DEFAULT_GUI_FONT));

		UINT   uFormat    = DT_CENTER ;
		if (m_Header.m_Format[nCol]=='0')
		{
			uFormat = DT_LEFT;
		}
		else if (m_Header.m_Format[nCol]=='1')
		{
			uFormat = DT_CENTER;
		}
		else if (m_Header.m_Format[nCol]=='2')
		{
			uFormat = DT_RIGHT;
		}
		
		CFont nFont ,* nOldFont; 
		nFont.CreateFont(m_fontHeight,m_fontWith,0,0,0,FALSE,FALSE,0,0,0,0,0,0,_TEXT("宋体"));//创建字体 
		nOldFont = pDC->SelectObject(&nFont);
		TEXTMETRIC metric;
		pDC->GetTextMetrics(&metric);
		int ofst;
		ofst = rcItem.Height() - metric.tmHeight;
		rcItem.OffsetRect(0,ofst/2);
		pDC->SetTextColor(m_color);
		COLORREF color;
		if (FindColTextColor(nCol,color))
		{
			pDC->SetTextColor(color);
		}
		if (FindItemTextColor(nCol,lpDrawItemStruct->itemID,color))
		{
			pDC->SetTextColor(color);
		}
		//rcItem.left += 4;
		DrawText(lpDrawItemStruct->hDC, lpBuffer, strlen(lpBuffer), 
			&rcItem, uFormat) ;

		pDC->SelectStockObject(SYSTEM_FONT) ;
	}

}

void CListCtrlCl::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CListCtrl::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}
void CListCtrlCl::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	if (m_nRowHeight>0)
	{
		lpMeasureItemStruct->itemHeight = m_nRowHeight;
	}
}
int CListCtrlCl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat /* = LVCFMT_LEFT */, int nWidth /* = -1 */, int nSubItem /* = -1 */)
{
	m_Header.m_HChar.Add(lpszColumnHeading);
	if (nFormat==LVCFMT_LEFT)
	{
		m_Header.m_Format = m_Header.m_Format + "0";
	}
	else if (nFormat==LVCFMT_CENTER)
	{
		m_Header.m_Format = m_Header.m_Format + "1";
	}
	else if (nFormat==LVCFMT_RIGHT)
	{
		m_Header.m_Format = m_Header.m_Format + "2";
	}
	else
	{
		m_Header.m_Format = m_Header.m_Format + "1";
	}
	return CListCtrl::InsertColumn(nCol,lpszColumnHeading,nFormat,nWidth,nSubItem);
}

BOOL CListCtrlCl::DeleteAllItems(void)
{
	for (POSITION pos = m_ptrListCol.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListCol.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_ptrListCol.RemoveAll();
	for (POSITION pos = m_ptrListItem.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListItem.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_ptrListItem.RemoveAll();

	for (POSITION pos = m_colTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_colTextColor.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_colTextColor.RemoveAll();

	for (POSITION pos = m_ItemTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ItemTextColor.GetNext(pos);
		delete pColor;
		pColor = NULL;
	}
	m_colTextColor.RemoveAll();
	return CListCtrl::DeleteAllItems();
}
// Gradient - 渐变系数，立体背景用,不用渐变设为0
void CListCtrlCl::SetHeaderBKColor(int R, int G, int B, int Gradient) //设置表头背景色
{
	m_Header.m_R = R;
	m_Header.m_G = G;
	m_Header.m_B = B;
	m_Header.m_Gradient = Gradient;
}

// 设置表头高度
void CListCtrlCl::SetHeaderHeight(float Height) //设置表头高度
{
	m_Header.m_Height = Height;
}
bool CListCtrlCl::FindColColor(int col,COLORREF &color) //查找列颜色
{
	int flag = 0;
	for (POSITION pos = m_ptrListCol.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListCol.GetNext(pos);
		if (pColor->nCol==col)
		{
			flag = 1;
			color = pColor->rgb;
			break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}
bool CListCtrlCl::FindItemColor(int col,int row,COLORREF &color) //查找颜色
{
	int flag = 0;
	for (POSITION pos = m_ptrListItem.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListItem.GetNext(pos);
		if (pColor->nCol==col&&pColor->nRow==row)
		{
			flag = 1;
			color = pColor->rgb;
			break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}
void CListCtrlCl::SetColColor(int col,COLORREF color) //设置列颜色
{
	stColor *pColor  = new stColor;
	pColor->nCol = col;
	pColor->rgb = color;
	m_ptrListCol.AddTail(pColor);
}
void CListCtrlCl::SetItemColor(int col,int row,COLORREF color) //设置格子颜色
{
	stColor *pColor  = new stColor;
	pColor->nCol = col;
	pColor->nRow = row;
	pColor->rgb = color;
	m_ptrListItem.AddTail(pColor);
}
void CListCtrlCl::SetRowHeigt(int nHeight) //高置行高
{
	m_nRowHeight = nHeight;

	CRect rcWin;
	GetWindowRect(&rcWin);
	WINDOWPOS wp;
	wp.hwnd = m_hWnd;
	wp.cx = rcWin.Width();
	wp.cy = rcWin.Height();
	wp.flags = SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER;
	SendMessage(WM_WINDOWPOSCHANGED, 0, (LPARAM)&wp);
}
void CListCtrlCl::SetHeaderFontHW(int nHeight,int nWith) //设置头部字体宽和高
{
	m_Header.m_fontHeight = nHeight;
	m_Header.m_fontWith = nWith;
}
void CListCtrlCl::SetHeaderTextColor(COLORREF color) //设置头部字体颜色
{
	m_Header.m_color = color;
}
BOOL CListCtrlCl::SetTextColor(COLORREF cr)  //设置字体颜色
{
	m_color = cr;
	return TRUE;
}
void CListCtrlCl::SetFontHW(int nHeight,int nWith) //设置字体高和宽
{
	m_fontHeight = nHeight;
	m_fontWith = nWith;
}
void CListCtrlCl::SetColTextColor(int col,COLORREF color)
{
	stColor *pColor = new stColor;
	pColor->nCol = col;
	pColor->rgb = color;
	m_colTextColor.AddTail(pColor);
}
bool CListCtrlCl::FindColTextColor(int col,COLORREF &color)
{
	int flag = 0;
	for (POSITION pos = m_colTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_colTextColor.GetNext(pos);
		if (pColor->nCol==col)
		{
			flag = 1;
			color = pColor->rgb;
			break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}
bool CListCtrlCl::FindItemTextColor(int col,int row,COLORREF &color)
{
	int flag = 0;
	for (POSITION pos = m_ItemTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ItemTextColor.GetNext(pos);
		if (pColor->nCol==col&&pColor->nRow==row)
		{
			flag = 1;
			color = pColor->rgb;
			break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}
void CListCtrlCl::SetItemTextColor(int col,int row,COLORREF color)
{
	stColor *pColor = new stColor;
	pColor->nCol = col;
	pColor->nRow = row;
	pColor->rgb = color;
	m_ItemTextColor.AddTail(pColor);
}

void CListCtrlCl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//if(m_EditItem.m_hWnd != NULL && m_bEditing)
	//{
	//    m_EditItem.ShowWindow(0);
	//	if(m_Row!= -1)
	//	{
	//	    CString ItemText;
	//	    m_EditItem.GetWindowText(ItemText);
	//		this->SetItemText(m_Row, m_Col, ItemText);
 //           m_BChanged = TRUE;
	//		::PostMessage(GetParent()->m_hWnd, MLSM_ITEMCHANGED, (WPARAM)MAKELONG(m_Row, m_Col), (LPARAM)KEY_RETURN);
	//		m_bEditing = FALSE;
	//	}
	//}
 //   m_Col = m_Row = -1;
 //   CListCtrl::OnLButtonDown(nFlags, point);

	UINT uFlags = 0;
	int nHitItem = HitTest(point, &uFlags);

	// we need additional checking in owner-draw mode
	// because we only get LVHT_ONITEM
	BOOL bHit = FALSE;
	if (uFlags == LVHT_ONITEM && (GetStyle() & LVS_OWNERDRAWFIXED))
	{
		CRect rect;
		GetItemRect(nHitItem, rect, LVIR_ICON);
		// check if hit was on a state icon
		if (point.x < rect.left)
		{
			bHit = TRUE;
		}
	}
	else if (uFlags & LVHT_ONITEMSTATEICON)
	{
		bHit = TRUE;
	}

	if (bHit)
	{
		if (GetCheck(nHitItem))
		{
			SetCheck(nHitItem, FALSE);
		}
		else
		{
			SetCheck(nHitItem, TRUE);
		}
	}
	else
	{
		if(m_EditItem.m_hWnd != NULL && m_bEditing)
		{
			m_EditItem.ShowWindow(0);
			if(m_Row!= -1)
			{
				CString ItemText;
				m_EditItem.GetWindowText(ItemText);
				this->SetItemText(m_Row, m_Col, ItemText);
				m_BChanged = TRUE;
				::PostMessage(GetParent()->m_hWnd, MLSM_ITEMCHANGED, (WPARAM)MAKELONG(m_Row, m_Col), (LPARAM)KEY_RETURN);
				m_bEditing = FALSE;
			}
		}
		m_Col = m_Row = -1;
		CListCtrl::OnLButtonDown(nFlags, point);
	}	
}

void CListCtrlCl::ListEditItem(int nRow, int nCol)
{
	if (nRow == -1 || 
		nCol == -1 ||
		nRow >= GetItemCount() ||
		nCol >= GetHeaderCtrl()->GetItemCount())
	{
		return;
	}

	m_Row = nRow;
	m_Col = nCol;

	if (IsEditColumn(nCol))
	{
		if(m_EditItem.m_hWnd == NULL)
		{
			RECT rect;
			rect.left = rect.top = 0;
			rect.bottom = 20;
			rect.right = 100;
			m_EditItem.Create(WS_CHILD | ES_CENTER | WS_BORDER | ES_AUTOHSCROLL | ES_WANTRETURN | ES_MULTILINE, rect, this, IDC_MY_LIST_EDITBOX);
			m_EditItem.SetFont(&m_font, TRUE);
		}
		CRect rect;
		GetSubItemRect(nRow, nCol, LVIR_BOUNDS, rect);
		m_EditItem.SetWindowText(this->GetItemText(nRow, nCol));
		m_EditItem.MoveWindow(&rect, TRUE);
		m_EditItem.ShowWindow(SW_SHOW);
		m_EditItem.SetFocus();
		m_bEditing = TRUE;
		::PostMessage(m_EditItem.m_hWnd,EM_SETSEL,0,-1);
	}
}


void CListCtrlCl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LVHITTESTINFO hi;
	hi.pt = point;
	if(SubItemHitTest(&hi) != -1 )
	{
		ListEditItem(hi.iItem, hi.iSubItem);
	} 
	CListCtrl::OnLButtonDblClk(nFlags, point);
}


BOOL CListCtrlCl::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	BOOL bHandledMsg = FALSE;
	if(pMsg->hwnd == m_EditItem.m_hWnd && m_bEditing)
	{
	    switch (pMsg->message)
		{
		    case WM_KEYDOWN:
			{
				CString ItemText;
				m_EditItem.GetWindowText(ItemText);
			    switch (pMsg->wParam)
				{
				    case VK_RETURN://回车
					    if(m_Row != -1)
					    {
							this->SetItemText(m_Row, m_Col, ItemText);
							m_BChanged = TRUE;
							::PostMessage(GetParent()->m_hWnd, MLSM_ITEMCHANGED, (WPARAM)MAKELONG(m_Row, m_Col), (LPARAM)KEY_RETURN);
					    }
					 case VK_ESCAPE://ESC键
						 m_EditItem.ShowWindow(FALSE);
						 m_Col = m_Row = -1;
						 bHandledMsg = TRUE;
						 m_bEditing = FALSE;
						 break;
					 case VK_UP:
						if (m_Row > 0)
						{
							this->SetItemText(m_Row, m_Col, ItemText);
							m_BChanged = TRUE;
							::PostMessage(GetParent()->m_hWnd, MLSM_ITEMCHANGED, (WPARAM)MAKELONG(m_Row, m_Col), (LPARAM)KEY_UP);
						}
						 break;
					 case VK_DOWN:
						 if (m_Row < (GetItemCount() -1 ))
						 {
							 this->SetItemText(m_Row, m_Col, ItemText);
							 m_BChanged = TRUE;
							 ::PostMessage(GetParent()->m_hWnd, MLSM_ITEMCHANGED, (WPARAM)MAKELONG(m_Row, m_Col), (LPARAM)KEY_DWON);
						 }
						 break;
					default:
					    break;
				}
			}// case WM_KEYDOWN
			break;
			default:
			break;
		}// switch(pMsg->message)
	}// if(pMsg->hwnd
	return (bHandledMsg ? TRUE : CListCtrl::PreTranslateMessage(pMsg)); 
}

BOOL CListCtrlCl::CheckTime(CString time)
{
	int temp;
	CString str;
	str = time;
	if (6 != str.GetLength())
	{
		return FALSE;
	}
	str = time.Mid(0,4);
	temp = atol(str.GetBuffer(0));
	str.ReleaseBuffer();
	if (1970 < temp && temp < 2100 )
	{ 
		str = time.Mid(4,2);
		temp = atol(str.GetBuffer(2));
		str.ReleaseBuffer();
		if (0 < temp && temp < 13)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void CListCtrlCl::SetChanged(BOOL bIsChanged)
{
    m_BChanged = bIsChanged;
}

void CListCtrlCl::SetEditColumn(int iColumn)
{
	m_vcEditColumn.push_back(iColumn);
}

BOOL CListCtrlCl::IsEditColumn(int iColumn)
{
	BOOL bRet = FALSE;
	size_t iSize = m_vcEditColumn.size();
	for (size_t i=0; i< iSize; i++)
	{
		int iNum = m_vcEditColumn.at(i);
		if (iNum == iColumn)
		{
			bRet = TRUE;
			break;
		}
	}
	return bRet;
}

void CListCtrlCl::OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult)
{
	return;
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	int nCol = pNMLV->iSubItem;
	if (m_SortCol==nCol)
	{
		m_Ascending = !m_Ascending;
	}
	else
	{
		m_SortCol = nCol;
		m_Ascending = true;
	}

	SortColumn(m_SortCol, m_Ascending);
//	SetSortArrow(m_SortCol, m_Ascending);
	*pResult = 0;
}

namespace {
	enum SortType
	{
		SORT_NUM = 0,
		SORT_STRING
	};
	struct PARAMSORT
	{
		PARAMSORT(HWND hWnd, int columnIndex, bool ascending)
			:m_hWnd(hWnd)
			,m_ColumnIndex(columnIndex)
			,m_Ascending(ascending)
			,m_sortType(SORT_NUM)
		{}

		SortType m_sortType;
		HWND m_hWnd;
		int  m_ColumnIndex;
		bool m_Ascending;
		CSimpleMap<int, CString> m_GroupNames;
	};

	// Comparison extracts values from the List-Control
	int CALLBACK SortFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
	{
		PARAMSORT& ps = *(PARAMSORT*)lParamSort;

		TCHAR left[256] = _T(""), right[256] = _T("");
		ListView_GetItemText(ps.m_hWnd, lParam1, ps.m_ColumnIndex, left, sizeof(left));
		ListView_GetItemText(ps.m_hWnd, lParam2, ps.m_ColumnIndex, right, sizeof(right));

		if (ps.m_sortType == SORT_NUM)
		{
			int iLeft = atoi(left);
			int lRight = atoi(right);
			int iRet = 0;
			if (ps.m_Ascending)
			{
				if (iLeft < lRight)
				{
					iRet = -1;
				}
				else
				{
					iRet = 1;
				}
			}
			else
			{
				if (iLeft < lRight)
				{
					iRet = 1;
				}
				else
				{
					iRet = 1;
				}
			}
			return iRet;
		}
		else
		{
			if (ps.m_Ascending)
				return _tcscmp( left, right );
			else
				return _tcscmp( right, left );	
		}
	}

	int CALLBACK SortFuncGroup(int nGroupId1, int nGroupId2, void* lParamSort)
	{
		PARAMSORT& ps = *(PARAMSORT*)lParamSort;

		const CString& left = ps.m_GroupNames.Lookup(nGroupId1);
		const CString& right = ps.m_GroupNames.Lookup(nGroupId2);

		if (ps.m_sortType == SORT_NUM)
		{
			int iLeft = atoi(left);
			int lRight = atoi(right);
			int iRet = 0;
			if (ps.m_Ascending)
			{
				if (iLeft < lRight)
				{
					iRet = -1;
				}
				else
				{
					iRet = 1;
				}
			}
			else
			{
				if (iLeft < lRight)
				{
					iRet = 1;
				}
				else
				{
					iRet = 1;
				}
			}
			return iRet;
		}
		else
		{
			if (ps.m_Ascending)
				return _tcscmp( left, right );
			else
				return _tcscmp( right, left );	
		}
	}
}

BOOL CListCtrlCl::GroupByColumn(int nCol)
{
	RemoveAllGroups();

	EnableGroupView( GetItemCount() > 0 );

	if (IsGroupViewEnabled())
	{
		CSimpleMap<CString,CSimpleArray<int> > groups;

		// Loop through all rows and find possible groups
		for(int nRow=0; nRow<GetItemCount(); ++nRow)
		{
			const CString& cellText = GetItemText(nRow, nCol);

			int nGroupId = groups.FindKey(cellText);
			if (nGroupId==-1)
			{
				CSimpleArray<int> rows;
				rows.Add(nRow);
				groups.Add(cellText, rows);
			}
			else
				groups.GetValueAt(nGroupId).Add(nRow);
		}

		// Look through all groups and assign rows to group
		for(int nGroupId = 0; nGroupId < groups.GetSize(); ++nGroupId)
		{
			const CSimpleArray<int>& groupRows = groups.GetValueAt(nGroupId);
			DWORD dwState = LVGS_NORMAL;

#ifdef LVGS_COLLAPSIBLE
			if (IsGroupStateEnabled())
				dwState = LVGS_COLLAPSIBLE;
#endif

			VERIFY( InsertGroupHeader(nGroupId, nGroupId, groups.GetKeyAt(nGroupId), dwState) != -1);
		}
		return TRUE;
	}

	return FALSE;
}

BOOL CListCtrlCl::SetRowGroupId(int nRow, int nGroupID)
{
	//OBS! Rows not assigned to a group will not show in group-view
	LVITEM lvItem = {0};
	lvItem.mask = LVIF_GROUPID;
	lvItem.iItem = nRow;
	lvItem.iSubItem = 0;
	lvItem.iGroupId = nGroupID;
	return SetItem( &lvItem );
}

int CListCtrlCl::GetRowGroupId(int nRow)
{
	LVITEM lvi = {0};
	lvi.mask = LVIF_GROUPID;
	lvi.iItem = nRow;
	VERIFY( GetItem(&lvi) );
	return lvi.iGroupId;
}

CString CListCtrlCl::GetGroupHeader(int nGroupID)
{
	LVGROUP lg = {0};
	lg.cbSize = sizeof(lg);
	lg.iGroupId = nGroupID;
	lg.mask = LVGF_HEADER | LVGF_GROUPID;
	VERIFY( GetGroupInfo(nGroupID, (PLVGROUP)&lg) != -1 );
#ifdef UNICODE
	return lg.pszHeader;
#else
	CComBSTR header( lg.pszHeader );
	return (LPCTSTR)COLE2T(header);
#endif
}

BOOL CListCtrlCl::IsGroupStateEnabled()
{
	if (!IsGroupViewEnabled())
		return FALSE;

	OSVERSIONINFO osver = {0};
	osver.dwOSVersionInfoSize = sizeof(osver);
	GetVersionEx(&osver);
	WORD fullver = MAKEWORD(osver.dwMinorVersion, osver.dwMajorVersion);
	if (fullver < 0x0600)
		return FALSE;

	return TRUE;
}

// Vista SDK - ListView_GetGroupState / LVM_GETGROUPSTATE
BOOL CListCtrlCl::HasGroupState(int nGroupID, DWORD dwState)
{
	LVGROUP lg = {0};
	lg.cbSize = sizeof(lg);
	lg.mask = LVGF_STATE;
	lg.stateMask = dwState;
	if ( GetGroupInfo(nGroupID, (PLVGROUP)&lg) == -1)
		return FALSE;

	return lg.state==dwState;
}

// Vista SDK - ListView_SetGroupState / LVM_SETGROUPINFO
BOOL CListCtrlCl::SetGroupState(int nGroupID, DWORD dwState)
{
	return TRUE;
}

int CListCtrlCl::GroupHitTest(const CPoint& point)
{
	return -1;
}


LRESULT CListCtrlCl::InsertGroupHeader(int nIndex, int nGroupID, const CString& strHeader, DWORD dwState /* = LVGS_NORMAL */, DWORD dwAlign /*= LVGA_HEADER_LEFT*/)
{
	LVGROUP lg = {0};
	lg.cbSize = sizeof(lg);
	lg.iGroupId = nGroupID;
	lg.state = dwState;
	lg.mask = LVGF_GROUPID | LVGF_HEADER | LVGF_STATE | LVGF_ALIGN;
	lg.uAlign = dwAlign;

	// Header-title must be unicode (Convert if necessary)
#ifdef UNICODE
	lg.pszHeader = strHeader.GetBuffer();
	lg.cchHeader = strHeader.GetLength();
#else
	CComBSTR header = strHeader;
	lg.pszHeader = header;
	lg.cchHeader = header.Length();
#endif

	return InsertGroup(nIndex, (PLVGROUP)&lg );
}

bool CListCtrlCl::SortColumn(int columnIndex, bool ascending)
{
	PARAMSORT paramsort(m_hWnd, columnIndex, ascending);
	if (IsGroupViewEnabled())
	{
		GroupByColumn(columnIndex);

		if (columnIndex == 0 || columnIndex == 4)
		{
			paramsort.m_sortType = SORT_NUM;
		}
		else
		{
			paramsort.m_sortType = SORT_STRING;
		}
		// Cannot use GetGroupInfo during sort
		for(int nRow=0 ; nRow < GetItemCount() ; ++nRow)
		{
			int nGroupId = GetRowGroupId(nRow);
			if (nGroupId!=-1 && paramsort.m_GroupNames.Lookup(nGroupId).IsEmpty())
				paramsort.m_GroupNames.Add(nGroupId, GetGroupHeader(nGroupId));
		}

		// Avoid bug in CListCtrl::SortGroups() which differs from ListView_SortGroups
		ListView_SortGroups(m_hWnd, SortFuncGroup, &paramsort);
	}

	// Always sort the rows, so the handicapped GroupHitTest() will work
	//	- Must ensure that the rows are reordered along with the groups.
	ListView_SortItemsEx(m_hWnd, SortFunc, &paramsort);
	return true;
}