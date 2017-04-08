// O(log*n), O(1)
#include<cstdio>

int parent[1000001];

void init(int n){
	for(int i=0; i<=n; ++i)
		parent[i] = i;
}

int Find(int x){
	if(x==parent[x]) return x;
	return parent[x]=Find(parent[x]);
}

void Union(int x, int y){
	parent[Find(y)] = Find(x);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	for(int t, a, b; m--;){
		scanf("%d%d%d", &t, &a, &b);
		if(t) puts(Find(a)==Find(b)?"YES":"NO");
		else Union(a, b);
	}
}
