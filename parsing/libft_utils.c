#include "parsing.h"




char	*ft_strjoin(char  *s1, char  *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;
	int		m=0;

	if (s1 || s2)
	{
        if(s1)
		    len1 = strlen(s1);
        else
            len1 = 0;
        if(s2)
		    len2 = strlen(s2);
        else
            len2 = 0;
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		if(s1){
		while (s1[++i])
			str[i] = s1[i];
		}
		else
		{
			m = 1;
		}
		if(!m)
			free(s1);
		i = -1;
        if(s2)
        {
		    while (s2[++i])
		    {
			    str[len1] = s2[i];
			    len1++;
		    }
        }
		
		str[len1] = '\0';
		return (str);
	}
    
	return (NULL);
}