/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:32 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 16:39:28 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_info(int fd, t_labels **save, header_t **head)
{
	t_pars	*lst;
	char	*line;

	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line && *line)
		{
			lst = ft_check_line(line, lst, head);
			if (lst)
				if (!(lst = ft_parsing(lst, lst)))
					ft_exit("ft_parsing failed");
			if (lst)
				ft_print_lst(lst);
		}
		ft_strdel(&line);
	}
	return (lst);
}

t_pars		*ft_parsing(t_pars *lst, t_pars *tmp)
{
	int tot_size;

	tot_size = 0;
	while (lst->next)
	{
		if (lst->next->next)
			tot_size = lst->position;
		lst = lst->next;
	}
	if (!(lst = ft_get_label(lst->line, lst)))
		ft_exit("get_label failed");
	if (!(lst = ft_get_op_name(lst->line, lst)))
		ft_exit("get_op_name failed");
	if (!(lst = ft_get_type(lst->line, lst)))
		ft_exit("get_type failed");
	if (!(lst = ft_get_size_code(lst, lst->op_code, tot_size)))
		ft_exit("get_size_code failed");
	return (tmp);
}
