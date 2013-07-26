// DeskListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DeskList.h"
#include "DeskListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeskListDlg dialog

CDeskListDlg::CDeskListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeskListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeskListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeskListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeskListDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDeskListDlg, CDialog)
	//{{AFX_MSG_MAP(CDeskListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonList)
	ON_BN_CLICKED(IDC_BUTTON2, OnDefaultView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeskListDlg message handlers

BOOL CDeskListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDeskListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDeskListDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDeskListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDeskListDlg::OnButtonList() 
{

	SetDesktopListViewStyle	(2,false);
}

void CDeskListDlg::OnDefaultView() 
{
	// TODO: Add your control notification handler code here
	SetDesktopListViewStyle(0,true);
	
}

void CDeskListDlg::SetDesktopListViewStyle(int itype,bool b_Large)
{
	
	HWND m_hWndProgramManager,m_hWndDesktop,m_hWndDesktopListView;
	LONG m_lStyle;
	LONG type;
	switch(itype)
	{
	case 0:
		type = LVS_ICON;
		break;
	case 1:
		type = LVS_REPORT;
		break;
	case 2:
		type = LVS_SMALLICON;
		break;
	case 3:
		type = LVS_LIST;
		break;
	default:
		type =	LVS_ICON;
	}

	if((m_hWndProgramManager = ::FindWindow(NULL, "Program Manager")) != NULL)
	{
		if((m_hWndDesktop = ::FindWindowEx(m_hWndProgramManager, NULL, "SHELLDLL_DefView", NULL)) != NULL)
		{
			m_hWndDesktopListView = ::FindWindowEx(m_hWndDesktop, NULL, "SysListView32", NULL);
			m_lStyle = GetWindowLong(m_hWndDesktopListView,GWL_STYLE);
			
			m_lStyle &= ~LVS_TYPEMASK;
			m_lStyle |= type;

			SetWindowLong(m_hWndDesktopListView,GWL_STYLE,m_lStyle);
	
			if(!b_Large)
			{
			for( int i=0; i<12; i++ )
				::SendMessage( m_hWndDesktopListView, WM_MOUSEWHEEL, MAKEWPARAM(MK_CONTROL, -WHEEL_DELTA), MAKELPARAM(0, 0) );
			}
			else
			{
			for( int i=0; i<12; i++ )
				::SendMessage( m_hWndDesktopListView, WM_MOUSEWHEEL, MAKEWPARAM(MK_CONTROL, WHEEL_DELTA), MAKELPARAM(0, 0) );
			}		

		}
	}
}
