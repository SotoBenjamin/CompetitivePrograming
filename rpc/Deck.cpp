#include <bits/stdc++.h>
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

const ll mod = 1e9+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 

vector<vector<int>> ap(1e4 + 1);
vector<vector<int>> bp(1e4 + 1);


vector<int> a(2e5);
vector<int> b(2e5);

signed slv() {
    int n,k; cin>>n>>k;
    for(int i = 1 ; i <= n*k ; i++){
        cin>>a[i];
        ap[a[i]].push_back(i);
    }
    for(int i = 1 ; i <= n*k ; i++){
        cin>>b[i];
        bp[b[i]].push_back(i);
    }




    // for(int i = 1 ; i <= n ; i++){
    //     ap[i].push_back(n*k+1);
    //     bp[i].push_back(n*k+1);
    //     reverse(ap[i].begin() , ap[i].end());
    //     reverse(bp[i].begin() , bp[i].end());
    //     ap[i].pop_back();
    //     bp[i].pop_back();
    // }

    // for(int i = 1; i <= n ; i++){
    //     for(auto j  : ap[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 1; i <= n ; i++){
    //     for(auto j  : bp[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    int i = 1 , j = 1;
    int ans = 0 ;
    while(i <= n*k && j <= n*k){
        // DBGS(a[i]);
        // DBGS(b[j]);
        if(a[i] == b[j]){
            ans++;
            i++;
            j++;
            // cout<<endl;
            continue;
        }
        int disa = 0;
        for(auto &item : ap[b[j]]){
            if(item > i){
                disa = item;
                break;
            }
        }
        int disb = 0;
        for(auto& item : bp[a[i]]){
            if(item > j){
                disb = item;
                break;
            }
        }

        if( disa  == 0){
            j++;
            // cout<<endl;
            continue;
        }
        if(disb == 0){
            i++;
            // cout<<endl;
            continue;
        }

      
        if( disa < disb){
            i++;
        }
        else if(disa > disb){
            j++;
        }
        else{
            if(disa - i <= disb - j){
                i++;
            }
            else{
                j++;
            }
        }
        // cout<<endl;
    }

    for(;j<=n*k;j++){
        if(a[i-1] == b[j] ) {ans++; break;}
    }
    for(;i<=n*k;i++){
        if(a[i] == b[j-1]) {ans++;break;}
    }



    cout<<ans<<"\n";


    return 0;
}

signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}