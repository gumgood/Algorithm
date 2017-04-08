// O(ElogV)
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<pair<int, int> > > g;
// g[i] : node i와 연결된 edge들
// g[i][j] : node i와 연결된 jth node의 정보 (cost, 반대편 node번호)

long long prim(int n,int s){
	// n : 노드 수, s : 시작점
	// pq : mst가 될 수 있는 edge들
	priority_queue<pair<int, int> > pq;
	bool visited[1001] = {0};

	for(int i=0; i<g[s].size(); ++i)
		pq.push(g[s][i]);
	visited[s] = true;

	long long ret = 0;
	for(int cnt=1; cnt<n;){ // 모든 노드를 포함할 때까지 반복
		int u = pq.top().second;  // 현재 edge의 목적지
		int cost = pq.top().first;// 현재 edge의 가중치
		pq.pop();
		if(visited[u]==false){
			visited[u] = true;
			ret += cost;
			for(int i=0; i<g[u].size(); ++i)
				pq.push(g[u][i]); // u와 인접한 모든 edge들 push
			cnt++;
		}
	}
	return ret;
}

int main(){
	return 0;
}
