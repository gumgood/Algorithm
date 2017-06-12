#include<cstdio>
#include<algorithm>
using namespace std;

int ab, bc, ca;

int set_ab(int, int, int);
int set_bc(int, int, int);
int set_ca(int, int, int);

int set_ab(int a,int b,int c){
	int ret = 0, cnt = 0;
	while(a>=0 && b>=0){
		ret = max(ret, cnt + set_bc(a,b,c));
		a--, b--, cnt+=ab;
	}
	return ret;
}

int set_bc(int a,int b,int c){
	int ret = 0, cnt = 0;
	while(b>=0 && c>=0){
		ret = max(ret, cnt + set_ca(a, b, c));
		b--, c--, cnt+=bc;
	}
	return ret;
}

int set_ca(int a, int b, int c){
	return min(a,c)*ca;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		scanf("%d%d%d", &ab, &bc, &ca);
		printf("%d\n", set_ab(a, b, c));
	}
}
