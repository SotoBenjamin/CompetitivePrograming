#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
void slv() {
    vector<ll> ans;
    ll c = 0;
    for (int i = 1 ; i < s.size() ; i++) {
        if (s[i] == '|') {
            ans.push_back(c);
            c = 0;
        }
        else {
            c++;
        }
    }
    for (auto& i : ans) cout<<i<<" ";
    cout<<"\n";
}



int main() {
    while (cin>>s) slv();
    return 0;
}