#include<cstdio>
#include<stack>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    
    stack<int> st;
    for(;t;t/=9)
        st.push(t%9);
    while(!st.empty()){
        printf("%d",st.top());
        st.pop();
    }
    return 0;
}
