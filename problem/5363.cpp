#include<cstdio>

int main(){
    int n;
    scanf("%d\n",&n);
    while(n--){
        char in[101];
        fgets(in,100,stdin);
        
        int flag = 0, cnt = 0;
        for(int i=0;cnt<2;++i){
            if(in[i]==' ')
                cnt++;
            if(cnt==2)
                flag = i;
        }
        for(int i=flag+1;in[i];++i){
            if(in[i]=='\n')
                in[i] = ' ';
            printf("%c",in[i]);
        }
        for(int i=0;i<flag;++i)
          printf("%c",in[i]);
        puts("");
    }
    return 0;
}
