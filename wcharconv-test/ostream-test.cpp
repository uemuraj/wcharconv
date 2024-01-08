#include "pch.h"

#include <wchardebug.h>

using namespace dbg;

TEST(wcdbg, output)
{
	wcdbg << L"Hello, world!" << std::endl;
}

TEST(wcdbg, output_exception)
{
	wcdbg << std::exception("Hello, world!") << std::endl;
}

TEST(wsycdbg, output)
{
	wsycdbg() << L"Hello, world!";
}

TEST(wsycdbg, output_exception)
{
	wsycdbg() << std::exception("Hello, world!");
}
