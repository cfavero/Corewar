/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/05 17:25:05 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int 		main(int ac, char **av)
{
	int		fd;
	t_pars	*op_codes;

	if (ac != 2)
		ft_printf("Error: need a file\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		op_codes = ft_get_info(fd, NULL);
	}

	return (0);
}
