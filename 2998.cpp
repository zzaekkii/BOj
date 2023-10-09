#include <bits/stdc++.h>
using namespace std;
string S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    reverse(S.begin(),S.end());
    
    while(S.length()%3) S.push_back('0');
    reverse(S.begin(),S.end());
    
    for(int i=0;S[i];i+=3){
        int n=0;
        for(int j=0;j<3;j++)
            n+=(S[i+j]-48)*((2-j)?((2-j)<<1):1);
        cout << n;
    }
}
