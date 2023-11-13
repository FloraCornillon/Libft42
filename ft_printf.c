#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_myputchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_myputstr(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	ft_myputnbr(long n, int base)
{
	int	count;
	char	*digit;

	digit = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_myputnbr(n * -1, base) + 1);
	}
	else if (n < base)
		return (ft_myputchar(digit[n]));
	else
       	{
		count = ft_myputnbr(n / base, base);
		return (count + ft_myputnbr(n % base, base));
	}
}

int	ft_get_format(char param, va_list ap)
{
	int	count;

	count = 0;
	if (param == 'c')
		count += ft_myputchar(va_arg(ap, int));
	else if (param == 's')
		count += ft_myputstr(va_arg(ap, char *));
	else if (param == 'd')
		count += ft_myputnbr((long)va_arg(ap, int), 10);
	else if (param == 'x')
		count += ft_myputnbr((long)va_arg(ap, int), 16);
	else
		count += write(1, &param, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_get_format(*++format, ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
				
int	main(void)
{
	int	count;
	
	//count = ft_printf("salut, %s\n", "Flora");
	count = ft_printf("%x\n", -18);
	printf("%d chars\n", count);
	printf("%x\n", -18);
}
		
