unsigned char	swap_bits(unsigned char octet)
{
    return (octet >> 4 | octet << 4);
    //return ((octet & 15) << 4 | (octect & 240) >> 4);
    // 15 == 00001111 and 240 == 11110000
}
