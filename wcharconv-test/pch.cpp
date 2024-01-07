//
// pch.cpp
//

#include "pch.h"

#include <locale>
#include <cstdlib>

struct LocaleEnvironment : public ::testing::Environment
{
	void SetUp() override
	{
		std::locale::global(std::locale(""));
	}
};

int main(int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::AddGlobalTestEnvironment(new LocaleEnvironment);
	return RUN_ALL_TESTS();
}
