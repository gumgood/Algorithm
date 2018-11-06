#include<cstdio>

const int n = 3;

int a,b,c;

int timeline[101];

int solve(){
    int ret = 0;
    for(int i=0;i<101;++i){
        if(timeline[i]==1)
            ret += a;
        else if(timeline[i]==2)
            ret += 2*b;
        else if(timeline[i]==3)
            ret += 3*c;
    }
    return ret;
}

int main(){
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<n;++i){
        int s, e;
        scanf("%d%d",&s,&e);
        for(int j=s;j<e;++j)
            timeline[j]++;
    }

    printf("%d",solve());

    return 0;
}
