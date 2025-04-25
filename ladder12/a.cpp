#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
#define cpu()                                                                  \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);
#define ll long long
#define lld long double
const int mod = 1e9 + 7;
 
void solve() {
    int n,k;
    cin>>n>>k;
    ll a[n];
    ll b[n];
    for(ll& i : a) cin>>i;
    for(ll& i : b) cin>>i;
    if (all_of(b,b+n , [&](ll i){return i == -1; })){
        ll l = *max_element(a,a+n);
        ll r = k + *min_element(a,a+n);
        if(l > r){
            cout<<0<<"\n";
            return;
        }
        cout<<(r-l+1)<<"\n";
        return;
    }
  
    ll x = 0;
    for(int i = 0 ; i < n ; i++){
        if( b[i] != -1){
            x = b[i] + a[i];
            break;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(b[i] != -1){
            if( b[i] + a[i] != x){
                cout<<0<<"\n";
                return;
            }
        }
        else{
            if( x - a[i] > k || x - a[i] < 0){
                cout<<0<<"\n";
                return;
            }
        }
    }
    cout<<1<<"\n";
}
 
int main() {
  cpu();
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
  #endif
  int t;
  t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}