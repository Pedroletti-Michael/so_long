#include "ft_printf.h"
#include "libft/libft.h"

int	process_hex(unsigned long long n, const char c)
{
	int count;

	count = 0;
	if (n > 15)
	{
		count += process_hex(n / 16, c);
		count += process_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			return (ft_putchar_fd(n + '0', 1));
		else
		{
			if (c == 'x')
				return (ft_putchar_fd(n - 10 + 'a', 1));
			else
				return (ft_putchar_fd(n - 10 + 'A', 1));
		}
	}
	return (count);
}
