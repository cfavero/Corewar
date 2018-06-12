/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:55:39 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/12 18:10:30 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				check_for_i(int *i)
{
	*i += 1;
	if (*i % 8 == 0)
		ft_printf(" ");
	if (*i >= 16)
	{
		ft_printf("\n");
		*i = 0;
	}
}

void 			write_oct_color(unsigned int nbr, int code_size, int *i)
{
	int			j;
	int			bytes;

	j = 0;
	bytes = code_size;
	while (code_size--)
	{
		bytes--;
		j = nbr >> (bytes * 8);
		ft_printf("%02x ", j & 0xFF);
		check_for_i(i);
	}
}

void		ft_print_bonus(t_pars *lst, int k, int bytes, int *i)
{
	unsigned int tmp;
	t_op		op_tab;
	int j;

	j = 0;
	op_tab = all_info(lst->op_code - 1);
	while (k < op_tab.nb_params)
	{
		tmp = ft_atoll(lst->value[k]);
		bytes = byte_size(tmp);
		if (lst->type[k] == 1)
		{
			ft_printf(MAGENTA);
			write_oct_color(tmp, 1, i);
		}
		else if (lst->type[k] == 2 && lst->dir_size == 4)
		{
			ft_printf(YELLOW);
			write_oct_color(tmp, DIR_SIZE, i);
		}
		else if (lst->type[k] == 3 || lst->type[k] == 2)
		{
			ft_printf(RED);
			write_oct_color(tmp, IND_SIZE, i);
		}
		k++;
	}
}

t_pars		*ft_print_hexa(t_pars *lst)
{
	int		tmp;
	t_op	op_tab;
	static int	i = 0;

	op_tab = all_info(lst->op_code - 1);
	if (!lst)
		ft_exit("No lst in hexa", 1);
	ft_printf(LCYAN);
	ft_printf(BOLD);
	write_oct_color(lst->op_code, 1, &i);
	ft_printf(NBOLD);
	tmp = count_op_size(lst);
	if (op_tab.oct_code)
	{
		ft_printf(GREEN);
		write_oct_color(tmp, 1, &i);
	}
	ft_print_bonus(lst, 0, 0, &i);
	return (lst);
}

void		print_header(header_t *head)
{
	ft_printf(ORANGE);
	ft_printf("%-12s: ", "Exec_magic");
	ft_printf(LYELLOW);
	ft_printf("-->%#x<--\n", head->magic);
	ft_printf(ORANGE);
	ft_printf("%-12s: ", "Prog_name");
	ft_printf(YELLOW);
	ft_printf("-->%s<--\n", head->prog_name);
	ft_printf(ORANGE);
	ft_printf("%-12s: ", "Prog_size");
	ft_printf(LYELLOW);
	ft_printf("-->%d Bytes<-->%#x<\n", head->prog_size, head->prog_size);
	ft_printf(ORANGE);
	ft_printf("%-12s: ", "Comment");
	ft_printf(YELLOW);
	ft_printf("-->%s<--\n", head->comment);
	ft_printf("\n");
}

void		print_hexa(t_labels *lab, header_t *head, t_pars *ops, int opt)
{
	if (opt & I && head)
		print_header(head);
	if (ops)
		ft_get_code(ops, lab, 0, opt);
		ft_printf("\n\n");
}
