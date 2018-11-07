#include<cstdio>
#include<algorithm>
using namespace std;

int in[20001];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",in+i);
    sort(in,in+n);
    printf("%d",in[(n-1)/2]);
}
