unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned n;
    
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
