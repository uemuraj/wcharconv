#pragma once

#include <cwchar>

namespace cnv
{
	template <typename T>
	T & MultiByte2WideChar(std::string_view mbs, T & wcs)
	{
		// * mbrtowc() �͕����o�C�g������ĂP�����̕ϊ����ʂ𓾂�
		// -> �������ő�ł� MB_CUR_MAX �o�C�g�܂ł�������Ȃ�
		// 
		// * mbrtowc() �͏�����o�C�g����Ԃ��A�߂�l�͕����Ȃ������^�����A�G���[�� -1, -2 �ŕԂ�
		// -> �ϊ��Ɏ��s���Ă��A���Ȃ��Ƃ��P�������Ō�܂Ői�߂�

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
