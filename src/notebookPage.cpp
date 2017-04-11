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
#include "hexDiagnostics.h"

// wxWidgets headers
#include <wx/settings.h>

// Standard C++ headers
#include <fstream>

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
BEGIN_EVENT_TABLE(NotebookPage, wxPanel)
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
NotebookPage::NotebookPage(wxWindow* parent) : wxPanel(parent)
{
	CreateControls();
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
	wxASSERT(hexDisplay && charDisplay);

	std::ifstream file(fileName.c_str().AsChar(), std::ios::binary);
	if (!file.is_open() || !file.good())
	{
		wxMessageBox(_T("Failed to open '") + fileName + _T("' for input."), _T("Error"));
		return false;
	}

	std::vector<unsigned char> contents((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

	hexDisplay->SetValue(HexDiagnostics::GetAsHexBytes(contents));
	charDisplay->SetValue(HexDiagnostics::GetAsPrintableChars(contents));

	return true;
}

//==========================================================================
// Class:			NotebookPage
// Function:		CreateControls
//
// Description:		Creates controls for this window.
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
void NotebookPage::CreateControls()
{
	wxSizer* topSizer(new wxBoxSizer(wxVERTICAL));
	wxSizer* upperSizer(new wxBoxSizer(wxHORIZONTAL));

	topSizer->Add(upperSizer, 1, wxGROW | wxALL, 5);

	hexDisplay = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE);
	charDisplay = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE);

	hexDisplay->SetFont(wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT));
	charDisplay->SetFont(wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT));

	upperSizer->Add(hexDisplay, 11, wxGROW);
	upperSizer->Add(charDisplay, 4, wxGROW);

	topSizer->Add(CreateInterpretedDisplayPanel(this), 0, wxALL, 5);

	SetSizerAndFit(topSizer);
}

//==========================================================================
// Class:			NotebookPage
// Function:		CreateInterpretedDisplayPanel
//
// Description:		Creates the display panel for interpreting selected bytes
//					as values.
//
// Input Arguments:
//		parent	= wxWindow*
//
// Output Arguments:
//		None
//
// Return Value:
//		wxSizer*
//
//==========================================================================
wxSizer* NotebookPage::CreateInterpretedDisplayPanel(wxWindow* parent)
{
	wxGridSizer* sizer(new wxGridSizer(3, wxSize(3,3)));

	for (auto& p : textCtrlPointers)
		p = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

	sizer->AddStretchSpacer();
	sizer->Add(new wxStaticText(parent, wxID_ANY, _T("Big Endian")));
	sizer->Add(new wxStaticText(parent, wxID_ANY, _T("LittleEndian")));

	sizer->Add(new wxStaticText(parent, wxID_ANY, _T("Unsigned Int")));
	sizer->Add(textCtrlPointers[static_cast<int>(InterpretedTextCtrl::BigEndianUnsignedInt)]);
	sizer->Add(textCtrlPointers[static_cast<int>(InterpretedTextCtrl::LittleEndianUnsignedInt)]);

	sizer->Add(new wxStaticText(parent, wxID_ANY, _T("Signed Int")));
	sizer->Add(textCtrlPointers[static_cast<int>(InterpretedTextCtrl::BigEndianSignedInt)]);
	sizer->Add(textCtrlPointers[static_cast<int>(InterpretedTextCtrl::LittleEndianSignedInt)]);

	sizer->Add(new wxStaticText(parent, wxID_ANY, _T("Floating Point")));
	sizer->Add(textCtrlPointers[static_cast<int>(InterpretedTextCtrl::BigEndianFloatingPoint)]);
	sizer->Add(textCtrlPointers[static_cast<int>(InterpretedTextCtrl::LittleEndianFloatingPoint)]);

	return sizer;
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
