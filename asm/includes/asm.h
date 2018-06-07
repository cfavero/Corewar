/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:36:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 16:40:56 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "ft_printf.h"
# include "op.h"

typedef struct		s_pars
{
	char			*line;
	char			*label;
	char			*op_name;
	char			*value[4];
	char			*line_code;
	int				type[3];
	int				op_code;
	int				size_code;
	int				position;
	struct s_pars	*next;
}					t_pars;
typedef struct		s_labels
{
	int				max_size;
	struct s_pars	*lst;
	struct s_labels	*next;
}					t_labels;

/*
**ERRORS
*/
void				ft_error_head_name(char *line, char *name);
void				ft_exit(char *message);
void				ft_print_lst(t_pars *lst);
void				ft_error_values(char *value, int code);
/*
**PARSING
*/
void				ft_add_lst(t_pars **lst, t_pars *new);
t_pars				*ft_check_line(char *line, t_pars *lst, header_t **head);
int					ft_check_opname_type(t_pars *l, int i);
char				*ft_comment_delete(char *line);
int					ft_create_tab(char *line);
t_pars				*ft_get_info(int fd, t_labels **save, header_t **head);
t_pars				*ft_get_label(char *line, t_pars *lst);
t_pars				*ft_get_op_name(char *line, t_pars *lst);
t_pars				*ft_get_size_code(t_pars *lst, int i, int tot_size);
t_pars				*ft_get_type(char *line, t_pars *lst);
int					ft_head_com(char *line, header_t **head);
int					ft_head_name(char *line, header_t **head);
t_pars				*ft_init_lst(t_pars *lst, char *line);
t_pars				*ft_parsing(t_pars *lst, t_pars *tmp);
int					ft_total_size_code(t_pars *lst, int tot_size);
/*
**FILE CREATION
*/
int					create_file(char *asm_file, int fd, header_t *head,\
	t_pars *ops);
char				*ft_get_filename(char *name);
void				ft_write_bits(unsigned char octet, int size, int fd);
void				write_commands(int fd, t_pars *lst);
void				write_header(int fd, header_t *head);


#endif
