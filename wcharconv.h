#pragma once

#include <ostream>
#include <string>
#include <string_view>

#include "integer2chars.h"
#include "mbs2wcs.h"

namespace cnv
{
	// 10 進数文字列への変換：
	// 
	// * ロケールに影響されない変換を行う
	// * 負の値にはマイナス記号が付く
	// * 正の値には幅指定が可能で、ゼロ埋めあり
	//
	template <typename T>
	struct to_dec
	{
		const T value;
		const int width;

		to_dec(T v, int n = 1) : value(v), width(n)
		{}

		operator std::string() const
		{
			return Integer2CharsBase10<char>(value, width);
		}

		operator std::wstring() const
		{
			return Integer2CharsBase10<wchar_t>(value, width);
		}
	};

	template <typename CharT, typename valueT>
	std::basic_ostream<CharT> & operator<<(std::basic_ostream<CharT> & os, const to_dec<valueT> & dec)
	{
		return os << (std::basic_string_view<CharT>) Integer2CharsBase10<CharT>(dec.value, dec.width);
	}


	// 16 進数文字列への変換：
	// 
	// * ロケールに影響されない変換を行う
	// * 数値型の大きさによる固定幅でゼロ埋めあり
	// * 最初に 0x を付けるか選択可能
	//
	template <typename T>
	struct to_hex
	{
		const T value;
		const bool showbase;

		to_hex(T v, bool s = true) : value(v), showbase(s)
		{}

		operator std::string() const
		{
			return Integer2CharsBase16<char>(value, showbase);
		}

		operator std::wstring() const
		{
			return Integer2CharsBase16<wchar_t>(value, showbase);
		}
	};

	template <typename CharT, typename valueT>
	std::basic_ostream<CharT> & operator<<(std::basic_ostream<CharT> & os, const to_hex<valueT> & hex)
	{
		return os << (std::basic_string_view<CharT>) Integer2CharsBase16<CharT>(hex.value, hex.showbase);
	}


	// ワイド文字列への変換：
	inline std::wostream & operator<<(std::wostream & os, std::string_view mbs)
	{
		return MultiByte2WideChar(mbs, os);
	}
}
