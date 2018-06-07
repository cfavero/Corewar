/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 15:27:06 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void		write_commands(int fd, t_pars *lst)
{
	int		i = 3;
	int		nb;

	nb = 0;
	if (!lst)
		ft_exit("Where is my list to write with");
	write(fd, &lst->op_code, 1);
	ft_printf("%d\n", lst->value[0]);
	ft_printf("%d\n", lst->value[1]);
	ft_printf("%d\n", lst->value[2]);
	write(fd, &lst->value[0], 1);
	write(fd, &lst->value[1], 1);
	write(fd, &lst->value[2], 1);
		//nb &= lst->type[i];
	ft_printf("NB test = %d\n", nb);
	//if (type +2 get the size of commands to write down)
	//Then get Which type and see write IND_SIZE or DIRECT_SIZE

}
