#include<cstdio>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;

long long in[501][501];
vector<ii> cod;
int dp[501][501]= {1};

int solve(int n,int m){
	int dx[4] = {0,0,-1,1};
	int dy[4] = {-1,1,0,0};
	sort(cod.begin(), cod.end(), [](ii a, ii b){
		return in[a.first][a.second] > in[b.first][b.second];
	});

	for(int i=0; i<cod.size(); ++i){
		int x = cod[i].first;
		int y = cod[i].second; //here
		for(int j=0; j<4; ++j){
			int nx = x + dx[j];
			int ny = y + dy[j]; //next
			if(nx<0 || ny<0 || nx>=n || ny>=m)
				continue;
			if(in[x][y] <= in[nx][ny])
				continue;
			dp[nx][ny] += dp[x][y];
		}
	}
	return dp[n-1][m-1];
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%lld", &in[i][j]);
			cod.push_back(ii(i, j));
		}
	}
	printf("%d",solve(n, m));
	return 0;
}
