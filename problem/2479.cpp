#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int code[1001][30];
bool adj[1001][1001];
int backtrack[1001];

bool bfs(int n, int s,int e){
    queue<int> q;
    bool v[1001] ={0};
    q.push(s);
    v[s] = true;
    backtrack[s] = 0;
    while(!q.empty()){
        int here = q.front();
        q.pop();

        if(here == e) return true;

        for(int there=1;there<=n;++there){
            if(!adj[here][there] || v[there])
                continue;
            q.push(there);
            v[there] = true;
            backtrack[there] = here;
        }
    }
    return false;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        for(int j=0;j<k;++j)
            scanf("%1d",&code[i][j]);

    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j){
            int cnt = 0;
            for(int l=0;l<k;++l)
                cnt += (code[i][l] != code[j][l]);
            adj[i][j] = adj[j][i] = (cnt==1);
        }

    int s, e;
    scanf("%d%d",&s,&e);

    if(!bfs(n,s,e))
        printf("-1");
    else{
        vector<int> stack;
        for(int i=e;i;i=backtrack[i])
            stack.push_back(i);
        for(int i=stack.size()-1;i>=0;--i)
            printf("%d ",stack[i]);
    }

    return 0;
}
