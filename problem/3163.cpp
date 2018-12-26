#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef pair<int,int> ii;

int n, l, k, a[100001], p[100001];

int solve(){
    priority_queue<int, vector<int>, greater<int> > left, right;
    for(int i=0;i<n;++i)
        if(a[i]<0) left.push(p[i]);
        else right.push(l-p[i]);
    left.push(2e9);
    right.push(2e9);

    int ret, i = 0, j = n-1;
    while(k--){
        if(left.top() < right.top()){
            left.pop();
            ret = a[i], i++;
        }else if(left.top() > right.top()){
            right.pop();
            ret = a[j], j--;
        }else{
            if(a[i] < a[j]){
                left.pop();
                ret = a[i], i++;
            }else{
                right.pop();
                ret = a[j], j--;
            }
        }
    }

    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&l,&k);
        for(int i=0;i<n;++i)
            scanf("%d%d",p+i,a+i);
        printf("%d\n",solve());
    }
    return 0;
}
