#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

char in[102];

bool chk(){
    stack<char> st;
    for(int i=0;in[i];++i){
        if(in[i]=='(' || in[i]=='['){
            st.push(in[i]);
        }else if(in[i]==')'){
            if(!st.empty() && st.top()=='(')
                st.pop();
            else return false;
        }else if(in[i]==']'){
            if(!st.empty() && st.top()=='[')
                st.pop();
            else return false;
        }
    }
    return st.empty();
}

int main(){
    while(true){
        fgets(in,102,stdin);
        if(!strcmp(in,".\n"))
            break;
        printf("%s\n",chk()?"yes":"no");
    }
    return 0;
}
