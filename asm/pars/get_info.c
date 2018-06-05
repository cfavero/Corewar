/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:33:32 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/05 19:13:01 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		ft_get_info(int fd, char *line)
{
	t_pars	*lst;

	while ((get_next_line(fd, &line)) > 0)
	{
		if (line && *line)
		{
			if (!(lst = ft_check_line(line, lst)))
				ft_exit("check_line failed");
			if (!(lst = ft_parsing(lst)))
				ft_exit("ft_parsing failed");
		}
		ft_strdel(&line);
	}

	return (lst);
}

t_pars		ft_parsing(char *line)
{
	t_pars	*lst;

	if (!(lst = ft_get_label(lst->line, lst)))
		ft_exit("get_label failed");
	if (!(lst = ft_get_op_name(lst->line, lst)))
		ft_exit("get_op_name failed");
	if (!(lst = ft_get_type(lst->line, lst)))
		ft_exit("get_type failed");
	if (!(lst = ft_get_size_code(lst)))
		ft_exit("get_size_code failed");
	return (lst);
}