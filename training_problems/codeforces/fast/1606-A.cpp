#include <bits/stdc++.h>
using ll  = long long int;
using namespace std;
int n;
using i2 = pair<char,int>;

string s;
void slv() {
    cin>>s;
    string sp = s + '#';
    int cnt = 1;
    vector<i2> b;
    for (int i = 1 ; i < (int) sp.size(); i++) {
        if (sp[i] == sp[i-1]) {
            cnt++;
        }
        else {
            b.emplace_back(sp[i-1],cnt);
            cnt = 1;
        }
    }

    if (b.size() % 2 == 1) {
        cout<<s<<"\n";
        return;
    }
    s[0] = s[0] == 'a' ? 'b' : 'a';
    cout<<s<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}