#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int dp1[2001],dp2[2001];

void LIS(int in[], int n){
	fill(dp1, dp1+2001, 1);
	for(int i=n-1; i>=0; --i)
		for(int j=n-1; j>i; --j)
			if(in[i] < in[j])
				dp1[i] = max(dp1[i], dp1[j]+1);
}

void LDS(int in[], int n){
	fill(dp2, dp2+2001, 1);
	for(int i=n-1; i>=0; --i)
		for(int j=n-1; j>i; --j)
			if(in[i] > in[j])
				dp2[i] = max(dp2[i], dp2[j]+1);
}

int main(){
	int n,arr[2001];
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", arr+i);
	
	int ans = 0;
	LIS(arr, n), LDS(arr, n);
	for(int i=0; i<n; ++i)
		ans = max(ans, dp1[i] + dp2[i] - 1);
	printf("%d", ans);
}
