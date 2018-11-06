#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX_V = 1001;
const int INF = 1e9;

vector<vector<pair<int,int> > > adj;
vector<vector<pair<int,int> > > revadj;

vector<int> dijkstra(const vector<vector<pair<int,int> > >& adj, int src){
    vector<int> dist(adj.size(),INF);
    dist[src] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i=0;i<adj[here].size();++i){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }
    return dist;
}

int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    adj.resize(n+1, vector<pair<int,int> >());
    revadj.resize(n+1, vector<pair<int,int> >());
    for(int i=0;i<m;++i){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        adj[a].push_back(make_pair(b,d));
        revadj[b].push_back(make_pair(a,d));
    }

    vector<int> dist = dijkstra(adj,x);
    vector<int> revdist = dijkstra(revadj,x);
    int ans = 0;
    for(int i=1;i<=n;++i)
        if(dist[i]!=INF && revdist[i]!=INF)
            ans = max(ans,dist[i] + revdist[i]);
    printf("%d",ans);
    return 0;
}
