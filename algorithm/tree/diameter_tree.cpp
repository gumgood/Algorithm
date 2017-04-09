// O(n)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii;
vector<vector<ii> > t;

bool visited[10001];

ii far(int n){ // furthermost node from node n
	visited[n] = true;

	ii ret(n, 0); // (node,cost);
	for(int i=0; i<t[n].size(); ++i){
		int next = t[n][i].first;
		int cost = t[n][i].second;
		if(visited[next] == true)
			continue;
		ii child = far(next);
		if(ret.second < child.second + cost)
			ret = ii(child.first, child.second + cost);
	}
	return ret;
}

int diameter_tree(int n){
	fill(visited, visited+n+1, false);
	ii u = far(1); // 1:root
	fill(visited, visited+n+1, false);
	ii v = far(u.first);
	return v.second;
}

int main(){
	int n; scanf("%d", &n);
	t.resize(n+1);
	for(int i=0; i<n-1; ++i){
		int p, c, cost;
		scanf("%d%d%d", &p, &c, &cost);
		t[p].push_back(ii(c, cost));
		t[c].push_back(ii(p, cost));
	}
	printf("%d", diameter_tree(n));
}
