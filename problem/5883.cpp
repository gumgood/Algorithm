#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n,in[1001];
int check[1000001];
int cnt; // indexing B(i)

int solve(){
    int ret = 0;
    for(int i=1;i<=cnt;++i){
        // ignore i
        int tcnt = 0, lindex = 0; // last index
        for(int j=0;j<n;++j){
            if(in[j] == i)
                continue;
            
            if(in[j] == in[lindex])
                tcnt++;
            else{
                lindex = j;
                tcnt = 1;
            }
            ret = max(ret, tcnt);
        }
    }
    return ret; 
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;++i){
        int t;
        scanf("%d",&t);
        if(check[t]==0)
            check[t] = ++cnt;
        in[i] = check[t];
    }

    printf("%d",solve());

    return 0;
}
