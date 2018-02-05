#include<cstdio>
#include<algorithm>
using namespace std;
const int _INF = 123456789;

int in[1001];
int dp[1001];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", in+i);
	
	for(int i=0; i<n; ++i)
		dp[i] = _INF;
	dp[0] = 0;

	for(int i=0; i<n; ++i)
		for(int j=1; j<=in[i]; ++j)
			dp[i+j] = min(dp[i+j], dp[i]+1);

	printf("%d", dp[n-1]==_INF ? -1 : dp[n-1]);
	return 0;
}
