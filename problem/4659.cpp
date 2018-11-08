#include<cstdio>
#include<cstring>

char in[21];
bool mo(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    return false;
}

bool evaluation(){
    // case 1
    bool flag = false;
    for(int i=0;in[i];++i)
        if(mo(in[i])) flag = true;
    if(flag==false) return false;

    // case 2
    int jaeum = 0, moeum = 0;
    for(int i=0;in[i];++i){
        if(mo(in[i]))
            jaeum = 0, moeum++;
        else
            jaeum++, moeum = 0;
        if(jaeum==3 || moeum==3)
            return false;
    }

    // case 3
    for(int i=1;in[i];++i)
        if(in[i]==in[i-1] && in[i]!='e' && in[i]!='o')
            return false;

    return true;
}

int main(){
    while(true){
        scanf("%s",in);
        if(!strcmp(in,"end"))
            break;
        if(evaluation())
            printf("<%s> is acceptable.\n",in);
        else
            printf("<%s> is not acceptable.\n",in);
    }
    return 0;
}
