#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long Data;
struct ST1{
	int n;
	vector<Data> t;
	ST1(const vector<Data>& in){
		n = in.size();
		t.resize(4*n);
		init(in, 1, 0, n-1);
	}

	Data idt = numeric_limits<Data>::max();

	Data init(const vector<Data>& in, int n, int s, int e){
		if(s==e) return t[n] = in[s];
		Data a = init(in, 2*n, s, (s+e)/2);
		Data b = init(in, 2*n+1, (s+e)/2+1, e);
		return t[n] = min(a, b);
	}

	Data query(int n, int s, int e, int l, int r){
		if(l>e || r<s) return idt;
		if(l<=s && e<=r) return t[n];
		Data a = query(2*n, s, (s+e)/2, l, r);
		Data b = query(2*n+1, (s+e)/2+1, e, l, r);
		return min(a, b);
	}
};

struct ST2{
	int n;
	vector<Data> t;
	ST2(const vector<Data>& in){
		n = in.size();
		t.resize(4*n);
		init(in, 1, 0, n-1);
	}

	Data idt = numeric_limits<Data>::min();

	Data init(const vector<Data>& in, int n, int s, int e){
		if(s==e) return t[n] = in[s];
		Data a = init(in, 2*n, s, (s+e)/2);
		Data b = init(in, 2*n+1, (s+e)/2+1, e);
		return t[n] = max(a, b);
	}

	Data query(int n, int s, int e, int l, int r){
		if(r<s || e<l) return idt;
		if(l<=s && e<=r) return t[n];
		Data a = query(2*n, s, (s+e)/2, l, r);
		Data b = query(2*n+1, (s+e)/2+1, e, l, r);
		return max(a, b);
	}
};

int main(){
	vector<Data> in;
	int n, m;
	scanf("%d%d", &n, &m);
	in.resize(n);
	for(int i=0; i<n; ++i)
		scanf("%lld", &in[i]);

	ST1 st1(in);
	ST2 st2(in);
	for(int i=0; i<m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld %lld\n", st1.query(1, 1, n, a, b), st2.query(1, 1, n, a, b));
	}
}
