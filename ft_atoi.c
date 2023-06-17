/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:41:27 by awalter           #+#    #+#             */
/*   Updated: 2023/01/23 09:41:29 by awalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xpm_parser.h"

int	ft_atoi(char *nptr)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (nptr[i])
	{
		if ('0' < nptr[i] && nptr[i] < '9')
			n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n);
}