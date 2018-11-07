#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int in[3001];
bool exist[2000001];

long long solve(){
    long long ret = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            long long diff = in[j] - in[i];
            if(exist[in[j]+diff]){
                long long sum = 0;
                for(long long k=in[i];exist[k];k+=diff)
                    sum += k;
                ret = max(ret, sum);
            }
        }
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",in+i);
        exist[in[i]] = true;
    }
    printf("%lld",solve());
    return 0;
}
