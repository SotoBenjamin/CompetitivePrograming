#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
void slv() {
    vector<int> cnt(10,0);
    for (int i = 0 ; i < 6 ; i++) cnt[s[i] - '0']++;
    if (cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3) {
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
}



int main() {
    while (cin>>s) slv();
    return 0;
}