#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
     
const ll mod = 1e9+7;
     
int nxt() {
    int x; cin >> x;
    return x;
}  
const int inf = INT_MAX;
template<typename T>
T minV(T a){
    return a;
}
template<typename T, typename ... Args>
T minV(T a , Args... arg){
    T b = minVariadic(arg...);
    return min(a,b);
}
int t;
int n;

void slv(){
    ll x;
    cin>>n>>x;
    vl a(n);
    for(ll& i : a) cin>>i;
    sort(all(a));
    ll mex = a[0];
    if ( mex != 0){
        cout<<0<<"\n";
        return;
    }
    mex++;
    map<ll,int> mp;
    int j = n;
    for(int i = 1 ; i < n ; i++){
        //DBG(a[i]);
        if(a[i] == a[i-1]){
            mp[a[i] % x]++;
            continue;   
        }

        if( a[i] != mex){
            j = i;
            break;
        }

        mex++;
        //DBG(mex);
    }
    ll i = mex;
    for(; i < n ; i++){
        while( j < n && i >= a[j] ){
            mp[a[j] % x]++;
            j++;
        }
        if (mp[i%x] == 0){
            cout<<i<<"\n";
            return;
        }
        mp[i%x]--;
    }
    cout<<i<<"\n";
}   
     
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif

    cin>>t;
    while(t--) slv();
    
    return 0;
}