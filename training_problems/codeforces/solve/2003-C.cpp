#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/2003/C
using namespace std;
const ll INF = (ll) 1e18;
int n;


void slv() {
    cin>>n;
    vector<char> ans(n);
    map<char, int> mp;
    for (int i = 0 ; i < n ; i++) {
        char c; cin>>c;
        mp[c]++;
    }
    vector<pair<int,char>> a;
    for (auto& [c,f] : mp) a.emplace_back(f,c);
    sort(a.rbegin(), a.rend());
    int j = 0;
    for (int i = 0 ; i < n ; i++) {
        ans[i] = a[j].second;
        a[j].first--;
        if (i == n-1) break;
        j = (j + 1) % a.size();
        while (a[j].first == 0) {
            j = (j+1) % a.size();
        }
    }
    for (int i = 0 ; i < n ; i++) cout<<ans[i];
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}