/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  mainFrame.h
// Created:  4/7/2017
// Author:  K. Loux
// Description:  Main frame for the application.

#ifndef MAIN_FRAME_H_
#define MAIN_FRAME_H_

// wxWidgets headers
#include <wx/wx.h>

class wxNotebook;

// The main frame class
class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame() = default;

	void AddNewFile(const wxString& fileName);

private:
	// Functions that do some of the frame initialization and control positioning
	void CreateControls();
	void SetProperties();

	wxWindow* CreateNotebook(wxWindow *parent);
	wxWindow* CreateVersionText(wxWindow *parent);

	wxNotebook* notebook = nullptr;

	static wxString ExtractFileNameFromPath(const wxString& path);
};

#endif// MAIN_FRAME_H_