#include<cstdio>
#include<vector>
using namespace std;

vector<int> in;
int n;

void dfs(vector<int>& ans, int d){
    if(ans.size() == 6){
        for(int i=0; i<ans.size(); ++i)
            printf("%d ", ans[i]);
        printf("\n");
    }else if (d < n){
        ans.push_back(in[d]);
        dfs(ans, d+1);
        ans.pop_back();
        dfs(ans, d+1);
    }
}

int main(){
    while(true){
        scanf("%d", &n);
        if(!n) break;
        in.resize(n);
        for(int i=0; i<n; ++i)
            scanf("%d", &in[i]);
        
        vector<int> ans;
        dfs(ans, 0);
        printf("\n");
    }
    return 0;
}
