#include <unistd.h>  // Pour write
#include <stdlib.h>  // Pour malloc et free
#include "job08.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*str++);
}

char    *ft_strtrim(char *str)
{
    char    *result;
    int     start;
    int     end;
    int     i;

    start = 0;
    while (str[start] == ' ')
        start++;
    end = 0;
    while (str[end])
        end++;
    end--;
    while (end >= start && str[end] == ' ')
        end--;
    result = (char *)malloc((end - start + 2));
    if (!result)
        return (NULL);
    i = 0;
    while (start <= end)
        result[i++] = str[start++];
    result[i] = '\0';
    return (result);
}

int     ft_strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void    ft_sort_strings(char **tab, int size)
{
    int     i;
    int     j;
    char    *tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (ft_strcmp(tab[i], tab[j]) > 0)
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int     main(int argc, char **argv)
{
    int     i;
    char    *trimmed;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        trimmed = ft_strtrim(argv[i]);
        if (trimmed)
        {
            argv[i] = trimmed;
        }
        i++;
    }
    ft_sort_strings(argv + 1, argc - 1);
    i = 1;
    while (i < argc)
    {
        ft_putstr(argv[i]);
        if (i < argc - 1)
            ft_putchar(' ');
        free(argv[i]);
        i++;
    }
    ft_putchar('\n');
    return (0);
}