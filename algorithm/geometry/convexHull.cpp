// graham_scan O(nlogn)

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<long long, long long> Point;

long long ccw(Point a, Point b, Point c){
	long long r = a.first*b.second + b.first*c.second + c.first*a.second
		- b.first*a.second - c.first*b.second - a.first*c.second;
	return r;
}

vector<Point> convexhull(vector<Point> p){
	swap(p[0], *min_element(p.begin(), p.end()));

	for (int i=1; i<p.size(); ++i)
		p[i].first -= p[0].first, p[i].second -= p[0].second;
	sort(p.begin()+1, p.end(), [](Point a, Point b){
		long long t = a.first*b.second - b.first*a.second;
		if (t == 0) return a < b;
		return t > 0;
	});
	for (int i=1; i<p.size(); ++i)
		p[i].first += p[0].first, p[i].second += p[0].second;

	vector<Point> r;
	r.push_back(p[0]);
	r.push_back(p[1]);
	for (int i=2; i<p.size(); ++i){
		while (r.size()>=2 && !(ccw(r[r.size()-2], r[r.size()-1], p[i]) > 0))
			r.pop_back();
		r.push_back(p[i]);
	}
	return r;
}

int main(){
	vector<Point> p;
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i){
		long long x, y;
		scanf("%lld%lld", &x, &y);
		p.push_back(Point(x, y));
	}
	printf("%d", convexhull(p).size());
}
