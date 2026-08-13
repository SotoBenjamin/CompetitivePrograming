#include <bits/stdc++.h>
#define ll long long
//#define int long long 
using namespace std;

int n,q;
string s;


int query(vector<vector<int>>& M, int x1, int y1, int x2, int y2){
	int A = 0,B = 0,C = 0;
	if(x1 >= 1) A = M[x1-1][y2];
	if(y1 >= 1) B = M[x2][y1-1];
	if(x1 >= 1 && y1 >= 1) C = M[x1-1][y1-1];
	return M[x2][y2] - A - B + C;
}


void slv(){
	n = (int) s.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i = 0 ; i < n ; i++) dp[i][i] = 1;
	for(int l = 2 ; l <= n ; l++){
		for(int i = 0 ; i < n -l + 1; i++){
			int j = i+l-1;
			if(s[i] == s[j]){
				if(i+1 <= j-1) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 1;
			} 
			else dp[i][j] = 0;
		}
	}
	
	/*
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	
	vector<vector<int>> M(n,vector<int>(n,0));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			M[i][j] = dp[i][j];
			if(i > 0 && j > 0) M[i][j] += M[i-1][j] + M[i][j-1] - M[i-1][j-1];
			else if(i > 0) M[i][j] += M[i-1][j];
			else if(j > 0) M[i][j] += M[i][j-1];
		}
	}
	/*
	cout<<"---------------\n";
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<M[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	
	
	cin>>q;
	while(q--){
		int l,r; cin>>l>>r;
		l--; r--;
		cout<<query(M,l,l,r,r)<<"\n";
	}
	
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>s) slv();
	return 0;
}
