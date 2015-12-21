#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/Consonants_Vowels.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(Consonants_VowelsSpec)
	{
	public:
		TEST_METHOD(OneLetter)
		{
			char str[] = "a";
			int consonants ;
			int vowels ;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 0, L"Consonants should be 0", LINE_INFO());

			Assert::AreEqual(vowels, 1, L"Vowels should be 1 for a", LINE_INFO());
		}

		TEST_METHOD(EmptyString)
		{
			char str[] = "";
			int consonants ;
			int vowels ;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 0, L"Consonants should be 0", LINE_INFO());

			Assert::AreEqual(vowels, 0, L"Vowels should be 0 for ", LINE_INFO());
		}
		TEST_METHOD(ComplexString)
		{
			char str[] = "a .?2343 BCDE mu";
			int consonants ;
			int vowels ;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 4, L"Consonants should be 4", LINE_INFO());

			Assert::AreEqual(vowels, 3, L"Vowels should be 3 for a .? 23 BCDE mu ", LINE_INFO());
		}
		TEST_METHOD(ComplexCapitalLong)
		{
			char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int consonants ;
			int vowels ;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 21, L"Consonants should be 21 for A-Z", LINE_INFO());

			Assert::AreEqual(vowels, 5, L"Vowels should be 5 for A-Z", LINE_INFO());
		}
		TEST_METHOD(NULLstring)
		{
			char *str=NULL;
			int consonants ;
			int vowels ;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 0, L"Consonants should be 0 for NULL", LINE_INFO());

			Assert::AreEqual(vowels, 0, L"Vowels should be 0 for NULL", LINE_INFO());
		}
	};
}