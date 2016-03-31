/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word){
	int count = 0, i = 0,j=0,flag=0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == *(word + j))
		{
			while (*(word + j) != '\0'&&(*(str + i) != '\0'))
			{
				if (*(str + i) != *(word + j))
				{
					flag = 1;
					break;
				}
				i++;
				j++;
			}
			i = i - j;
			if (*(word + j) != '\0')
				flag = 1;
            if (flag==0)
				count++;
		}
		
		i++;
		j = 0;
		flag = 0;
	}
	return count;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	int  j = 0, flag = 0;
	
	if (*str == '\0')
		return 0;
	else if ( *(word + j))
	{
		while (*(word + j) != '\0' && (*str != '\0'))
		{
			if (*str != *(word + j))
			{
				flag = 1;
				break;
			}
			str++;
			j++;
		}
		str = str - j;
		if (*(word + j) != '\0')
			flag = 1;
		if (flag == 0)
			return 1 + count_word_int_str_way_2_recursion(++str, word);
		else
			return 0 + count_word_int_str_way_2_recursion(++str, word);


	}
	else 
		return 0 + count_word_int_str_way_2_recursion(++str, word);


	
}

