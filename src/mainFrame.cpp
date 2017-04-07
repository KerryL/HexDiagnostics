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
#include "notebookPage.h"
#include "dropTarget.h"

// *nix Icons
#ifdef __WXGTK__
#include "../res/icons/hex16.xpm"
#include "../res/icons/hex24.xpm"
#include "../res/icons/hex32.xpm"
#include "../res/icons/hex48.xpm"
#include "../res/icons/hex64.xpm"
#include "../res/icons/hex96.xpm"
#include "../res/icons/hex128.xpm"
#endif

// wxWidgets headers
#include <wx/notebook.h>

// Standard C++ headers
#include <memory>

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
// Function:		AddNewFile
//
// Description:		Creates a new notebook page.  Each notebook page will
//					have three key areas:
//					1.  Hexidecimal display of each byte in the file
//					2.  Character representation of each byte
//					3.  Interpreting selected bytes as other data types
//					As portions of either the hex bytes or character window
//					are highlighted, those bytes are cast to other data types
//					and displayed in the third window.
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
void MainFrame::AddNewFile(const wxString& fileName)
{
	std::unique_ptr<NotebookPage> page(std::make_unique<NotebookPage>(notebook));
	if (!page->Initialize(fileName))
		return;

	notebook->AddPage(page.release(), ExtractFileNameFromPath(fileName), true);
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
	SetDropTarget(new DropTarget(*this));
	Center();

#ifdef __WXMSW__
	SetIcon(wxIcon(_T("ICON_ID_MAIN"), wxBITMAP_TYPE_ICO_RESOURCE));
#elif __WXGTK__
	SetIcon(wxIcon(hex16_xpm));
	SetIcon(wxIcon(hex24_xpm));
	SetIcon(wxIcon(hex32_xpm));
	SetIcon(wxIcon(hex48_xpm));
	SetIcon(wxIcon(hex64_xpm));
	SetIcon(wxIcon(hex96_xpm));
	SetIcon(wxIcon(hex128_xpm));
#endif
}

//==========================================================================
// Class:			MainFrame
// Function:		ExtractFileNameFromPath
//
// Description:		Pulls the file name out of the path string.
//
// Input Arguments:
//		path	= const wxString&
//
// Output Arguments:
//		None
//
// Return Value:
//		wxString
//
//==========================================================================
wxString MainFrame::ExtractFileNameFromPath(const wxString& path)
{
#ifdef __WXMSW__
	const wxChar slash('\\');
#else
	const wxChar slash('/');
#endif

	if (path.find(slash) == wxNOT_FOUND)
		return path;

	return path.Mid(path.find_last_of(slash) + 1);
}
