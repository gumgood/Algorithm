#include<cstdio>
#include<vector>
using namespace std;

int n;
vector<char> target;
vector<char> ring[101];

bool check(const vector<char> r){
    for(int i=0;i<r.size();++i){
        bool flag = true;
        for(int j=0;j<target.size();++j)
            if(r[i+j]!=target[j])
                flag = false;
        if(flag) return true;
    }
    return false;
}

int main(){
    char temp[11];
    scanf("%s",temp);
    for(int i=0;temp[i];++i)
        target.push_back(temp[i]);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",temp);
        for(int j=0;temp[j];++j)
            ring[i].push_back(temp[j]);
        for(int j=0;temp[j];++j)
            ring[i].push_back(temp[j]);
    }

    int ans = 0;
    for(int i=0;i<n;++i)
        if(check(ring[i]))
            ans++;
    printf("%d",ans);
    return 0;
}
