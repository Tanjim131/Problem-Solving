#include <stdio.h>

int lower(int c){
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}

int main(int argc, char const *argv[])
{
    printf("%c\n", lower('B'));
    return 0;
}
