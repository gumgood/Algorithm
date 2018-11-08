#include<cstdio>
#include<cstring>

char in[201];
char map[201][201];

int main(){
    while(true){
        int n;
        scanf("%d",&n);
        if(!n) break;
        scanf("%s",in);

        int m = strlen(in)/n;
        int k = 0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(i%2) map[i][n-j-1] = in[k++];
                else map[i][j] = in[k++];
        for(int j=0;j<n;++j)
            for(int i=0;i<m;++i)
                printf("%c",map[i][j]);
        puts("");
    }
    return 0;
}
