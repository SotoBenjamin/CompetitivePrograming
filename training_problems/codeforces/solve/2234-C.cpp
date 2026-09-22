#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/2234/C
using namespace std;
const ll INF = (ll) 1e18;
int n;

int nxt(int i) {
    return (i+1) % n;
}

int prv(int i) {
    return (i-1 + n) % n;
}

void slv() {
    cin>>n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin>>h[i];
    for (int i = 0 ; i < n ; i++) {
        vector<ll> w(n);
        w[i] = 0;
        int k = nxt(i);
        for (int j = 0 ; j < n-1 ; j++) {
            w[k] = max(w[prv(k)],h[prv(k)]);
            k = nxt(k);
        }
        k = prv(i);
        for (int j = 0 ; j < n-1 ; j++) {
            w[k] = min(w[k] , max(h[k] , w[nxt(k)]));
            k = prv(k);
        }
        ll s = 0;
        for (int j = 0 ; j < n ; j++) s += w[j];
        cout<<s<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}