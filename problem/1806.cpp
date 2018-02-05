#include<cstdio>
#include<algorithm>
using namespace std;

int in[100001];

int solve(int n, int s){
	int ret = 123456789;

	int i=0, j=0, sum=in[0];
	while(j<n){
		if(sum>=s){
			ret = min(ret, j-i+1);
			sum -= in[i];
			i++;
		} else{
			j++;
			sum += in[j];
		}
	}
	return ret==123456789 ? 0 : ret;
}

int main(){
	int n, s;
	scanf("%d%d", &n, &s);
	for(int i=0; i<n; ++i)
		scanf("%d", in+i);
	printf("%d", solve(n, s));
	return 0;
}
