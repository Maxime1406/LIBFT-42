/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:10:34 by mbardeau          #+#    #+#             */
/*   Updated: 2026/10/28 04:15:00 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

// Fonctions auxiliaires pour les tests ajoutés à la fin
static void	my_striteri_func(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static char	my_strmapi_func(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	my_lstiter_func(void *content)
{
	char	*str = (char *)content;
	if (str)
		printf("Lstiter element: %s\n", str);
}

static void	*my_lstmap_func(void *content)
{
	char	*str = (char *)content;
	if (!str)
		return (NULL);
	return (strdup(str));
}

static void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	int	c = ' ';
	printf("%d", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	printf("%d", ft_isdigit(c));
	printf("%d\n", isdigit(c));
	printf("%d", ft_isalnum(c));
	printf("%d\n", isalnum(c));
	printf("%d", ft_isascii(c));
	printf("%d\n", isascii(c));
	printf("%d", ft_isprint(c));
	printf("%d\n", isprint(c));
	char *str = "tests";
	printf("%zu", ft_strlen(str));
	printf("%lu\n", strlen(str));

	char string[16] = "je test un truc";
	int	n = 3;
	printf("\nBefore ft_memset(): %s\n", string);
	ft_memset(string + n, 'a', 4 * sizeof(char));
	printf("After ft_memset():  %s", string);
	printf("\nBefore memset(): %s\n", string);
	memset(string + n, 'b', 4 * sizeof(char));
	printf("After memset():  %s", string);

	printf("\nBefore ft_bzero(): %s\n", string);
	ft_bzero(string + n, 4 * sizeof(char));
	printf("After ft_bzero():  %s", string);
	char strings[16] = "je test un truc";
	printf("\nBefore bzero(): %s\n", strings);
	bzero(strings + n, 4 * sizeof(char));
	printf("After bzero():  %s", strings);

	char	dest[50] = "Ceci est la destination";
	char	src[50] = "Cristalisation";
	printf("\nBefore ft_memcpy(): %s\n", dest);
	ft_memcpy(dest + 4, src, 15 * sizeof(char));
	printf("After ft_memcpy():  %s", dest);
	char	desti[50] = "Ceci est la destination";
	printf("\nBefore memcpy(): %s\n", desti);
	memcpy(desti + 4, src, 15 * sizeof(char));
	printf("After memcpy():  %s", desti);

	char	move1[] = {67, 68, 67, 68, 69, 0, 45};
	char	move2[] = {67, 67, 68, 68, 69, 0, 45};
	printf("\nBefore ft_memmove(): %s\n", move1);
	ft_memmove(move1, move2, sizeof(move2));
	printf("After ft_memmove():  %s", move1);
	printf("\nBefore memmove(): %s\n", move2);
	memmove(move2, move1, sizeof(move1));
	printf("After memmove():  %s", move2);

	//ajouter le flag -lbsd pour strlcat, strlcpy et bzero (pour les fonctions de base)
	int	len1 = ft_strlcpy(dest, src, 4 * sizeof(char));
	printf("\nLen after ft_strlcpy():  %d", len1);
	int	len2 = strlcpy(dest, src, 4 * sizeof(char));
	printf("\nLen after strlcpy():  %d", len2);

	char	destcat1[50] = "Test strlcat";
	char	destcat2[50] = "Test strlcat";
	printf("\nDescat1: %s", destcat1);
	printf("\nDescat2: %s", destcat2);
	int	len3 = ft_strlcat(destcat1, src, sizeof(src));
	printf("\nLen after ft_strlcat():  %d", len3);
	printf("\n%s", destcat1);
	int	len4 = strlcat(destcat2, src, sizeof(src));
	printf("\nLen after strlcat():  %d", len4);
	printf("\n%s", destcat2);

	int	car1 = 'd';
	int	car2 = 'e';
	printf("\n Car1 avant: %d", car1);
	printf("\n Car2 avant: %d", car2);
	printf("\nft_toupper(): %d", ft_toupper(car1));
	printf("\ntoupper(): %d", toupper(car2));
	printf("\nft_tolower(): %d", ft_tolower(car1));
	printf("\ntolower(): %d", tolower(car2));

	char	chaine[50] = "Il faut trouver la lettre";
	int	letter_to_find = 'r';
	printf("\n%s", chaine);
	printf("\n%d", letter_to_find);
	printf("\n ft_strchr(): %s", ft_strchr(chaine, letter_to_find));
	printf("\n strchr(): %s", strchr(chaine, letter_to_find));

	printf("\n%s", chaine);
	printf("\n%d", letter_to_find);
	printf("\n ft_strrchr(): %s", ft_strrchr(chaine, letter_to_find));
	printf("\n strrchr(): %s", strrchr(chaine, letter_to_find));

	char s11[50] = "a";
	char s12[50] = "ab";
	char s21[50] = "Avion";
	char s22[50] = "Voiture";
	char s31[50] = "Xi";
	char s32[50] = "Piano";
	char s41[50] = "Violond";
	char s42[50] = "Violoncelle";
	printf("%s\n", s11);
	printf("%s\n", s12);
	printf("%d\n", strncmp(s11, s12, n));
	printf("%s\n", "comparaison");
	printf("%d\n", ft_strncmp(s11, s12, n));
	printf("%s\n", s21);
	printf("%s\n", s22);
	printf("%d\n", strncmp(s21, s22, n));
	printf("%s\n", "comparaison");
	printf("%d\n", ft_strncmp(s21, s22, n));
	printf("%s\n", s31);
	printf("%s\n", s32);
	printf("%d\n", strncmp(s31, s32, n));
	printf("%s\n", "comparaison");
	printf("%d\n", ft_strncmp(s31, s32, n));
	printf("%s\n", s41);
	printf("%s\n", s42);
	printf("%d\n", strncmp(s41, s42, n));
	printf("%s\n", "comparaison");
	printf("%d\n", ft_strncmp(s41, s42, n));

	char s_memchr[] = {0, 1, 2 ,3 ,4 ,5};
	printf("\nft_memchr(): %s", (char *)ft_memchr(s_memchr, 0, 0));
	printf("\nmemchr(): %s", (char *)memchr(s_memchr, 0, 0));

	printf("%s\n", s11);
	printf("%s\n", s12);
	printf("memcmp() %d\n", memcmp(s11, s12, 4));
	printf("%s\n", "comparaison");
	printf("ft_memcmp() %d\n", ft_memcmp(s11, s12, 4));
	printf("%s\n", s21);
	printf("%s\n", s22);
	printf("memcmp() %d\n", memcmp(s21, s22, 4));
	printf("%s\n", "comparaison");
	printf("ft_memcmp() %d\n", ft_memcmp(s21, s22, 4));
	printf("%s\n", s31);
	printf("%s\n", s32);
	printf("memcmp() %d\n", memcmp(s31, s32, 4));
	printf("%s\n", "comparaison");
	printf("ft_memcmp() %d\n", ft_memcmp(s31, s32, 4));

	char	*big;
	char	*result;
	big = "Bonjour tout le monde, bienvenue a 42";
	printf("--- Tests de ft_strnstr ---\n");
	printf("Grande chaîne : '%s'\n\n", big);
	// Test 1 : Trouver une sous-chaîne présente dans les limites
	result = ft_strnstr(big, "tout", 30);
	printf("1. Recherche de 'tout' (taille 30) :\n");
	printf("   Obtenu : '%s'\n\n", result ? result : "NULL");
	// Test 2 : La sous-chaîne commence au début
	result = ft_strnstr(big, "Bonjour", 10);
	printf("2. Recherche de 'Bonjour' (taille 10) :\n");
	printf("   Obtenu : '%s'\n\n", result ? result : "NULL");
	// Test 3 : La sous-chaîne existe mais dépasse la taille len autorisée
	result = ft_strnstr(big, "bienvenue", 15);
	printf("3. Recherche de 'bienvenue' avec une taille trop courte (taille 15) :\n");
	printf("   Obtenu : '%s' (Doit être NULL car coupé avant)\n\n", result ? result : "NULL");
	// Test 4 : Chercher une sous-chaîne absente
	result = ft_strnstr(big, "420", 40);
	printf("4. Recherche de '420' (absent, taille 40) :\n");
	printf("   Obtenu : '%s' (Doit etre NULL)\n\n", result ? result : "NULL");
	// Test 5 : Une sous-chaîne vide ("")
	result = ft_strnstr(big, "", 10);
	printf("5. Recherche d'une chaine vide "" (taille 10) :\n");
	printf("   Obtenu : '%s' (Doit retourner la grande chaine entiere)\n", result ? result : "NULL");
	// Test 1 : Trouver une sous-chaîne présente dans les limites
	result = strnstr(big, "tout", 30);
	printf("1. Recherche de 'tout' (taille 30) :\n");
	printf("   Obtenu : '%s'\n\n", result ? result : "NULL");
	// Test 2 : La sous-chaîne commence au début
	result = strnstr(big, "Bonjour", 10);
	printf("2. Recherche de 'Bonjour' (taille 10) :\n");
	printf("   Obtenu : '%s'\n\n", result ? result : "NULL");
	// Test 3 : La sous-chaîne existe mais dépasse la taille len autorisée
	result = strnstr(big, "bienvenue", 15);
	printf("3. Recherche de 'bienvenue' avec une taille trop courte (taille 15) :\n");
	printf("   Obtenu : '%s' (Doit être NULL car coupé avant)\n\n", result ? result : "NULL");
	// Test 4 : Chercher une sous-chaîne absente
	result = strnstr(big, "420", 40);
	printf("4. Recherche de '420' (absent, taille 40) :\n");
	printf("   Obtenu : '%s' (Doit etre NULL)\n\n", result ? result : "NULL");
	// Test 5 : Une sous-chaîne vide ("")
	result = strnstr(big, "", 10);
	printf("5. Recherche d'une chaine vide "" (taille 10) :\n");
	printf("   Obtenu : '%s' (Doit retourner la grande chaine entiere)\n", result ? result : "NULL");

	printf("--- Tests de ft_atoi ---\n\n");
	char *t1 = "42";
	printf("Test 1 (\"%s\") :\n", t1);
	printf("   ft_atoi : %d\n", ft_atoi(t1));
	printf("   atoi    : %d\n\n", atoi(t1));
	char *t2 = "   -4284";
	printf("Test 2 (\"%s\" avec espaces) :\n", t2);
	printf("   ft_atoi : %d\n", ft_atoi(t2));
	printf("   atoi    : %d\n\n", atoi(t2));
	char *t3 = "+12345";
	printf("Test 3 (\"%s\") :\n", t3);
	printf("   ft_atoi : %d\n", ft_atoi(t3));
	printf("   atoi    : %d\n\n", atoi(t3));
	char *t4 = "  -00742abc99";
	printf("Test 4 (\"%s\") :\n", t4);
	printf("   ft_atoi : %d\n", ft_atoi(t4));
	printf("   atoi    : %d\n\n", atoi(t4));
	char *t5 = "000000567";
	printf("Test 5 (\"%s\") :\n", t5);
	printf("   ft_atoi : %d\n", ft_atoi(t5));
	printf("   atoi    : %d\n\n", atoi(t5));
	char *t6 = " --+000000567";
	printf("Test 6 (\"%s\") :\n", t6);
	printf("   ft_atoi : %d\n", ft_atoi(t6));
	printf("   atoi    : %d\n\n", atoi(t6));
	char *t7 = "-9223372036854775809";
	printf("Test 7 (\"%s\") :\n", t7);
	printf("   ft_atoi : %d\n", ft_atoi(t7));
	printf("   atoi    : %d\n\n", atoi(t7));
	char *t8 = "+9223372036854775808";
	printf("Test 8 (\"%s\") :\n", t8);
	printf("   ft_atoi : %d\n", ft_atoi(t8));
	printf("   atoi    : %d\n\n", atoi(t8));

	void    *ptr1;
	void    *ptr2;
	void    *ptr3;
	printf("--- Tests ft_calloc ---\n\n");
	ptr1 = ft_calloc(5, sizeof(int));
	if (ptr1)
		printf("Test 1 (Allocation normale) : OK\n");
	else
		printf("Test 1 (Allocation normale) : FAIL\n");
	free(ptr1);
	ptr2 = ft_calloc(0, sizeof(int));
	if (ptr2)
		printf("Test 2 (Count a zero) : OK (Pointeur alloue)\n");
	else
		printf("Test 2 (Count a zero) : OK (NULL retourne)\n");
	free(ptr2);
	ptr3 = ft_calloc(SIZE_MAX, 10);
	if (ptr3 == NULL)
		printf("Test 3 (Overflow SIZE_MAX) : OK (Protege, retourne NULL)\n");
	else
	{
		printf("Test 3 (Overflow SIZE_MAX) : FAIL\n");
		free(ptr3);
	}
	printf("--- Tests ft_calloc ---\n\n");
	ptr1 = calloc(5, sizeof(int));
	if (ptr1)
		printf("Test 1 (Allocation normale) : OK\n");
	else
		printf("Test 1 (Allocation normale) : FAIL\n");
	free(ptr1);
	ptr2 = calloc(0, sizeof(int));
	if (ptr2)
		printf("Test 2 (Count a zero) : OK (Pointeur alloue)\n");
	else
		printf("Test 2 (Count a zero) : OK (NULL retourne)\n");
	free(ptr2);
	ptr3 = calloc(SIZE_MAX, 10);
	if (ptr3 == NULL)
		printf("Test 3 (Overflow SIZE_MAX) : OK (Protege, retourne NULL)\n");
	else
	{
		printf("Test 3 (Overflow SIZE_MAX) : FAIL\n");
		free(ptr3);
	}

	char    *orig1 = "Bonjour tout le monde !";
	char    *orig2 = "";
	char    *orig3 = "42 School Angouleme";

	char    *res_ft1;
	char    *res_std1;
	char    *res_ft2;
	char    *res_std2;
	char    *res_ft3;
	char    *res_std3;

	printf("--- Tests de comparaison ft_strdup vs strdup ---\n\n");

	// Test 1 : Chaîne classique
	res_ft1 = ft_strdup(orig1);
	res_std1 = strdup(orig1);
	printf("Test 1 (\"%s\") :\n", orig1);
	printf("   ft_strdup : \"%s\"\n", res_ft1);
	printf("   strdup    : \"%s\"\n", res_std1);
	if (res_ft1 && res_std1 && strcmp(res_ft1, res_std1) == 0)
		printf("   Resultat  : IDENTIQUE (OK)\n\n");
	else
		printf("   Resultat  : DIFFERENT (FAIL)\n\n");
	free(res_ft1);
	free(res_std1);

	// Test 2 : Chaîne vide ("")
	res_ft2 = ft_strdup(orig2);
	res_std2 = strdup(orig2);
	printf("Test 2 (Chaine vide \"\") :\n");
	printf("   ft_strdup : \"%s\"\n", res_ft2);
	printf("   strdup    : \"%s\"\n", res_std2);
	if (res_ft2 && res_std2 && strcmp(res_ft2, res_std2) == 0)
		printf("   Resultat  : IDENTIQUE (OK)\n\n");
	else
		printf("   Resultat  : DIFFERENT (FAIL)\n\n");
	free(res_ft2);
	free(res_std2);

	// Test 3 : Chaîne avec des chiffres et espaces
	res_ft3 = ft_strdup(orig3);
	res_std3 = strdup(orig3);
	printf("Test 3 (\"%s\") :\n", orig3);
	printf("   ft_strdup : \"%s\"\n", res_ft3);
	printf("   strdup    : \"%s\"\n", res_std3);
	if (res_ft3 && res_std3 && strcmp(res_ft3, res_std3) == 0)
		printf("   Resultat  : IDENTIQUE (OK)\n\n");
	else
		printf("   Resultat  : DIFFERENT (FAIL)\n\n");
	free(res_ft3);
	free(res_std3);


	//PART 2
	unsigned int start1 = 50;
	unsigned int start2 = 10;
	size_t lensubstr1 = 0;
	size_t lensubstr2 = 5;
	const char *s = "On essaie de finir libft";
	char	*res_substr1;
	res_substr1 = ft_substr(s, start2, lensubstr2);
	printf("\n%s", s);
	printf("\nResultat ft_substr(): %s", res_substr1);
	free(res_substr1);
	char	*res_substr2;
	res_substr2 = ft_substr(s, start2, lensubstr1);
	printf("\nResultat ft_substr(): %s", res_substr2);
	free(res_substr2);
	char	*res_substr3;
	res_substr3 = ft_substr(s, start1, lensubstr2);
	printf("\nResultat ft_substr(): %s", res_substr3);
	free(res_substr3);
	char	*res_substr4;
	res_substr4 = ft_substr(s, start1, lensubstr1);
	printf("\nResultat ft_substr(): %s", res_substr4);
	free(res_substr4);

	//FT_STRJOIN
	const char	*char_strjoin1 = "test de ";
	const char	*char_strjoin2 = "la fonction ft_strjoin";
	char	*res_strjoin;
	res_strjoin = ft_strjoin(char_strjoin1, char_strjoin2);
	printf("\n Resultat de ft_strjoin(): %s", res_strjoin);
	free(res_strjoin);

	//FT_STRTRIM
	const char	*char_strtrim = "*****Bonjour ..comment vas-tu?...";
	const char	*set_strtrim = "*.";
	char	*res_strtrim;
	res_strtrim = ft_strtrim(char_strtrim, set_strtrim);
	printf("\n Resultat de ft_strtrim(): %s \n", res_strtrim);
	free(res_strtrim);

	//FT_SPLIT
	char	sep = ' ';
	str = "    La maison est montee";
	char	**res = ft_split(str, sep);

	int	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	res = ft_split("  bab abab   abhc ", ' ');

	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);

	//FT_ITOA
	printf("\nResultat de ft_itoa(): %s", ft_itoa(2147483647));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-2147483648));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(0));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(1));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(2));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(9));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(10));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(11));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(42));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-1));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-2));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-9));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-10));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-11));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-42));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(6942069));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(14698465));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-16465));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(546465));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-164465));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(684));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(-68465));
	printf("\nResultat de ft_itoa(): %s", ft_itoa(6851465));

	//FT_LSTNEW
	char	*content = "Hello!";
	t_list *reslst = ft_lstnew(content);
	reslst = ft_lstnew("Coucou");
	reslst = ft_lstnew("Bonsoir");
	reslst = ft_lstnew("C\'est Polo");
	printf("\nResultat de ft_lstnew(): %s", (char *)reslst->content);
	
	//FT_LSTADD_FRONT
    t_list	*new = ft_lstnew("Salut");
	t_list	*new1 = ft_lstnew("Bonsoir");
	t_list	*new2 = ft_lstnew("C\'est Polo");
    ft_lstadd_front(&reslst, new);
	ft_lstadd_front(&reslst, new1);
	ft_lstadd_front(&reslst, new2);
    printf("\nResultat de ft_lstadd_front(): %s", (char *)reslst->content);

	//FT_LSTSIZE
	printf("\n ft_lstsize(): %d", ft_lstsize(reslst));


	// FT_STRITERI & FT_STRMAPI
	char	str_iter[] = "bonjour";
	ft_striteri(str_iter, my_striteri_func);
	printf("\nResultat ft_striteri(): %s", str_iter);

	char	*str_mapi = ft_strmapi("bonjour", my_strmapi_func);
	printf("\nResultat ft_strmapi():  %s", str_mapi);
	free(str_mapi);

	// FT_PUT*_FD
	printf("\nTests put*_fd : ");
	ft_putchar_fd('A', 1);
	ft_putstr_fd(" | ", 1);
	ft_putendl_fd("B", 1);
	ft_putnbr_fd(42, 1);
	printf("\n");

	// FT_LSTLAST & FT_LSTADD_BACK
	t_list	*new_back = ft_lstnew(strdup("Dernier_back"));
	ft_lstadd_back(&reslst, new_back);
	if (ft_lstlast(reslst))
		printf("ft_lstlast() resultat : %s\n", (char *)ft_lstlast(reslst)->content);

	// FT_LSTITER
	ft_lstiter(reslst, my_lstiter_func);

	// FT_LSTMAP
	t_list	*mapped = ft_lstmap(reslst, my_lstmap_func, del_content);
	if (mapped)
		printf("ft_lstmap premier element : %s\n", (char *)mapped->content);
	ft_lstclear(&mapped, del_content);

	// FT_LSTCLEAR
	ft_lstclear(&reslst, del_content);
	printf("Liste nettoyee avec ft_lstclear.\n");

	return (0);
}