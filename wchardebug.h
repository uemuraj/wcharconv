#pragma once

#include <ostream>
#include "wcharconv.h"
#include "streambuf4dbg.h"

namespace dbg
{
	//
	// デバッガコンソールへの出力バッファ
	//
	inline wcstreambuf g_buf(2048);

	//
	// デバッガコンソールへの出力
	//
	inline std::wostream wcdbg(&g_buf);

	//
	// デバッガコンソールへの同期制御出力
	//
	struct wsycdbg : wsycstreambuf, std::wostream
	{
		wsycdbg(const uint_least32_t line = __builtin_LINE(), const char * const file = __builtin_FILE()) : wsycstreambuf(1024), std::wostream(this)
		{
			*this << file << L'(' << cnv::to_dec(line) << L"): ";
		}

		~wsycdbg()
		{
			*this << std::endl;
		}
	};

	inline std::wostream & operator<<(std::wostream & os, const std::exception & e)
	{
		return cnv::operator<<(os, e.what());
	}
}
