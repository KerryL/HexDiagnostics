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

#ifndef NOTEBOOK_PAGE_H_
#define NOTEBOOK_PAGE_H_

// wxWidgets headers
#include <wx/wx.h>

class NotebookPage : public wxWindow
{
public:
	NotebookPage(wxWindow* parent);
	~NotebookPage() = default;

	bool Initialize(const wxString& fileName);

private:
	void CreateControls(wxWindow* parent);

	void OnRightClick(wxMouseEvent& event);
	void OnMouseMotion(wxMouseEvent& event);
	void OnLeftClickStart(wxMouseEvent& event);
	void OnLeftClickEnd(wxMouseEvent& event);
	void OnMouseEnterWindow(wxMouseEvent& event);
	void OnMouseLeaveWindow(wxMouseEvent& event);

	enum class MouseState
	{
		NothingSpecial,
		Dragging
	};

	MouseState state = MouseState::NothingSpecial;

	DECLARE_EVENT_TABLE();
};

#endif// NOTEBOOK_PAGE_H_