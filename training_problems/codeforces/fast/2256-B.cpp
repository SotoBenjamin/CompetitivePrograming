#include <bits/stdc++.h>
#define INF 1e18
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;

//https://codeforces.com/contest/2256/problem/B
int n;

void f(string& s, int& ans){
	bool f = true;
	for(int i = 0 ; i < (int)s.size() ; i++){
		if(s[i] != '?') f = false;
	}
	if(f){
		ans *= 2;
		return;
	}
	

	string s1,s2;
	for(int i = 0 ; i < (int)s.size() ; i++){
		if(i % 2 == 0){
			s1 += '0';
			s2 += '1';
		}
		else{
			s1 += '1';
			s2 += '0';
		}
	}
	
	bool is_s1 = true, is_s2 = true;
	for(int i = 0 ; i < (int)s.size() ; i++){
		if(s[i] == '?') continue;
		if(s[i] != s1[i]){
			is_s1 = false;
		}
		if(s[i] != s2[i]){
			is_s2 = false;
		}
	}
	
	if(!is_s1 && !is_s2){
		ans*=0;
	}
	
	return;
}


void slv(){
	cin>>n;
	string s; cin>>s;
	string even,odd;
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 0) even += s[i];
		else odd += s[i];
	}
	int ans = 1;
	
	f(even,ans);
	f(odd,ans);
	
	cout<<ans<<"\n";
	
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
