#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y){
    /* set the n bits of x (starting at position p) to 0 */
    unsigned mask1 = ~((~(~0 << n)) << (p - n + 1));
    x &= mask1;
    /* extract the rightmost n bits of y */
    unsigned mask2 = ~(~0 << n);
    unsigned bits = y & mask2;
    /* set the bits */
    x |= bits << (p - n + 1);
    return x;
}

int main(int argc, char const *argv[])
{
    unsigned x = 89, y = 49;
    int p = 4, n = 3;
    printf("%u\n", setbits(x,p,n,y));
    return 0;
}
