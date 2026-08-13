#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 7
using namespace std;

int n,m;

void slv(){
    vector<int> a(n+1) , b(m+1);
    a[n] = INF , b[m] = INF;
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    for(int i = 0 ; i < m ; i++) cin>>b[i];
    int i = 0 , j = 0;
    ll ans = 0;
    while(i < n && j < m){
        if(a[i] < b[j]) {
            i++;
            continue;
        }
        if(b[j] < a[i]) {
            j++;
            continue;
        }
        
        int cur = a[i], cnt1 = 0;
        while(i < n && cur == a[i]){
            cnt1++;
            i++;
        }

        cur = b[j]; int cnt2 = 0;
        while(j < m && cur == b[j]){
            cnt2++;
            j++;
        }
        ans += (ll) cnt1 * cnt2;
    }
    cout<<ans<<"\n";
}

int main(){
    while(cin >> n >> m) slv();
    return 0;
}
