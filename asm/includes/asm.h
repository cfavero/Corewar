/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:36:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 20:55:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H
# include "ft_printf.h"
# include "op.h"

typedef struct		s_pars
{
	char			*line;
	char			*label;
	char			*comment;
	char			*op_name;
	char			*param;
	char			*value[4];
	char			*line_code;
	int				type[3];
	int				op_code;
	int				size_code;
	struct s_pars	*next;
}					t_pars;


t_pars		*ft_get_info(int fd, char *line, header_t **head);
t_pars		*ft_parsing(t_pars *lst);
t_pars		*ft_check_line(char *line, t_pars *lst, header_t **head);
char		*ft_comment_delete(char *line);
t_pars		*ft_init_lst(t_pars *lst, char *line);
void		ft_add_lst(t_pars **lst, t_pars *new);
int			ft_create_tab(char *line);
t_pars		*ft_get_label(char *line, t_pars *lst);
t_pars		*ft_get_op_name(char *line, t_pars *lst);
t_pars		*ft_get_type(char *line, t_pars *lst);
t_pars		*ft_get_size_code(char *line, t_pars *lst);
int			ft_total_size_code(char *line, t_pars *lst);
int			ft_check_opname_type(t_pars *l, int i);
int			ft_head_name(char *line, header_t **head);
int			ft_head_com(char *line, header_t **head);
void		ft_error_head_name(char *line, char *name);
void		ft_exit(char *message);

#endif
