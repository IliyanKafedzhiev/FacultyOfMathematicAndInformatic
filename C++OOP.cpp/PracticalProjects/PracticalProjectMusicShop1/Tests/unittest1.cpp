#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PracticalProjectMusicShop1/MusicShop.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MusicShop a("payner","sofia",20);
			Assert::AreEqual("payner",a.getMusicShopName());
		}

	};
}