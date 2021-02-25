/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:16:24 by magostin          #+#    #+#             */
/*   Updated: 2021/02/25 12:13:38 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
int		ft_strlen(char *str);
ssize_t	ft_write(int fd, const void *buf, size_t count);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

int		main(void)
{

	char *test = ft_strdup(NULL);
	printf("|%s|\n", test);
	//free(test);
	return (1);
}