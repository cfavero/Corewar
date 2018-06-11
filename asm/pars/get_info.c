/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:32 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/09 18:48:25 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_info(int fd, t_labels **save, header_t **head)
{
	t_pars	*lst;
	char	*line;
	int		counter;

	line = NULL;
	counter = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line && *line)
		{
			lst = ft_check_line(line, lst, head, counter);
			if (lst)
			{
				if (!(lst = ft_parsing(lst, lst, save, counter)))
					ft_exit("ft_parsing failed", counter);
				}
		}
		counter++;
		ft_strdel(&line);
	}
	return (lst);
}

t_pars		*ft_parsing(t_pars *lst, t_pars *tmp, t_labels **save, int counter)
{
	int tot_size;

	tot_size = 0;
	while (lst->next)
	{
		if (lst->next)
		{
			lst->next->position = lst->position + lst->size_code;
			tot_size = lst->position;
		}
		lst = lst->next;
	}
	if (!(lst = ft_get_label(lst->line, lst, save, counter)))
		ft_exit("get_label failed", counter);
	if (!(lst = ft_get_op_name(lst->line, lst, counter)))
		ft_exit("get_op_name failed", counter);
	if (!(lst = ft_get_type(lst->line, lst, counter)))
		ft_exit("get_type failed", counter);
	if (!(lst = ft_get_size_code(lst, lst->op_code, tot_size)))
		ft_exit("get_size_code failed", counter);
	return (tmp);
}

t_pars		*ft_get_code(t_pars *lst, t_labels *label, int fd)
{
	t_pars *tmp;

	tmp = lst;
	while (lst)
	{
		if (!(lst = ft_get_label_values(lst, label, 0)))
			ft_exit("get_label failed", 0);
		if (!(lst = ft_get_hexadecimal(lst, fd)))
			ft_exit("get_hexadecimal failed", 0);
	// translate into hexadecimal
	// ft_print_lst_current(lst);
		lst = lst->next;
	}
	return (tmp);
}
