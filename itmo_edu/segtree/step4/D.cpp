#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
	int fr[41]{};
	ll inv = 0;
	Node(){}
	Node(int v){
		fr[v]++;
	}
};

Node comb(Node& l, Node& r){
	Node t;
	ll ans = 0;
	ll sum = r.fr[0];
	for(int i = 1; i <= 40; i++){
		ans += l.fr[i] * sum;
		sum += r.fr[i];
	}
	for(int i = 1 ; i <= 40 ; i++) t.fr[i] = l.fr[i] + r.fr[i];
	t.inv = ans + l.inv + r.inv;
	return t;
}

class Stree{
private:
	vector<Node> tree;
	int sz = 0;
	
	int left(int x){
		return 2*x + 1;
	}
	
	int right(int x){
		return 2*x + 2;
	}
	
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] = Node(v);
			return;
		}
		int m = (lx + rx)/2;
		if(i < m)
			set(i, v, left(x), lx, m);
		else
			set(i, v, right(x), m, rx);
		tree[x] = comb(tree[left(x)],tree[right(x)]);
	}
	// l lx rx r
	Node query(int l, int r, int x, int lx, int rx){
		if(l >= rx || r <= lx){
			return Node();
		}
		
		if(lx >= l && rx <= r){
			return tree[x];
		}
		
		int m = (lx + rx)/2;
		Node nl = query(l, r, left(x), lx, m);
		Node nr = query(l, r, right(x), m, rx);
		return comb(nl,nr);
	}
	
public:
	Stree(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		tree.assign(2*sz,Node());
	}
	
	void set(int i, int v){
		return set(i, v, 0, 0, sz);
	}
	
	int query(int l, int r){
		Node x =  query(l, r, 0, 0, sz);
		int ans = 0;
		for(int i = 1 ; i <= 40 ; i++){
			if(x.fr[i] > 0){
				ans++;
			}
		}
		return ans;
	}
};


int main(){
	int n,q; cin>>n>>q;
	Stree st(n);
	for(int i = 0 ; i < n ; i++){
		int v; cin>>v;
		st.set(i,v);
	}
	while(q--){
		int type; cin>>type;
		if(type == 1){
			int l,r; cin>>l>>r;
			l--; r--;
			int res = st.query(l,r+1);
			cout<<res<<"\n";
			continue;
		}
		int i,v; cin>>i>>v;
		i--;
		st.set(i,v);
	}
	
	return 0;
}

