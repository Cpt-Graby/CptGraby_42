#include <stdio.h>
#include <string.h>

int main()
{
	char s1[]= "bbcaefg";
	int c = 'a';

	printf("%d", strchr(s1,c) - s1 + 1);
	return (0);
}
