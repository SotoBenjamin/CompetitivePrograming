#include <bits/stdc++.h>
#define ll long long
using namespace std;
int NOP = -1;
class Stree {
    vector<ll> tree;
    vector<ll> op;
    int sz = 0;

    void apply(int x, ll  v) {
        tree[x] = v;
        op[x] = v;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1 || op[x] == NOP) return;
        apply(2*x+1,op[x]);
        apply(2*x+2,op[x]);
        op[x] = NOP;
    }

    void modify(int l, int r, ll v, int x, int lx, int rx) {
        if (l >= rx || r <= lx) return;
        if (lx >= l && rx <= r) {
            apply(x,v);
            return;
        }
        propagate(x,lx,rx);
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1 , lx , m);
        modify(l, r, v, 2 * x + 2, m , rx);
    }

    ll get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return tree[x];
        }
        propagate(x,lx,rx);
        int m = (lx + rx) / 2;
        ll res = 0;
        if (i < m) res = get(i, 2*x + 1, lx, m);
        else res = get(i, 2*x + 2, m, rx);
        return res;
    }

public:
    Stree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tree.assign(2*sz, 0);
        op.assign(2*sz,NOP);
    }

    void modify(int l, int r, ll v) {
        modify(l, r, v, 0 , 0 , sz);
    }

    ll get(int i) {
        return get(i,0,0,sz);
    }
};

int n,m;
int main() {
    cin>>n>>m;
    Stree st(n);
    while (m--) {
        int type; cin>>type;
        if (type == 1) {
            int l,r; ll v; cin>>l>>r>>v;
            st.modify(l,r,v);
            continue;
        }
        int id; cin>>id;
        cout<<st.get(id)<<"\n";
    }
    return 0;
}
