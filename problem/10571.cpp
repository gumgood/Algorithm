#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<double, double> dd;

int solve(vector<dd>& in){
	int lis[201], n=in.size();
	fill(lis, lis+n, 1);
	for(int i=0; i<n; ++i)
		for(int j=0; j<i; ++j)
			if(in[j].first<in[i].first && in[j].second>in[i].second)
				lis[i] = max(lis[i], lis[j]+1);
	int ret = 0;
	for(int i=0; i<n; ++i)
		ret = max(ret, lis[i]);
	return ret;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		vector<dd> in(n);
		for(int i=0; i<n; ++i)
			scanf("%lf%lf", &in[i].first, &in[i].second);
		printf("%d\n", solve(in));
	}
}
