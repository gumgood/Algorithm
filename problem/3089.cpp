#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> ii;

const int _MAX = 1e5 + 1;

int L[_MAX], R[_MAX], U[_MAX], D[_MAX];

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    
    vector<ii> cord;  // (x,y)
    vector<pair<ii,int> > srtx, srty; // (x,y,i), (y,x,i)

    cord.push_back(ii(0,0));
    srtx.push_back(make_pair(ii(0,0),0));
    srty.push_back(make_pair(ii(0,0),0));
    
    for(int i=0;i<n;++i){
        int x, y;
        scanf("%d%d",&x,&y);
        if(x==0 && y==0) continue;
        cord.push_back(ii(x,y));
        srtx.push_back(make_pair(ii(x,y), srtx.size()));
        srty.push_back(make_pair(ii(y,x), srty.size()));
    }
    sort(srtx.begin(), srtx.end());
    sort(srty.begin(), srty.end());

    for(int i=1;i<cord.size();++i){
        if(srtx[i].first.first == srtx[i-1].first.first){
            D[srtx[i].second] = srtx[i-1].second;
            U[srtx[i-1].second] = srtx[i].second;
        }
        if(srty[i].first.first == srty[i-1].first.first){
            L[srty[i].second] = srty[i-1].second;
            R[srty[i-1].second] = srty[i].second;
        }
    }

    char ord[100001];
    int here = 0;
    scanf("%s",ord);
    for(int i=0;ord[i];++i){
        if(ord[i] == 'L') here = L[here];
        if(ord[i] == 'R') here = R[here];
        if(ord[i] == 'U') here = U[here];
        if(ord[i] == 'D') here = D[here];
    }
    printf("%d %d\n", cord[here].first, cord[here].second);

    return 0;
}
