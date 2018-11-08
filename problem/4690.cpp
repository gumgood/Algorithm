#include<cstdio>

int is[1000001];

int main(){
    for(int i=1;i<=100;++i)
        is[i*i*i] = i;
    for(int a=2;a<=100;++a){
        int a3 = a*a*a;
        for(int b=2;b<=100;++b){
            int b3 = b*b*b;
            for(int c=b+1;c<=100;++c){
                int c3 = c*c*c;
                if(a3-b3-c3>=0 && is[a3-b3-c3]>c){
                    printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,is[a3-b3-c3]);
                }
            }
        }
    }
    return 0;
}
