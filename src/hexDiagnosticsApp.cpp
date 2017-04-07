/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  hexDiagnosticsApp.cpp
// Created:  4/7/2017
// Author:  K. Loux
// Description:  Application class.

// Local headers
#include "hexDiagnosticsApp.h"
#include "mainFrame.h"

// Implement the application (have wxWidgets set up the appropriate entry points, etc.)
IMPLEMENT_APP(HexDiagnosticsApp);

//==========================================================================
// Class:			HexDiagnosticsApp
// Function:		Constant Declarations
//
// Description:		Constant declarations for the DataPlotterApp class.
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
const wxString HexDiagnosticsApp::appTitle = _T("Hex Diagnostics");
const wxString HexDiagnosticsApp::appName = _T("HexDiagnosticsApplication");
const wxString HexDiagnosticsApp::creator = _T("Kerry Loux");
// gitHash and versionString are defined in gitHash.cpp, which is automatically generated during the build

//==========================================================================
// Class:			HexDiagnosticsApp
// Function:		OnInit
//
// Description:		Initializes the application window.
//
// Input Arguments:
//		None
//
// Output Arguments:
//		None
//
// Return Value:
//		bool = true for successful window initialization, false for error
//
//==========================================================================
bool HexDiagnosticsApp::OnInit()
{
	// Set the application's name and the vendor's name
	SetAppName(appName);
	SetVendorName(creator);

	// Create the MainFrame object - this is the parent for all other objects
	mainFrame = new MainFrame();

	// Make sure the MainFrame was successfully created
	if (mainFrame == NULL)
		return false;

	mainFrame->Show(true);
	return true;
}
