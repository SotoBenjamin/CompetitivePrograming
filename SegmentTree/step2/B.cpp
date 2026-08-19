#include <bits/stdc++.h>
#define ll long long

using namespace std;


class Stree{
private:
	int sz = 0;
	vector<int> tree;
	
	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		tree.assign(2*sz,0);
	}
	
	int left(int x){
		return 2*x + 1;
	}
	
	int right(int x){
		return 2*x + 2;
	}
	
	void set(int i, int v, int x, int lx, int rx){
		if (rx - lx == 1){
			tree[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m) set(i, v, left(x), lx, m);
		else set(i, v, right(x), m, rx);
		tree[x] = tree[left(x)] + tree[right(x)];
	}
	
	int query(int l, int r, int x, int lx, int rx){
		if(l >= rx || r <= lx){
			return 0;
		}
		
		if(lx >= l && rx <= r){
			return tree[x];
		}
		
		int m = (lx + rx)/2;
		int ql = query(l,r,left(x),lx,m);
		int qr = query(l,r,right(x),m,rx);
		return ql + qr;
	}
	
	int kth(int x, int lx, int rx, int k){
		if(rx - lx == 1){
			return lx;
		}
		int nl = tree[left(x)];
		int m = (lx + rx)/2;
		if(nl >= k) return kth(left(x),lx,m,k);
		else return kth(right(x),m,rx,k-nl);
	}
	
	
public:
	Stree(int n){
		init(n);
	}
	
	void set(int i, int v){
		set(i,v,0,0,sz);
	}
	
	int query(int l, int r){
		return query(l,r,0,0,sz);
	}
	
	int kth(int k){
		return kth(0,0,sz,k+1);
	}
};


int main(){
	int n,m; cin>>n>>m;
	Stree st(n);
	for(int i = 0 ; i < n ; i++){
		int v; cin>>v;
		st.set(i,v);
	}
	/*
	for(int i = 0 ; i < n ; i++){
		int x = st.query(i,i+1);
		cout<<x<<" ";	
	}
	cout<<"\n";
	*/
	
	while(m--){
		int type; cin>>type;
		if(type == 1){
			int i; cin>>i;
			int x = st.query(i,i+1);
			if(x == 1) st.set(i,0);
			else st.set(i,1);
			continue;
		}
		int k; cin>>k;
		cout<<st.kth(k)<<"\n";
	}
	return 0;
}
