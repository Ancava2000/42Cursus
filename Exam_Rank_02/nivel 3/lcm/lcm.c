unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int n;

    if (a == 0 || b == 0)
	return (0);
    if (a > b)
        n = a;
    else
        n = b;
    while(1)
    {
        if (n % a == 0 && n % b == 0)
            return (n);
        n++;
    }
} 
/* 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned int a = atoi(argv[1]);
	unsigned int b = atoi(argv[2]);
	printf("%d\n", lcm(a, b));
    return (0);
}
*/
