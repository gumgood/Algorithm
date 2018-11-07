#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;
char map[101][101];

int cntrow(int row){
    vector<int> col;
    col.push_back(-1);
    for(int i=0;i<n;++i)
        if(map[row][i] == 'X')
            col.push_back(i);
    col.push_back(n);

    int ret = 0;
    for(int i=1;i<col.size();++i)
        if(col[i]-col[i-1] > 2)
            ret++;
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%s",map[i]);

    int ans = 0;
    for(int i=0;i<n;++i)
        ans += cntrow(i);
    printf("%d ",ans);
    
    for(int i=0;i<n;++i)
        for(int j=0;j<i;++j)
            swap(map[i][j],map[j][i]);
    ans = 0;
    for(int i=0;i<n;++i)
        ans += cntrow(i);
    printf("%d ",ans);

    return 0;
}
