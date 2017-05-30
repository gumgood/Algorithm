#include<cstdio>

int main(){
	int t; scanf("%d", &t);
	while(t--){
		double a; scanf("%lf", &a);
		for(char t=0; t!='\n';){
			scanf("%c", &t);
			if(t=='@') a*=3;
			if(t=='%') a+=5;
			if(t=='#') a-=7;
		}
		printf("%.02lf\n", a);
	}
	return 0;
}
