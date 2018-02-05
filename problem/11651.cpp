#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> ii;

int main(){
	int n; scanf("%d", &n);
	vector<ii> a;
	for(int i=0; i<n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		a.push_back(ii(x, y));
	}
	sort(a.begin(), a.end(), [](ii p, ii q){
		if(p.second == q.second)
			return p.first < q.first;
		return p.second < q.second;
	});
	for(int i=0; i<n; ++i)
		printf("%d %d\n", a[i].first, a[i].second);
	return 0;
}
