#include<cstdio>
#include<vector>
using namespace std;

// e[i] : 'vertex i' to 'other vertex'
vector<int> e[500001]; 
bool v[1001];

void dfs(int here){
	v[here] = 1;
	for(int i=0; i<e[here].size(); ++i){
		int next = e[here][i];
		if(!v[next]) dfs(next);
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	int cnt = 0;
	for(int i=1; i<=n; ++i)
		if(!v[i])
			dfs(i), cnt++;
	printf("%d", cnt);
	return 0;
}
