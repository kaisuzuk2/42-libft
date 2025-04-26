#include <string.h>
#include <stdio.h>

int main(void)
{
	char str[60] = "hello world this is a pen";
	char set[] = "hello";
	char *res;

	res = (char *)memmove(str, str + 5, 5);
	printf("%s", res);
}