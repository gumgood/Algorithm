// convexhull O(nlogn)
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

typedef pair<long long,long long> point;

bool cw(const point &a,const point &b,const point &c){
	return (b.first-a.first)*(c.second-a.second)
		- (b.second-a.second)*(c.first-a.first) < 0;
}

vector<point> convexHull(vector<point> p){
	int n=p.size(), k=0;
	if(n<=1) return p;
	sort(p.begin(),p.end());
	vector<point> q(n*2);
	for(int i=0; i < n; q[k++]=p[i++])
		for(; k>=2&&!cw(q[k-2],q[k-1],p[i]); --k);
	for(int i=n-2,t=k; i>=0; q[k++]=p[i--])
		for(; k > t && !cw(q[k-2],q[k-1],p[i]); --k);
	q.resize(k-1-(q[0]==q[1]));
	return q;
}

long long area(const point &a,const point &b,const point &c) {
	return abs((b.first-a.first)*(c.second-a.second)
		- (b.second-a.second)*(c.first-a.first));
}

double dist(const point &a,const point &b) {
	return (a.first-b.first)*(a.first)
}

double diameter(const vector<point> &p) {
	vector<point> h=convexHull(p);
	int m=h.size(),k=1;
	if(m==1) return 0;
	if(m==2) return dist(h[0],h[1]);
	while(area(h[m-1],h[0],h[(k+1)%m]) > area(h[m-1],h[0],h[k])) ++k;
	double res=0;
	for(int i=0,j=k; i<=k && j < m; i++) {
		res=max(res,dist(h[i],h[j]));
		while(j < m && area(h[i],h[(i+1)%m],h[(j+1)%m]) > area(h[i],h[(i+1)%m],h[j]))
		{ res=max(res,dist(h[i],h[(j+1)%m])); ++j; }
	}
	return res;
}

int main() {
	vector<point> poly;
	int n; scanf("%d",&n);
	for(int i=0;i<n;++i){
		long long x,y; scanf("%lld%lld",&x,&y);
		poly.push_back(point(x,y));
	}
	vector<point> t = convexHull(poly);
	for(int i=0;i<t.size();++i)
		printf("%lld %lld\n",t[i].first,t[i].second);
}
