#include <bits/stdc++.h>
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
 
int n,m,q;
 


void slv(){ 
    cin>>n>>m>>q;
    
    int a[n] , b[m];
    ll k = 0 , t = 0;
    for(int i = 0 ; i < n ; i++) {cin>>a[i]; t += a[i];}
    for(int i = 0 ; i < m ; i++) {cin>>b[i]; k += b[i];}
    map<ll,bool> mp1,mp2;
    for(int i = 0 ; i < n ; i++) mp1[t - a[i]] = true;
    for(int i = 0 ; i < m ; i++) mp2[k - b[i]] = true;
   
    while(q--){
        ll x; cin>>x;
        //DBG(x);
        bool flag = false;
        if( x >= 0){
            for(ll i = 1 ; i*i <= x ; i++){
                if( x % i != 0){
                    continue;
                }

                if( mp1[i] && mp2[x/i]){
                    cout<<"YES"<<"\n";
                    flag = true;
                    break;
                }

                if( mp2[i] && mp1[x/i]){
                    flag = true;
                    cout<<"YES"<<"\n";
                    break;
                }

            }   
        }
        else{
            for(ll i = 1 ; i*i <= x ; i++){
                if( x % i != 0){
                    continue;
                }

                if( (mp1[-1*i] && mp2[x/i]) ||  (mp1[i] && mp2[-1*x/i]) ){
                    cout<<"YES"<<"\n";
                    flag = true;
                    break;
                }

                if( (mp2[-1*i] && mp1[x/i]) || (mp2[i] && mp1[-1*x/i])){
                    flag = true;
                    cout<<"YES"<<"\n";
                    break;
                }

            }   
        }

        if( flag ) continue;

        cout<<"NO"<<"\n";
    }
}
     
int main(){
    freopen("f.in" , "r" , stdin);
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}