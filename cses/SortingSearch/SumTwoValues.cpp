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
int n,m,k;
ll x;


void slv(){
    cin>>x;
    vpll a(n);
    for(int i = 0 ; i < n ; i++) {
        ll item; cin>>item;
        a[i].fi = item;
        a[i].se = i;
    }
    
    sort(all(a));

    int l = 0 , r = n-1;
    while(l < r){
        if (a[l].fi + a[r].fi == x){
            ll l1 = min(a[l].se , a[r].se);
            ll r1 = max(a[l].se , a[r].se);
            l1++;
            r1++;
            cout<<l1<<" "<<r1<<"\n";
            return;
        }
        else if(a[l].fi + a[r].fi > x){
            r--;
        }
        else{
            l++;
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}   
     
int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);    
    // freopen("output.txt","w",stdout);
    // #endif


    while(cin>>n) slv();
    return 0;
}