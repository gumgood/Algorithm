#include<cstdio>

long long fac(int n){
    long long ret = 1;
    for(int i=1;i<=n;++i)
        ret *= i;
    return ret;
}

double e(int n){
    double ret = 0;
    for(int i=0;i<=n;++i)
        ret += (double)fac(9)/fac(i);
    return ret/fac(9);
}

int main(){
    puts("n e");
    puts("- -----------");
    puts("0 1");
    puts("1 2");
    puts("2 2.5");
    for(int i=3;i<10;++i){
        printf("%d %.9lf\n",i,e(i));
    }
    return 0;
}
