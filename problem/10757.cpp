#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> bigint_add(vector<int>& a,vector<int>& b){
	int size = max(a.size(),b.size());	
	vector<int> c(size+1, 0);
	for(int i=0;i<size;++i){
		int result = c[i];
		if(i<a.size())
			result += a[i];
		if(i<b.size())
			result += b[i];

		if(result < 0){
			//
		}else{
			c[i] = result%10;
			c[i+1] += result/10;
		}
	}
	while(c.size() && c.back()==0)
		c.pop_back();
	return c;
}
	

int main(){
	char a[10001],b[10001];
	scanf("%s%s",a,b);
	
	vector<int> biga,bigb,bigc;
	for(int i=strlen(a)-1;i>=0;--i)
		biga.push_back(a[i]-'0');
	for(int i=strlen(b)-1;i>=0;--i)
		bigb.push_back(b[i]-'0');
	bigc = bigint_add(biga,bigb);
	for(int i=bigc.size()-1;i>=0;--i)
		printf("%d",bigc[i]);

	return 0;
}
