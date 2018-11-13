#include<cstdio>
#include<cstring>

char in[502];

int main(){
	while(true){
        fgets(in,502,stdin);
        if(!strcmp(in,"END\n"))
        	break;
        for(int i=strlen(in)-2;i>=0;--i)
            printf("%c",in[i]);
        puts("");
    }
    return 0;
}

