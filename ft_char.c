/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:51:52 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/30 18:51:54 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void ft_char(int c, char **str)
{
	*str = (char *)malloc((2) * sizeof(char));
	if (!*str)
		return;
	else
	{
		(*str)[0] = c;
		(*str)[1] = '\0';
	}
	return;
}
