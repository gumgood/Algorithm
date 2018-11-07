#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> ii;

int n, m;
vector<pair<int,ii> > edge;

int parent[200001];
void _init(int n){
    for(int i=0;i<=n;++i)
        parent[i] = i;
}
int _find(int x){
    if(x==parent[x]) return x;
    return parent[x] = _find(parent[x]);
}
void _union(int x,int y){
    parent[_find(x)] = _find(y);
}

long long kruskal(vector<pair<int,ii> > edge){
    long long cost = 0, save = 0;
    sort(edge.begin(), edge.end());
    for(int i=0;i<edge.size();++i){
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        int c = edge[i].first;
        cost += c;
        if(_find(u) == _find(v))
            continue;
        _union(u,v);
        save += c;
    }
    return cost - save;
}

int main(){
    while(true){
        scanf("%d%d",&m,&n);
        if(m==0 && n==0) break;
        
        _init(m);
        edge.clear();
        for(int i=0;i<n;++i){
            int x, y, z;
            scanf("%d%d%d",&x,&y,&z);
            edge.push_back(make_pair(z,ii(x,y)));
        }
        printf("%lld\n",kruskal(edge));
    }
    return 0;
}
