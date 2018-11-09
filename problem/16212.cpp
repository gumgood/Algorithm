#include<cstdio>
#include<algorithm>
using namespace std;

int in[500000];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",in+i);
    sort(in,in+n);
    for(int i=0;i<n;++i)
        printf("%d ",in[i]);
    return 0;
}
