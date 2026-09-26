#include <bits/stdc++.h>
#define INF 1e9;
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;

void slv(){
    ll w,h; cin>>w>>h;
    ll ans = 0;
    ll d = h;
    for (int i = 0 ; i < 4 ; i++) {
        int k; cin>>k;
        vector<ll> v(k);
        for (int j = 0 ; j < k ; j++) cin>>v[j];
        ans = max(ans , (v.back() - v.front()) * d );
        if (i == 1) {
            d = w;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
