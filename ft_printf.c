/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:32:40 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/30 23:32:42 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	get_value(const char *word, va_list pw, char **v)
{
	if(*word == 'c')
		ft_char(va_arg(pw, int ), v);
	if(*word == 's')
		ft_string(va_arg(pw, char *), v);
	if(*word == 'X')
		ft_upper_hex(va_arg(pw, unsigned long long), v);
	if(*word == 'i' || *word == 'd' )
		ft_itoa_dec(va_arg(pw, int), v);
	if(*word == 'x')
		ft_lower_hex(va_arg(pw, unsigned long long), v);
	if(*word == 'p')
		ft_pointer_hex(va_arg(pw, unsigned long long), v);
	if(*word == '%')
		ft_char('%', v);
	if(*word == 'u')
		ft_itoa_unsign(va_arg(pw, unsigned int), v);
}

size_t	ft_printf(const char *word, ...)
{
	va_list	pw;
	va_start(pw, word);
	size_t	i;
	char	*value;
	
	i = 0;
	value = 0;
	while(*word)
	{
		if(*word != '%')
		{
			//ft_putchar_fd(*word, 1);
			ft_char_word(*word, &value);
		}
		else
		{
			word++;
			get_value(word, pw, &value);
			//ft_putstr_fd(value, 1);
			//i += ft_strlen(value);
			//free(value);
		}
		ft_putstr_fd(value, 1);
		i += ft_strlen(value);
		free(value);
		word++;	
	}	
	return(i);
	
} 

/*int main ()
{
	char *a = "11111";
	char *value = a;
	//ft_printf("alalla %c %s %p\n", 's', "alalal", value );
	//ft_printf("alalla %s \n", "lallala");
	//printf("alalla %c %s %p\n", 's', "alalal", value );
	//ft_printf(" %p %p ", 0, 0);
	//printf(" %p %p ", 0, 0);
	//ft_printf(" NULL %s NULL ", NULL);
	//printf(" NULL %s NULL ", NULL);
	//ft_printf("%c", '0');
	//printf("%c", '0');
	
	//ft_printf("alalla %s \0", a );
	//ft_printf("alalla %c \0", 'd');
	//ft_printf("alalla %x \0", 3645);
	//ft_printf("alalla %X \0", 25375);
	//ft_printf("alalla %% \0");
	//ft_printf("alalla %d \0", 1264);
	//ft_printf("alalla %u \0", 126476543);
	
	return(0);
}
*/

