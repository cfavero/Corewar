/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:02:22 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 16:34:59 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

void		ft_print_lst(t_pars *lst)
{
	t_pars *tmp;

	tmp = lst;
	while (lst->next)
		lst = lst->next;
	ft_printf("________________________\n");
	ft_printf(" label : %s\n op_name %s\n op_code %d\n", lst->label, lst->op_name, lst->op_code);
	ft_printf(" op_type[0] %d = %s\n op_type[1] %d = %s\n op_type[2] %d = %s\n", lst->type[0], lst->value[0], lst->type[1], lst->value[1], lst->type[2], lst->value[2]);
	ft_printf(" Position = %d\n Nb of bytes = %d\n", lst->position, lst->size_code);
}
