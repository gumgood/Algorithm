#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n, in[500001];

int f1(){
    double sum = 0;
    for(int i=0;i<n;++i)
        sum += in[i];

    int ans = (int)(abs(sum)/n + 0.5);
    return sum < 0 ? -ans : ans;
}

int f2(){
    sort(in,in+n);
    return in[n/2];
}

int f3(){
    int cnt[8001] = {0};
    for(int i=0;i<n;++i)
        cnt[in[i]+4000]++;

    int ans = *min_element(in,in+n) + 4000;
    for(int i=0;i<8001;++i)
        if(cnt[i] && cnt[ans]<cnt[i])
            ans = i;
    for(int i=0;i<8001;++i)
        if(i!=ans && cnt[ans]==cnt[i])
            return i-4000;
    return ans-4000;
}

int f4(){
    return *max_element(in,in+n)
        - *min_element(in,in+n);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",in+i);
    printf("%d\n%d\n%d\n%d\n",f1(),f2(),f3(),f4());
    return 0;
}

