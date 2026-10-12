#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k;

using i3 = tuple<ll,ll,ll>;

ll cnt(ll a, ll b, ll c, ll t) {
    vector<ll> temp = {a,b,c};
    if (!ranges::is_sorted(temp)) return t - (a+b+c);
    ll m1 = LLONG_MAX;
    ll m2 = LLONG_MAX;
    if ( a < c) {
        m1 = (b-a+1) + t - (2*a - 1 + c);
    }
    if ( a < b) {
        m2 = c-b+1 + t - (2*b - 1 + a);
    }
    return min(m1,m2);
}

bool go(vector<i3>& v, ll t) {
    ll op = 0;
    for (int i = 0 ; i < n ; i++) {
        auto& [a,b,c] = v[i];
        if (a+b+c >= t) continue;
        if ( a == b && b == c ) return false;
        ll x =  cnt(a,b,c,t);
        if (x == LLONG_MAX) return false;
        op += x;
        if (op > k) return false;
    }
    return op <= k;
}

void slv() {
    cin >> n >> k;
    vector<i3> v(n);
    for (int i = 0 ; i < n ; i++) {
        ll a,b,c; cin>>a>>b>>c;
        v[i] = {a,b,c};
    }
    ll l = get<0>(v[0]) + get<1>(v[0]) + get<2>(v[0]);
    for (int i = 1 ; i < n ; i++) l = min(l,get<0>(v[i]) + get<1>(v[i]) + get<2>(v[i]));
    ll r = 4e18;
    ll ans = -1;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (go(v,m)) {
            ans = m;
            l  = m + 1;
        }
        else r = m - 1;
    }
    cout<<ans<<"\n";
}

int main() {
    int t = 1; cin >> t;
    while (t--) slv();
    return 0;
}