#include<cstdio>
#include<string>
using namespace std;

string p[5] = {"..#..", ".#.#.", "#...#", ".#.#.", "..#.."};
string w[5] = {"..*..", ".*.*.", "*...*", ".*.*.", "..*.."};

int main(){
    char str[16] = {0};
    scanf("%s",str);

    string ans[5] = {".", ".", "#", ".", "."};
    for(int i=0;str[i];++i){
        if((i+1)%3){
           for(int j=0;j<5;++j)
               for(int k=1;k<5;++k)
                   ans[j].push_back(p[j][k]);
        }else{
            for(int j=0;j<5;++j){
                ans[j].pop_back();
                for(int k=0;k<5;++k)
                    ans[j].push_back(w[j][k]);
            }
        }
        ans[2][4*i+2] = str[i];
    }
    
    for(int i=0;i<5;++i)
        puts(ans[i].c_str());
    return 0;
}
