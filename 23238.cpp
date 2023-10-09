#include <bits/stdc++.h>
using namespace std;
int N, Q, S, E;
int arr[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    
    for(int i=1;i<=N;i++)
        cin >> arr[i];
    
    while(Q--){
        cin >> S >> E;
        vector<int> V;
        int Vcount[100001]={0,};
        
        for(int i=S;i<=E;i++)
            if(find(V.begin(),V.end(),arr[i])==V.end()){
                V.push_back(arr[i]);
                Vcount[find(V.begin(),V.end(),arr[i])-V.begin()]++;
            }
            else Vcount[find(V.begin(),V.end(),arr[i])-V.begin()]++;
        
        int mmax=0;
        int ans=V[0];
        
        for(int i=0;i<V.size();i++)
            if(Vcount[i]>mmax){
                mmax=Vcount[i];
                ans=V[i];
            }
        
        cout << ans << '\n';
    }
}
