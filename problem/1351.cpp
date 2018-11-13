#include<cstdio>
#include<map>
using namespace std;

typedef long long ll;

ll n, p, q;
map<ll, ll> dp;

ll solve(ll i){
    if(dp.find(i) != dp.end())
        return dp[i];

    if(i==0) return dp[i] = 1;
    return dp[i] = solve(i/p) + solve(i/q);
}

int main(){
    scanf("%lld%lld%lld",&n,&p,&q);
    printf("%lld",solve(n));
    return 0;
}
