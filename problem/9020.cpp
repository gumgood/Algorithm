#include<cstdio>

bool isnp[10001] = {true,true};

int main(){
	
	for(long long i=2;i<10001;++i)
		for(long long j=i*i;j<10001;j+=i)
			isnp[j] = true;
	
	int n, t;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		for(int i=n/2;i<n;++i){
			if(!isnp[i] && !isnp[n-i]){
				printf("%d %d\n",n-i,i);
				break;
			}
		}
	}
	
	return 0;
}
