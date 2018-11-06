#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, indegree[32001];
vector<int> adj[32001];

vector<int> solve(priority_queue<int>& pq){
    vector<int> ret;
    while(!pq.empty()){
        int here = -pq.top();
        pq.pop();
        for(int i=0; i<adj[here].size(); ++i){
            int there = adj[here][i];
            indegree[there]--;
            if(indegree[there]==0)
                pq.push(-there);
        }
        ret.push_back(here);
    }
    return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        indegree[b]++;
	}

    priority_queue<int> pq;
    for(int i=1; i<=n; ++i)
        if(indegree[i] == 0)
            pq.push(-i);

    vector<int> ans = solve(pq);
    for(int i=0; i<ans.size(); ++i)
        printf("%d ", ans[i]);
    
    return 0;
}
