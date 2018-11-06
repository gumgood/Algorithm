#include<cstdio>

int main(){
    int a,b,c;
    while(true){
        scanf("%d%d%d",&a,&b,&c);
        if(!a && !b && !c)
            break;
        
        if(b-a == c-b)
            printf("AP %d\n",c+c-b);
        else
            printf("GP %d\n",c*(c/b));
    }
    return 0;
}
