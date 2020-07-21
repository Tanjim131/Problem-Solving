#include <stdio.h>

int any(char s1[], char s2[]){
    int i, k;
    int index = -1;
    for(k = 0 ; s2[k] != '\0' ; ++k){
        for(i = 0 ; s1[i] != '\0' ; ++i){
            if(s1[i] == s2[k]){
                index = i;
                break;
            }
        }
        if(index != -1) break;
    }
    return index;
}

int main(int argc, char const *argv[])
{
    char s1[] = "hello";
    char s2[] = "world";
    printf("%d\n", any(s1, s2));
    return 0;
}
