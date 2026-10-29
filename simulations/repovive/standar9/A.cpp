#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;

void slv() {
    cin>>n;
    int d[n+1];
    for (int i = 1 ; i <= n ; i++) cin>>d[i];
    vector<int> p(n+1,-1);
    for (int i = 1 ; i <= n ; i++) {
        if (p[i] != -1) {
            if (abs(i - p[i]) != d[i]) {
                cout<<"No\n";
                return;
            }
            continue;
        }
        if (i + d[i] > n) {
            cout<<"No\n";
            return;
        }
        int x = i + d[i];
        if (abs(x - i) != d[x]) {
            cout<<"No\n";
            return;
        }
        p[i] = x;
        p[x] = i;

    }


    vector<vector<int>> ad(n+1);

    for (int i = 1 ; i <= n ; i++) {
        if (p[i] == -1) {
            cout<<"No\n";
            return;
        }
        if (abs(i-p[i]) != d[i]) {
            cout<<"No\n";
            return;
        }
        ad[i].push_back(p[i]);
    }

    for (int i = 1 ; i <= n ; i++) {
        if (ad[i].size() == 0) {
            cout<<"No\n";
            return;
        }
        if (ad[i].size() > 1) {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main() {
    int t = 1; cin >> t;
    while (t--) slv();
    return 0;
}