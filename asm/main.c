/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/12 19:25:43 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			give_max_size(t_labels **head, t_pars *lst)
{
	t_labels	*tmp;

	tmp = *head;
	while (lst->next)
		lst = lst->next;
	while (tmp)
	{
		tmp->max_size = lst->position + lst->size_code;
		tmp = tmp->next;
	}
}

int				main(int ac, char **av)
{
	int			fd;
	t_pars		*op_codes;
	header_t	*head;
	t_labels	*lst_label;
	int			opt;

	if (!(head = (header_t*)malloc(sizeof(header_t))))
		return (-1);
	ft_bzero(head, sizeof(header_t));
	if (ac == 1)
		ft_printf("Error\nUsage: ./asm	-[Option -h]	[Path]/[File_name]\n");
	else
	{
		av = option_check(av, ac, &opt);
		if ((fd = open(av[0], O_RDONLY)) == -1)
			ft_exit("File doesn't exist", 0);
		op_codes = ft_get_info(fd, &lst_label, &head);
		give_max_size(&lst_label, op_codes);
		head->prog_size = lst_label->max_size;
		head->magic = COREWAR_EXEC_MAGIC;
		op_codes = create_file(av[0], lst_label, head, op_codes);
		(opt & D) ? print_hexa(lst_label, head, op_codes, opt) : 0;
		ft_printf("%s was created\n", ft_get_filename(av[0]));
	}
	return (0);
}
