#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
 
const ll mod = 1e9+7;
const ll inf = INT64_MAX;   
const ll ninf = INT64_MIN;
const int MAX = 2e5; 
ll ans = inf;
ll s = 0;
void f(int idx , int n , vector<ll>& v , ll sum_act){
    if( idx == n){
        ans = min(ans , max(s-sum_act,sum_act));
        return;
    }
 
    sum_act += v[idx];
    f(idx + 1 , n , v , sum_act);
    sum_act -= v[idx];
    f(idx + 1 , n , v , sum_act );
}
 
void solve(){
    int n; cin>>n;
    vector<ll> v(n);
    
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
        s += v[i];
    }
 
    f(0 , n , v, 0);
 
    cout<<ans<<"\n";   
}
 
int main(){
    cpu();
    int t = 1; 
    //cin>>t;
 
 
    solve();
        
 
    return 0;
}