#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> chkw, chkh;
int w, h, n;

int solve(){
	chkw.push_back(0);
	chkw.push_back(w);
	chkh.push_back(0);
	chkh.push_back(h);
	sort(chkw.begin(), chkw.end());
	sort(chkh.begin(), chkh.end());
	int x = 0, y = 0;
	for(int i=1; i<chkw.size(); ++i)
		x = max(x, chkw[i]-chkw[i-1]);
	for(int i=1; i<chkh.size(); ++i)
		y = max(y, chkh[i]-chkh[i-1]);
	return x*y;
}

int main(){
	scanf("%d%d%d", &w, &h, &n);
	for(int i=0; i<n; ++i){
		int wh, cor;
		scanf("%d%d", &wh, &cor);
		if(wh) chkw.push_back(cor);
		else chkh.push_back(cor);
	}
	printf("%d", solve());
}
