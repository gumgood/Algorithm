// O(ElogV)
// https://www.acmicpc.net/problem/1922
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > g;
int parent[1001];

int Find(int x){
	if(x==parent[x]) return x;
	return parent[x]=Find(parent[x]);
}

void Union(int x, int y){
	parent[Find(x)]=Find(y);
}

long long kruskal(int v, int e){
	long long ret = 0;
	for(int i=0; i<=v; ++i)
		parent[i] = i;
	sort(g.begin(), g.end());
	for(int i=0; i<e; ++i){
		int u = g[i].second.first;
		int v = g[i].second.second;
		if(Find(u)==Find(v)) continue;
		Union(u, v);
		ret += g[i].first;
	}
	return ret;
}

int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int a, b, c, i=0; i<m; ++i){
		scanf("%d%d%d", &a, &b, &c);
		g.push_back(make_pair(c, make_pair(a, b)));
	}
	printf("%lld", kruskal(n, m));
}
