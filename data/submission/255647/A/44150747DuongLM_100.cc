#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[]){
    char s[200000];
    char result[200000];
    
    char ch;
    int idx = 0;
    while((ch = getchar()) != '\n' && ch != EOF){
        s[idx] = ch;
        idx++;
    }

    int length = strlen(s);
    idx = 1;
    result[0] = s[0];
    for(int i = 1; i < length; i++){
        if(s[i] != s[i - 1]){
            result[idx] = s[i];
            idx++;
        }
    }
    printf("%s\n", result);
    return 0;
}
