#include<cstdio>
#include<algorithm>
using namespace std;

int lis[1000001];

int main() {
	int n; scanf("%d", &n);
	for(int i=0; i<n; ++i){
		int t; scanf("%d", &t);
		lis[t] = lis[t-1] + 1;
	}
	int ans = 0;
	for(int i=1; i<=n; ++i)
		ans = max(ans, lis[i]);
	printf("%d", n-ans);
}
