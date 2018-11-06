#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dec2b(int n,int b){
    vector<int> ret;
    for(;n;n/=b) ret.push_back(n%b);
    reverse(ret.begin(),ret.end());
    return ret;
}

int main(){
    int n, b;
    scanf("%d%d",&n,&b);

    vector<int> ans = dec2b(n,b);
    for(int i=0;i<ans.size();++i){
        if(ans[i]>9)
            printf("%c",ans[i]-10+'A');
        else
            printf("%d",ans[i]);
    }

    return 0;
}
