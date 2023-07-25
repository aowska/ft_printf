#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *word, ...)
{
	va_list	pw;
	va_start(pw, word);
	int i;
	char *value;
	
	i = 0;
	while(*word)
	{
		while (*word != '%' && *word)
		{
			ft_putchar_fd(*word, 1);
			word++;
			i++;
		}
		if(!*word)
			break;
		word++;
		if(*word == 'c')
		{
			word++;
			ft_putchar_fd(va_arg(pw, int),1);
			i++;
		}
		if(*word == 's')
		{
			word++;
			value = va_arg(pw, char *);
			while (*value)
			{
				ft_putchar_fd(*value, 1);
				i++;
				value++;
			}
		}
		if( *word == 'X')
		{
			word++;
			value = ft_pointerhex(va_arg(pw, unsigned long long));
			while (*value)
			{
				ft_putchar_fd(*value, 1);
				i++;
				value++;
			}
		}
		if(*word == 'i' || *word == 'd' )
		{
			word++;
			value = ft_itoa(va_arg(pw, int));
			while (*value)
			{
				ft_putchar_fd(*value, 1);
				i++;
				value++;
			}
		}
		if(*word == 'x')
		{
			word++;
			value = ft_hexlower(va_arg(pw, unsigned long long));
			while (*value)
			{
				ft_putchar_fd(*value, 1);
				i++;
				value++;
			}
		}
		if(*word == 'p')
		{
			word++;
			value = ft_hexlower(va_arg(pw, unsigned long long));
			ft_putchar_fd('0', 1);
			ft_putchar_fd('x', 1);
			i = i + 2;
			while (*value)
			{
				ft_putchar_fd(*value, 1);
				i++;
				value++;
			}
		}
		if(*word == '%')
		{
			word++;
			ft_putchar_fd('%',1);
			i++;
		}
		if(*word == 'u')
		{
			word++;
			value = ft_itoaun(va_arg(pw, unsigned int));
			while (*value)
			{
				ft_putchar_fd(*value, 1);
				i++;
				value++;
			}
		}
				
	}	
	return(i);
} 

int main ()
{
	char * a = "alalal";
	char *value = &a;
	ft_printf("alalla %c %s %p\n", 's', "alalal", value );
	ft_printf("alalla %s \n", "lallala");
	printf("alalla %c %s %p\n", 's', "alalal", value );
	ft_printf(" %p %p ", 0, 0);
	printf(" %p %p ", 0, 0);
	//ft_printf(" NULL %s NULL ", NULL);
	//printf(" NULL %s NULL ", NULL);
	
	//ft_printf("alalla %p \0", value);
	//ft_printf("alalla %i \0", 5);
	//ft_printf("alalla %x \0", 3645);
	//ft_printf("alalla %X \0", 25375);
	//ft_printf("alalla %% \0");
	//ft_printf("alalla %d \0", 1264);
	//ft_printf("alalla %u \0", 126476543);
	
	return(0);
} 


