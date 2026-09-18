//
// Created by bsoto on 9/18/26.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF  = (ll) 1e18;
int n;

ll f(ll* a, int k) {
    vector<ll> b;
    ll s = 0;
    int cnt = 0;
    for (int i = 0 ; i < n ; i++) {
        s += a[i];
        cnt++;
        if (cnt == k) {
            b.push_back(s);
            cnt = 0;
            s = 0;
        }
    }
    return *ranges::max_element(b) - *ranges::min_element(b);
}

void slv() {
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans = -INF;
    for (int k = 1 ; k*k <= n ; k++) {
        if (n %  k != 0) continue;
        //cout<<k<<" "<<n/k<<endl;
        ans = max(ans,f(a,k));
        ans = max(ans,f(a,n/k));
    }
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) slv();
    return 0;
}