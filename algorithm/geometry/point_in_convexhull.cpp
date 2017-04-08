// check point in convexhull
// www.acmicpc.net/problem/2254
// www.acmicpc.net/problem/3878
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

typedef pair<long long,long long> point;

long long ccw(Point a, Point b, Point c){
	long long r = a.first*b.second + b.first*c.second + c.first*a.second
		- b.first*a.second - c.first*b.second - a.first*c.second;
	if (r==0) return 0;
	return r > 0 ? 1 : -1;
}

bool x_in_p(vector<Point>& p, Point x){
	long long chk = ccw(x, p[p.size()-1], p[0]);
	for (int i=1; i<p.size(); ++i)
		if (chk != ccw(x, p[i-1], p[i]))
			return false;
	return true;
}

int main(){
    
}
