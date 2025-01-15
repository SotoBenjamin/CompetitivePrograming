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


void slv(){
    ll n,b,c;
    cin>>n>>b>>c;

    if ( n < c){
        cout<<n<<"\n";
        return;
    }


    if( b == 0){

        if ( c >= n){
            cout<<n<<"\n";
            return;
        }
        // c < n 
        if ( n-2 <= c){
            cout<<(n-1)<<"\n";
            return;
        }

        cout<<-1<<"\n";
        return;
    }
    ll j = (n - c + b-1)/b +1;
    cout<<(n - j + 1)<<"\n";
}   
     
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif


    while(cin>>t) {
        while(t--) slv();
    }
    return 0;
}