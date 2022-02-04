#include "ft_printf.h"
#include "libft/libft.h"

int	process_p(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_putstr_fd("0x", 1);
	count += process_hex(n, 'x');
	return (count);
}
