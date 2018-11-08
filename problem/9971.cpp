#include<cstdio>
#include<cstring>

char in[201];

char convert(char c){
    int num = c-'A'-5;
    num = (num+26)%26;
    return num + 'A';
}

int main(){
    while(true){
        scanf("%s\n",in);
        if(!strcmp(in,"ENDOFINPUT"))
            break;
        fgets(in,200,stdin);
        for(int i=0;in[i];++i){
            if('A'<=in[i] && in[i]<='Z')
                printf("%c",convert(in[i]));
            else
                printf("%c",in[i]);
        }
        scanf("%s\n",in);
    }
    return 0;
}
