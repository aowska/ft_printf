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

void	ft_to_pointer_hex(size_t i, unsigned long long n1, char **str)
{
	while (i--)
	{
		if(n1 % 16 < 10)
		{
			(*str)[i] = (n1 % 16 + '0');
			n1 = n1 / 16;
		}
		else
		{
			(*str)[i] = ((n1 % 16) - 10 + 'a');
			n1 = n1 / 16;
		}
	}
	return;
}

void	ft_pointer_hex(unsigned long long n,char **str)
{
	
	unsigned long long	n1;
	size_t		i;

	i = 0; 
	n1 = n;
	*str = NULL; 
	while (n1 != 0)
	{
		n1 = n1 / 16;
		i++;
	}
	n1 = n;
	*str = (char *)malloc((i + 1) * sizeof(char));
	if (!*str)
		return ;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	(*str)[i] = '\0';
	ft_to_pointer_hex(i, n1, str);
}

