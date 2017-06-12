#include<cstdio>

bool chk[3000][3000];

void solve(int x,int y,int n){
	if(n==1) chk[x][y] = true;
	else{
		int m = n/3;
		for(int i=x; i<x+n; i+=m){
			for(int j=y; j<y+n; j+=m){
				if(i==x+m&&j==y+m) continue;
				chk[i][j] = true;
				solve(i, j, m);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	solve(0,0,n);
	for(int i=0; i<n; ++i, puts(""))
		for(int j=0; j<n; ++j)
			printf("%c", chk[i][j]?'*':' ');
	return 0;
}
