#include<stdio.h>
#include<string.h>

void fanzhuan(char*s){
    int sz = strlen(s);
    for(int i = 0;i<sz;i++){
       s[i] = 'A'+'z'-s[i];
    }
}

int main(){
    char s[] = "abczyAAAAAAZBC";
    fanzhuan(s);
    for(int i =0;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
}