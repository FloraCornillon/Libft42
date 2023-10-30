#include <stdlib.h>
#include <stdio.h>

int	ft_get_len_num(int n)
{
	int	lenght;

	lenght = 0;
	if (n < 0)
	{
		n = n * -1;
		lenght++;
	}
	while (n > 9)
	{
		n = n / 10;
		lenght++;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	int	len;
	char	*str;
	int	sign;
	int	i;
	
	sign = 0;
	len = ft_get_len_num(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	str[len] = '\0';
	i = len;
	while (i >= sign)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

int	main(void)
{
	int num = -45893211;
	char *result = ft_itoa(num);
	printf("%s\n", result);
	free(result);
	return (0);
}




