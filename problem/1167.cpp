#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> ii;

vector<ii> e[100001];
bool visit[100001];
int sizev;

ii dfs(int here){
    // return (distance to farthest node, node number)
    visit[here] = true;

    ii ret(0,here);
    for(int i=0;i<e[here].size();++i){
        int next = e[here][i].first;
        int dist = e[here][i].second;
        if(visit[next]) continue;
        ii iidfs = dfs(next);
        if(ret.first < iidfs.first + dist){
            ret.first = iidfs.first + dist;
            ret.second = iidfs.second;
        }
    }
    return ret;
}

int main(){
    scanf("%d",&sizev);
    for(int i=0;i<sizev;++i){
        int a;
        scanf("%d",&a);
        while(true){
            int b,c;
            scanf("%d",&b);
            if(b==-1) break;
            scanf("%d",&c);
            e[a].push_back(ii(b,c));
            e[b].push_back(ii(a,c));
        }
    }

    memset(visit,0,sizeof(visit));
    ii t1 = dfs(1);
    memset(visit,0,sizeof(visit));
    ii t2 = dfs(t1.second);
    printf("%d",t2.first);

    return 0;
}

