/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:33 by fcornill          #+#    #+#             */
/*   Updated: 2023/11/10 15:39:28 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct
{
	char			c;
	char			*str;
	int				num;
	unsigned int	unum;
	void			*ptr;
}					ptf_args

int	ft_printf(const char *, ...);

#endif
