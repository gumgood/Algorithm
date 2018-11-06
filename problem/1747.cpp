#include<cstdio>

const int MAX = 11111111;

bool nprime[MAX] = {true,true};

bool check(int n){
    int revn = 0;
    for(int t=n; t; t/=10)
        revn = revn*10 + t%10;
    return n == revn;
}

int solve(int n){
    for(int i=n;i<MAX;++i)
        if(!nprime[i] && check(i))
            return i;
    return 0; // don't care
}

int main(){
    for(long long i=2;i<MAX;++i)
        for(long long j=i*i;j<MAX;j+=i)
            nprime[j] = true;

    int n;
    scanf("%d",&n);
    printf("%d",solve(n));

    return 0;
}
