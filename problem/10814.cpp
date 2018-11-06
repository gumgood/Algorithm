#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int> > in;
char name[100001][101];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int age;
        scanf("%d%s", &age,name[i]);
        in.push_back(make_pair(age, i));
    }
    sort(in.begin(), in.end());
    for(int i=0; i<n; ++i)
        printf("%d %s\n", in[i].first, name[in[i].second]);
    return 0;
}
