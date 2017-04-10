// O(nlogn)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int>& arr,int n){
	vector<int> IS(1, -99999999);
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
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	printf("%d", LIS(arr,n));
}
