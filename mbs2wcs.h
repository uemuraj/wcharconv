#pragma once

#include <cwchar>

namespace cnv
{
	template <typename T>
	T & MultiByte2WideChar(std::string_view mbs, T & wcs)
	{
		// * mbrtowc() は複数バイトを消費して１文字の変換結果を得る
		// -> ただし最大でも MB_CUR_MAX バイトまでしか消費しない
		// 
		// * mbrtowc() は消費したバイト数を返す、戻り値は符号なし整数型だが、エラーは -1, -2 で返す
		// -> 変換に失敗しても、少なくとも１文字ずつ最後まで進める

		if (!mbs.empty())
		{
			mbstate_t mbstate{};
			auto src = mbs.data();
			wchar_t dest[1]{};

			auto const max = MB_CUR_MAX;
			auto const end = src + mbs.size();

			for (auto ret = mbrtowc(dest, src, end - src, &mbstate); src < end; ret = mbrtowc(dest, src, end - src, &mbstate))
			{
				if (0 < ret && ret <= max)
				{
					wcs << dest[0];
					src += ret;
				}
				else
				{
					++src;
				}
			}
		}

		return wcs;
	}
}
