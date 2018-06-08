/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/08 19:16:00 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void 			give_max_size(t_labels **head, t_pars *lst)
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

int		 		main(int ac, char **av)
{
	int			fd;
	t_pars		*op_codes;
	header_t	*head;
	t_labels	*lst_label;
	char		*test = ft_strdup("   .name   \"54s\" ");
	char		*test2 = ft_strdup("   .comment   \"funziona!!\"  ");

	if (!(head = (header_t*)malloc(sizeof(header_t))))
		return (-1);
	ft_bzero(head, sizeof(header_t));
	if (ac != 2)
		ft_printf("Error\nUsage: ./asm [Path]/[File_name]\n");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_exit("File doesn't exist");
		op_codes = ft_get_info(fd, &lst_label, &head);
		give_max_size(&lst_label, op_codes);
		ft_print_labeled(lst_label);
		// ft_print_lst(op_codes);
		op_codes = ft_get_code(op_codes, lst_label);
		fd = create_file(av[1], 0, head, op_codes);
	}
	return (0);
}
