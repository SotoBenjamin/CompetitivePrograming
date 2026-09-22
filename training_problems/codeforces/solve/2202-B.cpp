#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/2202/B
using namespace std;
const ll INF = (ll) 1e18;
int n;

string s;
void slv() {
    cin>>n;
    cin>>s;

    int a = (n+1)/2 , b = n/2;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == 'b') b--;
        else if (s[i] == 'a') a--;
    }

    
    if (n % 2 == 1) {
        if (s[0] == 'b') {
            cout<<"NO"<<"\n";
            return;
        }
        if (s[0] == '?') {
            if (a == 0) {
                cout<<"NO"<<"\n";
                return;
            }
            s[0] = 'a';
            a--;
        }
    }

    int i = n % 2 == 0 ? 0 : 1;
    while (i < n) {
        if (s[i] == 'a' && s[i+1] == 'b') {
            i+=2;
            continue;
        }
        if (s[i] == 'b' && s[i+1] == 'a') {
            i += 2;
            continue;
        }
        if (s[i] != '?' && s[i] == s[i+1]) {
            cout<<"NO"<<"\n";
            return;
        }

        if (s[i] == '?') {
            if (s[i+1] == 'a') {
                if (b == 0) {
                    cout<<"NO"<<"\n";
                    return;
                }
                s[i] = 'b';
                b--;
            }
            else if (s[i+1] == 'b') {
                if (a == 0) {
                    cout<<"NO"<<"\n";
                    return;
                }
                s[i] = 'a';
                a--;
            }

        }
        else {
            if (s[i] == 'a') {
                if (b == 0) {
                    cout<<"NO"<<"\n";
                    return;
                }
                s[i+1] = 'b';
                b--;
            }
            else if (s[i] == 'b') {
                if (a == 0) {
                    cout<<"NO"<<"\n";
                    return;
                }
                s[i+1] = 'a';
                a--;
            }
        }
        i += 2;
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}