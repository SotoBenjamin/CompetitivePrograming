#include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/2050/D
using namespace std;
void slv() {
    string s;
    cin>>s;
    for (int i = 0 ; i < (int) s.size() ; i++) {
        int mx = s[i] - '0';
        int idx = i;
        for (int j = i ; j  <= min(i + 9 , (int) s.size() - 1) ; j++) {
            int x = s[j] - '0';
            if (x -j + i > mx) {
                mx = x -j + i;
                idx = j;
            }
        }

        int k = idx;
        while (k > i) swap(s[k],s[k-1]) , k--;
        s[i] = (char) (mx + 48);
    }
    cout<<s<<"\n";
}

int main() {
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}