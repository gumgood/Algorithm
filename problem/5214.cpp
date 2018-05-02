#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;

int n, m, k;

vector<int> adj[101001];
bool v[101001];

int solve() {
	queue<ii> q;
	q.push(ii(1, 0));
	v[1] = true;
	while(!q.empty()) {
		int here = q.front().first;
		int depth = q.front().second;
		q.pop();
		if(here == n) return depth/2+1;
		for(int i=0; i<adj[here].size(); ++i) {
			int next = adj[here][i];
			if(v[next]) continue;
			q.push(ii(next, depth+1));
			v[next] = true;
		}
	}
	return -1;
}

int main() {
	scanf("%d%d%d", &n, &k, &m);
	// let tube = n + 0,1,2,..
	for(int tube=1; tube<=m; ++tube) {
		for(int i=0; i<k; ++i) {
			int t; scanf("%d", &t);
			adj[n+tube].push_back(t);
			adj[t].push_back(n+tube);
		}
	}
	printf("%d", solve());
	return 0;
}
