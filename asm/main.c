/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 16:40:43 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		 		main(int ac, char **av)
{
	int			fd;
	t_pars		*op_codes;
	header_t	*head;
	t_labels	*lst_label;
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
		ft_printf("Error\nUsage: ./asm [Path]/[File_name]\n");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_exit("File doesn't exist");
		op_codes = ft_get_info(fd, &lst_label, &head);
		fd = create_file(av[1], 0, head, op_codes);
	}
	return (0);
}
