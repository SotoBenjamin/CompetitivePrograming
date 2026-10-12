#include <bits/stdc++.h>
using namespace std;
int n;
void slv() {
    cin>>n;
    string s; cin >> s;
    int ans = n-1;
    for (int i = 2 ; i < n ; i+=2) {
        if (s[i] == s[i-2]) ans--;
    }

    for (int i = 3 ; i < n ; i += 2) {
        if (s[i] == s[i-2]) ans--;
    }
    cout << ans << "\n";
}


int main() {
    int t = 1; cin>>t;
    while (t--) slv();
    return 0;
}
