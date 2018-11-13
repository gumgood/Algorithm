#include<cstdio>
#include<algorithm>
using namespace std;

char fnc[100001];
int n, arr[100001];

void solve(){
    bool rev = false;
    int start = 0, end = n;
    for(int i=0;fnc[i];++i){
        if(fnc[i]=='R')
            rev = !rev;
        else{
            if(rev) end--;
            else start++;
        }
    }
    if(start>end) puts("error");
    else{
        printf("[");
        if(rev){
            for(int i=end-1;i>=start;--i){
                printf("%d",arr[i]);
                if(i>start)
                    printf(",");
            }
        }else{
            for(int i=start;i<end;++i){
                printf("%d",arr[i]);
                if(i<end-1)
                    printf(",");
            }
        }
        printf("]\n");
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%d\n[%d",fnc,&n,arr);
        for(int i=1;i<n;++i)
            scanf(",%d",arr+i);
        scanf("]");
        
        solve();
    }
    return 0;
}

