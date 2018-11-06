#include<cstdio>

typedef long long ll;

bool chk[1000010];

ll nDiv(ll n,ll sq){
	return n/(sq*sq);
}

int solve(ll _min,ll _max){
	for(ll i=2;i*i<=_max;++i){
		ll low = nDiv(_min-1, i) + 1;
		ll high = nDiv(_max,i);
		
		for(ll j=low;j<=high;j++)
			if(j*i*i - _min >= 0)
				chk[j*i*i - _min] = true;
	}
	
	int ret = 0;
	for(ll i=0;i<=_max - _min;++i)
		if(!chk[i]) ret++;
	return ret;
}

int main(){
	ll _min,_max;
	scanf("%lld%lld",&_min,&_max);
	printf("%d",solve(_min,_max));
	return 0;
}
