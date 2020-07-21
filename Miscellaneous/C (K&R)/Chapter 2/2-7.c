#include <stdio.h>

unsigned invert(unsigned x, int p, int n){
    /* extract the bits */
    unsigned bits = x & (~(~0 << n) << (p - n + 1));
    /* set the n bits of x (starting at position p) to 0 */
    unsigned mask1 = ~((~(~0 << n)) << (p - n + 1));
    x &= mask1;
    /* flip the extracted bits */
    bits = ~bits & (~(~0 << n) << (p - n + 1));
    /* set the bits to original position */
    x |= bits;
    return x;
}

int main(int argc, char const *argv[])
{
    unsigned x = 93;
    int p = 4, n = 3;
    printf("invert = %u", invert(x,p,n));
    return 0;
}
