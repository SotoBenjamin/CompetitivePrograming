#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll NOP = -1;

class Stree {

    vector<ll> val , op;
    int sz = 0;

    void apply(int x, ll v) {
        val[x] += v;
        if (op[x] == NOP) op[x] = v;
        else op[x] += v;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1 || op[x] == NOP) return;
        apply(2*x+1,op[x]);
        apply(2*x+2,op[x]);
        op[x] = NOP;
    }

    void push(int x) {
        val[x] = std::min(val[2*x+1] , val[2*x+2]);
    }

    void modify(int l, int r, ll v, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return;
        if (lx >= l && rx <= r) {



            
            apply(x,v);
            return;
        }
        propagate(x,lx,rx);
        int m = (lx + rx)/2;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        push(x);
    }

    ll calc(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return LLONG_MAX;
        if (lx >= l && rx <= r) {
            return val[x];
        }
        propagate(x,lx,rx);
        int m = (lx + rx)/2;
        ll m1 = calc(l,r,2*x+1,lx,m);
        ll m2 = calc(l,r,2*x+2,m,rx);
        return std::min(m1,m2);
    }

public:

    Stree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        val.assign(2*sz,0);
        op.assign(2*sz,NOP);
    }

    void modify(int l, int r, ll v) {
        modify(l,r,v,0,0,sz);
    }

    ll calc(int l, int r) {
       return calc(l,r,0,0,sz);
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
        int l,r; cin>>l>>r;
        cout<<st.calc(l,r)<<"\n";
    }
    return 0;
}