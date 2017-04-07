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

bool cross_line(Point a, Point b, Point c, Point d){
	long long t1 = ccw(a, b, c)*ccw(a, b, d);
	long long t2 = ccw(c, d, a)*ccw(c, d, b);
	if (t1==0 && t2==0){
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return !(b<c || d<a);
	}
	return t1<=0 && t2<=0;
}

int main(){
    return 0;
}
