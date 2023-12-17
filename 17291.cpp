#include <bits/stdc++.h>
using namespace std;
int N;
int ist[23]={1,1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=1;i<N;i++){
        ist[i+1]=ist[i]*2;
        if((i+1-3>=1)&&(i+1-3)%2)ist[i+1]-=ist[i-3];
        if((i+1-4>=1)&&!((i+1-4)%2))ist[i+1]-=ist[i-4];
    }
    cout << ist[N];
}
