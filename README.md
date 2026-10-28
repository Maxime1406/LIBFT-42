# Libft - 42 Project

## À propos
La **Libft** est le premier projet du tronc commun de l'école 42. L'objectif est de recoder un ensemble de fonctions de la bibliothèque standard C (`libc`), ainsi que des fonctions utilitaires supplémentaires et de manipulation de listes chaînées, afin de se constituer une bibliothèque statique (`libft.a`) réutilisable pour les futurs projets du cursus.

---

## 📋 Description détaillée des fonctions

### 1. Partie 1 : Fonctions de la Libc

#### Classification de caractères (`<ctype.h>`)
* **`ft_isalpha`** : Vérifie si un caractère est alphabétique.
* **`ft_isdigit`** : Vérifie si un caractère est un chiffre décimal.
* **`ft_isalnum`** : Vérifie si un caractère est alphanumérique.
* **`ft_isascii`** : Vérifie si un caractère fait partie de la table ASCII.
* **`ft_isprint`** : Vérifie si un caractère est imprimable.

#### Conversion de casse
* **`ft_toupper`** : Convertit un caractère en majuscule.
* **`ft_tolower`** : Convertit un caractère en minuscule.

#### Manipulation de chaînes (`<string.h>`)
* **`ft_strlen`** : Calcule la longueur d'une chaîne de caractères.
* **`ft_strchr`** : Recherche la première occurrence d'un caractère dans une chaîne.
* **`ft_strrchr`** : Recherche la dernière occurrence d'un caractère dans une chaîne.
* **`ft_strncmp`** : Compare deux chaînes de caractères sur `n` octets.
* **`ft_strnstr`** : Localise une sous-chaîne dans une chaîne sur une taille maximale.
* **`ft_strlcpy`** : Copie une chaîne de caractères avec une taille limitée et sécurisée.
* **`ft_strlcat`** : Concatène deux chaînes de caractères de manière sécurisée.
* **`ft_strdup`** : Duplique une chaîne de caractères en allouant la mémoire nécessaire.

#### Manipulation de mémoire
* **`ft_memset`** : Remplit une zone mémoire avec une valeur constante.
* **`ft_bzero`** : Met à zéro une zone mémoire.
* **`ft_memcpy`** : Copie une zone mémoire.
* **`ft_memmove`** : Copie une zone mémoire en gérant les chevauchements.
* **`ft_memchr`** : Recherche un octet dans une zone mémoire.
* **`ft_memcmp`** : Compare deux zones mémoire.

#### Allocation et conversion
* **`ft_calloc`** : Alloue de la mémoire et l'initialise à zéro.
* **`ft_atoi`** : Convertit une chaîne de caractères en entier (`int`).

---

### 2. Partie 2 : Fonctions additionnelles
* **`ft_substr`** : Alloue (avec `malloc(3)`) et retourne une chaîne de caractères issue de la chaîne `s`. Cette nouvelle chaîne commence à l'index `start` et a pour taille maximale `len`.
* **`ft_strjoin`** : Alloue (avec `malloc(3)`) et retourne une nouvelle chaîne, résultat de la concaténation de `s1` et `s2`.
* **`ft_strtrim`** : Alloue (avec `malloc(3)`) et retourne une copie de la chaîne `s1`, sans les caractères spécifiés dans `set` au début et à la fin de la chaîne de caractères.
* **`ft_split`** : Alloue (avec `malloc(3)`) et retourne un tableau de chaînes de caractères obtenu en séparant `s` à l'aide du caractère `c`, utilisé comme délimiteur. Le tableau doit être terminé par `NULL`.
* **`ft_itoa`** : Alloue (avec `malloc(3)`) et retourne une chaîne de caractères représentant l'entier `n` reçu en argument. Les nombres négatifs doivent être gérés.
* **`ft_strmapi`** : Applique la fonction `f` à chaque caractère de la chaîne de caractères passée en argument pour créer une nouvelle chaîne de caractères (avec `malloc(3)`) résultant des applications successives de `f`.
* **`ft_striteri`** : Applique la fonction `f` à chaque caractère de la chaîne de caractères transmise comme argument, et en passant son index comme premier argument. Chaque caractère est transmis par adresse à `f` afin d'être modifié si nécessaire.
* **`ft_putchar_fd`** : Écrit le caractère `c` sur le descripteur de fichier donné.
* **`ft_putstr_fd`** : Écrit la chaîne de caractères `s` sur le descripteur de fichier donné.
* **`ft_putendl_fd`** : Écrit La chaîne de caractères `s` sur le descripteur de fichier donné suivie d'un retour à la ligne.
* **`ft_putnbr_fd`** : Écrit l'entier `n` sur le descripteur de fichier donné.

---

### 3. Partie Bonus : Listes chaînées
* **`ft_lstnew`** : Alloue (avec `malloc(3)`) et renvoie un nouvel élément. La variable membre `content` est initialisée à l'aide de la valeur du paramètre `content`. La variable `next` est initialisée à `NULL`.
* **`ft_lstadd_front`** : Ajoute l'élément `new` au début de la liste.
* **`ft_lstsize`** : Compte le nombre d'éléments de la liste.
* **`ft_lstlast`** : Renvoie le dernier élément de la liste.
* **`ft_lstadd_back`** : Ajoute l'élément `new` à la fin de la liste.
* **`ft_lstdelone`** : Libère la mémoire de l'élément passé en argument en utilisant la fonction `del` puis avec `free(3)`. La mémoire de `next` ne doit pas être free.
* **`ft_lstclear`** : Supprime et libère la mémoire de l'élément passé en paramètre, et de tous les éléments qui suivent, à l'aide de `del` et de `free(3)`. Enfin, le pointeur initial doit être mis à `NULL`.
* **`ft_lstiter`** : Itère sur la liste `lst` et applique la fonction `f` au contenu chaque élément.
* **`ft_lstmap`** : Itère sur la liste `lst` et applique la fonction `f` au contenu de chaque élément. Crée une nouvelle liste résultant des applications successives de `f`. La fonction `del` est là pour détruire le contenu d'un élément si nécessaire.

---

## 🛠️ Compilation et Utilisation

### Instructions du Makefile
À la racine du projet, utilise les commandes suivantes selon les besoins :

* **`make`** : Compile les fichiers sources et génère la bibliothèque statique **`libft.a`**.
* **`make clean`** : Supprime les fichiers objets (`.o`).
* **`make fclean`** : Supprime les fichiers objets ainsi que la bibliothèque `libft.a`.
* **`make re`** : Effectue un `fclean` suivi d'un `make` pour tout recompiler à neuf.

### Comment l'utiliser dans un programme
1. Inclure le fichier d'en-tête dans ton code source :
   ```c
   #include "libft.h"