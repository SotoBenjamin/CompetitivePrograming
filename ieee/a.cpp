#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
 
template<typename T>
void print(vector<T> &vec){
    for(auto &x:vec) cout<<x<<' ';
    cout<<'\n';
}
template<typename T>
void print(vector<pair<T,T>> &vec){
    for(auto &x:vec) cout<<x.first<<' '<<x.second<<'\n';
}
void barra(){ cout<<"----------------------"<<'\n'; }
 

bool isIN(int t , pair<int,int>& p){
    return t >= p.first && t <= p.second;
}

void solve(){
    int N;
    cin >> N;

    if (N == 0) {
        cout << "-1" << endl;
        return ;
    }

    

    vector<pair<int, int>> intervals(N);

    for (int i = 0; i < N; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    if(N == 1){
        cout<<intervals[0].first<<" "<<intervals[0].first<<"\n";
        return;
    }

    
    int minT1 = 101, minT2 = 101;
    for (int T1 = -100; T1 <= 100; T1++) {
        for (int T2 =T1; T2 <= 100; T2++) {
            bool flag = true;
            
            for (auto interval : intervals) {
                if( !isIN(T1,interval) && !isIN(T2,interval)){
                    flag = false;
                }
            }
            
            if( flag == false) continue;
            
            if(T1 < minT1){
                minT1 = T1;
                minT2 = T2;
            }
            else if( T1 == minT1){
                minT2 = min(minT2,T2);
            }

        }    
    }


    if( minT1 == 101){
        cout<<-1<<"\n";
        return;
    }

    cout<<min(minT1,minT2)<<" "<<max(minT1,minT2)<<"\n";
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) solve(); 
}