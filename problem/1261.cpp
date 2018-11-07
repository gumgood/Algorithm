#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> ii;

const int INF = 1e9;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

int map[101][101];
int n,m;

int dijkstra(){
    vector<vector<int> > dist(101,vector<int>(101,INF));
    priority_queue<pair<int,ii> > pq;
    pq.push(make_pair(0,ii(1,1)));
    dist[1][1] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(dist[x][y] < cost) continue;

        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<1 || n<nx) continue;
            if(ny<1 || m<ny) continue;

            int nextCost = cost + map[nx][ny];

            if(dist[nx][ny] > nextCost){
                dist[nx][ny] = nextCost;
                pq.push(make_pair(-nextCost, ii(nx,ny)));
            }
        }
    }

    return dist[n][m];
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%1d",&map[i][j]);
    printf("%d",dijkstra());
    return 0;
}
