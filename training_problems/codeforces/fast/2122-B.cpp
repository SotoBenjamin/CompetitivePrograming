#include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/2122/B
using ll  = long long int;
using namespace std;
int n;
ll a[200005] , b[200005] , c[200005] , d[200005];

void slv() {
    cin>>n;
    ll op = 0;
    for (int i = 0 ; i < n ; i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    for (int i = 0 ; i < n ; i++) {
        ll d0 = 0;
        ll d1 = 0;
        if (a[i] > c[i]) d0 = a[i] - c[i];
        if (b[i] > d[i]) d1 = b[i] - d[i];
        op += d0;
        a[i] -= d0;
        if (d1 > 0) {
            op += a[i] + d1;
        }
    }
    cout<<op<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}