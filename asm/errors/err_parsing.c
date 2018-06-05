/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:47:44 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/05 20:29:33 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_opname_type(t_pars *l, int i)
{
	if (i == 1 || i == 9 || 1 == 12 || i == 15)
		if (l->type[0] != 0 || l->type[1] != 0 || l->type[2] != 0)
			ft_exit("The params are wrong for the op type");
	else if (i == 4 || i == 5)
		if (l->type[0] != 1 || l->type[1] != 1 || l->type[2] != 1)
			ft_exit("The params are wrong for the op type");
	else if (i == 6 || i == 7 || i == 8 || i == 14)
		if (l->type[2] != 1)
			ft_exit("The params are wrong for the op type");
	else if (i == 2 || i == 13)
		if (l->type[0] == 1 || l->type[1] != 1 || l->type[2] != 0)
			ft_exit("The params are wrong for the op type");
	else if (i == 16 && (l->type[0] != 1 || l->type[1] != 0 || l->type[2] != 0))
		ft_exit("The params are wrong for the op type");
	else if (i == 10 && (l->type[2] != 1 || l->type[1] == 1))
		ft_exit("The params are wrong for the op type");
	else if (i == 11 && (l->type[0] != 1 || l->type[2] == 1))
		ft_exit("The params are wrong for the op type");
	else if (i == 3 && (l->type[0] != 1 || l->type[1] == 2 || l->type[2] != 0))
		ft_exit("The params are wrong for the op type");
	return (0);
}
