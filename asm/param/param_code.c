/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 16:33:34 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_size_count(t_pars *lst, int value)
{
	int k;

	k = 0;
	while (k++ < 3)
	{
		if (lst->type[k] == 1)
			lst->size_code++;
		else if (lst->type[k] == 2)
			lst->size_code += value;
		else if (lst->type[k] == 3)
			lst->size_code += 2;
	}
	return (lst);
}

t_pars		*ft_get_size_code(t_pars *lst, int i, int tot_size)
{
	lst->size_code = 2;
	if (i == 9 || 1 == 12 || i == 15 || i == 16)
		lst->size_code = 3;
	else if (i == 1 || i == 4 || i == 5)
		lst->size_code = 5;
	else if (i == 10 || i == 11 || i == 14)
		lst = ft_size_count(lst, 2);
	else
		lst = ft_size_count(lst, 4);
	lst->position = ft_total_size_code(lst, tot_size);
	return (lst);
}

int			ft_total_size_code(t_pars *lst, int tot_size)
{
	tot_size += lst->size_code;
	if (tot_size > MEM_SIZE) //Not sure about the MEM_SIZE being the total byte count
		ft_exit("File too big");
	return (tot_size);
}
