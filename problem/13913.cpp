#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> ii;

int n, k;
bool v[100001];
int bt[100001]; //backtrack

int bfs(){
	queue<ii> q;
	q.push(ii(n,0));
	v[n] = true;
	bt[n] = n;
	while(!q.empty()){
		int here = q.front().first;
		int deep = q.front().second; q.pop();
		if(here == k) return deep;
		
		if(here > 0 && v[here-1]==false){
			q.push(ii(here-1, deep+1));
			v[here-1] = true;
			bt[here-1] = here;
		}
		if(here < 1e5 && v[here+1]==false){
			q.push(ii(here+1, deep+1));
			v[here+1] = true;
			bt[here+1] = here;
		}
		if(here*2 <= 1e5 && v[here*2]==false){
			q.push(ii(here*2, deep+1));
			v[here*2] = true;
			bt[here*2] = here;
		}
	}
	return -1; // error
}

int main(){
	scanf("%d%d", &n, &k);
	printf("%d\n", bfs());
	
	vector<int> mv;
	for(int i=k; i!=n; i=bt[i])
		mv.push_back(i);
	mv.push_back(n);

	reverse(mv.begin(), mv.end());
	for(auto it=mv.begin(); it!=mv.end(); ++it)
		printf("%d ", *it);
}
