#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int _INF = 123456789;

int b[10];

bool chk(int n){
	do{
		if(b[n%10])
			return false;
		n/=10;
	} while(n);
	return true;
}

int digit(int n){
	if(n==0) return 1;

	int ret = 0;
	while(n)
		n/=10, ret++;
	return ret;
}

int solve(int n){
	int low = -_INF, high = _INF;
	for(int i=0; i<=n; ++i)
		if(chk(i))
			low = max(low, i);
	for(int i=n; i<=1000000; ++i)
		if(chk(i))
			high = min(high, i);

	int ret = abs(n-100);
	if(low != -_INF) ret = min(ret, n-low+digit(low));
	if(high != _INF) ret = min(ret, high-n+digit(high));
	return ret;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--){
		int t;
		scanf("%d", &t);
		b[t] = true;
	}
	printf("%d", solve(n));
	return 0;
}
