unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char reverse;
    int i;
    
    reverse = 0;
    i = 8;
    while (i--)
    {
        reverse <<= 1;
        reverse |= octec & 1;
        octet >>= 1;
    }
}
