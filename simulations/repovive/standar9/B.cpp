#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll k;
const ll MOD = 998244353;

ll f[200005];
ll p[200005];

void slv() {
    cin>>n>>k;
    ll ans;
    if (k == 1) ans = f[n];
    else ans = (f[k] * p[n-k]) % MOD;
    cout<<ans<<endl;
}



int main() {
    int t = 1; cin >> t;
    p[0] = 1;
    f[0] = 1;
    for (int i = 1 ; i <= 2e5 + 5 ; i++) {
        f[i] = (f[i-1] * i) % MOD;
        p[i] = (p[i-1] * 2) % MOD;
    }
    while (t--) slv();
    return 0;
}