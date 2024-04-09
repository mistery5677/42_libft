/*#include <stdio.h>
#include <ctype.h>

#include "libft.h"

int main()
{
    char c = '\0';
    char str[10] = "hello";

    printf("TESTING FT_ISALPHA \n\n");
    printf("my: %d\n", ft_isalpha(c));
    printf("original: %d\n\n", isalpha(c));

    printf("TESTING FT_ISDIGIT \n\n");
    printf("my: %d\n", ft_isdigit(c));
    printf("original: %d\n\n", isdigit(c));
    
    printf("TESTING FT_ISALNUM \n\n");
    printf("my: %d\n", ft_isalnum(c));
    printf("original: %d\n\n", isalnum(c));

    printf("TESTING FT_ISASCII \n\n");
    printf("my: %d\n", ft_isascii(c));
    printf("original: %d\n\n", isascii(c));

    printf("TESTING FT_ISPRINT \n\n");
    printf("my: %d\n", ft_isprint(c));
    printf("original: %d\n\n", isprint(c));

    printf("TESTING FT_STRLEN \n\n");
    printf("my: %lu\n", ft_strlen(str));
    printf("original: %lu\n\n", strlen(str));

    char teste[10];
    char teste2[10];
    size_t len = 10;
    ft_memset(teste, 'I', len);

    printf("TESTING FT_MEMSET \n\n");
    printf("my: %s\n", teste);
    ft_memset(teste2, 'I', len);
    printf("original: %s\n\n", teste2);

    char str2[10] = "Hello";
    printf("TESTING FT_BZERO \n\n");
    printf("Before zeroing: %s\n", str2);
    ft_bzero(str2, 3);
    printf("After zeroing: %s\n\n", str2);

    char *src = "hello";
    char dest[3];
    printf("TESTING FT_MEMCPY \n\n");
    printf("Before memcpy: %s\n", dest);
    ft_memcpy(dest, src, 3);
    printf("After memcpy: %s\n\n", dest);

    char dest_memmove[10] = "hello";
    char src_memmove[10] = "world";

    printf("TESTING FT_MEMMOVE \n\n");
    printf("before: str1 %s str2 %s\n", dest_memmove, src_memmove);
    ft_memmove(dest_memmove, src_memmove, 4);
    printf("after: str1 %s str2 %s\n\n", dest_memmove, src_memmove);

    char strlcpy_dest[5] = "hello";
    char strlcpy_src[5] = "world";

    printf("TESTING FT_STRLCPY \n\n");
    printf("antes: %s\n", strlcpy_dest);
    ft_strlcpy(strlcpy_dest, strlcpy_src, 3);
    printf("depois: %s %ld\n\n", strlcpy_dest, ft_strlcpy(strlcpy_dest,strlcpy_src, 3));

    char dst_strlcat[20] = "hello";
    char *src_strlcat = "world1";

    printf("TESTING FT_STRLCAT \n\n");
    printf("antes: %s\n", dst_strlcat);
    printf("numero: %ld\n", ft_strlcat(dst_strlcat, src_strlcat, 3));
    ft_strlcat(dst_strlcat, src_strlcat, 3);
    printf("depois: %s\n\n", dst_strlcat);

    char c_toupper = 'c';
    printf("TESTING FT_TOUPER \n\n");
    printf("%d\n", ft_toupper(c_toupper));
    printf("%d\n\n", toupper(c_toupper));

    printf("TESTING FT_TOLOWER \n\n");
    printf("%d\n", ft_tolower(c_toupper));
    printf("%d\n\n", tolower(c_toupper));

    const char s_strchr[] = "hello";
    printf("TESTING FT_STRCHR \n\n");
    printf("my: %s\n", ft_strchr(s_strchr, 'o'));
    printf("original: %s\n", strchr(s_strchr, 'o'));

    char str_dup[10] = "hello";
    char str_dup2[10] = "hello";
	char *str_dupp = ft_strdup(str_dup);
    char *str_dupp2 = strdup(str_dup2);
    printf("TESTING FT_STRDUP \n\n");
	printf("my: %s\n", str_dupp);
    printf("original: %s\n\n", str_dupp2);
	free(str_dupp);
    free(str_dupp2);

    printf("TESTING FT_STRRCHR \n\n");
    printf("my: %s\n", ft_strrchr(s_strchr, 'h'));
    printf("original: %s\n\n", strrchr(s_strchr, 'h'));

    char s1_strncmp[] = "hello";
    char s2_strncmp[] = "heloo";
    printf("TESTING FT_STRNCMP\n\n");
    printf("my: %d\n", ft_strncmp(s1_strncmp, s2_strncmp, 0));
    printf("original: %d\n\n", strncmp(s1_strncmp, s2_strncmp, 0));

    const char s_memchr[] = "hello";
    printf("TESTING FT_MEMCHR\n\n");
    printf("my: %p\n", ft_memchr(s_memchr, 'e', 1));
    printf("original: %p\n\n", memchr(s_memchr, 'e', 0));  

    char s1_memcmp[] = "hello";
    char s2_memcmp[] = "hello";
    printf("TESTING FT_MEMCMP\n\n");
    printf("my: %d\n", ft_memcmp(s1_memcmp, s2_memcmp, 5));
    printf("original: %d\n\n", memcmp(s1_memcmp, s2_memcmp, 5));

    const char big_strnstr[] = "heoloolpo";
    const char little_strnstr[] = "ool";
    printf("TESTING FT_STRNSTR \n\n");
    printf("mine: %s\n", ft_strnstr(big_strnstr, little_strnstr,9));

    const char nptr_atoi[] = "-3339999";
    printf("TESTING FT_ATOI \n\n");
    printf("meu: %d\n", ft_atoi(nptr_atoi));
    printf("original: %d\n\n", atoi(nptr_atoi));

        // Test case 1: Allocating memory for an array of integers
    int *intArray;
    size_t numInts = 5;
    size_t intSize = sizeof(int);

    printf("TESTING FT_CALLOC\n\n");
    printf("Test Case 1: Allocating memory for an array of integers\n");
    intArray = (int *)ft_calloc(numInts, intSize);
    if (intArray != NULL) {
        printf("Memory allocation successful\n");
        // Check if the memory is properly initialized to 0
        for (size_t i = 0; i < numInts; i++) {
            printf("%d ", intArray[i]);
        }
        printf("String: %ls\n", intArray);
        printf("\n");
        free(intArray); 
    } else {
        printf("Memory allocation failed\n");
    }

    // Test case 2: Allocating memory for an array of characters (string)
    char *str_calloc;
    size_t strLength = 10;
    size_t charSize = sizeof(char);

    printf("\nTest Case 2: Allocating memory for a string\n");
    str_calloc = (char *)ft_calloc(strLength, charSize);
    if (str_calloc != NULL) {
        printf("Memory allocation successful\n");
        // Check if the memory is properly initialized to '\0' (null characters)
        printf("String: %s\n\n", str_calloc);
        free(str_calloc); 
    } else {
        printf("Memory allocation failed\n");
    }

    const char sub_substr[] = "hello world";
    char *result_substr = ft_substr(sub_substr, 3, 4);
    printf("TESTING FT_SUBSTR \n\n");
    printf("meu: %s\n\n", result_substr);

    const char s1_strjoin[] = "hello ";
    const char s2_strjoin[] = "world";
    char *result_strjoin = ft_strjoin(s1_strjoin, s2_strjoin);
    printf("TESTING FT_STRJOIN \n\n");
    printf("meu: %s\n\n", result_strjoin);
    free(result_strjoin);

    const char *s1_strtrim = "wtestw";
    const char *set_strtrim = "w";
    char *str_strtrim = ft_strtrim(s1_strtrim, set_strtrim);
    printf("TESTING FT_STRTRIM \n\n");
    printf("meu: %s\n\n", str_strtrim);
    printf("start: %d\n\n", start(s1_strtrim, set_strtrim));
    printf("end: %d\n\n", end(s1_strtrim, set_strtrim));
    free(str_strtrim);

        char const s_ft_split[] = "eeeee";
        char const s_ft_split1[] = "hhhhhheeehh";
        char const s_ft_split2[] = "eeeehabceeehhhh";
        char const s_ft_split3[] = "hhhhh";
        char const s_ft_split4[] = "eeehhehheee";

        printf("TESTING FT_SPLIT \n\n");
        printf("string --> %s\n", ft_split(s_ft_split3, 'e'));
        printf("count_words: 0 --> %d\n", count_words(s_ft_split, 'e'));
        printf("count_words: 2 --> %d\n", count_words(s_ft_split1, 'e'));
        printf("count_words: 2 --> %d\n", count_words(s_ft_split2, 'e'));
        printf("count_words: 1 --> %d\n", count_words(s_ft_split3, 'e'));
        printf("count_words: 2 --> %d\n", count_words(s_ft_split4, 'e'));

    printf("TESTING FT_ITOA \n\n");
    printf("123 --> %s\n", ft_itoa(123));
    printf("0 --> %s\n", ft_itoa(0));
    printf("-123 --> %s\n\n", ft_itoa(-123));
    //printf("divided by %d\n", divide_nbr(n_itoa));

    printf("TESTING FT_PUTCHAR_FD \n\n");
    int fd_putchar = open("fd_putchar.txt", O_CREAT | S_IRWXU | O_WRONLY | O_APPEND, 0666);
    if (fd_putchar == -1) 
        perror("open");
    else
        printf("ficheiro criado com sucesso\n\n");
    ft_putchar_fd('c', fd_putchar);
    close(fd_putchar);

    printf("TESTING FT_PUTSTR_FD \n\n");
    int fd_putstr = open("fd_putstr.txt", O_CREAT | S_IRWXU | O_WRONLY | O_APPEND, 0666);
    if (fd_putstr == -1) 
        perror("open");
    else
        printf("ficheiro criado com sucesso\n\n");
    ft_putstr_fd("hello", fd_putstr);
    close(fd_putstr);

        printf("TESTING FT_PUTENDL_FD \n\n");
    int fd_putendl = open("fd_putendl.txt", O_CREAT | S_IRWXU | O_WRONLY | O_APPEND, 0666);
    if (fd_putendl == -1) 
        perror("open");
    else
        printf("ficheiro criado com sucesso\n\n");
    ft_putendl_fd("hello", fd_putendl);
    close(fd_putendl);

        printf("TESTING FT_PUTNBR_FD \n\n");
    int fd_putnbr = open("fd_putendl.txt", O_CREAT | S_IRWXU | O_WRONLY | O_APPEND, 0666);
    if (fd_putnbr == -1) 
        perror("open");
    else
        printf("ficheiro criado com sucesso\n\n");
    ft_putnbr_fd(123455, fd_putnbr);
    close(fd_putnbr);cd 
}*/