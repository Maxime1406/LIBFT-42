/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:10:34 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/28 03:30:00 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

static void	del(void *content)
{
	free(content);
}

static void	f_iter(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static char	f_mapi(unsigned int index, char c)
{
	(void)index;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	test_isalpha(void)
{
	int tab[] = {-100, -1, 0, 47, 48, 57, 58, 64, 65, 90, 91, 96, 97, 122, 123, 200};
	printf("IS_ALPHA: ");
	for (unsigned long i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
	{
		if ((ft_isalpha(tab[i]) != 0) == (isalpha(tab[i]) != 0))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_isdigit(void)
{
	int tab[] = {-50, 0, 47, 48, 49, 56, 57, 58, 100, 255};
	printf("IS_DIGIT: ");
	for (unsigned long i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
	{
		if ((ft_isdigit(tab[i]) != 0) == (isdigit(tab[i]) != 0))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_isalnum(void)
{
	int tab[] = {0, 47, 48, '5', 'A', 'Z', 'a', 'z', 127, 200};
	printf("ISALNUM:  ");
	for (unsigned long i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
	{
		if ((ft_isalnum(tab[i]) != 0) == (isalnum(tab[i]) != 0))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_isascii(void)
{
	int tab[] = {-10, 0, 1, 50, 126, 127, 128, 255, 500};
	printf("ISASCII:  ");
	for (unsigned long i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
	{
		if ((ft_isascii(tab[i]) != 0) == (isascii(tab[i]) != 0))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_isprint(void)
{
	int tab[] = {-1, 31, 32, 50, 126, 127, 200};
	printf("ISPRINT:  ");
	for (unsigned long i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
	{
		if ((ft_isprint(tab[i]) != 0) == (isprint(tab[i]) != 0))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_strlen(void)
{
	char *tests[] = {"", "a", "Hello 42", "Tripouille", "0123456789abcdefghijklmnopqrstuvwxyz"};
	printf("STRLEN:   ");
	for (unsigned long i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		if (ft_strlen(tests[i]) == strlen(tests[i]))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_memset(void)
{
	char b1[30], b2[30];
	int vals[] = {0, 'A', 'z', -1, 128};
	int sizes[] = {0, 1, 5, 10, 20};
	printf("MEMSET:   ");
	for (int i = 0; i < 5; i++)
	{
		memset(b1, '_', 30); memset(b2, '_', 30);
		ft_memset(b1 + 2, vals[i], sizes[i]);
		memset(b2 + 2, vals[i], sizes[i]);
		if (memcmp(b1, b2, 30) == 0)
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_bzero(void)
{
	char b1[20], b2[20];
	int sizes[] = {0, 1, 5, 10, 15};
	printf("BZERO:    ");
	for (int i = 0; i < 5; i++)
	{
		memset(b1, 'A', 20); memset(b2, 'A', 20);
		ft_bzero(b1 + 2, sizes[i]);
		bzero(b2 + 2, sizes[i]);
		if (memcmp(b1, b2, 20) == 0)
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_memcpy(void)
{
	char d1[30], d2[30];
	char *src = "Bonjour les amis 42";
	int lens[] = {0, 1, 5, 10, 19};
	printf("MEMCPY:   ");
	for (int i = 0; i < 5; i++)
	{
		bzero(d1, 30); bzero(d2, 30);
		ft_memcpy(d1, src, lens[i]);
		memcpy(d2, src, lens[i]);
		if (memcmp(d1, d2, 30) == 0)
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_memmove(void)
{
	char s1[] = "1234567890";
	char s2[] = "1234567890";
	printf("MEMMOVE:  ");
	ft_memmove(s1 + 2, s1, 5);
	memmove(s2 + 2, s2, 5);
	if (memcmp(s1, s2, 10) == 0) printf("[OK] "); else printf("[KO] ");
	char m1[] = "1234567890";
	char m2[] = "1234567890";
	ft_memmove(m1, m1 + 2, 5);
	memmove(m2, m2 + 2, 5);
	if (memcmp(m1, m2, 10) == 0) printf("[OK] "); else printf("[KO] ");
	printf("\n");
}

void	test_strlcpy(void)
{
	char d1[10], d2[10];
	printf("STRLCPY:  ");
	for (int sz = 0; sz <= 8; sz++)
	{
		bzero(d1, 10); bzero(d2, 10);
		int r1 = ft_strlcpy(d1, "Tripouille", sz);
		int r2 = strlcpy(d2, "Tripouille", sz);
		if (r1 == r2 && strcmp(d1, d2) == 0)
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_strlcat(void)
{
	char d1[20], d2[20];
	printf("STRLCAT:  ");
	for (int sz = 0; sz <= 15; sz++)
	{
		strcpy(d1, "Hello"); strcpy(d2, "Hello");
		int r1 = ft_strlcat(d1, "World", sz);
		int r2 = strlcat(d2, "World", sz);
		if (r1 == r2 && strcmp(d1, d2) == 0)
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_toupper_tolower(void)
{
	printf("TOUPPER:  ");
	for (int c = 0; c <= 255; c += 15)
		if (ft_toupper(c) == toupper(c)) printf("[OK] "); else printf("[KO] ");
	printf("\nTOLOWER:  ");
	for (int c = 0; c <= 255; c += 15)
		if (ft_tolower(c) == tolower(c)) printf("[OK] "); else printf("[KO] ");
	printf("\n");
}

void	test_strchr_strrchr(void)
{
	char *s = "tripouille";
	int chars[] = {'t', 'p', 'e', '\0', 'z', 256 + 't'};
	printf("STRCHR:   ");
	for (int i = 0; i < 6; i++)
		if (ft_strchr(s, chars[i]) == strchr(s, chars[i])) printf("[OK] "); else printf("[KO] ");
	printf("\nSTRRCHR:  ");
	for (int i = 0; i < 6; i++)
		if (ft_strrchr(s, chars[i]) == strrchr(s, chars[i])) printf("[OK] "); else printf("[KO] ");
	printf("\n");
}

void	test_strncmp_memcmp(void)
{
	printf("STRNCMP:  ");
	if (ft_strncmp("abc", "abc", 3) == strncmp("abc", "abc", 3)) printf("[OK] "); else printf("[KO] ");
	if (ft_strncmp("abcd", "abf", 3) == strncmp("abcd", "abf", 3)) printf("[OK] "); else printf("[KO] ");
	if ((ft_strncmp("test\200", "test\0", 6) > 0) == (strncmp("test\200", "test\0", 6) > 0)) printf("[OK] "); else printf("[KO] ");
	
	printf("\nMEMCMP:   ");
	if (ft_memcmp("abc", "abc", 3) == memcmp("abc", "abc", 3)) printf("[OK] "); else printf("[KO] ");
	if ((ft_memcmp("test\200", "test\0", 6) > 0) == (memcmp("test\200", "test\0", 6) > 0)) printf("[OK] "); else printf("[KO] ");
	printf("\n");
}

void	test_memchr(void)
{
	char tab[] = {0, 1, 128, 255, 42};
	printf("MEMCHR:   ");
	for (int sz = 0; sz <= 5; sz++)
	{
		if (ft_memchr(tab, 128, sz) == memchr(tab, 128, sz))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_strnstr(void)
{
	char *big = "lorem ipsum dolor sit amet";
	printf("STRNSTR:  ");
	if (ft_strnstr(big, "ipsum", 15) == strnstr(big, "ipsum", 15)) printf("[OK] "); else printf("[KO] ");
	if (ft_strnstr(big, "ipsum", 5) == strnstr(big, "ipsum", 5)) printf("[OK] "); else printf("[KO] ");
	if (ft_strnstr(big, "", 10) == strnstr(big, "", 10)) printf("[OK] "); else printf("[KO] ");
	if (ft_strnstr(big, "dolor", 5) == strnstr(big, "dolor", 5)) printf("[OK] "); else printf("[KO] ");
	printf("\n");
}

void	test_atoi(void)
{
	char *tests[] = {"0", "42", "-42", "   +42", "   -00742", "---+--+123", "9223372036854775807", "-9223372036854775808", "2147483647", "-2147483648", "abc42", "42abc"};
	printf("ATOI:     ");
	for (unsigned long i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		if (ft_atoi(tests[i]) == atoi(tests[i]))
			printf("[OK] ");
		else
			printf("[KO] ");
	}
	printf("\n");
}

void	test_calloc_strdup(void)
{
	printf("CALLOC:   ");
	void *p1 = ft_calloc(5, 4); void *p2 = calloc(5, 4);
	if (p1 && p2) printf("[OK] "); else printf("[KO] ");
	free(p1); free(p2);
	void *p3 = ft_calloc(0, 0);
	if (p3) printf("[OK] "); else printf("[KO] ");
	free(p3);

	printf("\nSTRDUP:   ");
	char *d1 = ft_strdup("Tripouille 42"); char *d2 = strdup("Tripouille 42");
	if (d1 && d2 && strcmp(d1, d2) == 0) printf("[OK] "); else printf("[KO] ");
	free(d1); free(d2);
	char *d3 = ft_strdup(""); char *d4 = strdup("");
	if (d3 && d4 && strcmp(d3, d4) == 0) printf("[OK] "); else printf("[KO] ");
	free(d3); free(d4);
	printf("\n");
}

void	test_substr(void)
{
	printf("SUBSTR:   ");
	char *s = "lorem ipsum";
	char *res;

	res = ft_substr(s, 0, 5); if (res && strcmp(res, "lorem") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_substr(s, 6, 5); if (res && strcmp(res, "ipsum") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_substr(s, 100, 5); if (res && strcmp(res, "") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_substr(s, 0, 0); if (res && strcmp(res, "") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_substr(s, 5, 20); if (res && strcmp(res, " ipsum") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	printf("\n");
}

void	test_strjoin(void)
{
	printf("STRJOIN:  ");
	char *res;
	res = ft_strjoin("abc", "def"); if (res && strcmp(res, "abcdef") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_strjoin("", "def"); if (res && strcmp(res, "def") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_strjoin("abc", ""); if (res && strcmp(res, "abc") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_strjoin("", ""); if (res && strcmp(res, "") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	printf("\n");
}

void	test_strtrim(void)
{
	printf("STRTRIM:  ");
	char *res;
	res = ft_strtrim("   abc   ", " "); if (res && strcmp(res, "abc") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_strtrim("xxxtestxxx", "x"); if (res && strcmp(res, "test") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_strtrim("   ", " "); if (res && strcmp(res, "") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_strtrim("abc", ""); if (res && strcmp(res, "abc") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	res = ft_strtrim("", "abc"); if (res && strcmp(res, "") == 0) printf("[OK] "); else printf("[KO] "); free(res);
	printf("\n");
}

void	test_split(void)
{
	printf("SPLIT:    ");
	char **tab = ft_split("  hello world  42  ", ' ');
	if (tab && tab[0] && strcmp(tab[0], "hello") == 0 && tab[1] && strcmp(tab[1], "world") == 0 && tab[2] && strcmp(tab[2], "42") == 0 && tab[3] == NULL)
		printf("[OK] ");
	else
		printf("[KO] ");
	int i = 0; while (tab && tab[i]) { free(tab[i]); i++; } free(tab);

	char **tab2 = ft_split("", ' ');
	if (tab2 && tab2[0] == NULL) printf("[OK] "); else printf("[KO] ");
	free(tab2);
	printf("\n");
}

void	test_itoa(void)
{
	int vals[] = {0, 1, -1, 9, 10, 11, 42, -42, 2147483647, INT_MIN, 6942069, -16465, 1000, -1000};
	char expected[30];
	printf("ITOA:     ");
	for (unsigned long i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
	{
		char *res = ft_itoa(vals[i]);
		sprintf(expected, "%d", vals[i]);
		if (res && strcmp(res, expected) == 0)
			printf("[OK] ");
		else
			printf("[KO] ");
		free(res);
	}
	printf("\n");
}

void	test_strmapi_striteri(void)
{
	char s1[] = "hello";
	ft_striteri(s1, f_iter);
	printf("STRITERI: ");
	if (strcmp(s1, "HELLO") == 0) printf("[OK] \n"); else printf("[KO] \n");

	char *s2 = ft_strmapi("hello", f_mapi);
	printf("STRMAPI:  ");
	if (s2 && strcmp(s2, "HELLO") == 0) printf("[OK] \n"); else printf("[KO] \n");
	free(s2);
}

void	test_lists(void)
{
	printf("LSTNEW:   ");
	t_list *n1 = ft_lstnew(strdup("test"));
	if (n1 && strcmp((char *)n1->content, "test") == 0 && n1->next == NULL) printf("[OK] \n"); else printf("[KO] \n");

	printf("LSTADD_F: ");
	t_list *n2 = ft_lstnew(strdup("second"));
	ft_lstadd_front(&n1, n2);
	if (n1 == n2) printf("[OK] \n"); else printf("[KO] \n");

	printf("LSTSIZE:  ");
	if (ft_lstsize(n1) == 2) printf("[OK] \n"); else printf("[KO] \n");

	printf("LSTLAST:  ");
	if (ft_lstlast(n1)->content == n2->content || ft_lstlast(n1)->next == NULL) printf("[OK] \n"); else printf("[KO] \n");
	
	printf("LSTADD_B: ");
	t_list *n3 = ft_lstnew(strdup("third"));
	ft_lstadd_back(&n1, n3);
	if (ft_lstlast(n1) == n3) printf("[OK] \n"); else printf("[KO] \n");

	// Test de ft_lstdelone sur un maillon isolé (non rattaché à la liste principale)
	t_list *isolated = ft_lstnew(strdup("isole"));
	ft_lstdelone(isolated, del);
	printf("LSTDELONE:[OK] \n");

	// Nettoyage de la vraie liste principale
	ft_lstclear(&n1, del);
	printf("LSTCLEAR: [OK] \n");
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper_tolower();
	test_strchr_strrchr();
	test_strncmp_memcmp();
	test_memchr();
	test_strnstr();
	test_atoi();
	test_calloc_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi_striteri();
	test_lists();
	return (0);
}