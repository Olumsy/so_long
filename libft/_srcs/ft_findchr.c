
int	ft_findchr(const char *str, int c)
{
	int				i;
	char			*str;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
