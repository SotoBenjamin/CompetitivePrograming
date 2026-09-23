#include <bits/stdc++.h>
//https://codeforces.com/contest/637/problem/B
using namespace std;

int n,m;

void slv() {
    map<string,int> mp;
    for (int i=0;i<n;i++) {
        string s; cin>>s;
        mp[s] = i;
    }
    vector<pair<int,string>> a;
    for (auto& [s,i] : mp) a.emplace_back(i,s);
    sort(a.rbegin() , a.rend());
    for (auto & i : a) {
        cout<<i.second<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        slv();
    }
    return 0;
}