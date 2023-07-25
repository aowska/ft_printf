/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:52:55 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/25 18:57:24 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toaun(size_t i,  unsigned int n1, unsigned int n, char *str)
{
	while (i--)
	{
		str[i] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoaun(unsigned int n)
{
	char		*str;
	unsigned int	n1;
	size_t		i;

	i = 0; 
	n1 = n;
	str = NULL; 
	while (n1 != 0)
	{
		n1 = n1 / 10;
		i++;
	}
	n1 = n;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	return (ft_toaun(i, n1, n, str));
}
