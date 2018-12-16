/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdio.h>
/* #include <string.h> */

int	strlen(char *);
char	*strchr(char *, int);
void	*memset(void *, int, size_t);
void	*memcpy(void *, void *, size_t);
int	strcmp(char *, char *);
void	*memmove(void *, void *, size_t);
int	strncmp(char *, char *, size_t);
int	strcasecmp(char *, char *);
char	*rindex(char *, char);
char	*strstr(char *, char *);
char	*strpbrk(char *, char *);
size_t	strcspn(char *, char *);

// bonuses
char	*strncpy(char *, char *, size_t);
char	*strcpy(char *, char *);
char	*index(char *, int);
char	*strrchr(char *, char);


int main()
{
	char	*str = "oui";
	char	*dup = strdup(str);

	printf("expect     3, got    %d\n", strlen(str));
	printf("expect     u, got    %c\n", strchr(str, 'u')[0]);
	memset(dup, '.', 2);
	printf("expect '..i', got '%s'\n", dup);
	memcpy(dup, "zob", 3);
	printf("expect 'zob', got '%s'\n", dup);
	printf("expect   -11, got  %d\n", strcmp(str, dup));
	memmove(dup, "pot", 3); //////// verif ce que fais memmove
	printf("expect 'pot', got '%s'\n", dup);
	printf("expect    -1, got   %d\n", strncmp(str, dup, 1));
	printf("expect     0, got    %d\n", strcasecmp("oui", "Oui"));
	printf("expect      o got    %c\n", rindex("bonjour", 'o')[0]);
	printf("expect   'ot' got  '%s'\n", strstr(dup, "o"));
	printf("expect   'ot' got  '%s'\n", strpbrk(dup, "o"));
	printf("expect      1 got    %lu\n", strcspn(dup, "o"));
	return (0);
}
