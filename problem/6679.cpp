#include<cstdio>

bool digitSum(int n){
    int ret10 = 0;
    for(int i=n;i;i/=10)
        ret10 += i%10;

    int ret12 = 0;
    for(int i=n;i;i/=12)
        ret12 += i%12;

    int ret16 = 0;
    for(int i=n;i;i/=16)
        ret16+= i%16;

    return (ret10==ret12) && (ret12==ret16);
}

int main(){
    for(int i=1000;i<10000;++i)
        if(digitSum(i)) printf("%d\n",i);
    return 0;
}
