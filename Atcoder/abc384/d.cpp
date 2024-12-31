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





    void slv(int n){ 
        ll s; cin>>s;
        ll a[n+1]; 
        for(int i = 1 ; i <= n ; i++) cin>>a[i];
        set<ll> prefix;
        ll s2 = 0;
        for(int i = 1 ; i <= n ; i++){
            prefix.insert(s2);
            s2 += a[i];
        }
        prefix.insert(s2);

        ll suffix[n+1];
        suffix[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            suffix[i] = suffix[i-1] + a[n-i+1];
        }

        for(int i = 0 ; i <= n ; ++i){
            ll t = s - suffix[i];
            //s2 max preffix
            if( prefix.find(t % s2) != prefix.end()){
                cout<<"Yes"<<"\n";
                return;
            }
        }

        cout<<"No"<<"\n";

    }
        
    int main(){
        //freopen("d.in" , "r" , stdin);
        while(cin>>n){
            slv(n);
        }
        return 0;
    }