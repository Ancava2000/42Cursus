int	ft_atoi_base(const char *str, int str_base)
{
    int i;
    int sign;
    int c;
    int res;
    
    i = 0;
    sign = 1;
    c = 0;              // remember the int variable to stored char by char
    res = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while(str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            c = str[i] - '0';                  // convert char to int
        else if (str[i] >= 'a' && str[i] <= 'f')
            c = (str[i] - 'a') + 10;           // remember the "- 'a'"
        else if (str[i] >= 'A' && str[i] <= 'F')
            c = (str[i] - 'A') + 10;
        else
            break;
        res = res * str_base + c;  // res * 10 or 16 + the character (the char converted to int)
        i++;
    }
    return (sign * res);
}

/*
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
    }
    return (0);
}
*/
