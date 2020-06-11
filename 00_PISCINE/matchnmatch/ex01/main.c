#include <stdio.h>

int	nmatch(char *s1, char *s2);

int	main(void)
{
	printf("nb match: %d\n", nmatch("abcbd", "*b*"));
	return (0);
}
