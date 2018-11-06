#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct bigint{
    vector<int> num;

    bigint(int in = 0){
        for(;in;in/=10)
            num.push_back(in%10);
    }

    bigint(vector<int>& in){
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
        for(i=0;i<num.size() && i<num2.vec().size();++i)
            ret[i] = num[i] + num2.vec()[i];
        for(;i<num.size();++i)
            ret[i] = num[i];
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

#include <cstring>

int main(){
    // input & convert
    char a[101];
    scanf("%s", a);

    bigint sigA; // significand
    int expA; // exponent

    vector<int> temp;
    reverse(a, a+strlen(a));
    for(int i=0;a[i];++i){
        if(a[i] == '.')
            expA = i;
        else
            temp.push_back(a[i]-'0');
    }
    sigA = bigint(temp);

    // solve
    int b;
    scanf("%d", &b);
    
    bigint ans(sigA);
    int exp_ans = expA * b;
    for(int i=1;i<b;++i)
        ans = ans * bigint(sigA);

    // output
    temp = ans.vec();
    while(temp.size() <= exp_ans)
        temp.push_back(0);
    for(int i = temp.size()-1; i>=0; --i){
        if(i == exp_ans - 1)
            printf(".");
        printf("%d", temp[i]);
    }

    return 0;
}
