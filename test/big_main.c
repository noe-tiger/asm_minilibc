/*
** EPITECH PROJECT, 2018
** test for minilibc
** File description:
** test for minilibc
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

# define RED "31"
# define GREEN "32"
# define YELLOW "33"
# define MAGENTA "35"
# define RESET "0"
# define COLOR(param) printf("\033[%sm", param)

static int cmp_bug = false;
static int success = 0;

extern size_t my_strlen(const char *str);
extern char * my_strchr(const char *str, int c);
extern char *my_memset(void *s, int c, size_t n);
extern char *my_memcpy(void *s, const void *src, size_t n);
extern char *my_memmove(void *s, const void *src, size_t n);
extern int my_strcmp(const char *s1, const char *s2);
extern int my_strncmp(const char *s1, const char *s2, size_t n);
extern int my_strcasecmp(const char *s1, const char *s2);
extern char *my_rindex(const char *str, int c);
extern char *my_strstr(const char *str, const char *accept);
extern char *my_strpbrk(const char *str, const char *accept);
extern int my_strcspn(const char *s1, const char *reject);

/*
**
**
** STRLEN
**
**
*/

void test_strlen()
{
	COLOR(MAGENTA);
	printf("STRLEN :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	size_t a2 = my_strlen(str);
	size_t a = strlen("Hello World!");
	if (a != a2) {
		printf("strlen easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%u]\n", a);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%u]\n", a2);
		COLOR(RESET);
	} else {
		printf("strlen easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	size_t b2 = my_strlen(str2);
	size_t b = strlen(str2);
	if (b != b2) {
		printf("strlen medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%u]\n", b);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%u]\n", b2);
		COLOR(RESET);
	} else {
		printf("strlen medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	size_t c2 = my_strlen(str3);
	size_t c = strlen(str3);
	if (c != c2) {
		printf("strlen easy hard 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%u]\n", c);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%u]\n", c2);
		COLOR(RESET);
	} else {
		printf("strlen hard test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	free(str);
	free(str2);
	free(str3);
}

/*
**
**
** STRCHR
**
**
*/

void test_strchr()
{
	COLOR(MAGENTA);
	printf("STRCHR :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *res2 = my_strchr(str, 'W');
	char *res = strchr(str, 'W');
	if (res2 == NULL || strcmp(res2, res) != 0) {
		printf("strchr easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2);
		COLOR(RESET);
	} else {
		printf("strchr easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res1_2 = my_strchr(str2, 'W');
	char *res1_1 = strchr(str2, 'W');
	if (res1_2 != NULL || res1_2 != res1_1) {
		printf("strchr medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[NULL]\n");
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res1_2);
		COLOR(RESET);
	} else {
		printf("strchr medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res2_2 = my_strchr(str3, 'g');
	char *res2_1 = strchr(str3, 'g');
	if (res2_2 == NULL || strcmp(res2_2, res2_1) != 0) {
		printf("strchr easy hard 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res2_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2_2);
		COLOR(RESET);
	} else {
		printf("strchr hard test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res3_2 = my_strchr(str3, '\0');
	char *res3_1 = strchr(str3, '\0');
	if (res3_2 == NULL ||strcmp(res3_2, res3_1) != 0) {
		printf("strchr easy hard 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res3_1);
		COLOR(RESET);
		COLOR(GREEN);
		if (res3_2 == NULL)
			printf("Got\t\t[NULL]\n", res3_2);
		else
			printf("Got\t\t[%s]\n", res3_2);
		COLOR(RESET);
	} else {
		printf("strchr hard test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	free(str);
	free(str2);
	free(str3);
}

/*
**
**
** MEMSET
**
**
*/

void test_memset()
{
	COLOR(MAGENTA);
	printf("MEMSET :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("bj   ");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	
	char *str4 = strdup("Hello World!");
	char *str5 = strdup("bj   ");
	char *str6 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *res2 = my_memset(str, 'a', 10);
	char *res = memset(str4, 'a', 10);
	if (res2 == NULL || strcmp(res2, res) != 0) {
		printf("memset easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2);
		COLOR(RESET);
	} else {
		printf("memset easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res1_2 = my_memset(str2, 'a', 5);
	char *res1_1 = memset(str5, 'a', 5);
	if (strcmp(res1_2, res1_1) != 0) {
		printf("memset medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res1_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res1_2);
		COLOR(RESET);
	} else {
		printf("memset medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res2_2 = my_memset(str3, '\0', strlen(str3));
	char *res2_1 = memset(str6, '\0', strlen(str6));
	if (res2_2 == NULL || strcmp(res2_2, res2_1) != 0) {
		printf("memset easy hard 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res2_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2_2);
		COLOR(RESET);
	} else {
		printf("memset hard test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	free(str);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
}

/*
**
**
** MEMCPY
**
**
*/

void test_memcpy()
{
	COLOR(MAGENTA);
	printf("MEMCPY :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("bj   ");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	
	char *str4 = strdup("Hello World!");
	char *str5 = strdup("bj   ");
	char *str6 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *res2 = my_memcpy(str, str3, 10);
	char *res = memcpy(str4, str6, 10);
	if (res2 == NULL || strcmp(res2, res) != 0 || strcmp(str, str4) != 0) {
		printf("memcpy easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2);
		COLOR(RESET);
	} else {
		printf("memcpy easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res1_2 = my_memcpy(str2, str, 0);
	char *res1_1 = memcpy(str5, str4, 0);
	if (strcmp(res1_2, res1_1) != 0) {
		printf("memcpy medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res1_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res1_2);
		COLOR(RESET);
	} else {
		printf("memcpy medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	/* char *str7 = strdup("Geeksfor"); */
	/* char *str8 = strdup("GeeksGeeksGeek"); */
	/* char *res3_2 = my_memcpy(str7+5, str7, strlen(str7) + 1); */
	/* if (res3_2 == NULL || strcmp(res3_2, str8) != 0) { */
	/* 	printf("memcpy hard 3: Output differs"); */
	/* 	COLOR(RED); */
	/* 	printf("\nExpected\t[%s]%d\n"); */
	/* 	COLOR(RESET); */
	/* 	COLOR(GREEN); */
	/* 	printf("Got\t\t[%s]\n", str7); */
	/* 	COLOR(RESET); */
	/* } else { */
	/* 	printf("memcpy hard test 3 :\t"); */
	/* 	COLOR(GREEN); */
	/* 	printf("PASSED\n"); */
	/* 	COLOR(RESET); */
	/* } */
	printf("memcpy hard test 3 :\t");
	COLOR(YELLOW);
	printf("DESACTIVATED\n");
	COLOR(RESET);
	free(str);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
	/* free(str7); */
	/* free(str8); */
}

/*
**
**
** MEMMOVE
**
**
*/

void test_memmove()
{
	COLOR(MAGENTA);
	printf("MEMMOVE :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("bj   ");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	
	char *str4 = strdup("Hello World!");
	char *str5 = strdup("bj   ");
	char *str6 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *res2 = my_memmove(str, str3, 10);
	char *res = memmove(str4, str6, 10);
	if (res2 == NULL || strcmp(res2, res) != 0 || strcmp(str, str4) != 0) {
		printf("memmove easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2);
		COLOR(RESET);
	} else {
		printf("memmove easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res1_2 = my_memmove(str2, str, 0);
	char *res1_1 = memmove(str5, str4, 0);
	if (strcmp(res1_2, res1_1) != 0) {
		printf("memmove medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res1_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res1_2);
		COLOR(RESET);
	} else {
		printf("memmove medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *str7 = strdup("Geeksfor");
	char *str8 = strdup("Geeksfor");
	char *res3_2 = my_memmove(str7+5, str7, strlen(str7) + 1);
	char *res3_1 = memmove(str8+5, str8, strlen(str8) + 1);
	if (res3_2 == NULL || strcmp(res3_2, res3_1) != 0) {
		printf("memmove hard 3: Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", str7);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", str8);
		COLOR(RESET);
	} else {
		printf("memmove hard test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *str9 = strdup("Geeksfor");
	char *str10 = strdup("Geeksfor");
	char *res4_2 = my_memmove(str9 - 5, str9, strlen(str9) + 1);
	char *res4_1 = memmove(str10 - 5, str10, strlen(str10) + 1);
	if (res3_2 == NULL || strcmp(res4_2, res4_1) != 0) {
		printf("memmove hard 4: Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", str9);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", str10);
		COLOR(RESET);
	} else {
		printf("memmove hard test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	free(str);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
	free(str7);
	free(str8);
}

/*
**
**
** strcmp
**
**
*/

void test_strcmp()
{
	COLOR(MAGENTA);
	printf("STRCMP :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("bj   ");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	
	char *str4 = strdup("Hello World!");
	char *str5 = strdup("bj   !");
	char *str6 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	int a2 = my_strcmp(str, str4);
	int a = 0;
	if (cmp_bug == false)
		a = strcmp(str, str4);
	if (a2 != a) {
		printf("strcmp easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", a);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", a2);
		COLOR(RESET);
	} else {
		printf("strcmp easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int b = 33;
	int b2 = my_strcmp(str5, str2);
	if (cmp_bug == false)
		b = strcmp(str5, str2);
	if (b2 != b) {
		printf("strcmp medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", b);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", b2);
		COLOR(RESET);
	} else {
		printf("strcmp medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int c = -33;
	int c2 = my_strcmp(str2, str5);
	if (cmp_bug == false)
		c = strcmp(str2, str5);
	if (c2 != c) {
		printf("strcmp medium test 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", c);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", c2);
		COLOR(RESET);
	} else {
		printf("strcmp medium test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int d = 72;
	int d2 = my_strcmp(str, "");
	if (cmp_bug == false)
		d = strcmp(str, "");
	if (d2 != d) {
		printf("strcmp medium test 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", d);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", d2);
		COLOR(RESET);
	} else {
		printf("strcmp medium test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int e = -72;
	int e2 = my_strcmp("", str);
	if (cmp_bug == false)
		e = strcmp("", str);
	if (e2 != e) {
		printf("strcmp medium test 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", e);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", e2);
		COLOR(RESET);
	} else {
		printf("strcmp medium test 5 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
}

/*
**
**
** strncmp
**
**
*/

void test_strncmp()
{
	COLOR(MAGENTA);
	printf("STRNCMP :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("bj   ");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	
	char *str4 = strdup("Hello World!");
	char *str5 = strdup("bj   !");
	char *str6 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	int a2 = my_strncmp(str, str4, strlen(str4));
	int a = strncmp(str, str4, strlen(str4));
	if (a2 != a) {
		printf("strncmp easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", a);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", a2);
		COLOR(RESET);
	} else {
		printf("strncmp easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int b2 = my_strncmp(str5, str2, 3);
	int b = strncmp(str5, str2, 3);
	if (b2 != b) {
		printf("strncmp medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", b);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", b2);
		COLOR(RESET);
	} else {
		printf("strncmp medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int c2 = my_strncmp(str2, str5, 3);
	int c = strncmp(str2, str5, 3);
	if (c2 != c) {
		printf("strncmp medium test 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", c);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", c2);
		COLOR(RESET);
	} else {
		printf("strncmp medium test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int d2 = my_strncmp(str, "", 0);
	int d = strncmp(str, "", 0);
	if (d2 != d) {
		printf("strncmp medium test 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", d);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", d2);
		COLOR(RESET);
	} else {
		printf("strncmp medium test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int e2 = my_strncmp("", str, 5);
	int e = strncmp("", str, 5);
	if (e2 != e) {
		printf("strncmp medium test 5 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", e);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", e2);
		COLOR(RESET);
	} else {
		printf("strncmp medium test 5 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
	}
	int f2 = my_strncmp("", str, -1);
	int f = strncmp("", str, -1);
	if (f2 != f) {
		printf("strncmp hard test 6 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", f);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", f2);
		COLOR(RESET);
	} else {
		printf("strncmp hard test 6 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
}

/*
**
**
** strcasecmp
**
**
*/

/* void test_strcasecmp() */
/* { */
/* 	COLOR(MAGENTA); */
/* 	printf("STRCASECMP :\n"); */
/* 	COLOR(RESET); */
/* 	char *str = strdup("Hello World!94"); */
/* 	char *str2 = strdup("bJ   "); */
/* 	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    "); */
	
/* 	char *str4 = strdup("HeLlO WoRlD!94"); */
/* 	char *str5 = strdup("bj   !"); */
/* 	char *str6 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    "); */
/* 	char *str7 = strdup("BonjoUR"); */
/* 	char *str8 = strdup("BonjoURS"); */
/* 	int a2 = my_strcasecmp(str, str4); */
/* 	int a = strcasecmp(str, str4); */
/* 	if (a2 != a) { */
/* 		printf("strcasecmp easy test 1 : Output differs"); */
/* 		COLOR(RED); */
/* 		printf("\nExpected\t[%d]\n", a); */
/* 		COLOR(RESET); */
/* 		COLOR(GREEN); */
/* 		printf("Got\t\t[%d]\n", a2); */
/* 		COLOR(RESET); */
/* 	} else { */
/* 		printf("strcasecmp easy test 1 :\t"); */
/* 		COLOR(GREEN); */
/* 		printf("PASSED\n"); */
/* 		COLOR(RESET); */
/* 		success += 1; */
/* 	} */
/* 	int a2_2 = my_strcasecmp(str7, str8); */
/* 	int a2_1 = strcasecmp(str7, str8); */
/* 	if (a2_1 != a2_2) { */
/* 		printf("strcasecmp easy test 2 : Output differs"); */
/* 		COLOR(RED); */
/* 		printf("\nExpected\t[%d]\n", a2_1); */
/* 		COLOR(RESET); */
/* 		COLOR(GREEN); */
/* 		printf("Got\t\t[%d]\n", a2_2); */
/* 		COLOR(RESET); */
/* 	} else { */
/* 		printf("strcasecmp easy test 2 :\t"); */
/* 		COLOR(GREEN); */
/* 		printf("PASSED\n"); */
/* 		COLOR(RESET); */
/* 		success += 1; */
/* 	} */
/* 	int a3_2 = my_strcasecmp(str8, str7); */
/* 	int a3_1 = strcasecmp(str8, str7); */
/* 	if (a3_1 != a3_2) { */
/* 		printf("strcasecmp easy test 3 : Output differs"); */
/* 		COLOR(RED); */
/* 		printf("\nExpected\t[%d]\n", a3_1); */
/* 		COLOR(RESET); */
/* 		COLOR(GREEN); */
/* 		printf("Got\t\t[%d]\n", a3_2); */
/* 		COLOR(RESET); */
/* 	} else { */
/* 		printf("strcasecmp easy test 3 :\t"); */
/* 		COLOR(GREEN); */
/* 		printf("PASSED\n"); */
/* 		COLOR(RESET); */
/* 		success += 1; */
/* 	} */
/* 	int b2 = my_strcasecmp(str5, str2); */
/* 	int b = strcasecmp(str5, str2); */
/* 	if (b2 != b) { */
/* 		printf("strcasecmp medium test 4 : Output differs"); */
/* 		COLOR(RED); */
/* 		printf("\nExpected\t[%d]\n", b); */
/* 		COLOR(RESET); */
/* 		COLOR(GREEN); */
/* 		printf("Got\t\t[%d]\n", b2); */
/* 		COLOR(RESET); */
/* 	} else { */
/* 		printf("strcasecmp medium test 4 :\t"); */
/* 		COLOR(GREEN); */
/* 		printf("PASSED\n"); */
/* 		COLOR(RESET); */
/* 		success += 1; */
/* 	} */
/* 	int c2 = my_strcasecmp(str5, str5); */
/* 	int c = strcasecmp(str5, str5); */
/* 	if (c2 != c) { */
/* 		printf("strcasecmp medium test 5 : Output differs"); */
/* 		COLOR(RED); */
/* 		printf("\nExpected\t[%d]\n", c); */
/* 		COLOR(RESET); */
/* 		COLOR(GREEN); */
/* 		printf("Got\t\t[%d]\n", c2); */
/* 		COLOR(RESET); */
/* 	} else { */
/* 		printf("strcasecmp medium test 5 :\t"); */
/* 		COLOR(GREEN); */
/* 		printf("PASSED\n"); */
/* 		COLOR(RESET); */
/* 		success += 1; */
/* 	} */
/* 	int d2 = my_strcasecmp(str, ""); */
/* 	int d = strcasecmp(str, ""); */
/* 	if (d2 != d) { */
/* 		printf("strcasecmp hard test 6 : Output differs"); */
/* 		COLOR(RED); */
/* 		printf("\nExpected\t[%d]\n", d); */
/* 		COLOR(RESET); */
/* 		COLOR(GREEN); */
/* 		printf("Got\t\t[%d]\n", d2); */
/* 		COLOR(RESET); */
/* 	} else { */
/* 		printf("strcasecmp hard test 6 :\t"); */
/* 		COLOR(GREEN); */
/* 		printf("PASSED\n"); */
/* 		COLOR(RESET); */
/* 		success += 1; */
/* 	} */
/* 	int e2 = my_strcasecmp("", str); */
/* 	int e = strcasecmp("", str); */
/* 	if (e2 != e) { */
/* 		printf("strcasecmp hard test 7 : Output differs"); */
/* 		COLOR(RED); */
/* 		printf("\nExpected\t[%d]\n", e); */
/* 		COLOR(RESET); */
/* 		COLOR(GREEN); */
/* 		printf("Got\t\t[%d]\n", e2); */
/* 		COLOR(RESET); */
/* 	} else { */
/* 		printf("strcasecmp hard test 7 :\t"); */
/* 		COLOR(GREEN); */
/* 		printf("PASSED\n"); */
/* 		COLOR(RESET); */
/* 		success += 1; */
/* 	} */
/* } */

/*
**
**
** RINDEX
**
**
*/

void test_rindex()
{
	COLOR(MAGENTA);
	printf("RINDEX :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *res2 = my_rindex(str, 'o');
	char *res = rindex(str, 'o');
	if (res2 == NULL || strcmp(res2, res) != 0) {
		printf("rindex easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2);
		COLOR(RESET);
	} else {
		printf("rindex easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res1_2 = my_rindex(str2, 'W');
	char *res1_1 = rindex(str2, 'W');
	if (res1_2 != NULL || res1_2 != res1_1) {
		printf("rindex medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[NULL]\n");
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res1_2);
		COLOR(RESET);
	} else {
		printf("rindex medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res2_2 = my_rindex(str3, 'g');
	char *res2_1 = rindex(str3, 'g');
	if (res2_2 == NULL || strcmp(res2_2, res2_1) != 0) {
		printf("rindex easy hard 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res2_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2_2);
		COLOR(RESET);
	} else {
		printf("rindex hard test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res3_2 = my_rindex(str3, '\0');
	char *res3_1 = rindex(str3, '\0');
	if (res3_2 == NULL ||strcmp(res3_2, res3_1) != 0) {
		printf("rindex easy hard 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res3_1);
		COLOR(RESET);
		COLOR(GREEN);
		if (res3_2 == NULL)
			printf("Got\t\t[NULL]\n", res3_2);
		else
			printf("Got\t\t[%s]\n", res3_2);
		COLOR(RESET);
	} else {
		printf("rindex hard test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	free(str);
	free(str2);
	free(str3);
}

/*
**
**
** STRSTR
**
**
*/

void test_strstr()
{
	COLOR(MAGENTA);
	printf("STRSTR :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *res2 = my_strstr(str, "World");
	char *res = strstr(str, "World");
	if (res2 == NULL || strcmp(res2, res) != 0) {
		printf("strstr easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2);
		COLOR(RESET);
	} else {
		printf("strstr easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res1_2 = my_strstr(str2, "a");
	char *res1_1 = strstr(str2, "a");
	if (res1_2 != NULL || res1_2 != res1_1) {
		printf("strstr medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[NULL]\n");
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res1_2);
		COLOR(RESET);
	} else {
		printf("strstr medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res2_2 = my_strstr(str3, "xdcfvghjn,k;l:mlkjdfghjklktsdfg");
	char *res2_1 = strstr(str3, "xdcfvghjn,k;l:mlkjdfghjklktsdfg");
	if (res2_2 == NULL || strcmp(res2_2, res2_1) != 0) {
		printf("strstr hard 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res2_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2_2);
		COLOR(RESET);
	} else {
		printf("strstr hard test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res3_2 = my_strstr(str3, "");
	char *res3_1 = strstr(str3, "");
	if (res3_2 == NULL ||strcmp(res3_2, res3_1) != 0) {
		printf("strstr hard test 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res3_1);
		COLOR(RESET);
		COLOR(GREEN);
		if (res3_2 == NULL)
			printf("Got\t\t[NULL]\n", res3_2);
		else
			printf("Got\t\t[%s]\n", res3_2);
		COLOR(RESET);
	} else {
		printf("strstr hard test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	free(str);
	free(str2);
	free(str3);
}

/*
**
**
** STRPBRK
**
**
*/

void test_strpbrk()
{
	COLOR(MAGENTA);
	printf("STRPBRK :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!");
	char *str2 = strdup("");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *res2 = my_strpbrk(str, "World");
	char *res = strpbrk(str, "World");
	if (res2 == NULL || strcmp(res2, res) != 0) {
		printf("strpbrk easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2);
		COLOR(RESET);
	} else {
		printf("strpbrk easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res1_2 = my_strpbrk(str2, "a");
	char *res1_1 = strpbrk(str2, "a");
	if (res1_2 != NULL || res1_2 != res1_1) {
		printf("strpbrk medium test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[NULL]\n");
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res1_2);
		COLOR(RESET);
	} else {
		printf("strpbrk medium test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res2_2 = my_strpbrk(str3, "xdcfvghjn,k;l:mlkjdfghjklktsdfg");
	char *res2_1 = strpbrk(str3, "xdcfvghjn,k;l:mlkjdfghjklktsdfg");
	if (res2_2 == NULL || strcmp(res2_2, res2_1) != 0) {
		printf("strpbrk hard 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res2_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%s]\n", res2_2);
		COLOR(RESET);
	} else {
		printf("strpbrk hard test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	char *res3_2 = my_strpbrk(str3, "");
	const char *res3_1 = strpbrk(str3, "");
	if (res3_2 != res3_1) {
		printf("strpbrk hard test 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%s]\n", res3_1);
		COLOR(RESET);
		COLOR(GREEN);
		if (res3_2 == NULL)
			printf("Got\t\t[NULL]\n", res3_2);
		else
			printf("Got\t\t[%s]\n", res3_2);
		COLOR(RESET);
	} else {
		printf("strpbrk hard test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	free(str);
	free(str2);
	free(str3);
}

/*
**
**
** strcspn
**
**
*/

void test_strcspn()
{
	COLOR(MAGENTA);
	printf("STRCSPN :\n");
	COLOR(RESET);
	char *str = strdup("Hello World!94");
	char *str2 = strdup("bJ   ");
	char *str3 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	
	char *str4 = strdup("HeLlO WoRlD!94");
	char *str5 = strdup("bj   !");
	char *str6 = strdup("                            xdcfvghjn,k;l:mlkjdfghjklktsdfg                                                                                                                                                                    ");
	char *str7 = strdup("BonjoUR");
	char *str8 = strdup("BonjoURS");
	int a2 = my_strcspn(str, str4);
	int a = strcspn(str, str4);
	if (a2 != a) {
		printf("strcspn easy test 1 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", a);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", a2);
		COLOR(RESET);
	} else {
		printf("strcspn easy test 1 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int a2_2 = my_strcspn(str7, str8);
	int a2_1 = strcspn(str7, str8);
	if (a2_1 != a2_2) {
		printf("strcspn easy test 2 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", a2_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", a2_2);
		COLOR(RESET);
	} else {
		printf("strcspn easy test 2 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int a3_2 = my_strcspn(str8, str7);
	int a3_1 = strcspn(str8, str7);
	if (a3_1 != a3_2) {
		printf("strcspn easy test 3 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", a3_1);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", a3_2);
		COLOR(RESET);
	} else {
		printf("strcspn easy test 3 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int b2 = my_strcspn(str5, str2);
	int b = strcspn(str5, str2);
	if (b2 != b) {
		printf("strcspn medium test 4 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", b);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", b2);
		COLOR(RESET);
	} else {
		printf("strcspn medium test 4 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int c2 = my_strcspn(str5, str5);
	int c = strcspn(str5, str5);
	if (c2 != c) {
		printf("strcspn medium test 5 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", c);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", c2);
		COLOR(RESET);
	} else {
		printf("strcspn medium test 5 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int d2 = my_strcspn(str, "");
	int d = strcspn(str, "");
	if (d2 != d) {
		printf("strcspn hard test 6 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", d);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", d2);
		COLOR(RESET);
	} else {
		printf("strcspn hard test 6 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
	int e2 = my_strcspn("", str);
	int e = strcspn("", str);
	if (e2 != e) {
		printf("strcspn hard test 7 : Output differs");
		COLOR(RED);
		printf("\nExpected\t[%d]\n", e);
		COLOR(RESET);
		COLOR(GREEN);
		printf("Got\t\t[%d]\n", e2);
		COLOR(RESET);
	} else {
		printf("strcspn hard test 7 :\t");
		COLOR(GREEN);
		printf("PASSED\n");
		COLOR(RESET);
		success += 1;
	}
}

int main()
{
	test_strlen();
	/* test_strchr(); */
	/* test_memset(); */
	/* test_memcpy(); */
	/* test_memmove(); */
	/* test_strcmp(); */
	/* test_strncmp(); */
	//test_strcasecmp();
	/* test_rindex(); */
	/* test_strstr(); */
	/* test_strpbrk(); */
	/* test_strcspn(); */
	float res = (success / (float)52) * 100;
	printf("\n");
	COLOR(YELLOW);
	printf("RESULTAT\t\t%0.2f%\n", res);
	COLOR(RESET);
	return (0);
}
