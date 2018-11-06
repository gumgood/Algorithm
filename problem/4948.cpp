#include<cstdio>

#define _MAX 300000

bool isnp[_MAX] ={true, true};
int cnt[_MAX];

int main(){
    for(long long i = 2; i*i < _MAX; ++i)
        for(long long j = i*i; j < _MAX; j += i)
            isnp[j] = true;
    for(int i=1; i<_MAX; ++i)
        cnt[i] = cnt[i-1] + (!isnp[i]);

    while(true){
        int n;
        scanf("%d", &n);
        if(!n) break;
        printf("%d\n", cnt[2*n] - cnt[n]);
    }
    return 0;
}
