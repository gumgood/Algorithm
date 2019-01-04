#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct segtree{
    int n;
    vector<long long> tree, lazy;

    segtree(int size) : n(size), tree(4*size), lazy(4*size) {}

    void propagate(int node,int l,int r){
        if(lazy[node]){
            if(l != r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            tree[node] += lazy[node] * (r-l+1);
            lazy[node] = 0;
        }
    }

    void add(int s,int e,int val) { add(s,e,val,1,0,n-1); }
    void add(int s,int e,int val,int node,int l,int r){
        propagate(node,l,r);
        if(r<s || e<l) return;
        if(s<=l && r<=e){
            lazy[node] += val;
            propagate(node,l,r);
            return;
        }
        int mid = (l+r)/2;
        add(s,e,val,2*node,l,mid);
        add(s,e,val,2*node+1,mid+1,r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long sum(int s,int e){ return sum(s,e,1,0,n-1); }
    long long sum(int s,int e, int node,int l,int r){
        propagate(node,l,r);
        if(r<s || e<l) return 0;
        if(s<=l && r<=e) return tree[node];
        int mid = (l+r)/2;
        return sum(s,e,2*node,l,mid) + sum(s,e,2*node+1,mid+1,r);
    }
};


int main(){
    int n, q1, q2;
    scanf("%d%d%d",&n,&q1,&q2);
    
    segtree st(n+1);
    for(int i=1;i<=n;++i){
        int ai;
        scanf("%d",&ai);
        st.add(i,i,ai);
    }
    for(int i=0;i<q1+q2;++i){
        int q, s, e, l;
        scanf("%d",&q);
        if(q==1){
            scanf("%d%d",&s, &e);
            printf("%lld\n",st.sum(s,e));
        }else{
            scanf("%d%d%d",&s,&e,&l);
            st.add(s,e,l);
        }
    }
    return 0;
}
