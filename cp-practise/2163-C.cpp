#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define dbg(x) cerr<<#x<<" : "<<x<<endl;
#define all(x) x.begin(),x.end()
#define pb push_back
#define EPS 1e-9
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
vector<vector<int>> M;


vector<int> premn,premx,sufmn,sufmx;


int largestPgreater(int x){
	int ans = -1;
	int l = 0 , r = n-1;
	while(l <= r){
		int m = (l+r)/2;
		if(premn[m] >= x){
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}
	return ans;
}


int largestPless(int x,int R){
	int ans = -1;
	int l = 0 , r = R;
	while(l <= r){
		int m = (l+r)/2;
		if(premx[m] <= x){
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}
	return ans;
}

int lowestSgreater(int x){
	int ans = -1;
	int l = 0 , r = n-1;
	while(l <= r){
		int m = (l+r)/2;
		if(sufmn[m] >= x){
			ans = m;
			r = m-1;
		}
		else l = m+1; 
	}
	return ans;
}

int lowestSless(int x,int L){
	int l = L ,r = n-1;
	int ans = -1;
	while(l <= r){
		int m = (l+r)/2;
		if(sufmx[m] <= x){
			ans = m;
			r = m-1;
		}
		else l = m+1;
	}
	return ans;
}

bool fo(int l1,int r1){
    int i = largestPgreater(l1);
    if(i == -1) return false;
    int j = largestPless(r1,i);
    if(j == -1) return false;
    int k = lowestSgreater(l1);
    if(k == -1) return false;
    int m = lowestSless(r1,k);
    if(m == -1) return false;
    return j >= m;
}

int f(int x){
    int l = x , r = 2*n;
    int ans = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(fo(x,m)){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    return ans;
}


void slv(){
    cin>>n;
    M.assign(2,vector<int>(n));
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < n ; j++) cin>>M[i][j];
        
    premn.assign(n,M[0][0]);
    premx.assign(n,M[0][0]);
	sufmn.assign(n,M[1][n-1]);
	sufmx.assign(n,M[1][n-1]);
	for(int i = 1 ; i < n ; i++){
		premn[i] = min(premn[i-1],M[0][i]);
		premx[i] = max(premx[i-1],M[0][i]);
	}
	
	for(int i = n-2 ; i >= 0 ; i--){
		sufmn[i] = min(sufmn[i+1],M[1][i]);
		sufmx[i] = max(sufmx[i+1],M[1][i]);
	}
    
    ll ans = 0;
    for(int l = 1 ; l <= 2*n ; l++){
        int p = f(l);
        if(p == -1) continue;
        ans += 2*n - p + 1;
    }
    cout<<ans<<"\n";
}

int main(){
    int t; cin>>t;
	while(t--){
		slv();
	}
	return 0;
}
