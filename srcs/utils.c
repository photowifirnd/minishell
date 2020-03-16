#include "../includes/minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*tmp;
	size_t	i;

	if (!str)
		return (NULL);
	if(!(tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * j)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	if (!str || !c)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!str)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- > 0 && str[i] != '\0')
		tmp[i++] = str[start++];
	tmp[i] = '\0';
	return (tmp);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s1[i] != '\0' || s2[i] !='\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (ret);
}
