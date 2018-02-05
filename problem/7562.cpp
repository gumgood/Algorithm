#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;

int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int solve(int l, ii a, ii b){
	vector<vector<bool> > v(l, vector<bool>(l, 0));
	queue<pair<int,ii> > q;
	
	q.push(make_pair(0,a));
	v[a.first][a.second] = 1;
	while(!q.empty()){
		int d = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		
		if(ii(x, y) == b)
			return d;

		for(int i=0; i<8; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0 || ny<0 || nx>=l || ny>=l)
				continue;
			if(!v[nx][ny]){
				v[nx][ny] = 1;
				q.push(make_pair(d+1,ii(nx, ny)));
			}
		}
	}
	return 0;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int l,x1,y1,x2,y2;
		scanf("%d%d%d%d%d", &l, &x1, &y1, &x2, &y2);
		printf("%d\n", solve(l,ii(x1,y1),ii(x2,y2)));
	}
	return 0;
}
