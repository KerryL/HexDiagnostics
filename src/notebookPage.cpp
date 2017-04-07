/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  notebookPage.h
// Created:  4/7/2017
// Author:  K. Loux
// Description:  GUI representation of binary file.

// Local headers
#include "notebookPage.h"

//==========================================================================
// Class:			NotebookPage
// Function:		Event Table
//
// Description:		Links GUI events with event handler functions.
//
// Input Arguments:
//		None
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
BEGIN_EVENT_TABLE(NotebookPage, wxWindow)
	EVT_RIGHT_UP(NotebookPage::OnRightClick)
	EVT_MOTION(NotebookPage::OnMouseMotion)
	EVT_LEFT_DOWN(NotebookPage::OnLeftClickStart)
	EVT_LEFT_UP(NotebookPage::OnLeftClickEnd)
	EVT_ENTER_WINDOW(NotebookPage::OnMouseEnterWindow)
	EVT_LEAVE_WINDOW(NotebookPage::OnMouseLeaveWindow)
END_EVENT_TABLE();

//==========================================================================
// Class:			NotebookPage
// Function:		NotebookPage
//
// Description:		Constructor for NotebookPage class.
//
// Input Arguments:
//		parent	= wxWindow*
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
NotebookPage::NotebookPage(wxWindow* parent) : wxWindow(parent, wxID_ANY)
{
	CreateControls(parent);
}

//==========================================================================
// Class:			NotebookPage
// Function:		Initialize
//
// Description:		Initializes this object with the information from the
//					specified file.
//
// Input Arguments:
//		fileName	= const wxString&
//
// Output Arguments:
//		None
//
// Return Value:
//		bool
//
//==========================================================================
bool NotebookPage::Initialize(const wxString& fileName)
{
	// TODO:  Implement
	return true;
}

//==========================================================================
// Class:			NotebookPage
// Function:		CreateControls
//
// Description:		Creates controls for this window.
//
// Input Arguments:
//		parent	= wxWindow*
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
void NotebookPage::CreateControls(wxWindow* parent)
{
	// TODO:  Implement
}

//==========================================================================
// Class:			NotebookPage
// Function:		OnRightClick
//
// Description:		Event handler for right-click events.
//
// Input Arguments:
//		event	= wxMouseEvent&
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
void NotebookPage::OnRightClick(wxMouseEvent& event)
{
}

//==========================================================================
// Class:			NotebookPage
// Function:		OnMouseMotion
//
// Description:		Event handler for mouse motion events.
//
// Input Arguments:
//		event	= wxMouseEvent&
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
void NotebookPage::OnMouseMotion(wxMouseEvent& event)
{
}

//==========================================================================
// Class:			NotebookPage
// Function:		OnLeftClickStart
//
// Description:		Event handler for left button down events.
//
// Input Arguments:
//		event	= wxMouseEvent&
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
void NotebookPage::OnLeftClickStart(wxMouseEvent& event)
{
}

//==========================================================================
// Class:			NotebookPage
// Function:		OnLeftClickEnd
//
// Description:		Event handler for left button up events.
//
// Input Arguments:
//		event	= wxMouseEvent&
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
void NotebookPage::OnLeftClickEnd(wxMouseEvent& event)
{
}

//==========================================================================
// Class:			NotebookPage
// Function:		OnMouseEnterWindow
//
// Description:		Event handler for mouse enter window events.
//
// Input Arguments:
//		event	= wxMouseEvent&
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
void NotebookPage::OnMouseEnterWindow(wxMouseEvent& event)
{
}

//==========================================================================
// Class:			NotebookPage
// Function:		OnMouseLeaveWindow
//
// Description:		Event handler for mouse exit window events.
//
// Input Arguments:
//		event	= wxMouseEvent&
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//==========================================================================
void NotebookPage::OnMouseLeaveWindow(wxMouseEvent& event)
{
}
