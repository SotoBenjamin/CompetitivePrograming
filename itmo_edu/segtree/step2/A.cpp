#include <bits/stdc++.h>
#define ll long long
const ll INF = (ll) 1e18;
using namespace std;



ll add(ll a, ll b){
  if(a == INF || b == INF) return INF;
  if(a == -INF || b == -INF) return -INF;
  return a + b;
}


struct Node{
    ll sum;
    ll pre;
    ll suf;
    ll max_seg;

    Node(ll s, ll p, ll sf, ll mx_sg){
        sum = s;
        pre = p;
        suf = sf;
        max_seg = mx_sg;
    }

    Node operator +(Node& o){
        ll sum1 = sum, pre1 = pre, suf1 = suf, max_seg1 = max_seg;
        ll sum2 = o.sum, pre2 = o.pre, suf2 = o.suf, max_seg2 = o.max_seg;
        ll max_seg_res = max(max_seg1, max(max_seg2, add(suf1,pre2)));
        ll pre_res = max(pre1, add(sum1,pre2));
        ll suf_res = max(suf2, add(sum2,suf1));
        ll sum_res = add(sum1,sum2);
        return {sum_res, pre_res, suf_res , max_seg_res};
    }
};

class Stree{
private:
    int sz = 0;
    vector<Node> tree;

    int left(int x){
    return 2*x + 1;
    }

    int right(int x){
        return 2*x + 2;
    }

    void init(int n){
        sz = 1;
        while(sz < n) sz *= 2;
        tree.assign(2 * sz, Node(0LL,-INF,-INF,-INF));
    }

    void build(vector<int>& a , int x, int lx, int rx){
        if (rx - lx == 1){
            if(lx < (int) a.size()){
                tree[x] = Node((ll)a[lx], (ll)a[lx], (ll)a[lx], (ll)a[lx]);
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, left(x), lx, m);
        build(a, right(x), m, rx);
        tree[x] = tree[left(x)] + tree[right(x)];
    }

    void set(int i, int v, int x, int lx, int rx){
        if (rx - lx == 1){
            tree[x] = Node((ll) v, (ll) v, (ll) v, (ll) v);
            return;
        }
        int m = (lx + rx)/2;
        if (i < m) set(i, v, left(x), lx, m);
        else set(i, v, right(x), m, rx);
        tree[x] = tree[left(x)] + tree[right(x)];
    }

    Node query(int l, int r, int x, int lx, int rx){
        if(rx <= l || lx >= r)
            return Node(0LL,-INF,-INF,-INF);

        if(lx >= l && rx <= r)
            return tree[x];

        int m = (lx + rx)/2;
        Node nl = query(l, r, left(x), lx, m);
        Node nr = query(l, r, right(x), m, rx);
        return nl + nr;
    }

public:
    Stree(int n){
        init(n);
    }

    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }

    void build(vector<int>& a){
        build(a, 0, 0, sz);
    }

    ll query(int l, int r){
        return query(l, r, 0, 0, sz).max_seg;
    }

  ll max_segment(){
    return max(query(0,sz), 0LL);
  }

};
int n,m;

void slv(){
    Stree st(n);
    vector<int> b(n);
    for(int i = 0 ; i < n ; i++) cin>>b[i];
    st.build(b);
    cout<<st.max_segment()<<"\n";
    while(m--){
        int i,v; cin>>i>>v;
        st.set(i,v);
        cout<<st.max_segment()<<"\n";
    }
}

int main(){
    while(cin>>n>>m) slv();
    return 0;
}
