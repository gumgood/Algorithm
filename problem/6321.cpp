#include<cstdio>

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        char str[51];
        scanf("%s",str);
        printf("String #%d\n",tc);
        for(int i=0;str[i];++i)
            if(str[i]=='Z')
                printf("A");
            else
                printf("%c",str[i]+1);
        printf("\n\n");
    }
    return 0;
}
