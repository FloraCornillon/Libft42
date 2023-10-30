#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	count_word(const char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

char	*word_dup(const char *str, size_t start, size_t finish)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int	index;
	char	**array;

	if (!s || !(array = malloc((count_word(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			array[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}

int	main(void)
{
	const char *str = "J'aime la programmation et la vie";
	char sep = ' ';
	char **result = ft_split(str, sep);
	size_t i;

	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
