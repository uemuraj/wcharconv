#pragma once

#include <type_traits>

#pragma warning(push)
#pragma warning(disable:26495)
#pragma intrinsic(abs)

namespace cnv
{
	// 数値から文字列への変換用リテラル：
	template <typename CharT>
	constexpr const CharT * NumberLiterals;

	template <>
	constexpr const char * NumberLiterals<char> = "0123456789ABCDEF";

	template <>
	constexpr const wchar_t * NumberLiterals<wchar_t> = L"0123456789ABCDEF";


	// 10 進数文字列への変換：
	template <typename CharT>
	class Integer2CharsBase10
	{
		CharT buf[24]; // !!! C26495
		CharT * ptr;
		CharT * end;

	public:
		template <typename ValueT>
		Integer2CharsBase10(ValueT value, int width = 1) : ptr(buf + _countof(buf)), end(ptr)
		{
			static_assert(std::is_integral_v<ValueT>, "ValueT must be integral type.");
			static_assert(sizeof(ValueT) <= sizeof(int64_t), "ValueT is too large.");

			bool minus;

			if constexpr (std::is_signed_v<ValueT>)
			{
				minus = (value < 0);

				for (; value != 0; value /= 10)
				{
					*--ptr = NumberLiterals<CharT>[abs(value % 10)]; // !!!
				}
			}
			else
			{
				minus = false;

				for (; value != 0; value /= 10)
				{
					*--ptr = NumberLiterals<CharT>[value % 10];
				}
			}

			if (minus)
			{
				*--ptr = '-';
				return;
			}

			while ((end - ptr) < width)
			{
				*--ptr = '0';
			}
		}

		operator std::basic_string<CharT>() const
		{
			return std::basic_string<CharT>(ptr, end);
		}

		operator std::basic_string_view<CharT>() const
		{
			return std::basic_string_view<CharT>(ptr, end - ptr);
		}
	};


	// 16 進数文字列への変換：
	template <typename CharT>
	class Integer2CharsBase16
	{
		CharT buf[24]; // !!! C26495
		CharT * ptr;
		CharT * end;

	public:
		template <typename ValueT>
		Integer2CharsBase16(ValueT value, bool showbase = true) : ptr(buf + _countof(buf)), end(ptr)
		{
			static_assert(std::is_integral_v<ValueT>, "ValueT must be integral type.");
			static_assert(sizeof(ValueT) <= sizeof(int64_t), "ValueT is too large.");

			for (size_t i = 0; i < (sizeof(ValueT) * 2); ++i, value >>= 4)
			{
				*--ptr = NumberLiterals<CharT>[value & 0x0F];
			}

			if (showbase)
			{
				*--ptr = L'x';
				*--ptr = L'0';
			}
		}

		operator std::basic_string<CharT>() const
		{
			return std::basic_string<CharT>(ptr, end);
		}

		operator std::basic_string_view<CharT>() const
		{
			return std::basic_string_view<CharT>(ptr, end - ptr);
		}
	};
}

#pragma warning(pop)
