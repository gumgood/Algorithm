#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

struct pqcmp{
	bool operator ()(int &a, int &b){
		if(abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main(){
	int n,x;
	scanf("%d", &n);

	priority_queue<int, vector<int>, pqcmp> pq;
	while(n--){
		scanf("%d", &x);
		if(x){
			pq.push(x);
		} else{
			if(pq.empty())
				printf("0\n");
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}
