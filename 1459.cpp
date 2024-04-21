#include <bits/stdc++.h>
using namespace std;

long long X,Y,W,S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> X >> Y >> W >> S;
    
    if(2*W>S){
        if(Y>X)Y^=X,X^=Y,Y^=X;
        
        int r=(X-Y)%2;
        if(W>S)cout << Y*S+((X-Y-r)*S+r*W);
        else cout << Y*S+((X-Y)*W);
    }else cout << (X+Y)*W;
}
