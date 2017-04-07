// O(n + mlogn)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long Data;
struct ST{ // Segment Tree
	int n;
	vector<Data> t;
	ST(const vector<Data> &in){
		n = in.size();
		t.resize(n*4);
		init(in, 1, 0, n-1); // in[0~n-1] 
	}

	Data idt = numeric_limits<int>::max(); // identity
	Data calc(Data a, Data b){
		return min(a,b); // Data modify here;
	}

	Data init(const vector<Data> &in, int n, int s, int e){
		if(s==e) return t[n] = in[s];
		Data a = init(in,2*n,  s,  (s+e)/2);
		Data b = init(in,2*n+1,(s+e)/2+1,e);
		return t[n] = calc(a, b);
	}

	void upd(int n,int s,int e,int p,Data v){
		// if nth node = [s,e], update pth element to 'v';
		// ex) upd(1, 1, n, p, v);
		if(p<s || p>e) return;
		if(s==e) t[n] = v;
		else{
			upd(2*n,   s,   (s+e)/2, p, v);
			upd(2*n+1, (s+e)/2+1, e, p, v);
			t[n] = calc(t[2*n], t[2*n+1]);
		}
	}

	Data query(int n, int s, int e, int l, int r){
		// If nth node = [s,e], then [l,r] = ?
		// ex) query(1, 1, n, l, r);
		if(l>e || r<s) return idt;
		if(l<=s && e<=r) return t[n];
		Data a = query(2*n,   s,   (s+e)/2, l, r);
		Data b = query(2*n+1, (s+e)/2+1, e, l, r);
		return calc(a, b);
	}
}; 

int main(){
	vector<Data> in;
	int n, m;
	scanf("%d%d", &n, &m);
	in.resize(n);
	for(int i=0; i<n; ++i)
		scanf("%lld", &in[i]);

	ST st(in);
	for(int i=0; i<m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", st.query(1, 1, n, a, b));
	}
}
