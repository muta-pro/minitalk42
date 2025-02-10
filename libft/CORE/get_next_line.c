/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:12:28 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/24 00:06:03 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static t_gnl	*get_node(t_gnl **head, int fd)
{
	t_gnl	*node;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = malloc(sizeof(t_gnl));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->buffer = ft_strdup("");
	if (!node->buffer)
	{
		free(node);
		return (NULL);
	}
	node->next = *head;
	*head = node;
	return (node);
}

static void	free_node(t_gnl **head, int fd)
{
	t_gnl	*previous;
	t_gnl	*current;

	previous = NULL;
	current = *head;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous)
				previous->next = current->next;
			else
				*head = current->next;
			free(current->buffer);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

static int	read_into_buf(t_gnl *node)
{
	char	*buffer;
	char	*temp;
	int		char_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	char_read = read(node->fd, buffer, BUFFER_SIZE);
	if (char_read <= 0)
	{
		free(buffer);
		return (char_read);
	}
	buffer[char_read] = '\0';
	temp = join_buffer(node->buffer, buffer);
	free(buffer);
	free(node->buffer);
	node->buffer = temp;
	if (temp)
		return (1);
	else
		return (-1);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	if (!*buffer || !**buffer)
		return (NULL);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = ft_strndup(*buffer, i);
	if (!line)
		return (NULL);
	temp = ft_strdup(*buffer + i);
	free(*buffer);
	*buffer = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head;
	t_gnl			*node;
	char			*line;
	int				res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(&head, fd);
	if (!node)
		return (NULL);
	res = 1;
	while (res > 0 && !ft_strchr(node->buffer, '\n'))
		res = read_into_buf(node);
	if (res == -1)
	{
		free_node(&head, fd);
		return (NULL);
	}
	line = extract_line(&node->buffer);
	if (!line || !node->buffer)
		free_node(&head, fd);
	return (line);
}
