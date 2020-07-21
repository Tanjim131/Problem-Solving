#include <stdio.h>

void squeeze(char s1[], char s2[]){
    int i, j, k;
    for(k = 0 ; s2[k] != '\0' ; ++k){
        j = 0;
        for(i = 0 ; s1[i] != '\0' ; ++i){
            if(s1[i] != s2[k]){
                s1[j++] = s1[i];
            }
        }
        s1[j] = '\0';
    }
}

int main(int argc, char const *argv[])
{
    char s1[] = "hello";
    char s2[] = "world";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}
