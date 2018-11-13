#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

typedef pair<int,int> ii;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d%d",&n,&m);
        vector<ii> q(n);
        for(int i=0;i<n;++i){
            scanf("%d",&q[i].first);
            q[i].second = i;
        }
        
        int cnt = 0;
        for(int i=0;i<q.size();++i){
            bool print = true;
            for(int j=i+1;j<q.size();++j)
                if(q[i].first < q[j].first) print = false;
            if(print==false)
                q.push_back(q[i]);
            else{
                cnt++;
                if(q[i].second == m)
                    printf("%d\n",cnt);
            }
        }
    }
    return 0;
}

