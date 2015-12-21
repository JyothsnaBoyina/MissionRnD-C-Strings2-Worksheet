#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/getSubstring.cpp"
#include <stddef.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(GetSubString)
	{
	public:
		
		TEST_METHOD(NormalString)
		{
			char str[] = "abcdefgh";
			int i = 0;
			int j = 2;
			int k;
			
			for (i = 0; i <= 1; i++){
				for (j = 3; j < 7; j++){
					char *new_str = get_sub_string(str, i, j);
					if (i <= j){
						for (k = i; k <= j; k++){
							Assert::AreEqual(new_str[k-i], str[k], L"Error in NormalString", LINE_INFO());
						}
					}
					else{
						Assert::IsNull(new_str, L"should be null for i > j", LINE_INFO());
					}
				}
			}
		}
		
		TEST_METHOD(NULLsubstring)
		{
			char *str = NULL;
			char *new_str = get_sub_string(str, 0,2);
			Assert::IsNull(new_str, L"should be null for null string",LINE_INFO());

		}

		TEST_METHOD(ComplexStringwithSymbols)
		{
			char str[] = "abcdefgh.,812639";
			int i = 0;
			int j = 2;
			int k;

			for (i = 0; i <= 8; i++){
				for (j = 5; j < 12; j++){
					char *new_str = get_sub_string(str, i, j);
					if (i <= j){
						for (k = i; k <= j; k++){
							Assert::AreEqual(new_str[k - i], str[k], L"Error in NormalString", LINE_INFO());
						}
					}
					else{
						//Logger::WriteMessage("I > J ");
						Assert::IsNull(new_str, L"should be null for i > j", LINE_INFO());
					}
				}
			}
		}
		TEST_METHOD(Spaces)
		{
			char str[] = "a          jhas   AB";
			int i = 0;
			int j = 2;
			int k;

			for (i = 0; i <= 1; i++){
				for (j = 3; j < 7; j++){
					char *new_str = get_sub_string(str, i, j);
					if (i <= j){
						for (k = i; k <= j; k++){
							Assert::AreEqual(new_str[k - i], str[k], L"Error in NormalString", LINE_INFO());
						}
					}
					else{
						Assert::IsNull(new_str, L"should be null for i > j", LINE_INFO());
					}
				}
			}
		}

	};
}