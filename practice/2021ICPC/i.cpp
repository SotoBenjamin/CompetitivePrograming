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
typedef tuple<int,int,int> ti;
 
const ll mod = 1e9+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 
const int inf = INT_MAX;
 
const int MAX = 1e6;


map<string,int> mp = {{"Mon",0},{"Tue",1}, {"Wed",2},{"Thu",3}, 
{"Fri",4},{"Sat",5},{"Sun",6}};


ll initial_day(ll di , string day){
    return  (mp[day] - di%7 + 7)%7;
}

ll ndays(ll d0 , ll di){
    switch (d0){
    case 0:
        if(di <= 30){
            return 30 -di;
        }
        if( di > 30 && di <= 60){
            return 60-di;
        }
        if( di > 60 && di <= 91){
            return 91 - di;
        }
        return ndays(0,di%91);
    break;
    case 1:
        if( di <= 30){
            return 30-di;
        }
        if( di > 30 && di <= 62){
            return 62 - di;
        }
        return ndays(0,di-62);
    break;
    case 2:
        if( di <= 30){
            return 30-di;
        }
        if(di > 30 && di <= 61){
            return 61 - di;
        }
        return ndays(0,di-61);
    break;
    case 3:
        if( di <= 32){
            return 32 - di;
        }
        return ndays(0,di-32);
    break;
    case 4:
        if( di <= 31){
            return 31 -di;
        }
        return ndays(0,di-31);
    break;
    default:
        cout<<"Error"<<"\n";
        return -1;
        break;
    }
}

signed slv() {
    string s; cin>>s;
    int n; cin>>n;
    vector<ll> d(n);

    for(int i = 0 ;i <n;i++) cin>>d[i];

    ll ans = INT64_MAX;
    for(int i = 0; i<n;i++){
        ll d0 = initial_day(d[i] , s);
        ll x = ndays(d0,d[i]);
        ll z = (x+mp[s])%7;
        if( z > 4){
            x += (7-z);
        }
        ans = min(ans,x);
    }

    cout<<ans<<"\n";
    
    return 0;
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    
    while (t--) slv();
    return 0;
}