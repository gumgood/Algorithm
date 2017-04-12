// O(nlogn + mlogn)
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
		for(int i=0; i<n; ++i)
			upd(1, 1, n, i+1, in[i]);
	}

	Data idt = numeric_limits<int>::max(); // identity
	Data calc(Data a, Data b){
		return min(a, b); // Data modify here;
	}

	void upd(int n, int s, int e, int p, Data v){
		// if nth node = [s,e], update pth element to 'v';
		// ex) upd(1, 1, n, p, v);
		if(p<s || e<p) return;
		if(s==e) t[n] = v;
		else{
			upd(2*n, s, (s+e)/2, p, v);
			upd(2*n+1, (s+e)/2+1, e, p, v);
			t[n] = calc(t[2*n], t[2*n+1]);
		}
	}

	Data query(int n, int s, int e, int l, int r){
		// If nth node = [s,e], then [l,r] = ?
		// ex) query(1, 1, n, l, r);
		if(r<s || e<l) return idt;
		if(l<=s && e<=r) return t[n];
		Data a = query(2*n, s, (s+e)/2, l, r);
		Data b = query(2*n+1, (s+e)/2+1, e, l, r);
		return calc(a, b);
	}
};

int main(){
	vector<Data> in;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	in.resize(n);
	for(int i=0; i<n; ++i)
		scanf("%lld", &in[i]);

	ST st(in);
	for(int i=0; i<m+k; ++i){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==1) st.upd(1, 1, n, b, c);
		else printf("%lld\n", st.query(1, 1, n, b, c));
	}
}
