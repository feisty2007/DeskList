// DeskList.h : main header file for the DESKLIST application
//

#if !defined(AFX_DESKLIST_H__D1416779_0395_4C3B_977B_CF3E38426B40__INCLUDED_)
#define AFX_DESKLIST_H__D1416779_0395_4C3B_977B_CF3E38426B40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeskListApp:
// See DeskList.cpp for the implementation of this class
//

class CDeskListApp : public CWinApp
{
public:
	CDeskListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeskListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeskListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKLIST_H__D1416779_0395_4C3B_977B_CF3E38426B40__INCLUDED_)
