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
void slv(){ 
    cin>>n;
    int b[n];
    //1 1 1 2
    //1 2 2   
    // 1 2 3 4 5
    for(int i = 0 ; i < n ; i++) cin>>b[i];
    char a[n];
    bool flag = false;
    int i;
    for(i = 1 ; i < n ; i++){
        if( b[i] != b[i-1]){
            flag = true;
            break;
        }
    }

    if(!flag){
        cout<<"NO"<<"\n";
        return;
    }

    cout<<"YES"<<"\n";

    if( i == n-1){
        
        a[0] = 'B';
        for(int j = 1 ; j < n ; j++){
            a[j] = 'R';
        }

        for(int j = 0 ; j < n ; j++) cout<<a[j];
        cout<<"\n";
        return;
    }

    for(int j = 0 ; j < n ; j++){
        if( j != i){
            a[j] = 'R';
        }
        else{
            a[j] = 'B';
        }
    }
    for(int j = 0 ; j < n ; j++) cout<<a[j];
    cout<<"\n";
 
}
     
int main(){
    //freopen("b.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}