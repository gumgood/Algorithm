#include<cstdio>

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        int chk[26] = {0};
        char in[102] = {0};
        fgets(in,102,stdin);
        for(int i=0;in[i];++i){
            if('A'<=in[i] && in[i]<='Z')
                chk[in[i]-'A'] = 1;
            if('a'<=in[i] && in[i]<='z')
                chk[in[i]-'a'] = 1;
        }
        int ans = 0;
        for(int i=0;i<26;++i)
            ans += chk[i];
        if(ans == 26)
            puts("pangram ");
        else{
            printf("missing ");
            for(int i=0;i<26;++i)
                if(!chk[i]) printf("%c",'a'+i);
            printf("\n");
        }
    }
    return 0;
}
