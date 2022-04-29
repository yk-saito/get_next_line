/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:14:00 by ysaito            #+#    #+#             */
/*   Updated: 2020/07/16 11:40:20 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		make_oneline(char *buf_join, char **savestr, \
							char **line, int *ret)
{
	int			len;

	len = 0;
	while (buf_join[len] != '\n' && buf_join[len] != '\0')
	{
		len++;
	}
	if (buf_join[len] == '\n')
	{
		*line = ft_substr(buf_join, 0, len);
		*savestr = ft_strdup(&buf_join[len + 1]);
		*ret = GNL_READ;
	}
	else
	{
		*line = ft_strdup(buf_join);
		*ret = GNL_EOF;
	}
	if (buf_join == NULL || line == NULL)
	{
		*ret = GNL_ERROR;
	}
	free(buf_join);
}

static char		*read_or_savedstr(char **savestr, int fd, int *ret)
{
	char		*buf;

	if (*savestr != NULL)
	{
		buf = *savestr;
		*savestr = NULL;
		*ret = GNL_READ;
	}
	else
	{
		if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		{
			*ret = GNL_ERROR;
			return (NULL);
		}
		*ret = read(fd, buf, BUFFER_SIZE);
		if (*ret < 0)
		{
			free(buf);
			*ret = GNL_ERROR;
			return (NULL);
		}
		buf[*ret] = '\0';
	}
	return (buf);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	static char	*savestr;
	char		*buf;
	char		*buf_join;
	char		*judge_lf;

	buf_join = NULL;
	if (fd == -1 || line == NULL)
		return (GNL_ERROR);
	while (1)
	{
		buf = read_or_savedstr(&savestr, fd, &ret);
		if (buf == NULL)
			return (ret);
		buf_join = buf_join != NULL ? \
		ft_strjoin(buf_join, buf) : ft_strdup(buf);
		if (*(judge_lf = ft_strchr(buf, '\n')) == '\n' || ret == 0)
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	make_oneline(buf_join, &savestr, line, &ret);
	return (ret);
}
