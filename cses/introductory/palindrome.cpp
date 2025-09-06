#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << " = " << x << '\n';
#define dbgs(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;


ll k;

void slv(){
    string s; cin>>s;
    int n = s.size();
    int a[26];
    int k = 0;
    for(int i = 0 ; i < 26 ; i++) a[i] = 0;
    for(int i = 0 ; i < n ; i++) a[s[i]-'A']++;
    int cnt = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(a[i] & 1) {cnt++; k = i;}
    }
    if(cnt >= 2){
        cout<<"NO SOLUTION"<<"\n";
        return;
    }
    vector<char> ans(n);
    if(n % 2 == 0 ){
        if( cnt == 1 ){
            cout<<"NO SOLUTION"<<"\n";
            return;
        }
        int j = 0;
        int l = 0 , r = n-1;
        while(l <= r){
            while( j < n && a[j] == 0) j++;
            if( j >= n ){
                l++;
                r--;
                continue;
            }
            ans[l] = j + 'A';
            ans[r] = j + 'A';
            a[j] -= 2;
            l++;
            r--;
        }
        for(int i = 0 ; i < n ; i++) cout<<ans[i];
        cout<<"\n";
        return;
    }
    ans[n/2] = k + 'A';
    a[k]--;
    int l = 0 , r = n-1;
    int j = 0;
    while(l <= r){
        while( j < n && a[j] == 0) j++;
        if( j >= n ){
            l++;
            r--;
            continue;
        }
        ans[l] = j + 'A';
        ans[r] = j + 'A';
        a[j] -= 2;
        l++;
        r--;
    }
    for(int i = 0 ; i < n ; i++) cout<<ans[i];
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int t = 1; //cin>>t;
    while(t--) slv();

    return  0;
}

