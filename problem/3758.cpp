#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int score[101][101] = {0};
		int number[101] = {0};
		int submit[101] = {0};

		int n, k, t, m;
		scanf("%d%d%d%d", &n, &k, &t, &m);
		for(int ii=0; ii<m; ++ii){
			int i, j, s;
			scanf("%d%d%d", &i, &j, &s);
			score[i][j] = max(score[i][j], s);
			number[i]++;
			submit[i] = ii;
		}
		// total score, count, last time, team index
		pair<ii,ii> team[101];
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=k; ++j)
				team[i].first.first -= score[i][j];
			team[i].first.second = number[i];
			team[i].second.first = submit[i];
			team[i].second.second = i;
		}
		sort(team+1, team+n+1);
		
		int ans;
		for(int i=1; i<=n; ++i)
			if(team[i].second.second == t)
				ans = i;
		printf("%d\n", ans);
	}
}
