// O(n^2)
// https://www.acmicpc.net/problem/1965
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[1001], in[1001];

int LIS(int n){
	fill(dp, dp+n, 1);
	for(int i=0; i<n; ++i)
		for(int j=0; j<i; ++j)
			if(in[j]<in[i])
				dp[i] = max(dp[i], dp[j]+1);

	int ret = 0;
	for(int i=0; i<n; ++i)
		ret = max(ret, dp[i]);
	return ret;
}

int main(){
	int n; scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", in+i);
	printf("%d", LIS(n));
	return 0;
}
