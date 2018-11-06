#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct bigint{
    vector<int> num;

    bigint(int in = 0){
        for(;in;in/=10)
            num.push_back(in%10);
    }

    bigint(vector<int> in){
        num.assign(in.begin(),in.end());
    }

    vector<int> vec() const{
        return num;
    }

    void normalize(vector<int> &n) const{
        n.push_back(0);
        for(int i=0;i<n.size();++i){
            if(n[i]<0){
                int borrow = (abs(n[i]) + 9) / 10;
                n[i+1] -= borrow;
                n[i] += borrow * 10;
            } else{
                n[i+1] += n[i] / 10;
                n[i] %= 10;
            }
        }
        while(n.size()>1 && n.back()==0)
            n.pop_back();
    }

    bigint operator + (const bigint& num2) const{
        vector<int> ret(num.size()+num2.vec().size(), 0);
        int i;
        for(i=0;i<num.size();++i)
            ret[i] = num[i] + num2.vec()[i];
        for(;i<num2.vec().size();++i)
            ret[i] = num2.vec()[i];
        normalize(ret);
        return ret;
    }

    bigint operator * (const bigint& num2) const{
        vector<int> ret(num.size() + num2.vec().size() + 1, 0);
        for(int i=0;i<num.size();++i)
            for(int j=0;j<num2.vec().size();++j)
                ret[i+j] += num[i] * num2.vec()[j];
        normalize(ret);
        return ret;
    }

}bigint;

bigint dp[251];

int main(){
    dp[0] = dp[1] = bigint(1);
    for(int i=2;i<251;++i)
        dp[i] = dp[i-1] + bigint(2)*dp[i-2];

    int n;
    while(~scanf("%d", &n)){
        for(int i=dp[n].vec().size()-1; i>=0; --i)
            printf("%d", dp[n].vec()[i]);
        printf("\n");
    }
    return 0;
}
