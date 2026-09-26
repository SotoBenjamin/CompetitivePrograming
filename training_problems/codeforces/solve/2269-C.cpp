#include <bits/stdc++.h>
//https://codeforces.com/contest/597/problem/B
using namespace std;
using ll = long long;
int n,k;

using i2 = pair<int, int>;

ll f(vector<int>& a,int l , int r, int op) {
    ll ans = 0;
    while (op > 0 && l <= r) {
        if (a[l] > a[r]) {
            ans += a[l];
            l++;
        }
        else {
            ans += a[r];
            r--;
        }
        op--;
    }
    l = k-1 , r = n-k+2;
    while (op > 0) {
        if (a[l] > a[r]) {
            ans += a[l];
            l--;
            r++;
        }
        else {
            ans += a[r];
            r++;
            l--;
        }
        op--;
    }

    return ans;
}

ll g(vector<int>& a,int l , int r, int op) {
    ll ans = 0;
    while (op > 0) {
        if (a[l] > a[r]) {
            ans += a[l];
            l++;
            r--;
        }
        else {
            ans += a[r];
            l++;
            r--;
        }
        op--;
    }
    return ans;
}


void slv() {
    cin>>n>>k;
    vector<int> a(n+1);
    for (int i = 1 ; i <= n ; i++) cin>>a[i];
    int op = n-k+1;
    int l = k, r = n-k+1;
    ll ans = 0;
    if (l <= r) ans = f(a,l,r,op);
    else ans = g(a,l,r,op);
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1; cin>>t;
    while (t--) {
        slv();
    }
    return 0;
}