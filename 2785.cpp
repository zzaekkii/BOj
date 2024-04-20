#include <bits/stdc++.h>
using namespace std;

int N,T;
vector<int> V;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> T;
        V.push_back(T);
    }
    
    sort(V.begin(),V.end());
    
    while(V.size()!=1){
        V[V.size()-2]+=V[V.size()-1];
        V.pop_back();
        ans++;
        V[0]--;
        
        if(!V[0]){
            for(int i=0;i<V.size()-1;i++)
                V[i]=V[i+1];
            V.pop_back();
        }
    }
    
    cout << ans;
}
