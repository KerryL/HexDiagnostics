/*===================================================================================
                                    HexDiagnostics
                          Copyright Kerry R. Loux 2017

                   This code is licensed under the GPLv2 License
                     (http://opensource.org/licenses/GPL-2.0).

===================================================================================*/

// File:  hexDiagnostics.h
// Created:  4/7/2017
// Author:  K. Loux
// Description:  Class for performing the hex diagnostics.

#ifndef HEX_DIAGNOSTICS_H_
#define HEX_DIAGNOSTICS_H_

// wxWidgets headers
#include <wx/wx.h>

// Standard C++ headers
#include <cstdint>

class HexDiagnostics
{
public:
	static uint16_t GetAsBigEndianUInt16(const wxString& bytes);
	static uint32_t GetAsBigEndianUInt32(const wxString& bytes);
	static uint64_t GetAsBigEndianUInt64(const wxString& bytes);
	static int16_t GetAsBigEndianSInt16(const wxString& bytes);
	static int32_t GetAsBigEndianSInt32(const wxString& bytes);
	static int64_t GetAsBigEndianSInt64(const wxString& bytes);

	static uint16_t GetAsLittleEndianUInt16(const wxString& bytes);
	static uint32_t GetAsLittleEndianUInt32(const wxString& bytes);
	static uint64_t GetAsLittleEndianUInt64(const wxString& bytes);
	static int16_t GetAsLittleEndianSInt16(const wxString& bytes);
	static int32_t GetAsLittleEndianSInt32(const wxString& bytes);
	static int64_t GetAsLittleEndianSInt64(const wxString& bytes);

	static float GetAsBigEndianFloat32(const wxString& bytes);
	static double GetAsBigEndianFloat64(const wxString& bytes);

	static float GetAsLittleEndianFloat32(const wxString& bytes);
	static double GetAsLittleEndianFloat64(const wxString& bytes);

	static wxString GetAsHexBytes(const std::vector<unsigned char>& raw);
	static wxString GetAsPrintableChars(const std::vector<unsigned char>& raw);

private:
	static wxString SwapByteOrder(const wxString& value);

	template<typename T>
	static T InterpretBytes(const wxString& bytes);
};

template <typename T>
T HexDiagnostics::InterpretBytes(const wxString& bytes)
{
	/*T interpreted(0);
	unsigned int i;
	for (i = 0; i < bytes.Len(); ++i)
		interpreted |= bytes[bytes.Len() - 1 - i] << (8 * i);
	return interpreted;*/
	return *reinterpret_cast<const T*>(bytes.c_str().AsChar());
}

#endif// HEX_DIAGNOSTICS_H_