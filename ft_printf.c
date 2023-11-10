/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:03:51 by fcornill          #+#    #+#             */
/*   Updated: 2023/11/10 16:16:23 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
				format++;
			if (*format == 'c')
				count +=ft_putchar(ap.c);
			else if (*format == 's')
				count	+=ft_putstr(ap.str);
			else if (*format == 'i')
				count +=ft_putnumber(ap.num);
			else if (*format == '%')
				count +=ft_puchar('%');
			else
				count +=ft_putchar(*format);
		}
		else
			count +=ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);	
}
