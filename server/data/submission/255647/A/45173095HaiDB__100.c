#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[15000], str2[15000];
    gets(str);
    int j=0;
    for(int i=0; i< strlen(str); i++){
        if(str[i] != str[i+1])
            str2[j++] = str[i];
    }
    str2[j] = '\0';
    printf("%s", str2);
    return 0;
}
