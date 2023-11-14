#include <bits/stdc++.h>
using namespace std;
int H,W;
string S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> H >> W;
    
    while(H--){
        cin >> S;        
        int x=-1;
        
        for(int i=0;i<W;i++){
            if(S[i]==99){
                x=i;
                cout << "0 ";
            }
            else{
                if(x==-1)cout << "-1 ";
                else cout << i-x << " ";
            }
        }
        cout << '\n';
    }
}
