// O(nlogn)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int _INF = numeric_limits<int>::min();

int arr[40001];

int LIS(int n){
	vector<int> IS(1, _INF);
	for(int i=0; i<n; ++i){
		if(IS.back() < arr[i])
			IS.push_back(arr[i]);
		else
			*lower_bound(IS.begin(), IS.end(), arr[i]) = arr[i];
	}
	return IS.size()-1;
}

int main(){
	int n; scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", arr+i);
	printf("%d", LIS(n));
}
