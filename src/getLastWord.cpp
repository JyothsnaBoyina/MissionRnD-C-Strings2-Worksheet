/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	char *temp;
	int i = 0,l=0,j=0;


	while (*(str + l) != '\0')
		l++;

	if (l!=0)
	i= l-1;

	temp = (char*)malloc(l * sizeof(char));

	if (*(str + i) == ' ')
		while (*(str + i) == ' '&& i != 0)
			i--;

	while (*(str + i) != ' '&& i != 0)
		i--;

	if (i!=0)
	 i = i + 1;

	while (*(str + i) != ' '&&*(str + i) != '\0')
	{
		*(temp + j) = *(str + i);
		i++;
		j++;
	}
	

	*(temp + j) = '\0';



	return temp;
}
