/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  hexDiagnostics.cpp
// Created:  4/7/2017
// Author:  K. Loux
// Description:  Class for performing the hex diagnostics.

// Local headers
#include "hexDiagnostics.h"

// Standard C++ headers
#include <cassert>
#include <algorithm>
#include <sstream>
#include <cctype>

uint16_t HexDiagnostics::GetAsBigEndianUInt16(const wxString& bytes)
{
	typedef uint16_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

uint32_t HexDiagnostics::GetAsBigEndianUInt32(const wxString& bytes)
{
	typedef uint32_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

uint64_t HexDiagnostics::GetAsBigEndianUInt64(const wxString& bytes)
{
	typedef uint64_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

int16_t HexDiagnostics::GetAsBigEndianSInt16(const wxString& bytes)
{
	typedef int16_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

int32_t HexDiagnostics::GetAsBigEndianSInt32(const wxString& bytes)
{
	typedef int32_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

int64_t HexDiagnostics::GetAsBigEndianSInt64(const wxString& bytes)
{
	typedef int64_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

uint16_t HexDiagnostics::GetAsLittleEndianUInt16(const wxString& bytes)
{
	typedef uint16_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

uint32_t HexDiagnostics::GetAsLittleEndianUInt32(const wxString& bytes)
{
	typedef uint32_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

uint64_t HexDiagnostics::GetAsLittleEndianUInt64(const wxString& bytes)
{
	typedef uint64_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

int16_t HexDiagnostics::GetAsLittleEndianSInt16(const wxString& bytes)
{
	typedef int16_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

int32_t HexDiagnostics::GetAsLittleEndianSInt32(const wxString& bytes)
{
	typedef int32_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

int64_t HexDiagnostics::GetAsLittleEndianSInt64(const wxString& bytes)
{
	typedef int64_t T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

float HexDiagnostics::GetAsBigEndianFloat32(const wxString& bytes)
{
	typedef float T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

double HexDiagnostics::GetAsBigEndianFloat64(const wxString& bytes)
{
	typedef double T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(SwapByteOrder(bytes));
}

float HexDiagnostics::GetAsLittleEndianFloat32(const wxString& bytes)
{
	typedef float T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

double HexDiagnostics::GetAsLittleEndianFloat64(const wxString& bytes)
{
	typedef double T;
	assert(bytes.Len() == sizeof(T));
	return InterpretBytes<T>(bytes);
}

wxString HexDiagnostics::GetAsHexBytes(const std::vector<unsigned char>& raw)
{
	
	std::ostringstream ss;
	ss << "Offset(h) 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F";
	ss.fill('0');

	size_t count(0);
	bool needsLineStart(true);
	for (const auto& c : raw)
	{
		if (needsLineStart)
		{
			ss << '\n';

			ss.width(8);
			ss << std::hex << std::uppercase << (count & 0xFFFFFFF0);

			ss.width(0);
			ss << "  ";

			needsLineStart = false;
		}

		ss.width(2);
		ss << std::hex << std::uppercase << (static_cast<unsigned short>(c) & 0xFF);

		ss.width(0);
		ss << " ";

		++count;
		if (count % 16 == 0)
			needsLineStart = true;
	}

	return ss.str();
}

wxString HexDiagnostics::GetAsPrintableChars(const std::vector<unsigned char>& raw)
{
	size_t count(0);
	std::ostringstream ss;

	for (const auto& c : raw)
	{
		if (std::isprint(c))
			ss << c;
		else
			ss << '.';
		if (count % 16 == 0)
			ss << '\n';

		++count;
	}

	return ss.str();
}

wxString HexDiagnostics::SwapByteOrder(const wxString& value)
{
	wxString swapped(value);
	std::reverse(swapped.begin(), swapped.end());
	return swapped;
}