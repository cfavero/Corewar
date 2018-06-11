/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/09 18:45:05 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			count_op_size(t_pars *lst)
{
	int		k;
	int		test;
	int		tmp;

	k = 0;
	tmp = 0;
	test = 6;
	if (!lst)
		return (-1);
	while (k < 3)
	{
		tmp |= lst->type[k] << test;
		k++;
		test -= 2;
	}
	return(tmp);
}

/*
**How to do the overflow in the number of bytes to print
*/
t_pars		*ft_get_hexadecimal(t_pars *lst, int fd)
{
	int	tmp;

	if (!lst)
		exit(1);
	write(fd, &lst->op_code, 1);
	tmp = count_op_size(lst);
	if (!(lst->op_code == 1 || lst->op_code == 12 || lst->op_code == 9 || \
		lst->op_code == 15))
		write(fd, &tmp, 1);
	ft_print_params(lst, fd, 0, 0);
	return (lst);
}

t_pars		*ft_size_count(t_pars *lst, int value)
{
	int k;

	k = -1;
	while (++k < 3)
	{
		if (lst->type[k] == 1)
			lst->size_code++;
		else if (lst->type[k] == 2)
		{
			lst->size_code += value;
			if (lst->value[k][0] == ':')
				lst->label_size = lst->size_code;
		}
		else if (lst->type[k] == 3)
			lst->size_code += 2;
	}
	return (lst);
}

t_pars		*ft_get_size_code(t_pars *lst, int i, int tot_size)
{
	lst->size_code = 2;
	lst->dir_size = DIR_SIZE;
	if (i == 9 || 1 == 12 || i == 15 || i == 16 || i == 1)
	{
		lst->size_code = (i == 1) ? 5 : 3;
		if (lst->value[0][0] == ':')
			lst->label_size = lst->size_code;
	}
	else if (i == 4 || i == 5)
		lst->size_code = 5;
	else if (i == 10 || i == 11 || i == 14)
	{
		lst = ft_size_count(lst, IND_SIZE);
		lst->dir_size = IND_SIZE;
	}
	else
		lst = ft_size_count(lst, DIR_SIZE);
	if ((lst->position + lst->size_code) > MEM_SIZE)
			ft_exit("File too big", 0);
	return (lst);
}
