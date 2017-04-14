#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct FT{
	vector<long long> t;
	FT(int n): t(n+1) {}
	long long sum(int i){
		long long ret=0;
		while(i>0)
			ret+=t[i], i -= (i & -i);
		return ret;
	}
	void update(int i,long long diff){
		while(i<t.size()){
			t[i]+=diff;
			i+=(i & -i);
		}
	}
};

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<long long> in(n+1);
	FT ft(n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&in[i]);
		ft.update(i,in[i]);
	}
	for(int i=0;i<m+k;++i){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		if(a==1) ft.update(b,c-in[b]),in[b]=c;
		else printf("%lld\n",ft.sum(c)-ft.sum(b-1));
	}
	return 0;
}
