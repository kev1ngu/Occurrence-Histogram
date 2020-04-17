//Print a histogram of length of words.
//Kevin Gu, 2020

#include <stdio.h>

#define IN 1
#define OUT 0


int main(void)
{
	int length, c;
	length = 0;
	c = 0;

	int state = 0;
	int occurrences[10];

	//initialize the array

	for (int i = 0; i < 10; ++i)
	{
		occurrences[i] = 0;
	}

	printf("Greetings.\nThis utility displays occurrences of length of words, from 1 to 9.\n\n");
	printf("Type in words you wanna analyze, end with a space. Then press Control+D:\n");

	//load the array
	while((c=getchar()) != EOF)
	{
		if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
		{
			state = IN;
			length++;
		}

		else if (c == ' ')
		{
			state = OUT;
			occurrences[length]++;
			length = 0;
		}
	}

	setbuf(stdin, NULL);

	printf("\n");

	int layout_style;

	printf("\nWords accepted!\nInput 0 if you wanna see result in horizontal layout, 1 for vertical style: \n");
	scanf("%d", &layout_style);

	if (layout_style)
	{
		//vertical histogram output
		printf("\nHere's the analysis result.\n");
		int highest_occurrence = 0;

		for (int j = 0; j < 10; ++j)
		{
			if (occurrences[j]>highest_occurrence)
			{
				highest_occurrence = occurrences[j];
			}
		}
	
		for(int i = 1; i <= highest_occurrence; i++)
		{
			for (int k = 1; k < 10; ++k)
			{
				if (occurrences[k] >= (highest_occurrence-i+1))
					printf(" *");
				else
					printf("  ");
			}
			printf("\n");
		}

		printf(" 1 2 3 4 5 6 7 8 9\n");
	}
	
	else
	{
		//horizontal histogram output
		printf("\nHere's the analysis result.\n");
		for (int i = 1; i < 10; ++i)
		{
			length = occurrences[i];
			printf("%d ", i);
			for (int c = 0; c < length; ++c)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	
	return 0;
}