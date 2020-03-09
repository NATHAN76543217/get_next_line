/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:27:07 by nlecaill          #+#    #+#             */
/*   Updated: 2020/02/21 17:56:42 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	char 	*line;
	int		fd;
	int i = 0;

	fd = open("file.txt", O_RDONLY);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	if (!line)
		printf("NULL\n");
	while (i < 10)
	{
		printf("|%d| ", line[i]);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*actu;
	int				result;

	if (read(fd, O_RDONLY, 0) < 0)
		return (-1);
	if (!(actu = init_list(&lst, lst, fd)))
		return (-1);
	*line = 0;
	if (actu->buf[0] == '\n')
		ft_memmove(actu->buf, actu->buf + 1, ft_strlen(actu->buf));
	result = ft_reading(fd, line, &actu, 0);
	if (result == 0)
		lst_delone(&lst, actu);
	return (result);
}

int		ft_reading(int fd, char **line, t_list **actu, int end)
{
	int		i;
	char	*tmp;

	i = 1;
	while ((end = ft_strchr((*actu)->buf, '\n')) == -1 && i > 0)
	{
		if (!(*line = ft_strjoin(*line, (*actu)->buf)))
			return (-1);
		if ((i = read(fd, (*actu)->buf, BUFFER_SIZE)) < 0)
			return (-1);
		(*actu)->buf[i] = '\0';
	}
	if (i == 0)
		return (0);
	if (!(tmp = ft_substr((*actu)->buf, 0, end)))
		return (-1);
	if (!(*line = ft_strjoin(*line, tmp)))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	ft_strlcpy((*actu)->buf, (*actu)->buf + end,
			(ft_strlen((*actu)->buf) - end) + 1);
	return (1);
}

void	lst_delone(t_list **lst, t_list *actu)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp == actu)
	{
		*lst = actu->next;
		free(actu->buf);
		free(actu);
		return ;
	}
	while (tmp->next != actu)
		tmp = tmp->next;
	tmp->next = actu->next;
	free(actu->buf);
	free(actu);
}

t_list	*init_list(t_list **lst_start, t_list *lst, int fd)
{
	t_list *new;

	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	if (!(new->buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	new->buf[0] = '\0';
	if (new->buf == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = *lst_start;
	*lst_start = new;
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned long	i;

	i = 0;
	if (s == NULL)
		return (ft_strjoin("", ""));
	if (ft_strlen(s) < start)
		return (ft_strjoin("", ""));
	if (!(sub = malloc(sizeof(char) * len + 1)))
		return (0);
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
