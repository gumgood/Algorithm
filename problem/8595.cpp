#include<cstdio>

char in[5000000];

long long solve(int n){
	long long ret = 0, num = 0;
	for(int i=0; i<=n; ++i){
		if('0'<=in[i] && in[i]<='9')
			num = num*10 + in[i] - '0';
		else
			ret += num, num = 0;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d%s", &n, in);
	printf("%lld", solve(n));
}
