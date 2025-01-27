char	*ft_strrev(char *str)
{
    int i;
    int len;
    char temp;
    
    i = 0;
    len = 0;
    while (str[len])
        len++;
    len -= 1;
    while (i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    return (str);
}
