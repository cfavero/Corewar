/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:45:52 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/05 20:29:55 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_label(*line, t_pars *lst)
{
	// ft_strchr for : and we check for % before
	return (lst);
}

t_pars		*ft_get_op_name(*line, t_pars *lst)
{
	// split all the names, we gwt the i of char *tab
	// the i is the int of the int tab (hexdec val)
	lst->op_code = ft_create_tab(lst->op_name);
	return (lst);
}

t_pars		*ft_get_type(*line, t_pars *lst)
{
	// if (r) REG_CODE 01 if (%) 10 else 11
	// type [0] type [1] type [2]
	// if is sm different we say error; 
	ft_check_opname_type(lst, lst->op_code);
	return (lst);
}

t_pars		*ft_get_size_code(*line, t_pars *lst)
{
	// if (op_code) == 1/9/12/15 size = 5 (1) size = 3 (9/12/15)
	// else check the type (10/11/14) D = 2 ->  2 + IN(2) + D(2) + R(1)
	// else 2 + IN(2) + D(4) + R(1)
	return (lst);
}

int			ft_total_size_code(*line, t_pars *lst)
{
	int	size_code;
	if (size_code > MEM_SIZE) //Not sure about the MEM_SIZE being the total byte count
		ft_exit("File too big");
	return (size_code);
}
