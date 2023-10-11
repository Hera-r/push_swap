#include <stdio.h>
#include <stdlib.h>



int	len_dup(char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != ' ')
	i++;
	return (i);
}

char	*strdupx(char *str)
{
	char	*str_buffer;
	int		size;
	int		i;
	
	i = 0;
	size = len_dup(str);
	str_buffer = malloc((size + 1) * sizeof(char));
	if (str_buffer == NULL)
		return (NULL);
	while (str[i] && str[i] != ' ')
	{
		str_buffer[i] = str[i];
		i++;
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}




