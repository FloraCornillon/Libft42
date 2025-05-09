/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:33 by fcornill          #+#    #+#             */
/*   Updated: 2023/11/21 15:23:38 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_myputchar(int c);
int		ft_myputstr(char *s);
int		ft_myputnbr(long n, int base, char param);
int		ft_printptr(unsigned long n, unsigned int base); 

#endif
