#include<cstdio>
#include<algorithm>
using namespace std;

int solve(int n){
    int cnt2 = 0, cnt5 = 0;
    for(int i=2;i<=n;i*=2)
        cnt2 += n/i;
    for(int i=5;i<=n;i*=5)
        cnt5 += n/i;
    return min(cnt2,cnt5);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",solve(n));
    }
    return 0;
}
