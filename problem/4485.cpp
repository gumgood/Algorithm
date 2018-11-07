#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> ii;

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
const int INF = 1e9;

int dijkstra(const vector<vector<int> >& map){
    int n = map.size();
    vector<vector<int> > dist(n, vector<int>(n,INF));
    dist[0][0] = map[0][0];
    priority_queue<pair<int,ii> > pq;
    pq.push(make_pair(-map[0][0],ii(0,0)));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(dist[x][y] < cost) continue;

        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || (n-1<nx)) continue;
            if(ny<0 || (n-1<ny)) continue;

            int nextCost = cost + map[nx][ny];

            if(dist[nx][ny] > nextCost){
                dist[nx][ny] = nextCost;
                pq.push(make_pair(-nextCost,ii(nx,ny)));
            }
        }
    }
    return dist[n-1][n-1];
}

int main(){
    for(int t=1;;t++){
        int n;
        scanf("%d",&n);
        if(n==0) break;
        vector<vector<int> > map(n, vector<int>(n));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&map[i][j]);
        printf("Problem %d: %d\n",t, dijkstra(map));
    }
    return 0;
}
