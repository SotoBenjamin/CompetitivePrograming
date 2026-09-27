#include <bits/stdc++.h>
#define INF 1e9;
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;
int n,q;
void slv(){
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int c3 = 0 , c5 = 0 , c10 = 0;

    for (int i = 0 ; i < n ; i++) {
        if (a[i] % 3 == 0) c3++;
        else if (a[i] == 5) c5++;
        else if (a[i] == 10) c10++;
    }
    cout<<(c3 + c5 + c10)<<" ";
    while(q--) {
        int p,x; cin>>p>>x;
        p--;
        if (a[p] % 3 == 0) c3--;
        else if (a[p] == 5) c5--;
        else if (a[p] == 10) c10--;
        a[p] = x;
        if (x % 3 == 0) c3++;
        else if (x == 5) c5++;
        else if (x == 10) c10++;

        cout<<(c3 + c5 + c10)<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
