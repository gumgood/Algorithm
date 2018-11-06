#include<cstdio>

int n, cnt[30];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char in[31];
        scanf("%s",in);
        cnt[in[0]-'a']++;
    }

    bool flag = false;
    for(int i=0;i<26;++i)
        if(cnt[i]>=5){
            printf("%c",'a'+i);
            flag = true;
        }

    if(!flag) printf("PREDAJA");

    return 0;
}
