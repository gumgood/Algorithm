#include<cstdio>

int parent[1001];

void disjoint_set_init(){
	for(int i=0; i<1001; ++i)
		parent[i] = i;
}

int Find(int x){
	if(parent[x]==x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
	parent[Find(x)] = Find(y);
}

int main(){
	disjoint_set_init();
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		Union(x, y);
	}

	bool exist[1001] = {0};
	for(int i=1; i<=n; ++i)
		exist[Find(i)] = 1;
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		ans += exist[i];
	printf("%d", ans);
	return 0;
}
