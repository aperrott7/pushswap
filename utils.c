#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "lib.h"

static char	*dfltcase(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	c;

	i = 0;
	c = (strlen(s) - (size_t) start);
	if (strlen(s) - start > len)
		sub = (char *) malloc((sizeof(char) * (len + 1)));
	else
		sub = (char *) malloc(sizeof(char) * ((strlen(s) - start) + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && i < c)
	{
		sub[i] = s[(size_t) start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (strlen(s) > (size_t) start)
		return (dfltcase(s, start, len));
	else
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
}


static unsigned int	count_words(const char *str, char div)
{
	unsigned int	i;
	unsigned int	count;
	short int		toggle;

	i = 0;
	count = 0;
	toggle = 0;
	while (str[i])
	{
		if (str[i] != div && toggle == 0)
		{
			count++;
			toggle = 1;
		}
		if (str[i] == div)
			toggle = 0;
		i++;
	}
	return (count);
}

char	**create_list(char **list, const char *s, char c)
{
	unsigned int	scan;
	unsigned int	i;
	unsigned int	list_index;

	i = 0;
	scan = 0;
	list_index = 0;
	while (s[scan])
	{
		if (s[scan] != c)
		{
			while (s[scan + i] && s[scan + i] != c)
				i++;
			list[list_index] = ft_substr(s, scan, i);
			list_index++;
			scan += i;
			i = 0;
		}
		else
			scan++;
	}
	list[list_index] = NULL;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (NULL);
	splitted = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	return (create_list(splitted, s, c));
}


int	ft_isdigit(char c)
{
	if ((c >= 48 && c <= 57) || c == 32)
		return (1);
	else
		return (0);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*united;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	united = (char *) malloc ((sizeof(char))
			* (strlen(s1) + strlen(s2) + 2));
	if (united == NULL)
		return (NULL);
	while (s1[j] != '\0')
		united[i++] = s1[j++];
    united[i++] = 32;
	j = 0;
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[i] = '\0';
	return (united);
}
