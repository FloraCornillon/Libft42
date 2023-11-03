/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:28:25 by fcornill          #+#    #+#             */
/*   Updated: 2023/11/03 16:50:36 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = current->next;
		(*del)(current->content);
		free(current);
	}
	*lst = NULL;
}
