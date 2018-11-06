#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
vector<pair<pair<int,int>,pair<int,string> > > in;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char name[11];
        int a,b,c;
        scanf("%s%d%d%d",name,&a,&b,&c);
        in.push_back(make_pair(make_pair(-a,b),make_pair(-c,name)));
    }
    sort(in.begin(),in.end());
    for(int i=0;i<n;++i)
        printf("%s\n",in[i].second.second.c_str());
    return 0;
}
