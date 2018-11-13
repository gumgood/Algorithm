#include<cstdio>
#include<cmath>

int main(){
    int n;
    scanf("%d",&n);

    int size = 2;
    for(int i=1;i<=n;++i)
        size = size + (size-1);
    printf("%d",(int)pow(size,2));
    return 0;
}
