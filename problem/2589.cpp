#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int dx[] = { 0,0,-1,1 };
int dy[] ={ -1,1,0,0 };

int l, w;
int map[50][50];
int v[50][50];

int fx, fy, fd;

void bfs(int x, int y, int vflag) {
	queue<iii> q;
	q.push(iii(ii(x, y),0));
	while(!q.empty()) {
		int hx = q.front().first.first;
		int hy = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(d > fd)
			fd = d, fx = hx, fy = hy;
		for(int i=0; i<4; ++i) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if(!(0<=nx && nx <l)) continue;
			if(!(0<=ny && ny <w)) continue;
			if(map[nx][ny]==0) continue;
			if(v[nx][ny] == vflag) continue;
			v[nx][ny] = vflag;
			q.push(iii(ii(nx, ny), d+1));
		}
	}
}

int solve() {
	int ret = 0;
	for(int i=0; i<l; ++i) {
		for(int j=0; j<w; ++j) {
			fd = 0;
			bfs(i, j, 1);
			if(fd) {
				fd = 0;
				bfs(fx, fy, 2);
				ret = max(ret, fd);
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &l, &w);
	for(int i=0; i<l; ++i) {
		char in[51];
		scanf("%s", in);
		for(int j=0;j<w;++j)
			if(in[j]=='L')
				map[i][j] = 1;
	}
	printf("%d", solve());
	return 0;
}
