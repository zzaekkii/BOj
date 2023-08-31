#include <bits/stdc++.h>
using namespace std;
int T, ans;
string S;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
      
    while(T--){
      ans = 0;
      cin >> S;
      for(auto a:S){
        if(a=='D') break;
        ans++;
      }
      cout << ans << '\n';
    }
}
