#include <stdio.h>
#include <limits.h>

#pragma GCC target("sse4.2")

unsigned rightrot(unsigned x, int n){
    int leftmostSetBitPosition = __builtin_clz(x) ^ (sizeof(unsigned) * CHAR_BIT - 1); /* not a portable solution */
    int i;
    for(i = 0 ; i < n ; ++i){
        int lsb = x & 1;
        /* printf("position = %d\n", leftmostSetBitPosition); */
        x >>= 1; /* right shifting an unsigned int will always fill the vacated bits with 0 */
        /* put the lsb at left most position */
        x |= lsb << leftmostSetBitPosition;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    unsigned x = 89;
    int n = 7;
    printf("%u\n", rightrot(x,n));
    return 0;
}
