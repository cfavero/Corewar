/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/09 18:26:28 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				byte_size(int w)
{
	int			bsize;

	bsize = 0;
	if (w <= 0x7F)
		bsize = 1;
	else if (w > 0x7F && w <= 0x7FF)
		bsize = 2;
	else if (w > 0x7FF && w <= 0xFFFF)
		bsize = 3;
	else if (w > 0xFFFF && w <= 0x10FFFF)
		bsize = 4;
	return (bsize);
}

void		ft_print_params(t_pars *lst, int fd, int k, int bytes)
{
	int tmp;
	int j;

	j = 0;
	while (k < 3 && lst->value[k])
	{
		tmp = ft_atoll(lst->value[k]);
		if (lst->type[k] == 1)
			write(fd, &tmp, 1);
		else if (lst->type[k] == 2 && lst->dir_size == 4)
		{
			bytes = byte_size(tmp);
			write(fd, &j, 4 - bytes);
			write(fd, &tmp, bytes);
		}
		else if (lst->type[k] == 3 || lst->type[k] == 2)
		{
			bytes = byte_size(tmp);
			write(fd, &j, 2 - bytes);
			write(fd, &tmp, bytes);
		}
		k++;
	}
}

void	ft_write_bits(unsigned char octet, int size, int fd)
{
	int oct;

	oct = octet;

	if (size)
	{
		ft_write_bits(octet >> 1, size - 1, fd);
		ft_putchar_fd((oct & 1), fd);
	}
}

void		write_header(int fd, header_t *head)
{
	int		len;

	len = ft_strlen(head->prog_name);
	write(fd, head->prog_name, len);
	ft_write_bits(0, PROG_NAME_LENGTH - len, fd);
	len = ft_strlen(head->comment);
	write(fd, head->comment, len);
	ft_write_bits(0, COMMENT_LENGTH - len, fd);
}
