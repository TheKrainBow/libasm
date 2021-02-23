/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:16:24 by magostin          #+#    #+#             */
/*   Updated: 2021/02/23 16:13:58 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
int		ft_strlen(char *str);
ssize_t	ft_write(int fd, const void *buf, size_t count);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;

	size = 0;
	while (s1[size])
		size++;
	if (!(dest = malloc((size + 1) * sizeof(char))))
		return (0);
	size = 0;
	while (s1[size])
	{
		dest[size] = s1[size];
		size++;
	}
	dest[size] = 0;
	return (&dest[0]);
}

int		main(void)
{
	char		buffer[100];

	STRLEN("test")
	WRITE("test", 4L)
	STRCMP("tortyrtto", "totpbar")
	CPY("test")
	return (1);
}