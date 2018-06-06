/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 21:15:05 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		 		main(int ac, char **av)
{
	int			fd;
	t_pars		*op_codes;
	header_t	*head;
	char		*test = ft_strdup("   .name   \"54s\" ");
	char		*test2 = ft_strdup("   .comment   \"funziona!!\"  ");

	if (!(head = malloc(sizeof(header_t))))
		return (-1);
	// ft_printf("prog_name _%c_\n", head->prog_name[0]);
	// head->prog_name = NULL;
	// head->comment = NULL;

	// op_codes = ft_init_lst(op_codes, "  label: hfufh");
	// op_codes = ft_get_label(op_codes->line, op_codes);
	// // ft_printf("%s-\n", op_codes->label);
	// ft_head_name(test, &head);
	// ft_head_name(test, &head);
	// ft_head_com(test2, &head);

	// ft_printf("prog_name %s\n", head->prog_name);
	// ft_printf("prog_comment %s\n", head->comment);
	if (ac != 2)
		ft_printf("Error: need a file\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		op_codes = ft_get_info(fd, NULL, &head);
	}
	ft_printf("prog_name -%s-\n", head->prog_name);
	ft_printf("prog_comment -%s-\n", head->comment);
	ft_printf("label -%s-\n", op_codes->label);
	ft_printf("op_name -%s-\n", op_codes->op_name);
	ft_printf("op_code %x\n", op_codes->op_code);
	return (0);
}
