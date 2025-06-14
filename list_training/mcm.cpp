#include <bits/stdc++.h>
 
using namespace std;
 

#define ll long long
#define lld long double
const int mod = 1e9 + 7;
int n;  
int dp[105][105];



int mcm(int i,int j,int* p){
	if(dp[i][j] != -1){
	   return dp[i][j];
	}
	if(i == j) {
		dp[i][j] = 0;
		return 0;
	}
	if( j == i+1){
		dp[i][j] = p[i-1]*p[i]*p[i+1];
		return dp[i][j];
	}
	dp[i][j] = 1e9;
	for(int k = i ; k < j ; k++){
		dp[i][j] = min(dp[i][j] , mcm(i,k,p) + mcm(k+1,j,p) + p[i-1]*p[k]*p[j]);
	}
	return dp[i][j];
}


void solve_memoization() {
    cin>>n;
    int p[n+1];
    for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			dp[i][j] = -1;
		}
	}
    for(int i = 1 ; i <= n ; i++){
		cin>>p[i-1]>>p[i];
	}
	int ans = mcm(1,n,p);
	cout<<ans<<"\n";
}

void solve_tabulation(){
	cin>>n;
    int p[n+1];
    for(int i = 1 ; i <= n ; i++){
		cin>>p[i-1]>>p[i];
	}
    for(int i = 0 ; i <= n ; i++) dp[i][i] = 0;
    
    
	for(int l = 2 ; l <= n ; l++){
		for(int i = 1 ; i <= n-l +1; i++){
			int j = i + l -1;
			dp[i][j] = 1e9;
			for(int k = i ; k < j ; k++){
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]);
			}
		}
	}
	cout<<dp[1][n]<<"\n";
}
 
int main() {
  int t = 1;
  //cin >> t;
  while (t--) solve_tabulation();
  return 0;
}
