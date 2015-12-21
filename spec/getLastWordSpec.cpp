#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/getLastWord.cpp"
#include <stddef.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(GetLastWord)
	{
	public:

		TEST_METHOD(NormalStringLastword)
		{
			char sentences[][100] = {"abc is a word","he he","   ","d ab   ","  x","asd324","","a"};
			char ans[][100] = { "word", "he","","ab","x","asd324","","a"};
			int sc = 8;
			int si = 0;
			for (si = 0; si < sc; si++){
				char *new_str = get_last_word(sentences[si]);
				int k = 0;
				for (k = 0; new_str[k] != '\0'; k++){
					Assert::AreEqual(new_str[k], ans[si][k], L"Error in NormalString", LINE_INFO());
				}
			}
			
		}
	};
}