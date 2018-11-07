#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> ii;

const int INF = 1e7;


vector<int> dijkstra(const vector<vector<ii> >& adj,int src){
    vector<int> dist(adj.size(), INF);
    priority_queue<ii> pq;
    pq.push(ii(0,src));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i=0;i<adj[here].size();++i){
            int next = adj[here][i].first;
            int newcost = cost + adj[here][i].second;

            if(dist[next] > newcost){
                dist[next] = newcost;
                pq.push(ii(-newcost,next));
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<ii> > adj;
    int n, e;
    scanf("%d%d",&n,&e);
    adj.resize(n+1,vector<ii>());
    for(int i=0;i<e;++i){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(ii(b,c));
        adj[b].push_back(ii(a,c));
    }

    int node1, node2;
    scanf("%d%d",&node1,&node2);
    vector<int> startdist = dijkstra(adj, 1);
    vector<int> node1dist = dijkstra(adj,node1);
    vector<int> node2dist = dijkstra(adj,node2);
    startdist[1] = 0;
    node1dist[node1] = 0;
    node2dist[node2] = 0;

    int ans1 = startdist[node1] + node1dist[node2] + node2dist[n];
    int ans2 = startdist[node2] + node2dist[node1] + node1dist[n];

    if(ans1 >= INF && ans2 >= INF)
        printf("-1");
    else
        printf("%d",min(ans1,ans2));

    return 0;
}
