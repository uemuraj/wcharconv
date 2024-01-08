#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <streambuf>
#include <memory_resource>

namespace dbg
{
	class wcstreambuf : public std::wstreambuf
	{
		wchar_t * const m_buff;

	public:
		wcstreambuf(size_t size) : m_buff(new wchar_t[size])
		{
			auto last = m_buff + size - 1; // !!!
			setp(m_buff, last);
			setg(m_buff, m_buff, last);
		}

		~wcstreambuf()
		{
			delete[] m_buff;
		}

	protected:
		int sync() override
		{
			auto p = pbase();
			auto q = pptr();

			*q = 0; // !!!
			::OutputDebugStringW(p);

			pbump((int) (p - q));
			return 0;
		}

		int_type overflow(int_type c) override
		{
			sync();
			sputc(c);
			return false;
		}
	};


	class wsycstreambuf : public std::wstreambuf
	{
		std::pmr::monotonic_buffer_resource m_resource;
		std::pmr::polymorphic_allocator<wchar_t> m_alloc;

		wchar_t * m_buff;

	public:
		wsycstreambuf(size_t size) : m_resource(size * 8), m_alloc(&m_resource), m_buff(m_alloc.allocate(size))
		{
			auto last = m_buff + size - 1; // !!!
			setp(m_buff, last);
			setg(m_buff, m_buff, last);
		}

		~wsycstreambuf()
		{
			auto p = pbase();
			auto q = pptr();

			*q = 0; // !!!
			::OutputDebugStringW(p);
		}

	protected:
		int_type overflow(int_type c) override
		{
			auto p = pbase();
			auto q = pptr();

			*q++ = c; // !!!

			auto offset = (int) (q - p);
			auto size = (size_t) (offset + 1024);

			m_buff = wmemcpy(m_alloc.allocate(size), p, offset);

			auto last = m_buff + size - 1; // !!!
			setp(m_buff, last);
			setg(m_buff, m_buff, last);
			pbump(offset);

			return false;
		}
	};
}
