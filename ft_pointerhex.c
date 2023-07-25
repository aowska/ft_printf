/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinterhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:51 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/24 21:28:54 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_toahex(size_t i, unsigned long long n1, char *str)
{
	while (i--)
	{
		if(n1 % 16 < 10)
		{
			str[i] = (n1 % 16 + '0');
			n1 = n1 / 16;
		}
		else
		{
			str[i] = ((n1 % 16) - 10 + 'A');
			n1 = n1 / 16;
		}
	}
	return (str);
}

char	*ft_pointerhex(unsigned long long n)
{
	char		*str;
	unsigned long long	n1;
	size_t		i;

	i = 0; 
	n1 = n;
	str = NULL; 
	while (n1 != 0)
	{
		n1 = n1 / 16;
		i++;
	}
	n1 = n;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	return (ft_toahex(i, n1, str));
}

