#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int n;

bool f(ll x) {
    if (x == 1) return true;
    if (x == 2) return false;
    ll p = 1;
    while (p < x) p*=2;
    p = p/2;
    return !f(x-p);
}

char inv(char c) {
    if (std::islower(c)) {
        return (char) toupper(c);
    }
    return (char) tolower(c);
}

void slv() {
    n = s.size();
    s = '#' + s;
    int q; cin>>q;
    while (q--) {
        ll k; cin>>k;
        ll id = (k-1) % n + 1;
        ll x = (k + n-1)/n;
        //cout<<id<<" "<<x<<endl;
        bool ok = f(x);
        if (ok) {
            cout<<s[id]<<" ";
            continue;
        }
        cout<<inv(s[id])<<" ";
    }
    cout<<"\n";
}



int main() {
    while (cin>>s) slv();
    return 0;
}