#include <bits/stdc++.h>
//https://codeforces.com/contest/597/problem/B
using namespace std;
using ll = long long;
int n,m;

using i2 = pair<int, int>;

void slv() {
    vector<i2> a(n);
    for (int i = 0 ; i < n; i++) cin>>a[i].first>>a[i].second;
    ranges::sort(a, [&](const i2& p, const i2& q) {
        return p.second < q.second;
    });
    ll ans = 1;
    int end = a[0].second;
    for (int i = 1 ; i < n ; i++) {
        if (a[i].first > end) {
            end = a[i].second;
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        slv();
    }
    return 0;
}