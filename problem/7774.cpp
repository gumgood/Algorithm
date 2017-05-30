#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int n, m;
vector<int> a, b;

int solve(){
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	int ia=0, ib=0, cnta=1, cntb=0;
	while(ia<n && ib<m){
		if(cntb==0) cntb+=a[ia], ia++, cnta--;
		while(ib<m && cntb)
			cnta+=b[ib], ib++, cntb--;
	}
	return cnta;
}

int main(){
	scanf("%d%d", &n, &m);
	a.resize(n);
	b.resize(m);
	for(int i=0; i<n; ++i)
		scanf("%d", &a[i]);
	for(int i=0; i<m; ++i)
		scanf("%d", &b[i]);
	printf("%d", solve());
}
