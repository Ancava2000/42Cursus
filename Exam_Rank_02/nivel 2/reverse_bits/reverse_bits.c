unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char reverse;
    int i;
    
    reverse = 0;
    i = 8;
    while (i--)
    {
        reverse = reverse << 1 | (octet & 1);
        octet >>= 1;
    }
    return (reverse);
}
