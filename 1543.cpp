#include <bits/stdc++.h>
using namespace std;

string D, S;
int cnt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin,D);
    getline(cin,S);
    
    int ld=D.length(), ls=S.length();
    
    for(int i=0;i<l;i++){
        bool f=1;
        for(int j=0;j<ls;j++)
            if(D[i+j]!=S[j]){
                f=0;
                break;
            }
        if(f){
            cnt++;
            i+=ls-1;
        }
    }
    cout << cnt;
}
