/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:09:32 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/24 20:09:34 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar_fd(char s, int fd);
char	*ft_itoa(int n);
char	*ft_hexlower(unsigned long long n);
char	*ft_pointerhex(unsigned long long n);
char    *ft_itoaun(unsigned int n);
int	ft_printf(const char *word, ...);


#endif
