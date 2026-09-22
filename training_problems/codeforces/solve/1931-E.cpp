#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/1931/E
using namespace std;
const ll INF = (ll) 1e18;
int n,m;

int leading_zeros(ll a) {
    string s = to_string(a);
    int n = s.size();
    int idx = n-1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] != '0') {
            idx= i;
            break;
        }
    }
    return n-1-idx;
}

void slv() {
    cin>>n>>m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    ll d = 0;
    vector<pair<ll,ll>> b;
    for (int i = 0 ; i < n ; i++) {
        int x = leading_zeros(a[i]);
        if (x == 0) {
            d += (ll) to_string(a[i]).size();
            continue;
        }
        b.emplace_back(x,a[i]);
    }
    sort(b.rbegin(), b.rend());
    if (d >= m+1) {
        cout<<"Sasha\n";
        return;
    }

    for (int i = 0 ; i < (int) b.size() ; i++) {
        if (i % 2 == 0) {
            d += (ll) to_string(b[i].second).size() - b[i].first;
        }
        else {
            d += (ll) to_string(b[i].second).size();
        }
    }

    if (d >= m+1) {
        cout<<"Sasha\n";
    }
    else cout<<"Anna\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
