/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 13:02:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 17:46:42 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_atoi(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, int n);
char			*ft_strstr(char *str, char *to_find);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, int n);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strcapitalize(char *str);
int				ft_str_is_alpha(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_uppercase(char *str);
int				ft_str_is_printable(char *str);
char			*ft_strcat(char *dest, char*src);
char			*ft_strncat(char *dest, char*src, int nb);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int		main(void)
{
	char	str[79] = {'\0'};
	char	str2[79] = {'\0'};
	char	str3[79] = {'\0'};
	int		i;
	int		j;
	int		exo;
	char	*test;
	
	printf("\t\t****************************************\n");
	printf("\t\t*                DAY 05                *\n");
	printf("\t\t****************************************\n\n");

	printf("What exercice do you want to test?  ");
	scanf("%d", &exo);
	while (getchar() != '\n');

	switch (exo)
	{
		case 0:
			/*	EXERCICE 0	*/
			
			do
			{
				printf("Give me a string (0 to stop): ");
				fgets(str, 79, stdin);
				ft_putstr(str);
				ft_putchar('\n');
			}while (str[0] != '0');
			break ;	

		case 1:
			/*	EXERCICE 1	*/
			
			i = 0;
			while (i != 42)
			{
				printf("GIVE a number: ");
				scanf("%d", &i);
				ft_putnbr(i);
				ft_putchar('\n');
			}
			break ;

		case 2:
			/*	EXERCICE 2	*/
			
			do
			{    
				printf("Give me a string (0 to stop): ");
				gets(str);
				printf("Atoi result: %d\n", atoi(str));
				printf("My Atoi result: %d\n\n", ft_atoi(str));
				ft_putchar('\n');
			}while (str[0] != '0');
			break ;

		case 3:
			/*	EXERCICE 3	*/
			
			do
			{
				printf("Give me a string (0 to stop): ");
				fgets(str, 79, stdin);
				printf("Your original string: %s\n", str);
				ft_strcpy(str2, str);
				printf("The copy: %s\n\n", str2);
			}while (str[0] != '0');
			break ;

		case 4:
			/*	EXERCICE 4	*/
			
			do
			{
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Now give me a number: ");
				scanf("%d", &i);
				printf("Your original string: %s\n\n", str);
				strncpy(str2, str, i);
				printf("The real result:\t%s\n", str2);
				ft_strncpy(str3, str, i);
				printf("My func result:\t\t%s\n\n", str2);
				while (getchar() != '\n');
			}while (str[0] != '0');
			break ;

		case 5:
			/*	EXERCICE 5	*/
				
			do
			{
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Give me a sub-string: ");
				gets(str2);
				
				test = ft_strstr(str, str2);
				printf("\nHere is what you return: %s", test);
				test = strstr(str, str2);
				printf("\nHere is the value it should return: %s\n", test);
			}while (str[0] != '0');
			break ;

		case 6:
			/*	EXERCICE 6	*/
			
			do
			{
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Give me a secondb string: ");
				gets(str2);

				printf("Here is the expected result: %d\n", strcmp(str, str2));
				printf("Here is my result: %d\n", ft_strcmp(str, str2));
			}while (str[0] != '0');
			break ;

		case 7:
			/*	EXERCICE 7	*/
			
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Give me a secondb string: ");
				gets(str2);
				printf("Give me a number: ");
				scanf("%d", &i);
				while (getchar() != '\n');

				printf("Here is the expected result: %d\n", strncmp(str, str2, i));
				printf("Here is my result: %d\n", ft_strncmp(str, str2, i));
			}while (str[0] != '0');
			break ;

		case 8:
			/*	EXERCICE 8	*/
				
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				ft_strupcase(str);
				printf("Here is my result: %s\n", str);
			}while (str[0] != '0');
			break ;

		case 9:
			/*	EXERCICE 9	*/
			
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				ft_strlowcase(str);
				printf("Here is my result: %s\n", str);
			}while (str[0] != '0');
			break ;

		case 10:
			/*	EXERCICE 10	*/
				
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				ft_strcapitalize(str);
				printf("Here is my result: %s\n", str);
			}while (str[0] != '0');
			break ;

		case 11:
			/*	EXERCICE 11	*/
			
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				if (ft_str_is_alpha(str))
					printf("Congs' your string is ALPHANUMERIC :)\n");
				else
					printf("So bad, it's just a classic string...\n");
			}while (str[0] != '0');
			break ;

		case 12:
			/*	EXERCICE 12	*/
			
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				if (ft_str_is_numeric(str))
					printf("Congs' your string is NUMERIC :)\n");
				else
					printf("So bad, it's just a classic string...\n");
			}while (str[0] != '0');
			break ;

		case 13:
			/*	EXERCICE 13	*/
			
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				if (ft_str_is_lowercase(str))
					printf("Congs' your string is lower :)\n");
				else
					printf("So bad, it's just a classic string...\n");
			}while (str[0] != '0');
			break ;

		case 14:
			/*	EXERCICE 14	*/
			
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				if (ft_str_is_uppercase(str))
					printf("Congs' your string is upper :)\n");
				else
					printf("So bad, it's just a classic string...\n");
			}while (str[0] != '0');
			break ;
			
		case 15:
			/*	EXERCICE 15	*/
			
			do {
				printf("\nGive me a string (0 to stop): ");
				gets(str);

				if (ft_str_is_printable(str))
					printf("Congs' your string is printable :)\n");
				else
					printf("So bad, it's just a classic string...\n");
			}while (str[0] != '0');
			break ;

		case 16:
			/*	EXERCICE 16	*/
			
			do
			{
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Give me a secondb string: ");
				gets(str2);
				printf("Give me the same string: ");
				gets(str3);

				printf("Here is the expected result: %s\n", strcat(str2, str));
				printf("Here is my result: %s\n", ft_strcat(str3, str));
			}while (str[0] != '0');
			break ;

		case 17:
			/*	EXERCICE 17	*/
			
			do
			{
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Give me a secondb string: ");
				gets(str2);
				printf("Give me the same string: ");
				gets(str3);
				printf("Now, give me a number please: ");
				scanf("%d", &i);
				while (getchar() != '\n');

				printf("Here is the expected result: %s\n", strncat(str2, str, i));
				printf("Here is my result: %s\n", ft_strncat(str3, str, i));
			}while (str[0] != '0');
			break ;

		case 18:
			/*	EXERCICE 18	*/
			
			do
			{
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Give me a secondb string: ");
				gets(str2);
				printf("Give me the same string: ");
				gets(str3);
				printf("Now, give me a number please: ");
				scanf("%d", &i);
				while (getchar() != '\n');
				j = strlcat(str2, str, i);
				printf("Here is the expected result: %s\n", str2);
				printf("Num returned: %d\n", j);
				j = ft_strlcat(str3, str, i);
				printf("Here is my result: %s\n", str3);
				printf("Num returned: %d\n", j);
			}while (str[0] != '0');
			break ;

		case 19:
			/*	EXERCICE 19	*/
			
			do
			{
				printf("\nGive me a string (0 to stop): ");
				gets(str);
				printf("Now, give me a number please: ");
				scanf("%d", &i);
				while (getchar() != '\n');
				j = strlcpy(str2, str, i);
				printf("Here is the expected result: %s\n", str2);
				printf("Num returned: %d\n", j);
				j = ft_strlcpy(str3, str, i);
				printf("Here is my result: %s\n", str3);
				printf("Num returned: %d\n", j);
			}while (str[0] != '0');
			break ;
	}
}
