/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:42:24 by naali             #+#    #+#             */
/*   Updated: 2019/02/18 14:27:03 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "test.h"

void	*ft_putchar(void *c)
{
	char	a = '\n';
	int		*b = (int*)c;
	int		i;

	i = 0;
	while (i < 5)
	{
		*b = *b + 40000;
		i++;
	}
	printf("%d\n", *b);
//	write(1, &a, 1);
	return ((void*)b);
}

int		main(void)
{
	unsigned long	test[5];
	int				*c;
	int				b = 64;
	int				ret;
	int				i;

	c = &b;
	i = 0;
	while (i < 5)
	{
		ret = pthread_create(&(test[i]), NULL, &ft_putchar, (void*)c);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		printf("pthread_join = %d\n", pthread_join(test[i], NULL));
		i++;
	}
	printf("b = %d\n", b);
	return (0);
}
