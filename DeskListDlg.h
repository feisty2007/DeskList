// DeskListDlg.h : header file
//

#if !defined(AFX_DESKLISTDLG_H__81BBE6DD_EDB8_4672_96AB_8222C2ED2798__INCLUDED_)
#define AFX_DESKLISTDLG_H__81BBE6DD_EDB8_4672_96AB_8222C2ED2798__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeskListDlg dialog

class CDeskListDlg : public CDialog
{
// Construction
public:
	CDeskListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeskListDlg)
	enum { IDD = IDD_DESKLIST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeskListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDeskListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonList();
	afx_msg void OnDefaultView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetDesktopListViewStyle(int type,bool b_large);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKLISTDLG_H__81BBE6DD_EDB8_4672_96AB_8222C2ED2798__INCLUDED_)
