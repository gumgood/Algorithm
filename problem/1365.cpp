#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int in[100001];

int LIS(int n){
	vector<int> IS(1, -99999999);
	for(int i=0; i<n; ++i){
		if(IS[IS.size()-1] < in[i])
			IS.push_back(in[i]);
		else
			*lower_bound(IS.begin(), IS.end(), in[i]) = in[i];
	}
	return IS.size()-1;
}

int main(){
	int n; scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", in+i);
	printf("%d", n - LIS(n));
}
