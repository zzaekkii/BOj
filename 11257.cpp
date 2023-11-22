#include <bits/stdc++.h>
using namespace std;
int T,N,A,B,C;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
      cin >> N >> A >> B >> C;
      cout << N << ' ' << A+B+C << ' ';
      if(A+B+C>=55&&A>=11&&B>=8&&C>=12)cout << "PASS\n";
      else cout << "FAIL\n";
    }
}
