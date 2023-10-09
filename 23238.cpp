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
        unordered_map<int, int> V;
        
        for(int i=S;i<=E;i++)
            if(V.find(arr[i])==V.end())
                V.insert({arr[i],1});
            else V[arr[i]]++;
        
        int mmax=0;
        auto ans=V.begin();
        
        for(auto i=V.begin();i!=V.end();i++)
            if(i->second>=mmax){
                mmax=i->second;
                ans=i;
            }
        
        cout << ans->first << '\n';
    }
}
