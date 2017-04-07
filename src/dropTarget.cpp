/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  dropTarget.cpp
// Created:  4/7/2017
// Author:  K. Loux
// Description:  Class for handling drag-and-drop of binary files.

// Local headers
#include "dropTarget.h"
#include "mainFrame.h"

//=============================================================================
// Class:			DropTarget
// Function:		DropTarget
//
// Description:		Constructor for DropTarget class.
//
// Input Arguments:
//		mainFrame	= &MainFrame, reference to main application window
//
// Output Arguments:
//		None
//
// Return Value:
//		None
//
//=============================================================================
DropTarget::DropTarget(MainFrame &mainFrame) : mainFrame(mainFrame)
{
	wxDataObjectComposite *dataObject = new wxDataObjectComposite;

	dataObject->Add(new wxFileDataObject);

	SetDataObject(dataObject);
}

//=============================================================================
// Class:			DropTarget
// Function:		OnDropFiles
//
// Description:		Handles dragging and dropping of files.
//
// Input Arguments:
//		fileNames	= const &wxArrayString containing the list of filenames
//					  being dropped
//
// Output Arguments:
//		None
//
// Return Value:
//		true to accept the data, false to veto
//
//=============================================================================
bool DropTarget::OnDropFiles(const wxArrayString &fileNames)
{
	for (const auto& fileName : fileNames)
		mainFrame.AddNewFile(fileName);

	return true;// TODO:  Should I ever return false?
}

//=============================================================================
// Class:			DropTarget
// Function:		OnData
//
// Description:		Overloaded virtual method from wxTextDropTarget.
//
// Input Arguments:
//		x		= wxCoord (unused)
//		y		= wxCoord (unused)
//		def		= wxDragResult
//
// Output Arguments:
//		None
//
// Return Value:
//		wxDragResult
//
//=============================================================================
wxDragResult DropTarget::OnData(wxCoord WXUNUSED(x), wxCoord WXUNUSED(y),
	wxDragResult def)
{
	if (!GetData())
		return wxDragNone;

	wxDataObjectComposite *dataObject(
		static_cast<wxDataObjectComposite*>(m_dataObject));
	const size_t bufferSize(
		dataObject->GetDataSize(dataObject->GetReceivedFormat()));

	std::vector<char> buffer(bufferSize);
	if (!dataObject->GetDataHere(
		dataObject->GetReceivedFormat(), buffer.data()))
		return wxDragNone;

	if (dataObject->GetReceivedFormat().GetType() == wxDF_FILENAME)
	{
		wxFileDataObject fileData;
		fileData.SetData(bufferSize, buffer.data());
		return OnDropFiles(fileData.GetFilenames()) ? def : wxDragNone;
	}

	assert(false);
	return wxDragNone;
}