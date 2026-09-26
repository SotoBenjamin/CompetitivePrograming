#include <bits/stdc++.h>
#define INF 1e9;
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;

string s;
void slv(){
    cin>>s;
    int cnta = 0;
    for (int i = 0 ; i < (int) s.length(); i++)
        if (s[i] == '0') cnta++;
    int cntb = (int) s.length() - cnta;
    if (min(cnta, cntb) % 2 == 1) {
        cout<<"DA\n";
        return;
    }

    cout<<"NET\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
