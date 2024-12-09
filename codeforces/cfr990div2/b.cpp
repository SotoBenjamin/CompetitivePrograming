#include "bits/stdc++.h"
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll mod = 1e9+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 
const int inf = INT_MAX;
 



        
signed slv() {
	int n; cin >> n;
    string s; cin>>s;
    map<char,int> frec;
    for(int i = 0 ; i < n ; i++) frec[s[i]]++;

    if(frec.size() == 1){
        cout<<s<<"\n";
        return 0;
    }

    char c;
    int cnt = 0;
    for(auto & p : frec){
        if(p.second >= cnt){
            c = p.first;
            cnt = p.second;
        }
    }

    char c1 = '#';
    int cnt1 = 11;
    for(auto & p : frec){
        if(p.second <= cnt1 && p.first != c){
            c1 = p.first;
            cnt1 = p.second;
        }
    }


    int j = 0;
    int  k = 0;
    for(int i = 0 ; i < n ; i++){
        if( c1 == s[i]) j = i;
        if( c == s[i]) k = i;
    }

    s[j] = s[k];
   
    cout<<s<<"\n";

    return 0;
}
 
signed main(){
    //freopen("b.in","r",stdin);
    int t; cin>>t;
    while(t--) slv();
    return 0;
}