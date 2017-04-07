/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  dropTarget.h
// Created:  4/7/2017
// Author:  K. Loux
// Description:  Class for handling drag-and-drop of binary files.

#ifndef DROP_TARGET_H_
#define DROP_TARGET_H_

// wxWidgets headers
#include <wx/dnd.h>

class MainFrame;

/// Class derived from wxDropTarget in order to allow drag-and-drop operations.
class DropTarget : public wxDropTarget
{
public:
	explicit DropTarget(MainFrame& mainFrame);
	~DropTarget() = default;

	wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def) override;

private:
	MainFrame& mainFrame;

	bool OnDropFiles(const wxArrayString &fileNames);
};

#endif// DROP_TARGET_H_