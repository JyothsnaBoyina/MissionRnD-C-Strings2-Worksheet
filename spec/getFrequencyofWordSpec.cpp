
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/getFrequencyofWord.cpp"
#include <stddef.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(getFrequencyofWordSpec)
	{
	public:

		TEST_METHOD(NormalStringFrequency)
		{
			char sentences[][100] = { "abababa", "he he", "ab cd ab cd", "    ", "1234 aaaaaaa", "asd324", "yzqwer 23425", "a" };
			char words[][100] = { "ab", "he", "ab cd", " ", "aa", "asd324", "x", "a" };
			int counts[100] = { 3,2,2,4,6,1,0};
			int sc = 7;
			int si = 0;
			for (si = 0; si < sc; si++){
				int temp_c = count_word_in_str_way_1(sentences[si],words[si]);
				Assert::AreEqual(temp_c,counts[si], L"Error in NormalStringLastword", LINE_INFO());
				
			}

		}
	};
}