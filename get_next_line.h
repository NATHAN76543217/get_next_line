/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nlecaill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/31 16:46:40 by nlecaill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 17:09:10 by nlecaill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char	*buf;
	int		fd;
	void	*next;

}				t_list;
t_list			*fd_is_in(t_list *lst, int file_descriptor);
t_list			*init_list(t_list **lst_start, t_list *lst, int fd);
void			lst_delone(t_list **lst, t_list *actu);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);
int				ft_reading(int fd, char	**line, t_list **actu, int end);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, const char *s2);
char			*ft_substr(const char *s, unsigned int start, size_t len);
#endif
