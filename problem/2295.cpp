#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int n;
ll u[1001];

ll solve(){
    // x + y = k - z
    vector<ll> left; // x+y
    vector<pair<ll,ll> > right; // k-z, k

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            left.push_back(u[i]+u[j]);
            right.push_back(make_pair(u[i]-u[j],u[i]));
        }
    }
    
    // find ret = (k-z)
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    ll ret = 0;
    int i=0, j=0;
    while(i<left.size() && j<right.size()){
        if(left[i] > right[j].first)
            j++;
        else if(left[i] < right[j].first)
            i++;
        else{
            ret = max(ret,right[j].second); // k
            i++, j++;
        }
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%lld",u+i);

    printf("%lld",solve());

    return 0;
}
