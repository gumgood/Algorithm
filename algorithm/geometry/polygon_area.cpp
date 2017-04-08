// area of polygon
// www.acmicpc.net/problem/2166
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<long long, long long> Point;

double area(vector<Point>& p){
	double ret = 0;
	for (int i=0; i<p.size(); ++i){
		int j = (i+1)%p.size();
		ret += (p[i].first*p[j].second - p[j].first*p[i].second);
	}
	return abs(ret)/2;
}

int main(){
    vector<Point> p;
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i){
		long long x, y;
		scanf("%lld%lld", &x, &y);
		p.push_back(Point(x, y));
	}
	printf("%lf",area());
}
