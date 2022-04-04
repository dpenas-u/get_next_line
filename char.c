# include "get_next_line.h"
# include <stdio.h>
void	catchar(void)
{
	static	char	*s;
	char	*str;

	str = "b";

	if (!s)
		s = str;
	else
		s = ft_strjoin(s, str);
	printf("%s\n", s);
}

int	main(void)
{
	catchar();
	catchar();
	catchar();
}
