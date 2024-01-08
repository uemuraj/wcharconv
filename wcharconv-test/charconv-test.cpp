#include "pch.h"

#include <wcharconv.h>
#include <limits>

namespace cnv
{
	TEST(to_dec, int32_to_string)
	{
		EXPECT_EQ((std::string) to_dec(123), "123");
		EXPECT_EQ((std::string) to_dec(1234567890), "1234567890");
		EXPECT_EQ((std::string) to_dec(0), "0");
		EXPECT_EQ((std::string) to_dec(-123), "-123");
		EXPECT_EQ((std::string) to_dec(-1234567890), "-1234567890");
	}

	TEST(to_dec, int32_to_wstring)
	{
		EXPECT_EQ((std::wstring) to_dec(123), L"123");
		EXPECT_EQ((std::wstring) to_dec(1234567890), L"1234567890");
		EXPECT_EQ((std::wstring) to_dec(0), L"0");
		EXPECT_EQ((std::wstring) to_dec(-123), L"-123");
		EXPECT_EQ((std::wstring) to_dec(-1234567890), L"-1234567890");
	}

	TEST(to_dec, int32_to_string_width_9)
	{
		EXPECT_EQ((std::string) to_dec(123, 9), "000000123");
		EXPECT_EQ((std::string) to_dec(1234567890, 9), "1234567890");
		EXPECT_EQ((std::string) to_dec(0, 9), "000000000");
		EXPECT_EQ((std::string) to_dec(-123, 9), "-123");
		EXPECT_EQ((std::string) to_dec(-1234567890, 9), "-1234567890");
	}

	TEST(to_dec, int32_to_wstring_width_9)
	{
		EXPECT_EQ((std::wstring) to_dec(123, 9), L"000000123");
		EXPECT_EQ((std::wstring) to_dec(1234567890, 9), L"1234567890");
		EXPECT_EQ((std::wstring) to_dec(0, 9), L"000000000");
		EXPECT_EQ((std::wstring) to_dec(-123, 9), L"-123");
		EXPECT_EQ((std::wstring) to_dec(-1234567890, 9), L"-1234567890");
	}

	TEST(to_dec, uint32_to_string)
	{
		EXPECT_EQ((std::string) to_dec(123u), "123");
		EXPECT_EQ((std::string) to_dec(1234567890u), "1234567890");
		EXPECT_EQ((std::string) to_dec(0u), "0");
	}

	TEST(to_dec, uint32_to_wstring)
	{
		EXPECT_EQ((std::wstring) to_dec(123u), L"123");
		EXPECT_EQ((std::wstring) to_dec(1234567890u), L"1234567890");
		EXPECT_EQ((std::wstring) to_dec(0u), L"0");
	}

	TEST(to_dec, uint32_to_string_width_9)
	{
		EXPECT_EQ((std::string) to_dec(123u, 9), "000000123");
		EXPECT_EQ((std::string) to_dec(1234567890u, 9), "1234567890");
		EXPECT_EQ((std::string) to_dec(0u, 9), "000000000");
	}

	TEST(to_dec, uint32_to_wstring_width_9)
	{
		EXPECT_EQ((std::wstring) to_dec(123u, 9), L"000000123");
		EXPECT_EQ((std::wstring) to_dec(1234567890u, 9), L"1234567890");
		EXPECT_EQ((std::wstring) to_dec(0u, 9), L"000000000");
	}

	TEST(to_dec, int64_to_string)
	{
		EXPECT_EQ((std::string) to_dec(123LL), "123");
		EXPECT_EQ((std::string) to_dec(1234567890123456789LL), "1234567890123456789");
		EXPECT_EQ((std::string) to_dec(0LL), "0");
		EXPECT_EQ((std::string) to_dec(-123LL), "-123");
		EXPECT_EQ((std::string) to_dec(-1234567890123456789LL), "-1234567890123456789");
	}

	TEST(to_dec, int64_to_wstring)
	{
		EXPECT_EQ((std::wstring) to_dec(123LL), L"123");
		EXPECT_EQ((std::wstring) to_dec(1234567890123456789LL), L"1234567890123456789");
		EXPECT_EQ((std::wstring) to_dec(0LL), L"0");
		EXPECT_EQ((std::wstring) to_dec(-123LL), L"-123");
		EXPECT_EQ((std::wstring) to_dec(-1234567890123456789LL), L"-1234567890123456789");
	}

	TEST(to_dec, int64_to_string_width_9)
	{
		EXPECT_EQ((std::string) to_dec(123LL, 9), "000000123");
		EXPECT_EQ((std::string) to_dec(1234567890123456789LL, 9), "1234567890123456789");
		EXPECT_EQ((std::string) to_dec(0LL, 9), "000000000");
		EXPECT_EQ((std::string) to_dec(-123LL, 9), "-123");
		EXPECT_EQ((std::string) to_dec(-1234567890123456789LL, 9), "-1234567890123456789");
	}

	TEST(to_dec, int64_to_wstring_width_9)
	{
		EXPECT_EQ((std::wstring) to_dec(123LL, 9), L"000000123");
		EXPECT_EQ((std::wstring) to_dec(1234567890123456789LL, 9), L"1234567890123456789");
		EXPECT_EQ((std::wstring) to_dec(0LL, 9), L"000000000");
		EXPECT_EQ((std::wstring) to_dec(-123LL, 9), L"-123");
		EXPECT_EQ((std::wstring) to_dec(-1234567890123456789LL, 9), L"-1234567890123456789");
	}

	TEST(to_dec, uint64_to_string)
	{
		EXPECT_EQ((std::string) to_dec(123ULL), "123");
		EXPECT_EQ((std::string) to_dec(12345678901234567890ULL), "12345678901234567890");
		EXPECT_EQ((std::string) to_dec(0ULL), "0");
	}

	TEST(to_dec, uint64_to_wstring)
	{
		EXPECT_EQ((std::wstring) to_dec(123ULL), L"123");
		EXPECT_EQ((std::wstring) to_dec(12345678901234567890ULL), L"12345678901234567890");
		EXPECT_EQ((std::wstring) to_dec(0ULL), L"0");
	}

	TEST(to_dec, uint64_to_string_width_9)
	{
		EXPECT_EQ((std::string) to_dec(123ULL, 9), "000000123");
		EXPECT_EQ((std::string) to_dec(12345678901234567890ULL, 9), "12345678901234567890");
		EXPECT_EQ((std::string) to_dec(0ULL, 9), "000000000");
	}

	TEST(to_dec, uint64_to_wstring_width_9)
	{
		EXPECT_EQ((std::wstring) to_dec(123ULL, 9), L"000000123");
		EXPECT_EQ((std::wstring) to_dec(12345678901234567890ULL, 9), L"12345678901234567890");
		EXPECT_EQ((std::wstring) to_dec(0ULL, 9), L"000000000");
	}

	TEST(to_hex, int32_to_string)
	{
		EXPECT_EQ((std::string) to_hex(0x123), "0x00000123");
		EXPECT_EQ((std::string) to_hex(0x12345678), "0x12345678");
		EXPECT_EQ((std::string) to_hex(0), "0x00000000");
	}

	TEST(to_hex, int32_to_wstring)
	{
		EXPECT_EQ((std::wstring) to_hex(0x123), L"0x00000123");
		EXPECT_EQ((std::wstring) to_hex(0x12345678), L"0x12345678");
		EXPECT_EQ((std::wstring) to_hex(0), L"0x00000000");
	}

	TEST(to_hex, int32_to_string_noshowbase)
	{
		EXPECT_EQ((std::string) to_hex(0x123, false), "00000123");
		EXPECT_EQ((std::string) to_hex(0x12345678, false), "12345678");
		EXPECT_EQ((std::string) to_hex(0, false), "00000000");
	}

	TEST(to_hex, int32_to_wstring_noshowbase)
	{
		EXPECT_EQ((std::wstring) to_hex(0x123, false), L"00000123");
		EXPECT_EQ((std::wstring) to_hex(0x12345678, false), L"12345678");
		EXPECT_EQ((std::wstring) to_hex(0, false), L"00000000");
	}

	TEST(to_hex, int64_to_string)
	{
		EXPECT_EQ((std::string) to_hex(0x123LL), "0x0000000000000123");
		EXPECT_EQ((std::string) to_hex(0x1234567890123456LL), "0x1234567890123456");
		EXPECT_EQ((std::string) to_hex(0LL), "0x0000000000000000");
	}

	TEST(to_hex, int64_to_wstring)
	{
		EXPECT_EQ((std::wstring) to_hex(0x123LL), L"0x0000000000000123");
		EXPECT_EQ((std::wstring) to_hex(0x1234567890123456LL), L"0x1234567890123456");
		EXPECT_EQ((std::wstring) to_hex(0LL), L"0x0000000000000000");
	}

	TEST(to_hex, int64_to_string_noshowbase)
	{
		EXPECT_EQ((std::string) to_hex(0x123LL, false), "0000000000000123");
		EXPECT_EQ((std::string) to_hex(0x1234567890123456LL, false), "1234567890123456");
		EXPECT_EQ((std::string) to_hex(0LL, false), "0000000000000000");
	}

	TEST(to_hex, int64_to_wstring_noshowbase)
	{
		EXPECT_EQ((std::wstring) to_hex(0x123LL, false), L"0000000000000123");
		EXPECT_EQ((std::wstring) to_hex(0x1234567890123456LL, false), L"1234567890123456");
		EXPECT_EQ((std::wstring) to_hex(0LL, false), L"0000000000000000");
	}

	TEST(to_dec, limits)
	{
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<int>::min()), "-2147483648");
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<int>::max()), "2147483647");
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<unsigned int>::min()), "0");
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<unsigned int>::max()), "4294967295");
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<long long>::min()), "-9223372036854775808");
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<long long>::max()), "9223372036854775807");
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<unsigned long long>::min()), "0");
		EXPECT_EQ((std::string) to_dec(std::numeric_limits<unsigned long long>::max()), "18446744073709551615");
	}

	TEST(to_hex, limits)
	{
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<int>::min()), "0x80000000");
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<int>::max()), "0x7FFFFFFF");
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<unsigned int>::min()), "0x00000000");
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<unsigned int>::max()), "0xFFFFFFFF");
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<long long>::min()), "0x8000000000000000");
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<long long>::max()), "0x7FFFFFFFFFFFFFFF");
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<unsigned long long>::min()), "0x0000000000000000");
		EXPECT_EQ((std::string) to_hex(std::numeric_limits<unsigned long long>::max()), "0xFFFFFFFFFFFFFFFF");
	}
}
