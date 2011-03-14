#include <stdio.h>

extern char etext;

int main()
{
	unsigned int text_len = 1045;
	char *btext = (&etext) - text_len;

	for (int i = 0; i < text_len; i++)
	{
		printf("%c", btext[i]);
		//btext[i]++;
	}
	return 0;
}
