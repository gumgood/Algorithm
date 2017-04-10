#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii;

vector<int> LIS(vector<int>& in){ // return LIS of array 'in'
	int n = in.size();
	vector<ii> is; //(number, index in 'in');
	vector<int> parent(n+1); // parent index
	
	is.push_back(ii(-99999999, -1));
	for(int i=0; i<n; ++i){
		if(is.back().first < in[i]){
			parent[i] = is.back().second;
			is.push_back(ii(in[i], i));
		} else{
			auto it = lower_bound(is.begin(), is.end(), ii(in[i], i));
			parent[i] = (it-1)->second;
			*it = ii(in[i], i);
		}
	}

	vector<int> ret;
	for(int i=is.back().second; i>=0; i=parent[i])
		ret.push_back(in[i]);
	reverse(ret.begin(), ret.end());
	return ret;
}

void solve(vector<ii>& arr){
	int n = arr.size();
	vector<int> in(n);
	sort(arr.begin(), arr.end());
	for(int i=0; i<n; ++i)
		in[i] = arr[i].second;
	
	vector<int> _lis = LIS(in);
	printf("%d\n", n - _lis.size());
	for(int i=0; i<n; ++i){
		if(binary_search(_lis.begin(), _lis.end(), arr[i].second))
			continue;
		else
			printf("%d\n", arr[i].first);
	}
}

int main(){
	vector<ii> arr;
	int n; scanf("%d", &n);
	for(int i=0; i<n; ++i){
		int s, e;
		scanf("%d%d", &s, &e);
		arr.push_back(ii(s, e));
	}
	solve(arr);
}
