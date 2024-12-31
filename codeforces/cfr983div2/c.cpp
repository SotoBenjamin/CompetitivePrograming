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
 
int n;
int findI(ll a[] , int j){
    int l = 0 , r = j ;
    int ans = -1;
    while( l <= r){
        int mid = (l+r)/2;
        if( a[mid] + a[mid+1] > a[j]){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

 
void slv(){ 
  
    cin>>n;
    ll a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    sort(a,a+n);
    int ans = n;

    for(int j = n - 1 ; j >= 0 ; j--){
        int i = findI(a,j);
        if( i != -1){
            ans = min(ans , n - j - 1 + i);
        }
    }
    cout<<ans<<"\n";

}
     
int main(){
    //freopen("c.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}