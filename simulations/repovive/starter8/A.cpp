#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
	int n,a,b; cin>>n>>a>>b;
	int ans = (a+b - 7*(n-1))/2;
	cout<<ans<<"\n";
	return 0;
}
