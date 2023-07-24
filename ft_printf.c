#include <stdarg.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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
			ft_putchar_fd(va_arg(pw, int),1);
			i++;
		}
		if(*word == 's')
		{
			value = va_arg(pw, char *);
			while (*value)
			{
				ft_putchar_fd(*value, 1);
				i++;
				value++;
			}
		}
		return(i);
	}
} 

int main ()
{
	ft_printf("alalla %c \0", 's');
	ft_printf("alalla %s \0", "lallala");
}


