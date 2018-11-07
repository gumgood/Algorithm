#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool isnp[100001] = {true,true};

char n[256];

int sti(int s,int e){
    int num = 0;
    for(int i=s;i<=e;++i)
        num = num*10 + (n[i]-'0');
    return num;
}

int main(){
    for(long long i=2;i<100001;++i)
        if(!isnp[i])
            for(long long j=i*i;j<100001;j+=i)
                isnp[j] = true;

    while(true){
        scanf("%s",n);
        if(n[0]=='0' && n[1]==0) break;
        
        int ans = 0;
        int len = strlen(n);
        for(int i=0;i<len;++i)
            for(int j=i;j<i+6 && j<len;++j){
                int num = sti(i,j);
                if(num<=100000 && !isnp[num])
                    ans = max(ans, num);
            }
        printf("%d\n",ans);
    }
    return 0;
}
