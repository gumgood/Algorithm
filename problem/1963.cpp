#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool isnp[10000] ={true,true};

vector<int> num2vec(int num){
    vector<int> vec(4);
    vec[0] = num%10/1;
    vec[1] = num%100/10;
    vec[2] = num%1000/100;
    vec[3] = num%10000/1000;
    return vec;
}

int vec2num(vector<int>& vec){
    int num = 0;
    num += vec[0]*1;
    num += vec[1]*10;
    num += vec[2]*100;
    num += vec[3]*1000;
    return num;
}

int bfs(int src, int dst){
    vector<bool> v(10000,false);
    queue<pair<int,int> > q;
    q.push(make_pair(src, 0));
    v[src] = true;
    while(!q.empty()){
        int here = q.front().first;
        int deep = q.front().second;
        q.pop();

        if(here == dst) return deep;
        
        vector<int> vhere = num2vec(here);
        vector<int> vnext;
        for(int i=0;i<4;++i){
            for(int j=0;j<10;++j){
                vnext = vhere;
                vnext[i] = j;
                int next = vec2num(vnext);
                if(next < 1000) continue;
                if(isnp[next]) continue;
                if(v[next]) continue;
                v[next] = true;
                q.push(make_pair(next, deep+1));
            }
        }
    }
    return -1;
}

int main(){
    for(long long i=2;i<10000;++i)
        for(long long j=i*i;j<10000;j+=i)
            isnp[j] = true;

    int t;
    scanf("%d",&t);
    while(t--){
        int src, dst, ans;
        scanf("%d%d",&src,&dst);
        ans = bfs(src,dst);
        if(ans<0)
            puts("Impossible");
        else
            printf("%d\n",ans);
    }

    return 0;
}
