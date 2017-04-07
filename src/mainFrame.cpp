/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  mainFrame.cpp
// Created:  4/7/2017
// Author:  K. Loux
// Description:  Main frame for the application.

// Local headers
#include "mainFrame.h"
#include "hexDiagnosticsApp.h"

// wxWidgets headers
#include <wx/notebook.h>

//==========================================================================
// Class:			MainFrame
// Function:		MainFrame
//
// Description:		Constructor for MainFrame class.  Initializes the form
//					and creates the controls, etc.
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
MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, wxEmptyString,
	wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE)
{
	CreateControls();
	SetProperties();
}

//==========================================================================
// Class:			MainFrame
// Function:		CreateControls
//
// Description:		Creates sizers and controls and lays them out in the window.
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
void MainFrame::CreateControls()
{
	wxBoxSizer *topSizer(new wxBoxSizer(wxHORIZONTAL));
	wxPanel *panel(new wxPanel(this));
	topSizer->Add(panel, 1, wxGROW);

	wxBoxSizer *panelSizer(new wxBoxSizer(wxVERTICAL));
	panel->SetSizer(panelSizer);
	wxBoxSizer *mainSizer(new wxBoxSizer(wxVERTICAL));
	panelSizer->Add(mainSizer, 1, wxGROW | wxALL, 5);

	mainSizer->Add(CreateNotebook(panel), 1, wxGROW);
	mainSizer->Add(CreateVersionText(panel));

	SetSizerAndFit(topSizer);
}

//==========================================================================
// Class:			MainFrame
// Function:		CreateNotebook
//
// Description:		Creates the notebook area.
//
// Input Arguments:
//		parent	= wxWindow*
//
// Output Arguments:
//		None
//
// Return Value:
//		wxWindow*
//
//==========================================================================
wxWindow* MainFrame::CreateNotebook(wxWindow *parent)
{
	notebook = new wxNotebook(parent, wxID_ANY, wxDefaultPosition, wxSize(600, 400));

	return notebook;
}

//==========================================================================
// Class:			MainFrame
// Function:		CreateNotebookPage
//
// Description:		Creates a new notebook page.
//
// Input Arguments:
//		parent	= wxWindow*
//
// Output Arguments:
//		None
//
// Return Value:
//		wxBoxSizer*
//
//==========================================================================
wxBoxSizer* MainFrame::CreateNotebookPage(wxWindow *parent)
{
	return nullptr;
}

//==========================================================================
// Class:			MainFrame
// Function:		CreateInterpretationControls
//
// Description:		Creates a sizer containing the interpretation controls
//					for a notebook page.
//
// Input Arguments:
//		parent	= wxWindow*
//
// Output Arguments:
//		None
//
// Return Value:
//		wxBoxSizer*
//
//==========================================================================
wxBoxSizer* MainFrame::CreateInterpretationControls(wxWindow *parent)
{
	return nullptr;
}

//==========================================================================
// Class:			MainFrame
// Function:		CreateVersionText
//
// Description:		Builds a static text control containing version
//					information.
//
// Input Arguments:
//		parent	= wxWindow*
//
// Output Arguments:
//		None
//
// Return Value:
//		wxWindow*
//
//==========================================================================
wxWindow* MainFrame::CreateVersionText(wxWindow *parent)
{
	wxString versionString(HexDiagnosticsApp::versionString
		+ _T(" (") + HexDiagnosticsApp::gitHash + _T(")"));

	wxStaticText* versionInfo(new wxStaticText(parent, wxID_ANY,
		versionString));

	return versionInfo;
}

//==========================================================================
// Class:			MainFrame
// Function:		SetProperties
//
// Description:		Sets the window properties for this window.  Includes
//					title, frame size, and default fonts.
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
void MainFrame::SetProperties()
{
	SetTitle(HexDiagnosticsApp::appTitle);
	SetName(HexDiagnosticsApp::appName);
	Center();

/*#ifdef __WXMSW__
	SetIcon(wxIcon(_T("ICON_ID_MAIN"), wxBITMAP_TYPE_ICO_RESOURCE));
#elif __WXGTK__
	SetIcon(wxIcon(plots16_xpm));
	SetIcon(wxIcon(plots24_xpm));
	SetIcon(wxIcon(plots32_xpm));
	SetIcon(wxIcon(plots48_xpm));
	SetIcon(wxIcon(plots64_xpm));
	SetIcon(wxIcon(plots128_xpm));
#endif*/
}

//==========================================================================
// Class:			MainFrame
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
/*BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(idButtonOpen,			MainFrame::ButtonOpenClickedEvent)
	EVT_BUTTON(idButtonAutoScale,		MainFrame::ButtonAutoScaleClickedEvent)
	EVT_BUTTON(idButtonRemoveCurve,		MainFrame::ButtonRemoveCurveClickedEvent)
	EVT_BUTTON(idButtonReloadData,		MainFrame::ButtonReloadDataClickedEvent)
	EVT_MENU(idCopyEvent,				MainFrame::CopyEvent)
	EVT_MENU(idPasteEvent,				MainFrame::PasteEvent)
END_EVENT_TABLE();*/
