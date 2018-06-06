/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 13:50:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_size_code(char *line, t_pars *lst)
{
	// if (op_code) == 1/9/12/15 size = 5 (1) size = 3 (9/12/15)
	// else check the type (10/11/14) D = 2 ->  2 + IN(2) + D(2) + R(1)
	// else 2 + IN(2) + D(4) + R(1)
	return (lst);
}

int			ft_total_size_code(char *line, t_pars *lst)
{
	int	size_code;
	if (size_code > MEM_SIZE) //Not sure about the MEM_SIZE being the total byte count
		ft_exit("File too big");
	return (size_code);
}
