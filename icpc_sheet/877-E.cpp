#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = (int)2e5 + 5;
int n;
vector<int> adj[N];
vector<int> a;
vector<int> tin;
vector<int> tout;
vector<int> b;
int temp = 0;
void dfs(int u, int p) {
    tin[u] = temp;
    b[temp] = a[u];
    temp++;
    for (auto& v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = temp;
}

const int NONE = 0;
const int INVERT = 1;


class Stree {

    vector<int> val;
    vector<int> op;
    int sz = 1;

    void build(vector<int>& a , int x, int lx, int rx){
        if (rx - lx == 1){
            if(lx < (int) a.size()){
                val[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        val[x] = val[2*x + 1] +val[2*x +2];
    }

    void apply(int x, int lx, int rx) {
        int len = rx - lx;
        val[x] = len - val[x];
        if (op[x] == INVERT) op[x] = NONE;
        else op[x] = INVERT;
    }

    void propagate(int x, int lx, int rx) {
        if ( rx - lx == 1 || op[x] == NONE) return;
        int m = (lx + rx)/2;
        apply(2*x+1,lx,m);
        apply(2*x+2,m,rx);
        op[x] = NONE;
    }

    void push(int x) {
        val[x] = val[2*x + 1] +val[2*x + 2];
    }

    void modify(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return;
        if (lx >= l && rx <= r) {
            apply(x,lx,rx);
            return;
        }
        propagate(x,lx,rx);
        int m = (lx + rx)/2;
        modify(l,r,2*x+1,lx,m);
        modify(l,r,2*x+2,m,rx);
        push(x);
    }

    int calc(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) return 0;
        if (lx >= l && rx <= r) {
            return val[x];
        }
        propagate(x,lx,rx);
        int m = (lx + rx)/2;
        int s1 = calc(l,r,2*x+1,lx,m);
        int s2 = calc(l,r,2*x+2,m,rx);
        return s1 + s2;
    }

public:

    Stree(int n, vector<int>& a) {
        while (sz < n) sz *= 2;
        val.assign(2*sz, 0);
        op.assign(2*sz, NONE);
        build(a, 0, 0, sz);
    }

    void modify(int l, int r) {
        modify(l, r, 0, 0, sz);
    }

    int calc(int l, int r) {
        return calc(l, r, 0, 0, sz);
    }


};
void slv() {
    for (int i = 1 ; i < n ; i++) {
        int u; cin>>u; u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    a.assign(n, 0);
    b.assign(n, 0);
    tin.assign(n, 0);
    tout.assign(n, 0);
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    dfs(0,-1);
/*
    for (int i = 0 ; i < n ; i++)
        cout<<b[i]<<" ";

    cout<<endl;

    for (int i = 0 ; i < n ; i++)
            cout<<tin[i]<<" "<<tout[i]<<endl;
    cout<<endl;
*/
    int q; cin>>q;
    Stree st(n,b);

    while (q--) {
        string type;
        int v;
        cin>>type>>v;
        v--;
        int l = tin[v] , r = tout[v];
        if (type == "get") {
            cout<<st.calc(l,r)<<"\n";
            continue;
        }
        st.modify(l,r);
    }
}

int main() {
    while (cin >> n) {
        slv();
        for (int i = 0 ; i < n ; i++) adj[i].clear();
    }
    return 0;
}