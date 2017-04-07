// stern brocot tree
// find real number by binary search
// www.acmicpc.net/problem/5655

#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

char t[9];
ll A, B, D;
pair<ll, ll> L, R;

ll binary(ll a,ll b,ll c,ll d){
	// stern_brocot_tree
	ll chk = 0, ret1 = 1e18, ret2 = 1e18;
	if ((b*L.first <= L.second*a) && (R.second*a < b*R.first))
			ret1=b, chk=1;
	if ((d*L.first <= L.second*c) && (R.second*c < d*R.first))
		ret2=d, chk=1;
	if (chk) return min(ret1, ret2);

	if (B*(b+d) < D*(a+c))
		return binary(a,b,a+c,b+d);
	return binary(a+c,b+d,c,d);
}

int main(){
	int tc = 1;
	while (true){
		scanf("%lld.%s", &A, t);
		if (A<0) break;

		B = 0, D = 1;
		for (int i=0; t[i]; ++i)
			B = B*10 + t[i] -'0', D*=10;
		L.first = B*10-5, L.second = 10*D;
		R.first = B*10+5, R.second = 10*D;

		printf("Case %d: %lld\n", tc++, binary(0,1,1,0));
	}
}
