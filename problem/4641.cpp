#include<cstdio>

int main(){
    while(true){
        int in[15] = {0};
        bool is[201] = {0};

        scanf("%d",in);
        if(in[0] == -1) break;
        
        is[in[0]] = true;

        for(int i=1;;i++){
            scanf("%d",in+i);
            if(in[i] == 0) break;
            is[in[i]] = true;
        }

        int ans = 0;
        for(int i=0;i<15;++i)
            if(is[in[i]*2]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
