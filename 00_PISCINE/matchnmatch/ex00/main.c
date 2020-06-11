#include <stdio.h>

int	match(char *s1, char *s2);

int	main(void)
{
	printf("nb match: %d\n", match("abcbd", "*b*"));
	return (0);
}
