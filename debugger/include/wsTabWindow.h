//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:	$Id$
// Copyright (C) 2002 - 2007, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// wsTabWindow.h - debugger 
//
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//	class wsTabWindow
//
//	The wsTabWindow class implements the tab control that displays at the
//	bottom of the debugger window.  
//
//	A wsTabWindow object holds a notebook control, a result window (a window
//  that displays the result set generated by a query), and a varWindow (a
//  window that displays the local variables when debugging a PL function).
//
////////////////////////////////////////////////////////////////////////////////

#ifndef WSTABWINDOWH
#define WSTABWINDOWH

#include <wx/frame.h>		
#include <wx/docview.h>
#include <wx/laywin.h>
#include <wx/notebook.h>
#include "wx/hashmap.h"

#include "wsVarWindow.h"
#include "wsMessageWindow.h"
#include "wsStackWindow.h"
#include "wsResultGrid.h"

WX_DECLARE_HASH_MAP( int, int, wxIntegerHash, wxIntegerEqual, wsTabHash );

class wsTabWindow : public wxNotebook
{
	DECLARE_CLASS( wsTabWindow )

  public:

	wsTabWindow( wxWindow * parent, wxWindowID id, const wxPoint & pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCLIP_CHILDREN | wxSW_3D, const wxString& name = wxT( "layoutWindow" ));

	wsVarWindow	*getVarWindow( bool create = true );		// Returns a pointer to the local-variables window (creates it if requested)
	wsVarWindow	*getPkgVarWindow( bool create = true );	// Returns a pointer to the package-variables window (creates it if requested)
	wsVarWindow	*getParamWindow( bool create = true );		// Returns a pointer to the parameters window (creates it if requested)

	wsResultGrid	*getResultWindow( void );					// Returns a pointer to the result window (creates it if necessary)
	wsStackWindow	*getStackWindow( void );					// Returns a pointer to the stack-trace window (creates it if necessary)
	wsMessageWindow *getMessageWindow( void );					// Returns a pointer to the DBMS messages window (creates it if necessary)
	void	selectTab( wxWindowID id );

  private:
	wsResultGrid	*m_resultWindow;	// Displays the result set from a query
	wsVarWindow	*m_varWindow;		// Displays the local variables when debugging a PL function
	wsVarWindow	*m_pkgVarWindow;	// Displays the package variables when debugging a PL function
	wsStackWindow	*m_stackWindow;		// Displays the current call stack
	wsVarWindow	*m_paramWindow;		// Displays the parameters when debugging a PL function
	wsMessageWindow	*m_messageWindow;	// Displays the DBMS messages when debugging a PL function

	wsTabHash	*m_tabMap;		// Map window ID's to tab numbers

};

#endif
