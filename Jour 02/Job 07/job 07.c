// job7.c
#include <unistd.h>
#include "job 07.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

char	*ft_strtolower(char *str)
{
	char	*result;
	int		i;

	i = 0;
	while (str[i])
		i++;
	result = (char *)malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			result[i] = str[i] + 32;
		else
			result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*tmp;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		tmp = ft_strtolower(argv[i]);
		if (tmp)
		{
			ft_putstr(tmp);
			free(tmp);
		}
		i++;
	}
	return (0);
}