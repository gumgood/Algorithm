#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int n,m;
vector<int> adj[32001];
bool v[32001];
stack<int> s;

void dfs(int x) {
    for (int i = 0;i<adj[x].size();++i)
        if (v[adj[x][i]]==false) {
            v[adj[x][i]] = true;
            dfs(adj[x][i]);
        }
    s.push(x);
}

void solve() {
    for (int i = 1;i<=n;++i)
        if (v[i]==false){
            v[i] = true;
            dfs(i);
        }
    while (!s.empty()) {
        printf("%d ",s.top());
        s.pop();
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 0;i<m;++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
    }
    solve();
    return 0;
}
