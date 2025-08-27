#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long ll;

struct Hash {
    /*
        Constantes
        P = potencia o base del hash polinomial
        MOD[0] , MOD[1] primos
        PI[0] , PI[1], inversos multiplicativos de P en MOD[0] y MOD[1] respectivamente
        
        Arreglos
        h[0][i] , h[1][i] hash en modulo MOD[0] y MOD[1] del substring de 0 ... i-1
        pi[0][i] , pi[1][i] inverso multiplicativo de las potencias de P en MODULO MOD[0] y MOD[1]
        pot[0][i] , pot[1][i] potensias de P en MOD[0] y MOD[1]
    */
	int P=1777771,MOD[2],PI[2];
	vector<int> h[2],pi[2];
    vector<ll> pot[2];
	Hash(string& s){
		MOD[0]=999727999;MOD[1]=1070777777;
		PI[0]=325255434;PI[1]=10018302;
		for(int k = 0 ; k < 2 ; ++k)
            h[k].resize(s.size()+1),pi[k].resize(s.size()+1), pot[k].resize(s.size() + 1);
	
        for(int k = 0 ; k < 2 ; ++k){
			h[k][0]=0;pi[k][0]=1;
			ll p=1;
            pot[k][0] = 1;
			for(int i = 1 ; i < s.size() + 1; ++i){
				h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
                pot[k][i] = p;
			}
		}
	}
	pair<ll,ll> get(int s, int e){
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
		h0=(1LL*h0*pi[0][s])%MOD[0];
		
        ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
		h1=(1LL*h1*pi[1][s])%MOD[1];
        return {h0,h1};
	}

    pair<ll,ll> add(int s1,int e1,int s2,int e2){
        auto H_r1 = get(s1,e1);
        auto H_r2 = get(s2,e2);
        ll h0 = (H_r2.first * pot[0][e1-s1]) % MOD[0];
        h0 = (h0 + H_r1.first) % MOD[0];

        ll h1 =(H_r2.second * pot[1][e1-s1]) % MOD[1];
        h1 = ( h1 + H_r1.second) % MOD[1];
        return {h0,h1};
    }
    
};

void test(){
    string s = "abacbaca";
    string sr = s;
    reverse(sr.begin(),sr.end());
    Hash a(s);
    Hash b(sr);
    bool x = a.add(0,2,6,s.size()) == b.get(2,6);
    cout<<x<<endl;
}

int n;
void slv(){
    string s,sr;
    cin>>s;
    sr = s;
    reverse(sr.begin(),sr.end());
    Hash a(s),b(sr);
    for(int i = 0 ; i < n ; i++){
        auto h1 = a.add(0,i,i+n,s.size());
        int l = i, r = i+n-1;
        l = s.size() - l - 1;
        r = s.size() - r - 1;
        auto h2 = b.get(r,l+1);
        if( h1 == h2){
            for(int j = r ; j <= l ; ++j) cout<<sr[j];
            cout<<"\n";
            cout<<(i)<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
}

int main(){
    while(cin>>n){
        slv();
    }
    return 0;
}
