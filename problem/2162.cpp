#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<long long,long long> ll;

long long ccw(ll a, ll b, ll c){
    long long ret = a.first*b.second + b.first*c.second
        + c.first*a.second - b.first*a.second
        - c.first*b.second - a.first*c.second;
    if(ret == 0) return 0;
    return ret > 0 ? 1 : -1;
}

bool cross_line(ll a, ll b, ll c, ll d){
    long long t1 = ccw(a,b,c)*ccw(a,b,d);
    long long t2 = ccw(c,d,a)*ccw(c,d,b);
    if(t1==0 && t2==0){
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return !(b<c || d<a);
    }
    return t1<=0 && t2<=0;
}

ll point1[3001],point2[3001];
bool v[3001];
int n;

int dfs(int here){
    int ret = 1;
    v[here] = true;
    for(int i=0;i<n;++i)
        if(!v[i] && cross_line(point1[here],point2[here],
                    point1[i],point2[i]))
            ret += dfs(i);
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        point1[i] = ll(x1,y1);
        point2[i] = ll(x2,y2);
    }

    int ans1 = 0, ans2 = 0;
    for(int i=0;i<n;++i)
        if(v[i]==false)
            ans1++, ans2 = max(ans2, dfs(i));
    printf("%d\n%d",ans1,ans2);

    return 0;
}
